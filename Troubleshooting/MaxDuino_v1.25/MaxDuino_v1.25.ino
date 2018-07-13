#define VERSION "v1.25 MaxDuino"
// ---------------------------------------------------------------------------------
// DO NOT USE CLASS-10 CARDS on this project - they're too fast to operate using SPI
// ---------------------------------------------------------------------------------
/*
 *                                    TZXduino
 *                             Written and tested by
 *                          Andrew Beer, Duncan Edwards
 *                          www.facebook.com/Arduitape/
 *                          
 *              Designed for TZX files for Spectrum (and more later)
 *              Load TZX files onto an SD card, and play them directly 
 *              without converting to WAV first!
 *              
 *              Directory system allows multiple layers,  to return to root 
 *              directory ensure a file titles ROOT (no extension) or by 
 *              pressing the Menu Select Button.
 *              
 *              Written using info from worldofspectrum.org
 *              and TZX2WAV code by Francisco Javier Crespo
 *              
 *              ***************************************************************
 *              Menu System:
 *                TODO: add ORIC and ATARI tap support, clean up code, sleep                 
 *                
 *              V1.0
 *                Motor Control Added.
 *                High compatibility with Spectrum TZX, and Tap files
 *                and CPC CDT and TZX files.
 *                
 *                V1.32 Added direct loading support of AY files using the SpecAY loader 
 *                to play Z80 coded files for the AY chip on any 128K or 48K with AY 
 *                expansion without the need to convert AY to TAP using FILE2TAP.EXE. 
 *                Download the AY loader from http://www.specay.co.uk/download 
 *                and load the LOADER.TAP AY file loader on your spectrum first then
 *                simply select any AY file and just hit play to load it. A complete
 *                set of extracted and DEMO AY files can be downloaded from
 *                http://www.worldofspectrum.org/projectay/index.htm
 *                Happy listening!
 */

#include <SdFat.h>
#include <TimerOne.h>
#include <EEPROM.h>
#include "MaxDuino.h"

//Set defines for various types of screen, currently only 16x2 I2C LCD is supported
//#define SERIALSCREEN  1
//#define LCDSCREEN16x2   1
#define OLED1306   1
//#define P8544   1

#define MENU_ON 1  //comment to remove menu and save space

#define XY  1     //use original settings for Oled line 0,1 and status for menu
//#define XY2 1     //use double size font wihtout status line for menu
#ifdef XY
byte lineaxy=1;
#endif
#ifdef XY2
byte lineaxy=2;
#endif

//#define LOGOARDUITAPE 1   // original logo from arduitape
//#define LOGOMAXDUINO 1    //new logo made by Spirax
#define LOGOMAXDUINO2 1   //new logo2 made by rcmolina
//#define LOGOMAXDUINO3 1    //new logo3 made by rcmolina
//#define LOGOMAXDUINO4 1    //new logo4 made by rcmolina

#ifdef LCDSCREEN16x2
  #include <Wire.h> 
  #include <LiquidCrystal_I2C.h>
  LiquidCrystal_I2C lcd(0x3f,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display
  char indicators[] = {'|', '/', '-',0};
  uint8_t SpecialChar [8]= { 0x00, 0x10, 0x08, 0x04, 0x02, 0x01, 0x00, 0x00 };
  #define SCREENSIZE 16
#endif

#ifdef OLED1306 
  #include <Wire.h> 
  //#include "U8glib.h"
  //U8GLIB_SSD1306_128X32 u8g(U8G_I2C_OPT_NONE);  // I2C / TWI 

  //char line0[17];
  //char line1[17];
  char indicators[] = {'|', '/', '-',92};
  #define SCREENSIZE 16
#endif

#ifdef P8544
  #include <pcd8544.h>
  #define ADMAX 1023
  #define ADPIN 0
  #include <avr/pgmspace.h>
  byte dc_pin = 5;
  byte reset_pin = 3;
  byte cs_pin = 4;
  pcd8544 lcd(dc_pin, reset_pin, cs_pin);
  char indicators[] = {'|', '/', '-',0};
  uint8_t SpecialChar [8]= { 0x00, 0x10, 0x08, 0x04, 0x02, 0x01, 0x00, 0x00 };
  #define backlight_pin 2
  
  const byte Play [] PROGMEM = {
    0x00, 0x7f, 0x3e, 0x1c, 0x08, 0x00, 0x00
  };

  const byte Paused [] PROGMEM = {
    0x00, 0x7f, 0x7f, 0x00, 0x7f, 0x7f, 0x00
  };

  const byte Stop [] PROGMEM = {
    0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e
  };
  #define SCREENSIZE 14
#endif

char fline[17];

SdFat sd;                           //Initialise Sd card 

SdFile entry;                       //SD card file

#define filenameLength    100       //Maximum length for scrolling filename, hasta 255 no incrementa consumo RAM
#define subdirLength     25         // hasta 62 no incrementa el consumo de RAM

char fileName[filenameLength + 1];    //Current filename
char sfileName[13];                   //Short filename variable
char prevSubDir[3][subdirLength];    // Subir a la EPROM ¿?
int DirFilePos[3];                   //File Positios in Directory to be restored
int subdir = 0;
unsigned long filesize;             // filesize used for dimensioning AY files
const int chipSelect = 10;          //Sd card chip select pin

#define btnPlay       17            //Play Button
#define btnStop       16            //Stop Button
#define btnUp         15            //Up button
#define btnDown       14            //Down button
#define btnMotor      6             //Motor Sense (connect pin to gnd to play, NC for pause)
#define btnRoot       7             //Return to SD card root
#define scrollSpeed   250           //text scroll delay
#define scrollWait    3000          //Delay before scrolling starts

byte scrollPos = 0;                 //Stores scrolling text position
unsigned long scrollTime = millis() + scrollWait;

byte mselectMask = 0;              //Motor control state 1=on 0=off
byte motorState = 1;                //Current motor control state
byte oldMotorState = 1;             //Last motor control state
byte start = 0;                     //Currently playing flag
byte pskipMask = 0;                 // Pauses allowed
byte pauseOn = 0;                   //Pause state
int currentFile = 1;                //Current position in directory
int maxFile = 0;                    //Total number of files in directory
byte isDir = 0;                     //Is the current file a directory
unsigned long timeDiff = 0;         //button debounce

byte UP = 0;                      //Next File, down button pressed
char PlayBytes[subdirLength];

//byte block = 0;
//byte BlockCurrentID[10];
//unsigned long Fpos[10];

void setup() {
  
  #ifdef LCDSCREEN16x2
    lcd.init();                     //Initialise LCD (16x2 type)
    lcd.backlight();
    lcd.clear();
    lcd.createChar(0, SpecialChar);
  #endif
  
  #ifdef SERIALSCREEN
    Serial.begin(115200);
  #endif
  
  #ifdef OLED1306 
    //u8g.setRot180();  // Maybe you dont need this one, depends on how the display is mounted
    //sendcommand(0xc0); //set COM output scan direction (vertical flip) - reset value is 0xc0 (or 0xc8)
    /* sendcommand(0xa1);  //set segment re-map (horizontal flip) - reset value is 0xa0 (or 0xa1) */
                      
    //u8g.setFont(u8g_font_7x14); 
    //u8g.setFont(u8g_font_unifont); 
//    u8g.setFont(u8g_font_unifontr); // last from file u8g_font_data.c

    //const int PWR_ON = 0;  //Using Pin 0 to power the oleds VCC
    //const int RESET = 4;
    //pinMode(PWR_ON, OUTPUT);
    //digitalWrite(PWR_ON, HIGH);
    //pinMode(RESET, OUTPUT);
    //digitalWrite(RESET, HIGH); 
    delay(1000);  //Needed!
    // Initialize I2C and OLED Display
      // I2C Init

  
    Wire.begin();
    init_OLED();
    delay(1300);              // Show logo
    reset_display();           // Clear logo and load saved mode

  #endif

  #ifdef P8544 
    lcd.begin ();
    analogWrite (backlight_pin, 20);
    //lcd.clear();
    P8544_splash(); 
  #endif
  
  pinMode(chipSelect, OUTPUT);      //Setup SD card chipselect pin
//  if (!sd.begin(chipSelect,SPI_FULL_SPEED)) {
    while (!sd.begin(chipSelect,SPI_FULL_SPEED)) {      
    //Start SD card and check it's working
    printtextF(PSTR("No SD Card"),0);
    //lcd_clearline(0);
    //lcd.print(F("No SD Card"));
//    return;
    delay(250);
  } 
  
  sd.chdir();                       //set SD to root directory
  UniSetup();                       //Setup TZX specific options
  
  //General Pin settings
  //Setup buttons with internal pullup 
  pinMode(btnPlay,INPUT_PULLUP);
  digitalWrite(btnPlay,HIGH);
  pinMode(btnStop,INPUT_PULLUP);
  digitalWrite(btnStop,HIGH);
  pinMode(btnUp,INPUT_PULLUP);
  digitalWrite(btnUp,HIGH);
  pinMode(btnDown,INPUT_PULLUP);
  digitalWrite(btnDown,HIGH);
  pinMode(btnMotor, INPUT_PULLUP);
  digitalWrite(btnMotor,HIGH);
  pinMode(btnRoot, INPUT_PULLUP);
  digitalWrite(btnRoot, HIGH); 
   
 //printtext(VERSION,0);
  //lcd_clearline(0);
  //lcd.print(F(VERSION));
  printtextF(PSTR("Reset.."),0);
  delay(500);
  
  #ifdef LCDSCREEN16x2
    lcd.clear();
  #endif

  #ifdef P8544
    lcd.clear();
  #endif
       
  getMaxFile();                     //get the total number of files in the directory
  seekFile(currentFile);            //move to the first file in the directory
  #ifdef MENU_ON
    loadEEPROM();
  #endif  
  //delay(2000);  
  //printtextF(PSTR("Ready.."),0);
  //lcd_clearline(0);
  //lcd.print(F("Ready.."));  

  #ifdef OLED1306
    OledStatusLine();
  #endif
  
}

void loop(void) {
  
  if(start==1)
  {
    //TZXLoop only runs if a file is playing, and keeps the buffer full.
    uniLoop();
  } else {
    digitalWrite(outputPin, LOW);    //Keep output LOW while no file is playing.
  }
  
  if((millis()>=scrollTime) && start==0 && (strlen(fileName)> SCREENSIZE)) {
    //Filename scrolling only runs if no file is playing to prevent I2C writes 
    //conflicting with the playback Interrupt
    scrollTime = millis()+scrollSpeed;
    scrollText(fileName);
    scrollPos +=1;
    if(scrollPos>strlen(fileName)) {
      scrollPos=0;
      scrollTime=millis()+scrollWait;
      scrollText(fileName);
    }
  }
  motorState=digitalRead(btnMotor);
  if (millis() - timeDiff > 50) {   // check switch every 50ms 
     timeDiff = millis();           // get current millisecond count
      
     if(digitalRead(btnPlay) == LOW) {
        //Handle Play/Pause button
        if(start==0) {
          //If no file is play, start playback
          playFile();
          if (mselectMask == 1){  
            oldMotorState = !motorState;  //Start in pause if Motor Control is selected
          }
          delay(200);
          
        } else {
          //If a file is playing, pause or unpause the file                  
          if (pauseOn == 0) printtextF(PSTR("Paused"),0); 
          else printtextF(PSTR("Playing"),0);      
                         
          #ifdef LCDSCREEN16x2            
   /*         //lcd_clearline(0);
            lcd.setCursor(0,0);
            lcd.print(F("Paused "));
            //sprintf(PlayBytes,"Paused % 3d%%  %03d",newpct,lcdsegs%1000);lcd.setCursor(0,0);lcd.print(PlayBytes);               
            //lcd.print(entry.curPosition()); */

            //sprintf(PlayBytes,"Paused % 3d%%  %03d",newpct,lcdsegs%1000); sendStrXY(PlayBytes,0,0);
                          
            itoa(newpct,PlayBytes,10);strcat_P(PlayBytes,PSTR("%"));lcd.setCursor(8,0);lcd.print(PlayBytes);
            //sprintf(PlayBytes,"%03d",lcdsegs%1000);lcd.setCursor(13,0);lcd.print(PlayBytes);
            strcpy(PlayBytes,"000");
            if ((lcdsegs %1000) <10) itoa(lcdsegs%10,PlayBytes+2,10);
            else 
               if ((lcdsegs %1000) <100)itoa(lcdsegs%1000,PlayBytes+1,10);
               else 
                  itoa(lcdsegs%1000,PlayBytes,10);
                              
            lcd.setCursor(13,0);lcd.print(PlayBytes); 
            
          #endif
          #ifdef OLED1306
            //sprintf(PlayBytes,"Paused % 3d%%  %03d",newpct,lcdsegs%1000); sendStrXY(PlayBytes,0,0);
                         
            itoa(newpct,PlayBytes,10);strcat_P(PlayBytes,PSTR("%"));setXY (8,0);sendStr(PlayBytes);
            //sprintf(PlayBytes,"%03d",lcdsegs%1000);sendStrXY(PlayBytes,13,0);
            strcpy(PlayBytes,"000");
            if ((lcdsegs %1000) <10) itoa(lcdsegs%10,PlayBytes+2,10);
            else 
               if ((lcdsegs %1000) <100)itoa(lcdsegs%1000,PlayBytes+1,10);
               else 
                  itoa(lcdsegs%1000,PlayBytes,10);
                              
            setXY(13,0);
            sendStr(PlayBytes);
          #endif

         #ifdef P8544                                      
            itoa(newpct,PlayBytes,10);
            strcat_P(PlayBytes,PSTR("%"));
            lcd.setCursor(0,3);
            lcd.print(PlayBytes);
            //sprintf(PlayBytes,"%03d",lcdsegs%1000);lcd.setCursor(13,0);lcd.print(PlayBytes);strcpy(PlayBytes,"000");
            if ((lcdsegs %1000) <10) itoa(lcdsegs%10,PlayBytes+2,10);
            else 
               if ((lcdsegs %1000) <100)itoa(lcdsegs%1000,PlayBytes+1,10);
               else 
                  itoa(lcdsegs%1000,PlayBytes,10);
                              
            //lcd.setCursor(0,3);lcd.print(PlayBytes); 
            lcd.gotoRc(3,38);
            lcd.bitmap(Paused, 1, 6);
          #endif
            
          //scrollPos=0;
          //scrollText(fileName);                                       
          pauseOn = !pauseOn;
       }
       
       debounce(btnPlay);         
/*       while(digitalRead(btnPlay)==LOW) {
        //prevent button repeats by waiting until the button is released.
        delay(50);
       }
*/
     }

/*
     if(digitalRead(btnRoot)==LOW && start==1 ){
 //      printtextF(PSTR("REPeat Block.."),0);
 //      delay(500);

       bytesRead=blockOffset[block];                                //offset from beginning
       currentID=blockID[block];
       currentTask=PROCESSID;
       
       PlayBlock();  

       debounce(btnRoot);  
//       while(digitalRead(btnRoot)==LOW) {
//         //prevent button repeats by waiting until the button is released.
//         delay(50);
//       }

     }
*/
     if(digitalRead(btnRoot)==LOW && start==0){
       //Return to root of the SD card.
       //printtextF(PSTR(VERSION),0);
       //lcd_clearline(0);
       //lcd.print(F(VERSION));

        #ifdef MENU_ON
           menuMode();
           //setBaud();
           printtextF(PSTR(VERSION),0);
           //lcd_clearline(1);
          #ifdef LCDSCREEN16x2
            printtextF(PSTR(""),1);
          #endif      
          #ifdef OLED1306
            printtextF(PSTR(""),lineaxy);
          #endif
          #ifdef P8544
            printtextF(PSTR(""),1);
          #endif      
         
          scrollPos=0;
          scrollText(fileName);
     /*     #ifdef OLED1306 
            OledStatusLine();
          #endif */
       #else             
         subdir=0;
         prevSubDir[0][0]='\0';
         prevSubDir[1][0]='\0';
         prevSubDir[2][0]='\0';
         sd.chdir(true);
         getMaxFile();
         currentFile=1;
         seekFile(currentFile);         
       #endif

       debounce(btnRoot);  
/*       while(digitalRead(btnRoot)==LOW) {
         //prevent button repeats by waiting until the button is released.
         delay(50);
       }
*/       
     }
     
     if(digitalRead(btnStop)==LOW && start==1) {
       stopFile();

       debounce(btnStop);  
/*       while(digitalRead(btnStop)==LOW) {
         //prevent button repeats by waiting until the button is released.
         delay(50);
       }
*/       
     }
     if(digitalRead(btnStop)==LOW && start==0 && subdir >0) {  
       fileName[0]='\0';
       subdir--;
       prevSubDir[subdir][0]='\0';     
       switch(subdir){
        case 1:
           //sprintf(fileName,"%s%s",prevSubDir[0],prevSubDir[1]);
           sd.chdir(strcat(strcat(fileName,"/"),prevSubDir[0]),true);
           break;
        case 2:
           //sprintf(fileName,"%s%s/%s",prevSubDir[0],prevSubDir[1],prevSubDir[2]);
           sd.chdir(strcat(strcat(strcat(strcat(fileName,"/"),prevSubDir[0]),"/"),prevSubDir[1]),true);
           break;
       case 3:
           //sprintf(fileName,"%s%s/%s/%s",prevSubDir[0],prevSubDir[1],prevSubDir[2],prevSubDir[3]);
          sd.chdir(strcat(strcat(strcat(strcat(strcat(strcat(fileName,"/"),prevSubDir[0]),"/"),prevSubDir[1]),"/"),prevSubDir[2]),true); 
           break;          
        default: 
           //sprintf(fileName,"%s",prevSubDir[0]);
           sd.chdir("/",true);
       }
       //Return to prev Dir of the SD card.
       //sd.chdir(fileName,true);
       //sd.chdir("/CDT");       
       //printtext(prevDir,0); //debug back dir
       
       getMaxFile();
       //currentFile=1;
       currentFile=DirFilePos[subdir];
       
/*          PlayBytes[0]='\0'; itoa(currentFile,PlayBytes,10); 
          printtext(PlayBytes,0);
          delay(1000);
          PlayBytes[0]='\0'; itoa(DirFilePos[0],PlayBytes,10); 
          printtext(PlayBytes,0);
          delay(1000);
          PlayBytes[0]='\0'; itoa(DirFilePos[1],PlayBytes,10); 
          printtext(PlayBytes,0);
          delay(1000);
          PlayBytes[0]='\0'; itoa(DirFilePos[2],PlayBytes,10); 
          printtext(PlayBytes,0);
          delay(1000); */

       UP=1;
       seekFile(currentFile);
       DirFilePos[subdir]=0;

    /*      PlayBytes[0]='\0'; itoa(currentFile,PlayBytes,10); 
          printtext(PlayBytes,0);
          delay(1000);
          PlayBytes[0]='\0'; itoa(DirFilePos[0],PlayBytes,10); 
          printtext(PlayBytes,0);
          delay(1000);
          PlayBytes[0]='\0'; itoa(DirFilePos[1],PlayBytes,10); 
          printtext(PlayBytes,0);
          delay(1000);
          PlayBytes[0]='\0'; itoa(DirFilePos[2],PlayBytes,10); 
          printtext(PlayBytes,0);
          delay(1000); */

       debounce(btnStop);   
/*       while(digitalRead(btnStop)==LOW) {
         //prevent button repeats by waiting until the button is released.
         delay(50);
       }
*/
     }     

     if(digitalRead(btnUp)==LOW && start==1 && pauseOn==1) {

/*
       bytesRead=11;                     // for tzx skip header(10) + GETID(11)
       currentTask=PROCESSID;
*/
/*
       bytesRead=0;                       // for both tap and tzx, no header for tap
       currentTask=GETFILEHEADER;         //First task (default): search for tzx header
*/
       if (block < maxblock-1) block++;
       else block = 0;
       bytesRead=blockOffset[block];
       currentID=blockID[block];
       currentTask=PROCESSID; 
       
       PlayBlock();       
       debounce(btnUp);         
/*       while(digitalRead(btnUp)==LOW) {
         //prevent button repeats by waiting until the button is released.
         delay(50); 
       }
 */      
     }
         
     if(digitalRead(btnUp)==LOW && start==0) {
       //Move up a file in the directory
       scrollTime=millis()+scrollWait;
       scrollPos=0;
       upFile();
       
       debounce(btnUp);       
/*       while(digitalRead(btnUp)==LOW) {
         //prevent button repeats by waiting until the button is released.
         delay(50); 
       }
*/
     }

     if(digitalRead(btnDown)==LOW && start==1 && pauseOn==1) {

/*
       bytesRead=11;                     // for tzx skip header(10) + GETID(11)
       currentTask=PROCESSID;
*/
/*
       bytesRead=0;                       // for both tap and tzx, no header for tap
       currentTask=GETFILEHEADER;         //First task (default): search for tzx header
*/
       if (block > 0) block--;
       else block = maxblock-1; 
       bytesRead=blockOffset[block];
       currentID=blockID[block];
       currentTask=PROCESSID; 
       
       PlayBlock(); 
      debounce(btnDown);                  
/*       while(digitalRead(btnDown)==LOW) {
         //prevent button repeats by waiting until the button is released.
         delay(50);
       }
*/
     }
     
     if(digitalRead(btnDown)==LOW && start==0 ) {
       //Move down a file in the directory
       scrollTime=millis()+scrollWait;
       scrollPos=0;
       downFile();
       
       debounce(btnDown);      
/*       while(digitalRead(btnDown)==LOW) {
         //prevent button repeats by waiting until the button is released.
         delay(50); 
       }
*/
     }
     if(start==1 && (!oldMotorState==motorState) && mselectMask==1 ) {  
       //if file is playing and motor control is on then handle current motor state
       //Motor control works by pulling the btnMotor pin to ground to play, and NC to stop
       if(motorState==1 && pauseOn==0) {
         //printtextF(PSTR("PAUSED"),0);
         #ifdef LCDSCREEN16x2
              lcd.setCursor(0,0);
              lcd.print("PAUSED ");    
         #endif 
         #ifdef OLED1306
              sendStrXY("PAUSED ",0,0);
         #endif 
         #ifdef P8544
              lcd.setCursor(0,0);
              lcd.print("PAUSED ");                       
         #endif                 
         scrollPos=0;
         scrollText(fileName);
         //lcd_clearline(0);
         //lcd.print(F("Paused "));         
         pauseOn = 1;
       } 
       if(motorState==0 && pauseOn==1) {
         //printtextF(PSTR("PLAYing"),0);
         #ifdef LCDSCREEN16x2
              lcd.setCursor(0,0);
              lcd.print("PLAYing");    
         #endif 
         #ifdef OLED1306
              sendStrXY("PLAYing",0,0);
         #endif 
         #ifdef P8544
              lcd.setCursor(0,0);
              lcd.print("PLAYing");                       
         #endif            
         scrollPos=0;
         scrollText(fileName);
         //lcd_clearline(0);
         //lcd.print(F("Playing"));   
         //delay(2250);
         pauseOn = 0;
       }
       oldMotorState=motorState;
     }
  }
}

void debounce(int boton){
  while(digitalRead(boton)==LOW){
    //prevent button repeats by waiting until the button is released.
    delay(50);
  }
}

void upFile() {    
  //move up a file in the directory
  currentFile--;
  if(currentFile<1) {
    getMaxFile();
    currentFile = maxFile;
  }
  UP=1;   
  seekFile(currentFile);
}

void downFile() {    
  //move down a file in the directory
  currentFile++;
  if(currentFile>maxFile) { currentFile=1; }
  UP=0;  
  seekFile(currentFile);
}

void seekFile(int pos) {    
  //move to a set position in the directory, store the filename, and display the name on screen.
  if (UP==1) {  
    entry.cwd()->rewind();
    for(int i=1;i<=currentFile-1;i++) {
      entry.openNext(entry.cwd(),O_READ);
      entry.close();
    }
  }

  if (currentFile==1) {entry.cwd()->rewind();}
  entry.openNext(entry.cwd(),O_READ);
  entry.getName(fileName,filenameLength);
  entry.getSFN(sfileName);
  filesize = entry.fileSize();
  ayblklen = filesize + 3;  // add 3 file header, data byte and chksum byte to file length
  if(entry.isDir() || !strcmp(sfileName, "ROOT")) { isDir=1; } else { isDir=0; }
  entry.close();

  PlayBytes[0]='\0'; 
  if (isDir==1) {
 //   strcat_P(PlayBytes,PSTR(VERSION));
    //if (subdir >0)strncpy(PlayBytes,prevSubDir[subdir-1],16);
    if (subdir >0)strcpy(PlayBytes,prevSubDir[subdir-1]);
    else strcat_P(PlayBytes,PSTR(VERSION));
    #ifdef P8544
      printtext("                 ",3);
    #endif
    
  } else {
    ltoa(filesize,PlayBytes,10);strcat_P(PlayBytes,PSTR(" bytes"));
    #ifdef P8544
      printtext("                 ",3);
    #endif
  }

  //PlayBytes[0]='\0'; itoa(DirFilePos[0],PlayBytes,10); 
  printtext(PlayBytes,0);
  //printtext(prevSubDir[0],0);

  
  scrollPos=0;
  scrollText(fileName);
}

void stopFile() {
  //TZXStop();
  casStop();
  if(start==1){
    printtextF(PSTR("Stopped"),0);
    //lcd_clearline(0);
    //lcd.print(F("Stopped"));
    #ifdef P8544
      lcd.gotoRc(3,38);
      lcd.bitmap(Stop, 1, 6);
    #endif
    start=0;
  }
}

void playFile() {
  //PlayBytes[0]='\0';
  //strcat_P(PlayBytes,PSTR("Playing "));ltoa(filesize,PlayBytes+8,10);strcat_P(PlayBytes,PSTR("B"));  
  if(isDir==1) {
    //If selected file is a directory move into directory
    changeDir();
  } else {
    if(entry.cwd()->exists(sfileName)) {
      printtextF(PSTR("Playing"),0);
      //printtext(PlayBytes,0);
      //lcd_clearline(0);
      //lcd.print(PlayBytes);      
      scrollPos=0;
      pauseOn = 0;
      scrollText(fileName);
      currpct=100;
      lcdsegs=0;
      UniPlay(sfileName);           //Load using the short filename
        #ifdef P8544
          lcd.gotoRc(3,38);
          lcd.bitmap(Play, 1, 6);
        #endif      
      start=1;       
    } else {
      #ifdef LCDSCREEN16x2
        printtextF(PSTR("No File Selected"),1);
      #endif      
      #ifdef OLED1306
        printtextF(PSTR("No File Selected"),lineaxy);
      #endif
      #ifdef P8544
        printtextF(PSTR("No File Selected"),1);
      #endif
      
      //lcd_clearline(1);
      //lcd.print(F("No File Selected"));
    }
  }
}

void getMaxFile() {    
  //gets the total files in the current directory and stores the number in maxFile
  
  entry.cwd()->rewind();
  maxFile=0;
  while(entry.openNext(entry.cwd(),O_READ)) {
    //entry.getName(fileName,filenameLength);
    entry.close();
    maxFile++;
  }
  entry.cwd()->rewind();
}



void changeDir() {    
  //change directory, if fileName="ROOT" then return to the root directory
  //SDFat has no easy way to move up a directory, so returning to root is the easiest way. 
  //each directory (except the root) must have a file called ROOT (no extension)
                      
  if(!strcmp(fileName, "ROOT")) {
    subdir=0;    
    sd.chdir(true);
  } else {
     //if (subdir >0) entry.cwd()->getName(prevSubDir[subdir-1],filenameLength); // Antes de cambiar
     DirFilePos[subdir] = currentFile;
     sd.chdir(fileName, true);
     if (strlen(fileName) > subdirLength) {
      //entry.getSFN(sfileName);
      strcpy(prevSubDir[subdir], sfileName);
     }
     else {
      strcpy(prevSubDir[subdir], fileName);
     }
     
     //entry.cwd()->getName(prevSubDir[subdir],filenameLength);
     //entry.getSFN(sfileName);
     //strcpy(prevSubDir[subdir], sfileName);
     //strcpy(prevSubDir[subdir], fileName);
     
     subdir++;      
  }
  getMaxFile();
  currentFile=1;
  seekFile(currentFile);
}

void scrollText(char* text)
{
  #ifdef LCDSCREEN16x2
  //Text scrolling routine.  Setup for 16x2 screen so will only display 16 chars
  if(scrollPos<0) scrollPos=0;
  char outtext[17];
  if(isDir) { outtext[0]= 0x3E; 
    for(int i=1;i<16;i++)
    {
      int p=i+scrollPos-1;
      if(p<strlen(text)) 
      {
        outtext[i]=text[p];
      } else {
        outtext[i]='\0';
      }
    }
  } else { 
    for(int i=0;i<16;i++)
    {
      int p=i+scrollPos;
      if(p<strlen(text)) 
      {
        outtext[i]=text[p];
      } else {
        outtext[i]='\0';
      }
    }
  }
  outtext[16]='\0';
  printtext(outtext,1);
  //lcd_clearline(1);
  //lcd.print(outtext);
  #endif

  #ifdef OLED1306
  //Text scrolling routine.  Setup for 16x2 screen so will only display 16 chars
  if(scrollPos<0) scrollPos=0;
  char outtext[17];
  if(isDir) { outtext[0]= 0x3E; 
    for(int i=1;i<16;i++)
    {
      int p=i+scrollPos-1;
      if(p<strlen(text)) 
      {
        outtext[i]=text[p];
      } else {
        outtext[i]='\0';
      }
    }
  } else { 
    for(int i=0;i<16;i++)
    {
      int p=i+scrollPos;
      if(p<strlen(text)) 
      {
        outtext[i]=text[p];
      } else {
        outtext[i]='\0';
      }
    }
  }
  outtext[16]='\0';
  printtext(outtext,lineaxy);
  //lcd_clearline(1);
  //lcd.print(outtext);
  #endif

  #ifdef P8544
  //Text scrolling routine.  Setup for 16x2 screen so will only display 16 chars
  if(scrollPos<0) scrollPos=0;
  char outtext[15];
  if(isDir) { outtext[0]= 0x3E; 
    for(int i=1;i<14;i++)
    {
      int p=i+scrollPos-1;
      if(p<strlen(text)) 
      {
        outtext[i]=text[p];
      } else {
        outtext[i]='\0';
      }
    }
  } else { 
    for(int i=0;i<14;i++)
    {
      int p=i+scrollPos;
      if(p<strlen(text)) 
      {
        outtext[i]=text[p];
      } else {
        outtext[i]='\0';
      }
    }
  }
  outtext[14]='\0';
  printtext(outtext,1);
  //lcd_clearline(1);
  //lcd.print(outtext);
  #endif
}

/*
void lcd_clearline(int l) {    
  //clear a single line on the LCD
  
  lcd.setCursor(0,l);
  lcd.print(F("                    "));
  lcd.setCursor(0,l);
}
*/

void printtextF(const char* text, int l) {  //Print text to screen. 
  
  #ifdef SERIALSCREEN
  Serial.println(reinterpret_cast <const __FlashStringHelper *> (text));
  #endif
  
  #ifdef LCDSCREEN16x2
    strncpy_P(fline, text, 16);
    for(int i=strlen(fline);i<16;i++) fline[i]=0x20;
    //lcd.setCursor(0,l);
    //lcd.print(F("                    "));
    lcd.setCursor(0,l);
    lcd.print(fline);
    //lcd.print(reinterpret_cast <const __FlashStringHelper *> (text));
    
  #endif

 #ifdef OLED1306
      strncpy_P(fline, text, 16);
      for(int i=strlen(fline);i<16;i++) fline[i]=0x20;
      sendStrXY(fline,0,l);
  /*    u8g.firstPage();
      do {  
         u8g.drawStr( 0, 15, line0);   
         u8g.drawStr( 0, 30, line1);    
      } while( u8g.nextPage() ); */
      //sendStrXY(line0,0,0);
      //sendStrXY(line1,0,1);
  #endif

  #ifdef P8544
    strncpy_P(fline, text, 14);
    for(int i=strlen(fline);i<14;i++) fline[i]=0x20;
    //lcd.setCursor(0,l);
    //lcd.print(F("              "));
    lcd.setCursor(0,l);
    lcd.print(fline);
    //lcd.print(reinterpret_cast <const __FlashStringHelper *> (text));
  #endif 
   
}

void printtext(char* text, int l) {  //Print text to screen. 
  
  #ifdef SERIALSCREEN
  Serial.println(text);
  #endif
  
  #ifdef LCDSCREEN16x2
    for(int i=0;i<16;i++)
    {
      if(i<strlen(text))  fline[i]=text[i];
      else  fline[i]=0x20;
    }   

    //lcd.setCursor(0,l);
    //lcd.print(F("                    "));
    lcd.setCursor(0,l);
    lcd.print(fline);
  #endif

   #ifdef OLED1306
      for(int i=0;i<16;i++)
      {
        if(i<strlen(text))  fline[i]=text[i];
        else  fline[i]=0x20;
      }    
      sendStrXY(fline,0,l);
      //setXY(0,l);
      //sendStr("                    ");
      //setXY(0,l);
      //sendStr(text);
  #endif

  #ifdef P8544
    for(int i=0;i<14;i++)
      {
        if(i<strlen(text))  fline[i]=text[i];
        else  fline[i]=0x20;
      }  
    //lcd.setCursor(0,l);
    //lcd.print(F("              "));
    lcd.setCursor(0,l);
    lcd.print(fline);
  #endif 
   
}

#ifdef OLED1306
  void OledStatusLine() {
    #ifdef XY
    setXY(0,3);
    sendChar(48+BAUDRATE/1000); sendChar(48+(BAUDRATE/100)%10);sendChar(48+(BAUDRATE/10)%10);sendChar(48+BAUDRATE%10);
    setXY(5,3);
    if(mselectMask==1) sendStr(" M:ON");
    else sendStr("m:off");    
    setXY(11,3); 
    if (TSXspeedup == 1) sendStr(" S^ON");
    else sendStr("s^off");
    #endif
  }
#endif

void PlayBlock()
{

       printtextF(PSTR(" "),0);
       #ifdef LCDSCREEN16x2
         lcd.setCursor(0,0);
   //      lcd.print("BLK:");lcd.print(' ');
         lcd.print(block);lcd.print(' ');
         lcd.print("ID:");lcd.print(blockID[block],HEX); // Block ID en hex
         lcd.print(' ');lcd.print("#:");lcd.print(blockOffset[block]);
       #endif
       #ifdef OLED1306
          setXY(0,0);
   //       sendStr("BLK:");
          utoa(block, PlayBytes, 10);sendStr(PlayBytes);sendChar(' ');
          sendStr("ID:");utoa(blockID[block],PlayBytes,16);sendStr(PlayBytes); // Block ID en hex
          sendChar(' ');sendStr("#:");utoa(blockOffset[block],PlayBytes,10);sendStr(PlayBytes);
       #endif      
       #ifdef P8544
          lcd.setCursor(12,3);lcd.print('B'+block);
       #endif

//       printtextF(PSTR("REWind ALL..    "),0);
       delay(1000);
       
       printtextF(PSTR("Playing"),0);
       //block--;
       //currentID=BlockCurrentID[block];
       //pos=Fpos[block];
       //entry.seekSet(Fpos[block]);
       //entry.seekSet(0);
       //pos=0;       
       //lcd.println(pos); lcd.print(" ");
       //stopFile();
       //playFile(); 
       //TZXPlay(sfileName);           //Load using the short filename

       //reset data block values
       //clearBuffer();
       currpct=100;
       lcdsegs=0;       
       currentBit=0;                               // fallo reproducción de .tap tras .tzx
       pass=0;
              

/*
       entry.getSFN(sfileName);

       currentBlockTask = READPARAM;               //First block task is to read in parameters
       //currentTask=PROCESSID;
       //currentID=TAP;
       currentTask=GETFILEHEADER;                  //First task: search for header
       checkForEXT(sfileName);
*/


//  entry.getSFN(sfileName);
  
  
//  Timer1.stop();                              //Stop timer interrupt

//  bytesRead=0;                                //start of file

  checkForEXT (sfileName);
  if (!casduino) {
    currentBlockTask = READPARAM;               //First block task is to read in parameters
//    clearBuffer2();                               // chick sound with CASDUINO clearBuffer()
//    isStopped=false;
//    pinState=LOW;                               //Always Start on a LOW output for simplicity
//    count = 255;                                //End of file buffer flush
//    EndOfFile=false;
//    digitalWrite(outputPin, pinState);
    Timer1.setPeriod(1000);                     //set 1ms wait at start of a file.
  }


   
/*
       isStopped=false;
       pinState=LOW;                               //Always Start on a LOW output for simplicity
       count = 255;                                //End of file buffer flush
       EndOfFile=false;
       digitalWrite(outputPin, pinState);
*/   
}

