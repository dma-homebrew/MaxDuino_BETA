#ifdef OLED1306

  #define ROTATE180   1
  //#define UNROTATE 1

  #define OLED_address   0x3C //0x3C or 0x3D

//------------------------------------------------------------------------------
// Files generated by LCD Assistant
// http://en.radzio.dxp.pl/bitmap_converter/
//------------------------------------------------------------------------------

#ifdef LOGOMAXDUINO2
// 'Maxduino2_128x32'
const byte logo [] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x80, 0x80, 0x40, 0x40, 0x80, 0x60, 0xF0, 0x60, 0xC0,
0x80, 0x60, 0xF0, 0xF0, 0xF8, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
0x88, 0xF8, 0xC0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00,
0xE8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xC8, 0x08, 0xF8, 0xF8, 0xF8, 0xF8, 0x38, 0x18,
0x18, 0x38, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x38, 0x38, 0x38, 0xF8,
0xF8, 0xF8, 0x08, 0xC8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF0, 0xE0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x0D, 0x1E, 0x3F, 0x38, 0x18, 0x7F, 0x3E, 0x19, 0x7E, 0xF9, 0xFB, 0x3E,
0x18, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0x3F, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x18, 0x18, 0x10, 0x10,
0x10, 0x1C, 0x18, 0x10, 0x1F, 0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x18, 0x00, 0x00, 0x00,
0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0x7F, 0x7F, 0xFF, 0xFF, 0xFC, 0xF0, 0xF3, 0xF3, 0xF3, 0xF3, 0xF2,
0xF2, 0xF2, 0x73, 0x73, 0x73, 0x73, 0x73, 0x73, 0x73, 0x73, 0x73, 0x73, 0x73, 0x72, 0xF3, 0xF3,
0xF3, 0xF0, 0xFC, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0x00, 0x00,
0x00, 0xC0, 0xC0, 0xC0, 0xC1, 0x01, 0x01, 0x01, 0xC1, 0xC1, 0x81, 0x01, 0x81, 0xC1, 0x01, 0x01,
0xC1, 0xC1, 0xC1, 0xC1, 0xC1, 0x81, 0x01, 0x01, 0x01, 0xC1, 0xC1, 0x01, 0x01, 0x01, 0xC1, 0xC1,
0x01, 0x01, 0xC0, 0xC0, 0x00, 0x00, 0xC0, 0xC0, 0x80, 0x80, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x80,
0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x07, 0x7F, 0xFF, 0xFF, 0xFF, 0xE1, 0xC0, 0xC0, 0xC0, 0xE1, 0xF3,
0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x3F, 0x7B,
0x71, 0x60, 0x71, 0x71, 0x3F, 0x1F, 0x07, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x0F, 0x0F, 0x1E, 0x0E, 0x0F, 0x3F, 0x00, 0x00,
0x1C, 0x17, 0x17, 0x3F, 0x3F, 0x3C, 0x00, 0x00, 0x20, 0x31, 0x1F, 0x1F, 0x31, 0x20, 0x00, 0x00,
0x1F, 0x3F, 0x31, 0x30, 0x30, 0x19, 0x0F, 0x00, 0x00, 0x0F, 0x1F, 0x20, 0x20, 0x20, 0x3F, 0x3F,
0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00, 0x3F, 0x07, 0x07, 0x0F, 0x1F, 0x01, 0x00, 0x00, 0x0F, 0x1D,
0x30, 0x30, 0x18, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xFF, 0xFF, 0xFF, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE1, 0xE9, 0xEB, 0xEB, 0xEB, 0xEB, 0xEB, 0xE9,
0xE9, 0xE8, 0xE8, 0xE8, 0xE8, 0xE8, 0xE8, 0xE8, 0xE8, 0xE8, 0xE8, 0xE8, 0xE8, 0xE8, 0xE8, 0xE8,
0xE8, 0xE8, 0xE8, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00
};
#endif

#ifdef LOGOMAXDUINO
// 'Maxduino_128x32'
const byte logo [] PROGMEM = {

0x00, 0x00, 0x00, 0x00, 0x60, 0xB8, 0x44, 0x5A, 0x2D, 0x2E, 0x95, 0x93, 0x16, 0x96, 0x94, 0x10,
0x10, 0x20, 0x20, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00,
0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00,
0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80,
0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x40, 0x40, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x01,
0x96, 0x22, 0x02, 0xA2, 0x92, 0x06, 0x03, 0x01, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x40, 0xE6, 0xF9, 0xF0, 0xF8, 0x78, 0xFC, 0xF0, 0xF1, 0xE0, 0xE7, 0xE6, 0x31, 0xF8,
0xF4, 0xE2, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x02, 0xF2, 0xC6, 0x38, 0xC3, 0xE0, 0x18,
0xC6, 0xF2, 0x02, 0xFE, 0x00, 0x01, 0xC0, 0x38, 0x86, 0x62, 0x3A, 0xC6, 0x38, 0xC1, 0x00, 0x18,
0xC0, 0x1E, 0x62, 0x8C, 0x10, 0x31, 0x8C, 0x62, 0x12, 0x0E, 0x00, 0xFE, 0x02, 0xFA, 0x0A, 0x0A,
0x0A, 0x0A, 0x12, 0xE4, 0x08, 0xF1, 0x02, 0xF0, 0x10, 0xF4, 0x04, 0x04, 0x04, 0xF0, 0x10, 0xF4,
0x00, 0xF7, 0x15, 0xF7, 0x00, 0xF1, 0x10, 0xB0, 0xD4, 0x54, 0x54, 0x94, 0x24, 0xC8, 0x10, 0x80,
0x60, 0xA0, 0xD4, 0x54, 0xD2, 0x92, 0x62, 0x82, 0x0C, 0xF0, 0x00, 0x00, 0x00, 0x80, 0xEB, 0xF4,
0x73, 0x25, 0x65, 0x27, 0x73, 0xF0, 0xE8, 0xB2, 0x75, 0xF4, 0xE8, 0x90, 0x60, 0x80, 0x00, 0x00,
0x00, 0x01, 0x0F, 0x1E, 0x3D, 0x31, 0x4C, 0x7B, 0x7B, 0xF7, 0xF7, 0x07, 0x7B, 0x7B, 0x1B, 0x00,
0x01, 0x02, 0x07, 0x07, 0x0E, 0x0C, 0x00, 0x00, 0x3F, 0x20, 0x3F, 0x01, 0x0E, 0x30, 0x30, 0x0E,
0x01, 0x3F, 0x20, 0x3F, 0x10, 0x2E, 0x31, 0x0C, 0x05, 0x05, 0x05, 0x05, 0x0C, 0x31, 0x2E, 0x10,
0x30, 0x2C, 0x23, 0x18, 0x04, 0x06, 0x18, 0x23, 0x24, 0x38, 0x00, 0x3F, 0x20, 0x2F, 0x28, 0x28,
0x28, 0x28, 0x24, 0x13, 0x08, 0x07, 0x00, 0x1F, 0x30, 0x27, 0x28, 0x28, 0x2C, 0x37, 0x20, 0x3F,
0x00, 0x3F, 0x20, 0x3F, 0x00, 0x3F, 0x20, 0x3F, 0x00, 0x00, 0x00, 0x3F, 0x20, 0x3F, 0x00, 0x07,
0x18, 0x17, 0x2C, 0x28, 0x2C, 0x27, 0x18, 0x07, 0x00, 0x01, 0x00, 0x08, 0xDC, 0x0D, 0x03, 0x00,
0xE7, 0xCF, 0x4E, 0x0F, 0x0F, 0xCF, 0xE7, 0x43, 0x18, 0x3B, 0x17, 0x07, 0x00, 0x03, 0xFE, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x1B, 0x3B, 0x28, 0x66, 0x66, 0x36, 0x0D, 0x18, 0x1C, 0x1C,
0x00, 0x02, 0x02, 0x02, 0x02, 0x22, 0x00, 0x08, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
0x02, 0x22, 0x00, 0x08, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x22, 0x00, 0x08,
0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x22, 0x00, 0x08, 0x00, 0x02, 0x02, 0x02,
0x02, 0x02, 0x02, 0x02, 0x02, 0x22, 0x00, 0x08, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
0x02, 0x22, 0x00, 0x08, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x22, 0x00, 0x08,
0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x22, 0x00, 0x04, 0x0A, 0x09, 0x34, 0x3A, 0x1C,
0x1B, 0x0F, 0x0C, 0x62, 0x70, 0x37, 0x3F, 0x18, 0x04, 0x08, 0x2C, 0x58, 0x40, 0x20, 0x1F, 0x00
};
#endif

#ifdef LOGOARDUITAPE
 // 'Arduitape_128x32'
const byte logo [] PROGMEM = {

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80,
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF0, 0xF8, 0xF8, 0xF8, 0xF8,
0xF8, 0xF0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xF8,
0xF8, 0xF8, 0xF8, 0x18, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0xB8, 0xB8, 0xB8, 0x98, 0x00, 0x00, 0xFF, 0x01, 0x00, 0x00,
0x00, 0x80, 0x80, 0xC1, 0xE3, 0x64, 0x74, 0x34, 0x34, 0x34, 0x34, 0x34, 0x64, 0x64, 0xC4, 0xC4,
0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x80, 0xC0, 0xE0, 0x60, 0x70, 0x30,
0x30, 0x30, 0x30, 0x30, 0x64, 0x64, 0xC3, 0xC1, 0x80, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
0x00, 0x00, 0x00, 0xC0, 0xE0, 0xF0, 0x7C, 0x3E, 0x3F, 0x3F, 0x33, 0x31, 0x30, 0x31, 0x3F, 0x7F,
0xFF, 0xFF, 0xFF, 0xF8, 0xE0, 0x00, 0x00, 0xC0, 0xF0, 0xFF, 0xFF, 0xFF, 0x0F, 0x03, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x38, 0xFF, 0xFF, 0xE7, 0xC3, 0xC0, 0xC0, 0x40, 0xC0, 0xFC, 0xFF, 0xFF,
0x7F, 0x1F, 0x00, 0x00, 0x7C, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0xC0, 0x40, 0x40, 0xE0, 0xFC, 0xFF,
0x7F, 0x03, 0x00, 0xE0, 0xFC, 0xFF, 0xFF, 0xFF, 0x03, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00,
0x00, 0x1F, 0x3F, 0x70, 0x60, 0xE0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xE0, 0x60, 0x71, 0x3F,
0x1F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x3F, 0x70, 0x60, 0xE0, 0xC0, 0xC0,
0xC0, 0xC0, 0xC0, 0xC0, 0xE0, 0x60, 0x70, 0x3F, 0x1F, 0x0F, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x08, 0x08,
0x08, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x08, 0x08, 0x07, 0x00, 0x00

};
#endif
  
// Small 8x8 font
const unsigned char myFont[][8] PROGMEM = {
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x5F, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x07, 0x00, 0x07, 0x00, 0x00, 0x00},
  {0x00, 0x14, 0x7F, 0x14, 0x7F, 0x14, 0x00, 0x00}, {0x00, 0x24, 0x2A, 0x7F, 0x2A, 0x12, 0x00, 0x00}, {0x00, 0x23, 0x13, 0x08, 0x64, 0x62, 0x00, 0x00},
  {0x00, 0x36, 0x49, 0x55, 0x22, 0x50, 0x00, 0x00}, {0x00, 0x00, 0x05, 0x03, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x1C, 0x22, 0x41, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x41, 0x22, 0x1C, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x08, 0x2A, 0x1C, 0x2A, 0x08, 0x00, 0x00}, {0x00, 0x08, 0x08, 0x3E, 0x08, 0x08, 0x00, 0x00},
  {0x00, 0xA0, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00}, {0x00, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x20, 0x10, 0x08, 0x04, 0x02, 0x00, 0x00}, {0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E, 0x00, 0x00}, {0x00, 0x00, 0x42, 0x7F, 0x40, 0x00, 0x00, 0x00},
  {0x00, 0x62, 0x51, 0x49, 0x49, 0x46, 0x00, 0x00}, {0x00, 0x22, 0x41, 0x49, 0x49, 0x36, 0x00, 0x00}, {0x00, 0x18, 0x14, 0x12, 0x7F, 0x10, 0x00, 0x00},
  {0x00, 0x27, 0x45, 0x45, 0x45, 0x39, 0x00, 0x00}, {0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30, 0x00, 0x00}, {0x00, 0x01, 0x71, 0x09, 0x05, 0x03, 0x00, 0x00},
  {0x00, 0x36, 0x49, 0x49, 0x49, 0x36, 0x00, 0x00}, {0x00, 0x06, 0x49, 0x49, 0x29, 0x1E, 0x00, 0x00}, {0x00, 0x00, 0x36, 0x36, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0xAC, 0x6C, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x08, 0x14, 0x22, 0x41, 0x00, 0x00, 0x00}, {0x00, 0x14, 0x14, 0x14, 0x14, 0x14, 0x00, 0x00},
  {0x00, 0x41, 0x22, 0x14, 0x08, 0x00, 0x00, 0x00}, {0x00, 0x02, 0x01, 0x51, 0x09, 0x06, 0x00, 0x00}, {0x00, 0x32, 0x49, 0x79, 0x41, 0x3E, 0x00, 0x00},
  {0x00, 0x7E, 0x09, 0x09, 0x09, 0x7E, 0x00, 0x00}, {0x00, 0x7F, 0x49, 0x49, 0x49, 0x36, 0x00, 0x00}, {0x00, 0x3E, 0x41, 0x41, 0x41, 0x22, 0x00, 0x00},
  {0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C, 0x00, 0x00}, {0x00, 0x7F, 0x49, 0x49, 0x49, 0x41, 0x00, 0x00}, {0x00, 0x7F, 0x09, 0x09, 0x09, 0x01, 0x00, 0x00},
  {0x00, 0x3E, 0x41, 0x41, 0x51, 0x72, 0x00, 0x00}, {0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00, 0x00}, {0x00, 0x41, 0x7F, 0x41, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x20, 0x40, 0x41, 0x3F, 0x01, 0x00, 0x00}, {0x00, 0x7F, 0x08, 0x14, 0x22, 0x41, 0x00, 0x00}, {0x00, 0x7F, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00},
  {0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F, 0x00, 0x00}, {0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F, 0x00, 0x00}, {0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00, 0x00},
  {0x00, 0x7F, 0x09, 0x09, 0x09, 0x06, 0x00, 0x00}, {0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E, 0x00, 0x00}, {0x00, 0x7F, 0x09, 0x19, 0x29, 0x46, 0x00, 0x00},
  {0x00, 0x26, 0x49, 0x49, 0x49, 0x32, 0x00, 0x00}, {0x00, 0x01, 0x01, 0x7F, 0x01, 0x01, 0x00, 0x00}, {0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F, 0x00, 0x00},
  {0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F, 0x00, 0x00}, {0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F, 0x00, 0x00}, {0x00, 0x63, 0x14, 0x08, 0x14, 0x63, 0x00, 0x00},
  {0x00, 0x03, 0x04, 0x78, 0x04, 0x03, 0x00, 0x00}, {0x00, 0x61, 0x51, 0x49, 0x45, 0x43, 0x00, 0x00}, {0x00, 0x7F, 0x41, 0x41, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x02, 0x04, 0x08, 0x10, 0x20, 0x00, 0x00}, {0x00, 0x41, 0x41, 0x7F, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x04, 0x02, 0x01, 0x02, 0x04, 0x00, 0x00},
  {0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00}, {0x00, 0x01, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x20, 0x54, 0x54, 0x54, 0x78, 0x00, 0x00},
  {0x00, 0x7F, 0x48, 0x44, 0x44, 0x38, 0x00, 0x00}, {0x00, 0x38, 0x44, 0x44, 0x28, 0x00, 0x00, 0x00}, {0x00, 0x38, 0x44, 0x44, 0x48, 0x7F, 0x00, 0x00},
  {0x00, 0x38, 0x54, 0x54, 0x54, 0x18, 0x00, 0x00}, {0x00, 0x08, 0x7E, 0x09, 0x02, 0x00, 0x00, 0x00}, {0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C, 0x00, 0x00},
  {0x00, 0x7F, 0x08, 0x04, 0x04, 0x78, 0x00, 0x00}, {0x00, 0x00, 0x7D, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x80, 0x84, 0x7D, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x7F, 0x10, 0x28, 0x44, 0x00, 0x00, 0x00}, {0x00, 0x41, 0x7F, 0x40, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x7C, 0x04, 0x18, 0x04, 0x78, 0x00, 0x00},
  {0x00, 0x7C, 0x08, 0x04, 0x7C, 0x00, 0x00, 0x00}, {0x00, 0x38, 0x44, 0x44, 0x38, 0x00, 0x00, 0x00}, {0x00, 0xFC, 0x24, 0x24, 0x18, 0x00, 0x00, 0x00},
  {0x00, 0x18, 0x24, 0x24, 0xFC, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x7C, 0x08, 0x04, 0x00, 0x00, 0x00}, {0x00, 0x48, 0x54, 0x54, 0x24, 0x00, 0x00, 0x00},
  {0x00, 0x04, 0x7F, 0x44, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x3C, 0x40, 0x40, 0x7C, 0x00, 0x00, 0x00}, {0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C, 0x00, 0x00},
  {0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C, 0x00, 0x00}, {0x00, 0x44, 0x28, 0x10, 0x28, 0x44, 0x00, 0x00}, {0x00, 0x1C, 0xA0, 0xA0, 0x7C, 0x00, 0x00, 0x00},
  {0x00, 0x44, 0x64, 0x54, 0x4C, 0x44, 0x00, 0x00}, {0x00, 0x08, 0x36, 0x41, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x41, 0x36, 0x08, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x02, 0x01, 0x01, 0x02, 0x01, 0x00, 0x00}, {0x00, 0x02, 0x05, 0x05, 0x02, 0x00, 0x00, 0x00}
};
    //==========================================================//
    // Used to send commands to the display.
    static void sendcommand(unsigned char com)
    {
    Wire.beginTransmission(OLED_address); //begin transmitting
    Wire.write(0x80); //command mode
    Wire.write(com);
    Wire.endTransmission(); // stop transmitting
    }
    //==========================================================//
    // Actually this sends a byte, not a char to draw in the display.
    // Display's chars uses 8 byte font the small ones and 96 bytes
    // for the big number font.
    static void SendByte(unsigned char data)
    {
    Wire.beginTransmission(OLED_address); // begin transmitting
    Wire.write(0x40);//data mode
    Wire.write(data);
    Wire.endTransmission(); // stop transmitting
    }
    //==========================================================//
    // Prints a display char (not just a byte)
    // being multiples of 8. This means we have 16 COLS (0-15)
    // and 8 ROWS (0-7).
    static void sendChar(unsigned char data)
    {
    Wire.beginTransmission(OLED_address); // begin transmitting
    Wire.write(0x40);//data mode
    for(int i=0;i<8;i++)
    Wire.write(pgm_read_byte(myFont[data-0x20]+i));
    Wire.endTransmission(); // stop transmitting
    } 
    /*
    //==========================================================//
    // Prints a display char (not just a byte) in coordinates X Y,
    // being multiples of 8. This means we have 16 COLS (0-15)
    // and 8 ROWS (0-7).
    static void sendCharXY(unsigned char data, int X, int Y)
    {
    setXY(X, Y);
    Wire.beginTransmission(OLED_address); // begin transmitting
    Wire.write(0x40);//data mode
    for(int i=0;i<8;i++)
    Wire.write(pgm_read_byte(myFont[data-0x20]+i));
    Wire.endTransmission(); // stop transmitting
    }
    */
    //==========================================================//
    // Set the cursor position in a 16 COL * 2 ROW map.
    static void setXY(unsigned char col,unsigned char row)
    {
    sendcommand(0xb0+row); //set page address
    sendcommand(0x00+(8*col&0x0f)); //set low col address
    sendcommand(0x10+((8*col>>4)&0x0f)); //set high col address
    }
    //==========================================================//
    // Prints a string regardless the cursor position.
    static void sendStr(unsigned char *string)
    {
    unsigned char i=0;
    while(*string)
    {
    for(i=0;i<8;i++)
    {
    SendByte(pgm_read_byte(myFont[*string-0x20]+i));
    }
    *string++;
    }
    }
    //==========================================================//
    // Prints a string in coordinates X Y, being multiples of 8.
    // This means we have 16 COLS (0-15) and 8 ROWS (0-7).
    static void sendStrXY( char *string, int X, int Y)
    {
    #ifdef XY
    setXY(X,Y);
    unsigned char i=0;
    while(*string)
    {
    for(i=0;i<8;i++)
    {
    SendByte(pgm_read_byte(myFont[*string-0x20]+i));
    }
    *string++;
    }
    #endif
    
    #ifdef XY2
    while(*string)
    {
      setXY(X,Y);
    
      for(int i=0;i<8;i++)
        {
        unsigned int il=0;
        unsigned int ril=(pgm_read_byte(myFont[*string-0x20]+i));
        
        for(int ib=0;ib<4;ib++)
            {
            if (bitRead (ril,ib)) 
              {
                il |= (1 << ib*2);
                il |= (1 << (ib*2)+1);
              }
            }
            SendByte(il);
        }
    setXY (X,Y+1);
        for(int i=0;i<8;i++)
         {
         unsigned int ih=0;
         unsigned int rih=(pgm_read_byte(myFont[*string-0x20]+i));
        
         for(int ic=4;ic<8;ic++)
            {
            if (bitRead (rih,ic)) 
               {
                ih |= (1 << (ic-4)*2);
                ih |= (1 << ((ic-4)*2)+1);
                }   
            }
            SendByte(ih);
            }
    X++;    
   *string++;
    }
    #endif
    }
    //==========================================================//

// Resets display depending on the actual mode.
static void reset_display(void)
{
  displayOff();
  clear_display();

  
  displayOn();
}


//==========================================================//
// Turns display on.
void displayOn(void)
{
    sendcommand(0xaf);        //display on
}

//==========================================================//
// Turns display off.
void displayOff(void)
{
  sendcommand(0xae);    //display off
}

//==========================================================//
// Clears the display by sendind 0 to all the screen map.
static void clear_display(void)
{
  unsigned char i,k;
  for(k=0;k<4;k++)  //4
  { 
    setXY(0,k);    
    {
      for(i=0;i<128;i++)     //was 128
      {
        SendByte(0);         //clear all COL
        //delay(10);
      }
    }
  }
}
    
//==========================================================//
// Inits oled and draws logo at startup
static void init_OLED(void)
{
  /*
  sequence := { direct_value | escape_sequence }
  direct_value := 0..254
  escape_sequence := value_255 | sequence_end | delay | adr | cs | not_used 
  value_255 := 255 255
  sequence_end = 255 254
  delay := 255 0..127
  adr := 255 0x0e0 .. 0x0ef 
  cs := 255 0x0d0 .. 0x0df 
  not_used := 255 101..254
*/  
  //sendcommand(0xae);    //display off
  //sendcommand(0xa6);            //Set Normal Display (default) 
    // Adafruit Init sequence for 128x32 OLED module

/*    sendcommand(0xFF); // U8G_ESC_CS(0) disable chip
    sendcommand(0xd0 | ((0)&0x0f));
    sendcommand(0xFF); // 8G_ESC_ADR(0) instruction mode
    sendcommand(0xe0 | ((0)&0x0f));
    sendcommand(0xFF); // U8G_ESC_RST(1 do reset low pulse with (1*16)+2 milliseconds
    sendcommand(0xc0 | ((1)&0x0f));        
    sendcommand(0xFF); // U8G_ESC_CS(1) enable chip
    sendcommand(0xd0 | ((1)&0x0f)); */    
        
    sendcommand(0xAE);             //DISPLAYOFF
    sendcommand(0xD5);            //SETDISPLAYCLOCKDIV
    sendcommand(0x80);            // the suggested ratio 0x80
    sendcommand(0xA8);            //SSD1306_SETMULTIPLEX
    sendcommand(0x1f); //--1/48 duty, NEW!!! Feb 23, 2013: 128x32 OLED: 0x01f,  128x32 OLED 0x03f
    sendcommand(0xD3);            //SETDISPLAYOFFSET
    sendcommand(0x0);             //no offset
    sendcommand(0x40 | 0x0);      //SETSTARTLINE
    sendcommand(0x8D);            //CHARGEPUMP
    sendcommand(0x14);
    sendcommand(0x20);             //MEMORYMODE
    sendcommand(0x02);             //com pin HW config, sequential com pin config (bit 4), disable left/right remap (bit 5), Feb 23, 2013: 128x32 OLED: 0x002,  128x32 OLED 0x012

#ifdef ROTATE180    
    sendcommand(0xA0 | 0x1);      //SEGREMAP   //Rotate screen 180 deg 0xA1
    //sendcommand(0xA0);
    
    sendcommand(0xC8);            //COMSCANDEC  Rotate screen 180 Deg /* c0: scan dir normal, c8: reverse */
    //sendcommand(0xC0);
#endif

#ifdef UNROTATE    
    //sendcommand(0xA0 | 0x1);      //SEGREMAP   //Rotate screen 180 deg 0xA1
    sendcommand(0xA0);
    
    //sendcommand(0xC8);            //COMSCANDEC  Rotate screen 180 Deg /* c0: scan dir normal, c8: reverse */
    sendcommand(0xC0);
#endif
    
    sendcommand(0xDA);            //0xDA
    sendcommand(0x02);           //COMSCANDEC /* com pin HW config, sequential com pin config (bit 4), disable left/right remap (bit 5) */
    sendcommand(0x81);           //SETCONTRAS
    sendcommand(0xcf);           //
    sendcommand(0xD9);          //SETPRECHARGE /* [2] pre-charge period 0x022/f1*/
    sendcommand(0xf1); 
    sendcommand(0xDB);        //SETVCOMDETECT                
    sendcommand(0x40);
    sendcommand(0x2E);            // stop scroll
    sendcommand(0xA4);        //DISPLAYALLON_RESUME        
    sendcommand(0xA6);        //NORMALDISPLAY             
    sendcommand(0xAF);    //display on

/*    sendcommand(0xFF); // U8G_ESC_CS(0) disable chip
    sendcommand(0xd0 | ((0)&0x0f));
    sendcommand(0xFF); // U8G_ESC_END end of sequence
    sendcommand(0xfe); */

  //----------------------------REVERSE comments----------------------------//
  //  sendcommand(0xa0);    //seg re-map 0->127(default)
  //  sendcommand(0xa1);    //seg re-map 127->0
  //  sendcommand(0xc8);
  //  delay(1000);
  //----------------------------REVERSE comments----------------------------//
  // sendcommand(0xa7);  //Set Inverse Display  
  // sendcommand(0xae);   //display off
  //sendcommand(0x20);            //Set Memory Addressing Mode
  //sendcommand(0x00);            //Set Memory Addressing Mode ab Horizontal addressing mode
    //sendcommand(0x02);         // Set Memory Addressing Mode ab Page addressing mode(RESET)  
  
  clear_display();
  for(int j=0;j<4;j++)
  {
    setXY(0,j);
    for(int i=0;i<128;i++)     // show 128* 32 Logo
    {
      SendByte(pgm_read_byte(logo+j*128+i));
    }  
  }
}

#endif

//==========================================================//

#ifdef P8544


const unsigned char logo1 [] PROGMEM = {

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0xC0, 0x60, 0x20, 0x20, 0x60, 0xE0,
0xE0, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0xE0, 0x60, 0x20, 0x20, 0x60, 0xC0, 0x00, 0x00,
0x00, 0x80, 0xC0, 0xF0, 0x7C, 0x3E, 0xFE, 0xFE, 0xFE, 0xE0,
0x00, 0x00, 0x00, 0x80, 0xE0, 0xE0, 0xE0, 0x60, 0x60, 0x60,
0x20, 0x00, 0xC0, 0xE0, 0x60, 0x60, 0x60, 0x60, 0xFC, 0xFE,
0xFE, 0x0E, 0x80, 0xE0, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0xE0,
0xE0, 0x60, 0x00, 0xE4, 0xEE, 0xFE, 0x26, 0x00, 0xFF, 0x00,
0x00, 0xC0, 0xF0, 0x78, 0x19, 0x1B, 0x0F, 0x0B, 0x1B, 0x1B,
0x73, 0xE3, 0xC3, 0x03, 0x03, 0x03, 0x03, 0xC3, 0xE3, 0x73,
0x3B, 0x1B, 0x1F, 0x0F, 0x1A, 0x1B, 0x79, 0xF0, 0xC0, 0x00,
0x00, 0xFF 
};

const unsigned char logo2 [] PROGMEM = {
   
 0x20, 0x38, 0x3E, 0x1F, 0x0F, 0x0F, 0x0C, 0x0C, 0x0F, 0x3F,
 0x3F, 0x3F, 0x3C, 0x00, 0x00, 0x3F, 0x3F, 0x3F, 0x03, 0x00,
 0x00, 0x00, 0x00, 0x1F, 0x3F, 0x3F, 0x30, 0x30, 0x30, 0x3F,
 0x3F, 0x3F, 0x03, 0x00, 0x1F, 0x3F, 0x3F, 0x31, 0x30, 0x30,
 0x3C, 0x3F, 0x1F, 0x00, 0x3C, 0x3F, 0x3F, 0x0F, 0x00, 0x00,
 0xFF, 0x00, 0x00, 0x07, 0x0F, 0x1C, 0x38, 0x30, 0x30, 0x30,
 0x30, 0x38, 0x1C, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03,
 0x0F, 0x1C, 0x38, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1C, 0x0F,
 0x07, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x06, 0x06, 0x06, 0x06,
 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x02, 0x01, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00
};

 
#endif

#ifdef P8544
 static void P8544_splash (void)
{
  lcd.gotoRc(0, 0);
  lcd.bitmap(logo1, 3,84);
  lcd.gotoRc(3, 0);
  lcd.bitmap(logo2, 3,84);
  delay(2000);
  lcd.clear();
  
}
#endif
