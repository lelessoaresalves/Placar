
#include <Adafruit_GFX.h>
#include "FreeSerif9pt7b.h"
#include "splash.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

#include <MD_MAX72xx.h>

#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES 2
#define CLK_PIN   52  // or SCK
#define DATA_PIN  51  // or MOSI
#define CS_PIN   53   // or SS

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);   

void drawArray(const byte *person, char matriz);





#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


// 'placar2', 40x45px
const unsigned char placar2 [] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 
	0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 
	0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 
	0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 
	0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 
	0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 
	0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 
	0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 
	0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 
	0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 
	0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 
	0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 
	0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 0x80, 0x00, 0x18, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 
	0xff
};

// 'back_volei', 128x20px
const unsigned char back_volei_select [] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x80, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 
	0x80, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xff, 
	0x80, 0x00, 0x18, 0x00, 0x00, 0x38, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0xff, 
	0x80, 0x00, 0x18, 0x00, 0x03, 0xe0, 0x00, 0x01, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x3f, 0xff, 0xff, 
	0x80, 0x00, 0x18, 0x00, 0x3f, 0x00, 0x00, 0x01, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x1f, 0xff, 0xff, 
	0x80, 0x00, 0x18, 0x01, 0xf8, 0x00, 0x00, 0x01, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x3f, 0xff, 0xff, 
	0x80, 0x00, 0x18, 0x1f, 0xc0, 0x00, 0x00, 0x01, 0xff, 0xff, 0xe3, 0xff, 0xfc, 0x7f, 0xff, 0xff, 
	0x80, 0x00, 0x19, 0xfe, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xe3, 0xff, 0xfc, 0xff, 0xff, 0xff, 
	0x80, 0x00, 0x1f, 0xf0, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xe3, 0xff, 0xfd, 0xff, 0xff, 0xff, 
	0x80, 0x00, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xe0, 0x00, 0x1f, 0xff, 0xff, 0xff, 
	0x80, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xe0, 0x00, 0x1f, 0xff, 0xff, 0xff, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xe0, 0x00, 0x1f, 0xff, 0xff, 0xff, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
// 'marcar_volei', 128x20px
const unsigned char marcar_volei_select [] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0xff, 0xff, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x01, 
	0xff, 0xff, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x01, 
	0xff, 0xff, 0xe7, 0xff, 0xff, 0xc7, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x01, 
	0xff, 0xff, 0xe7, 0xff, 0xfc, 0x1f, 0xff, 0xff, 0x80, 0x00, 0x1f, 0xff, 0xff, 0xc0, 0x00, 0x01, 
	0xff, 0xff, 0xe7, 0xff, 0xc0, 0xff, 0xff, 0xff, 0x80, 0x00, 0x1f, 0xff, 0xff, 0xe0, 0x00, 0x01, 
	0xff, 0xff, 0xe7, 0xfe, 0x07, 0xff, 0xff, 0xff, 0x80, 0x00, 0x1f, 0xff, 0xff, 0xc0, 0x00, 0x01, 
	0xff, 0xff, 0xe7, 0xe0, 0x3f, 0xff, 0xff, 0xff, 0x80, 0x00, 0x1c, 0x00, 0x03, 0x80, 0x00, 0x01, 
	0xff, 0xff, 0xe6, 0x01, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x1c, 0x00, 0x03, 0x00, 0x00, 0x01, 
	0xff, 0xff, 0xe0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x1c, 0x00, 0x02, 0x00, 0x00, 0x01, 
	0xff, 0xff, 0xe0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x1f, 0xff, 0xe0, 0x00, 0x00, 0x01, 
	0xff, 0xff, 0xe1, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x1f, 0xff, 0xe0, 0x00, 0x00, 0x01, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x1f, 0xff, 0xe0, 0x00, 0x00, 0x01, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};


// 'placar2', 128x20px
const unsigned char epd_bitmap_yes_no [] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

// 'back selectCopia', 26x14px
const unsigned char epd_bitmap_back [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0xc0, 0x00, 
	0x00, 0x01, 0xf0, 0x00, 0x07, 0xff, 0xf8, 0x00, 0x04, 0x01, 0xf0, 0x00, 0x04, 0x01, 0xc0, 0x00, 
	0x04, 0x01, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'placar2', 128x20px
const unsigned char epd_bitmap_nav [] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x01, 
	0x80, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x01, 
	0x8c, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x01, 
	0x8c, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x81, 
	0x8c, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xc1, 
	0x8c, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xe1, 
	0x8c, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x18, 0x00, 0x0f, 0xc1, 
	0x8c, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x18, 0x00, 0x0f, 0x81, 
	0x8c, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x18, 0x00, 0x0f, 0x01, 
	0x8c, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x18, 0x00, 0x0c, 0x01, 
	0x8c, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x18, 0x00, 0x08, 0x01, 
	0x8f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x01, 
	0x8f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x01, 
	0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x1f, 0xff, 0x80, 0x01, 
	0x8e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x1f, 0xff, 0x80, 0x01, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
// 'placar2', 128x64px
const unsigned char epd_bitmap_placar [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x01, 
	0x80, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x01, 
	0x8c, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x01, 
	0x8c, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x81, 
	0x8c, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xc1, 
	0x8c, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xe1, 
	0x8c, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x18, 0x00, 0x0f, 0xc1, 
	0x8c, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x18, 0x00, 0x0f, 0x81, 
	0x8c, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x18, 0x00, 0x0f, 0x01, 
	0x8c, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x18, 0x00, 0x0c, 0x01, 
	0x8c, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x18, 0x00, 0x08, 0x01, 
	0x8f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x01, 
	0x8f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x01, 
	0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x1f, 0xff, 0x80, 0x01, 
	0x8e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x1f, 0xff, 0x80, 0x01, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
// 'backCopia', 26x14px
const unsigned char epd_bitmap_ok [] PROGMEM = {
	0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0xf0, 0x00, 
	0x00, 0x01, 0xe0, 0x00, 0x70, 0x07, 0x80, 0x00, 0x78, 0x0f, 0x00, 0x00, 0x78, 0x1f, 0x00, 0x00, 
	0x78, 0x7c, 0x00, 0x00, 0x3c, 0xfc, 0x00, 0x00, 0x3d, 0xf8, 0x00, 0x00, 0x3f, 0xf0, 0x00, 0x00, 
	0x1f, 0xe0, 0x00, 0x00, 0x1f, 0x80, 0x00, 0x00
};

// 'seletor', 12x12px
const unsigned char epd_bitmap_seletor [] PROGMEM = {
	0x1f, 0x80, 0x3f, 0xc0, 0x7f, 0xe0, 0xff, 0xf0, 0xef, 0x70, 0xff, 0xf0, 0xff, 0xf0, 0xef, 0x70, 
	0xe6, 0x70, 0x70, 0xe0, 0x3f, 0xc0, 0x1f, 0x80
};

// 'X', 12x12px
const unsigned char epd_bitmap_X [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x20, 0x40, 0x10, 0x80, 0x09, 0x00, 0x06, 0x00, 0x06, 0x00, 0x09, 0x00, 
	0x10, 0x80, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00
};



// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 1536)
const int epd_bitmap_allArray_LEN = 6;
const unsigned char* epd_bitmap_allArray[6] = {
	epd_bitmap_back,
	epd_bitmap_ok,
	epd_bitmap_placar,
	epd_bitmap_nav,
  epd_bitmap_seletor,
  epd_bitmap_X
};



// 'hora', 53x40px
const unsigned char epd_bitmap_hora [] PROGMEM = {
	0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x0c, 0x30, 
	0x00, 0x1f, 0xff, 0x80, 0x00, 0x18, 0x18, 0x00, 0x7f, 0xff, 0xe0, 0x00, 0x18, 0x18, 0x01, 0xfe, 
	0x07, 0xf0, 0x00, 0x18, 0x18, 0x03, 0xf0, 0x00, 0xfc, 0x00, 0x18, 0x18, 0x07, 0xc0, 0x60, 0x3e, 
	0x00, 0x18, 0x18, 0x0f, 0x00, 0x60, 0x0f, 0x00, 0x18, 0x18, 0x1e, 0x30, 0x01, 0x87, 0x80, 0x1b, 
	0xd8, 0x3c, 0x30, 0x01, 0x83, 0xc0, 0x1b, 0xd8, 0x78, 0x00, 0x00, 0x01, 0xc0, 0x1b, 0xd8, 0x70, 
	0x00, 0x40, 0x01, 0xe0, 0x1b, 0xd8, 0xf0, 0x00, 0x40, 0x00, 0xe0, 0x1b, 0xd8, 0xe6, 0x00, 0x60, 
	0x0c, 0xf0, 0x1b, 0xd8, 0xe2, 0x00, 0x60, 0x0c, 0x70, 0x1b, 0xd9, 0xc0, 0x00, 0x60, 0x00, 0x70, 
	0x1b, 0xd9, 0xc0, 0x00, 0x60, 0x00, 0x38, 0x1b, 0xd9, 0xc0, 0x00, 0x60, 0x00, 0x38, 0x1b, 0xd9, 
	0xc0, 0x00, 0x60, 0x00, 0x38, 0x1b, 0xd9, 0xc8, 0x00, 0x60, 0x03, 0x38, 0x1b, 0xd9, 0xcc, 0x00, 
	0xe0, 0x03, 0x38, 0x1b, 0xd9, 0xc0, 0x01, 0xff, 0xc0, 0x38, 0x1b, 0xd9, 0xc0, 0x01, 0xf8, 0x00, 
	0x38, 0x1b, 0xd9, 0xc0, 0x00, 0xe0, 0x00, 0x38, 0x1b, 0xd9, 0xc0, 0x00, 0x40, 0x00, 0x78, 0x1b, 
	0xd9, 0xc0, 0x00, 0x00, 0x00, 0x70, 0x13, 0xd8, 0xe6, 0x00, 0x00, 0x0c, 0x70, 0x33, 0xcc, 0xe2, 
	0x00, 0x00, 0x0c, 0xf0, 0x67, 0xe6, 0x70, 0x00, 0x00, 0x00, 0xe0, 0xcf, 0xf2, 0x78, 0x00, 0x00, 
	0x01, 0xe0, 0xdf, 0xfb, 0x38, 0x00, 0x00, 0x03, 0xc0, 0xdf, 0xfb, 0x3c, 0x30, 0x01, 0x87, 0x80, 
	0xdf, 0xfb, 0x1e, 0x10, 0x40, 0x8f, 0x80, 0xdf, 0xfb, 0x0f, 0x80, 0x60, 0x1f, 0x00, 0xcf, 0xf3, 
	0x07, 0xc0, 0x00, 0x3e, 0x00, 0x6f, 0xf6, 0x03, 0xf0, 0x01, 0xf8, 0x00, 0x63, 0xc6, 0x00, 0xff, 
	0xff, 0xf0, 0x00, 0x38, 0x1c, 0x00, 0x7f, 0xff, 0xc0, 0x00, 0x1f, 0xf8, 0x00, 0x0f, 0xff, 0x00, 
	0x00, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00
};



// 'ampulheta', 40x40px
const unsigned char epd_bitmap_ampulheta [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x01, 
	0xff, 0xff, 0xff, 0x80, 0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 0x60, 0x00, 0x06, 0x00, 0x00, 0x20, 
	0x00, 0x04, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x00, 0x20, 0x00, 
	0x04, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x00, 0x30, 0x00, 0x04, 0x00, 0x00, 0x33, 0xff, 0xec, 
	0x00, 0x00, 0x1b, 0xff, 0xd8, 0x00, 0x00, 0x09, 0xff, 0x90, 0x00, 0x00, 0x06, 0xff, 0x60, 0x00, 
	0x00, 0x03, 0x7e, 0xc0, 0x00, 0x00, 0x01, 0xbd, 0x80, 0x00, 0x00, 0x00, 0xdb, 0x00, 0x00, 0x00, 
	0x00, 0x5a, 0x00, 0x00, 0x00, 0x00, 0x42, 0x00, 0x00, 0x00, 0x00, 0xcb, 0x00, 0x00, 0x00, 0x01, 
	0x81, 0x80, 0x00, 0x00, 0x03, 0x00, 0xc0, 0x00, 0x00, 0x06, 0x00, 0x60, 0x00, 0x00, 0x0c, 0x18, 
	0x30, 0x00, 0x00, 0x18, 0xff, 0x18, 0x00, 0x00, 0x11, 0xff, 0x88, 0x00, 0x00, 0x33, 0xff, 0xcc, 
	0x00, 0x00, 0x27, 0xff, 0xe4, 0x00, 0x00, 0x27, 0xff, 0xe4, 0x00, 0x00, 0x27, 0xff, 0xe4, 0x00, 
	0x00, 0x2f, 0xff, 0xe4, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x01, 
	0xff, 0xff, 0xff, 0x80, 0x01, 0xff, 0xff, 0xff, 0x80, 0x01, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


// 'volei', 40x40px
const unsigned char epd_bitmap_volei [] PROGMEM = {
	0x00, 0x07, 0xff, 0xe0, 0x00, 0x00, 0x3f, 0xff, 0xf8, 0x00, 0x00, 0x7f, 0xff, 0xfe, 0x00, 0x01, 
	0xfe, 0x1e, 0x7f, 0x00, 0x03, 0xf0, 0x1e, 0x1f, 0xc0, 0x07, 0xe0, 0x0e, 0x07, 0xe0, 0x0f, 0x80, 
	0x0e, 0x07, 0xe0, 0x1f, 0x00, 0x0f, 0x03, 0xf0, 0x1e, 0x00, 0x0f, 0x03, 0xf8, 0x3c, 0x00, 0x3f, 
	0x03, 0x7c, 0x3c, 0x07, 0xff, 0x03, 0x3c, 0x78, 0x1f, 0xff, 0x03, 0x1e, 0x78, 0xfc, 0x0f, 0x03, 
	0x1e, 0xf3, 0xf0, 0x0f, 0x03, 0x0e, 0xff, 0x80, 0x0e, 0x07, 0x0f, 0xfe, 0x00, 0x0e, 0x07, 0x0f, 
	0xfc, 0x00, 0x1e, 0x06, 0x0f, 0xf0, 0x00, 0x1e, 0x06, 0x07, 0xe0, 0x01, 0xfc, 0x06, 0x07, 0xe0, 
	0x07, 0xfc, 0x0e, 0x07, 0xe0, 0x1f, 0xfe, 0x0e, 0x07, 0xe0, 0x7f, 0xdf, 0x0c, 0x07, 0xe1, 0xfe, 
	0x0f, 0x9c, 0x0f, 0xf3, 0xf8, 0x07, 0xf8, 0x0f, 0xf7, 0xf8, 0x03, 0xf8, 0x0f, 0xff, 0x9c, 0x01, 
	0xfc, 0x0e, 0x7f, 0x0e, 0x00, 0xff, 0x9e, 0x7e, 0x07, 0x00, 0x3f, 0xfe, 0x7c, 0x03, 0x80, 0x0f, 
	0xfc, 0x3c, 0x01, 0xc0, 0x03, 0xfc, 0x1e, 0x00, 0xf0, 0x00, 0xf8, 0x1f, 0x00, 0x78, 0x00, 0xf0, 
	0x0f, 0x80, 0x1e, 0x01, 0xe0, 0x07, 0xc0, 0x0f, 0x87, 0xe0, 0x03, 0xf0, 0x03, 0xff, 0xc0, 0x01, 
	0xfe, 0x01, 0xff, 0x00, 0x00, 0x7f, 0xff, 0xfe, 0x00, 0x00, 0x3f, 0xff, 0xf8, 0x00, 0x00, 0x07, 
	0xff, 0xe0, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00
};




//CRONOMETRO =================================================================================

// 'play', 8x14px
const unsigned char epd_bitmap_play [] PROGMEM = {
	0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0
};
// 'pause', 8x14px
const unsigned char epd_bitmap_pause [] PROGMEM = {
	0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7
};
// 'zerar', 11x14px
const unsigned char epd_bitmap_zerar [] PROGMEM = {
	0x0e, 0x00, 0x11, 0x00, 0xff, 0xe0, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x55, 0x40, 0x55, 0x40, 
	0x55, 0x40, 0x55, 0x40, 0x55, 0x40, 0x55, 0x40, 0x40, 0x40, 0x3f, 0x80
};


// 'back', 24x15px
const unsigned char epd_bitmap_back2 [] PROGMEM = {
	0x00, 0x00, 0x40, 0x00, 0x00, 0x60, 0x00, 0x00, 0x78, 0x00, 0x00, 0x7c, 0xff, 0xff, 0xfe, 0xff, 
	0xff, 0xff, 0xc0, 0x00, 0x7e, 0xc0, 0x00, 0x7c, 0xc0, 0x00, 0x78, 0xc0, 0x00, 0x60, 0xc0, 0x00, 
	0x40, 0xc0, 0x00, 0x00, 0xc0, 0x00, 0x00, 0xff, 0xfc, 0x00, 0xff, 0xfc, 0x00
};


// 'seletor_cronometro', 128x20px
const unsigned char epd_bitmap_seletor_cronometro [] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};





#define AD0 2
#define BD0 3
#define CD0 4
#define DD0 5
#define ED0 6
#define FD0 7
#define GD0 8

#define AD1 22
#define BD1 24
#define CD1 26
#define DD1 28
#define ED1 30
#define FD1 32
#define GD1 34

#define AD2 A8
#define BD2 A9
#define CD2 A10
#define DD2 A11
#define ED2 A12
#define FD2 A13
#define GD2 A14

#define AD3 A0
#define BD3 A1
#define CD3 A2
#define DD3 A3
#define ED3 A4
#define FD3 A5
#define GD3 A6

byte arrayD0[7] = {AD0, BD0, CD0, DD0, ED0, FD0, GD0};
byte arrayD1[7] = {AD1, BD1, CD1, DD1, ED1, FD1, GD1};
byte arrayD2[7] = {AD2, BD2, CD2, DD2, ED2, FD2, GD2};
byte arrayD3[7] = {AD3, BD3, CD3, DD3, ED3, FD3, GD3};
#define QUANT_OUTPUTS 28
byte allOutputs[QUANT_OUTPUTS] = {AD0,BD0,CD0,DD0,ED0,FD0,GD0,AD1,BD1,CD1,DD1,ED1,FD1,GD1,AD2,BD2,CD2,DD2,ED2,FD2,GD2,AD3,BD3,CD3,DD3,ED3,FD3,GD3};

byte arrayCirculoCompleto[12] = {AD0, AD1, AD2, AD3, BD3, CD3, DD3, DD2, DD1, DD0, ED0, FD0};
byte arrayCirculoA[8] = {AD0, AD1, BD1, CD1, DD1, DD0, ED0, FD0};
byte arrayCirculoB[8] = {AD2, AD3, BD3, CD3, DD3, DD2, ED2, FD2};

byte arrayLinhaSuperior[8] = {AD0, AD1, AD2, AD3};
byte arrayLinhaCentral[8] = {GD0, GD1, GD2, GD3};
byte arrayLinhaInferior[8] = {DD0, DD1, DD2, DD3};

#define JOY_X  A15
#define JOY_Y  A7
#define JOY_SW 44


 enum Effects {CRICULO = 1, LINHA};


#define BTN_MAIS_A  9
#define BTN_MENOS_A 10

#define BTN_MAIS_B  41
#define BTN_MENOS_B 43

//19CXY8K E4
//UNL2003AN (NOVO)

//CHINA H730CR
//UNL2003APG (VELHO)
#define MIN_LEDS   0
#define MAX_LEDS   6
#define MIN_DIGIT  7
#define MAX_DIGIT 10
#define MIN_B_A   11
#define MAX_B_A   12


#define QUANT_CARACTERES 20
int digits[QUANT_CARACTERES][7] = 
                    { 
                    // a,b,c,d,e,f,g
                      {1,1,1,1,1,1,0},//0              =  0
                      {0,1,1,0,0,0,0},//1              =  1
                      {1,1,0,1,1,0,1},//2              =  2
                      {1,1,1,1,0,0,1},//3              =  3
                      {0,1,1,0,0,1,1},//4              =  4
                      {1,0,1,1,0,1,1},//5              =  5
                      {1,0,1,1,1,1,1},//6              =  6
                      {1,1,1,0,0,0,0},//7              =  7
                      {1,1,1,1,1,1,1},//8              =  8
                      {1,1,1,1,0,1,1},//9              =  9
                      {0,0,0,0,0,0,0},//dispay apagado = 10
                      {0,1,1,0,1,1,1},//H              = 11
                      {1,1,0,0,0,1,1},//graus          = 12
                      {1,1,1,0,1,1,0},//m1             = 13
                      {0,0,1,0,1,0,1},//m2             = 14
                      {1,0,0,1,1,1,0},//C              = 15
                      {0,0,0,0,1,0,1},//r              = 16
                      {0,0,1,1,1,0,1},//o              = 17
                      {1,1,1,0,1,1,1},//A              = 18
                      {0,0,1,1,1,1,1} //b              = 19
                    };


const byte digitsMatriz[16][8] = {


  ///*CORRETO
  {B00000000, B00111110, B01000001, B01000001, B01000001, B00111110, B00000000, 0}, // 0 
  {B00000000, B00000000, B01000010, B01111111, B01000000, B00000000, B00000000, 0}, // 1 
  {B00000000, B01100010, B01010001, B01001001, B01001001, B01000110, B00000000, 0}, // 2
  {B00000000, B00000000, B01001001, B01001001, B01001001, B00110110, B00000000, 0}, // 3
  {B00010000, B00011000, B00010100, B00010010, B01111111, B00010000, B00000000, 0}, // 4
  {B00000000, B00101111, B01001001, B01001001, B01001001, B00110001, B00000000, 0}, // 5
  {B00111110, B01001001, B01001001, B01001001, B01001001, B00110010, B00000000, 0}, // 6
  {B01000001, B00100001, B00010001, B00001001, B00000101, B00000011, B00000000, 0}, // 7
  {B00110110, B01001001, B01001001, B01001001, B01001001, B00110110, B00000000, 0}, // 8
  {B00001110, B01010001, B01010001, B01010001, B01010001, B00111110, B00000000, 0}, // 9
  {B01001110, B10010001, B10010001, B10010001, B10010001, B01100010, B00000000, 0}, //S
  {B01111100, B10010010, B10010010, B10010010, B01001100, B00000000, B00000000, 0}, //e
  {B11111111, B00000010, B00000100, B00001000, B00000100, B00000010, B11111111, 0}, //M
  {B00000000, B00000000, B10001000, B11111010, B10000000, B00000000, B00000000, 0}, //i
  {B11111111, B00010000, B00010000, B00010000, B00010000, B11111111, B00000000, 0}, //H
  {B01111100, B10000010, B10000010, B10000010, B10000010, B01111100, B00000000, 0}  //o

  /*PONTA CABEÇA
  {B00000000, B01111100, B10000010, B10000010, B10000010, B01111100, B00000000, 0}, // 0 
  {B00000000, B00000000, B00000010, B11111110, B01000010, B00000000, B00000000, 0}, // 1 
  {B00000000, B01100010, B10010010, B10010010, B10001010, B01000110, B00000000, 0}, // 2
  {B00000000, B01101100, B10010010, B10010010, B10010010, B01000100, B00000000, 0}, // 3
  {B00000000, B00001000, B11111110, B01001000, B00101000, B00011000, B00001000, 0}, // 4
  {B00000000, B10001100, B10010010, B10010010, B10010010, B11110100, B00000000, 0}, // 5
  {B00000000, B01001100, B10010010, B10010010, B10010010, B10010010, B01111100, 0}, // 6
  {B00000000, B11000000, B10100000, B10010000, B10001000, B10000100, B10000010, 0}, // 7
  {B00000000, B01101100, B10010010, B10010010, B10010010, B10010010, B01101100, 0}, // 8
  {B00000000, B01111100, B10001010, B10001010, B10001010, B10001010, B01110000, 0} // 9
  //*/

  /*VERTICAL
  {B00111100, B01000010, B01000010, B01000010, B01000010, B01000010, B00111100, 1}, // 0
  {B00010000, B00110000, B00010000, B00010000, B00010000, B00010000, B00111000, 1}, // 1
  {B00111100, B01000010, B00000010, B00001100, B00010000, B00100000, B01111110, 1}, // 2
  {B00111100, B01000010, B00000010, B00011100, B00000010, B01000010, B00111100, 0}, // 3
  {B00000100, B00001100, B00010100, B00100100, B01111110, B00000100, B00000100, 0}, // 4
  {B01111110, B01000000, B01000000, B01111100, B00000010, B01000010, B00111100, 0}, // 5
  {B00111100, B01000010, B01000000, B01111100, B01000010, B01000010, B00111100, 0}, // 6
  {B01111110, B00000010, B00000100, B00001000, B00010000, B00100000, B01000000, 0}, // 7
  {B00111100, B01000010, B01000010, B00111100, B01000010, B01000010, B00111100, 0}, // 8
  {B00111100, B01000010, B01000010, B01000010, B00111110, B00000010, B00111100, 0}  // 9
  //*/
};


const byte feliz[8]  = {B00111100, B01000010, B10010101, B10100001, B10100001, B10010101, B01000010, B00111100}; 
const byte normal[8] = {B00111100, B01000010, B10100101, B10100001, B10100001, B10100101, B01000010, B00111100}; 
const byte triste[8] = {B00111100, B01000010, B10100101, B10010001, B10010001, B10100101, B01000010, B00111100}; 

const byte espada[8] = {B00000000, B00010000, B00111000, B00010000, B00010000, B00010000, B00000000, B00000000}; 

const byte olhoC[8]  = {B01111110, B11111111, B11111111, B11100111, B11100111, B11111111, B11111111, B01111110};
const byte olhoEC[8] = {B01111110, B11100111, B11100111, B11111111, B11111111, B11111111, B11111111, B01111110};
const byte olhoDC[8] = {B01111110, B11111111, B11111111, B11111111, B11111111, B11100111, B11100111, B01111110};
const byte olhoIC[8] = {B01111110, B11111111, B11111111, B10011111, B10011111, B11111111, B11111111, B01111110};
const byte olhoIE[8] = {B01111110, B10011111, B10011111, B11111111, B11111111, B11111111, B11111111, B01111110};
const byte olhoID[8] = {B01111110, B11111111, B11111111, B11111111, B11111111, B10011111, B10011111, B01111110};
const byte olhoSE[8] = {B01111110, B11111001, B11111001, B11111111, B11111111, B11111111, B11111111, B01111110}; 
const byte olhoSD[8] = {B01111110, B11111111, B11111111, B11111111, B11111111, B11111001, B11111001, B01111110}; 
const byte olhoSC[8] = {B01111110, B11111111, B11111111, B11111001, B11111001, B11111111, B11111111, B01111110};

const byte olhoTC[8]  = {B01111100, B11111100, B11111100, B11100100, B11100100, B11111100, B11111100, B01111100};
const byte olhoTEC[8] = {B01111100, B11100100, B11100100, B11111100, B11111100, B11111100, B11111100, B01111100};
const byte olhoTDC[8] = {B01111100, B11111100, B11111100, B11111100, B11111100, B11100100, B11100100, B01111100};
const byte olhoTIC[8] = {B01111100, B11111100, B11111100, B10011100, B10011100, B11111100, B11111100, B01111100};
const byte olhoTIE[8] = {B01111100, B10011100, B10011100, B11111100, B11111100, B11111100, B11111100, B01111100};
const byte olhoTID[8] = {B01111100, B11111100, B11111100, B11111100, B11111100, B10011100, B10011100, B01111100};
const byte olhoTSE[8] = {B01111100, B11111000, B11111000, B11111100, B11111100, B11111100, B11111100, B01111100}; 
const byte olhoTSD[8] = {B01111100, B11111100, B11111100, B11111100, B11111100, B11111000, B11111000, B01111100}; 
const byte olhoTSC[8] = {B01111100, B11111100, B11111100, B11111000, B11111000, B11111100, B11111100, B01111100};

const byte preto[8] = {0,0,0,0,0,0,0,0};



//************************************
unsigned long timerCur = 0;
unsigned long atualizaTempo();
//************************************

//************************************
int G_lastNum = 0;
int G_lastDigits[4] = {0,0,0,0}; // M, C, D, U
#define INTER_DIGITS 1
unsigned long timer_digits = 0;
bool enableTimerDigits1 = true;
bool enableTimerDigits2 = true;
byte countTimerDigits = 0;
  bool fourDigits(int num);
//************************************
void controllerDigits(int digit);
void turnOffAll();
//************************************
unsigned long timerLast1         = 0;
unsigned long timerLast2         = 0;


int contaPontosALast = 0;
int contaPontosBLast = 0;
bool estadoBmais = false;
bool estadoBmenos = false;
#define INTERVALO_BTN 100
  
//************************************


enum MaqMenuTelas {
    MAQ_MENU_PRINCIPAL,         
    MAQ_VOLEI,
    MAQ_CONFIRMACAO_VOLEI_MARCAR,
    MAQ_CONFIRMACAO_VOLEI_SAIR,
    MAQ_CRONOMETRO,
    MAQ_CONFIRMACAO_CRONOMETRO_SAIR
};
MaqMenuTelas maqMenu = MAQ_MENU_PRINCIPAL;



enum TipoTeclado {
  TIPO_TECLADO_NENHUM,
  TIPO_TECLADO_TODOS,
  TIPO_TECLADO_APENAS_AB,
  TIPO_TECLADO_APENAS_A,
  TIPO_TECLADO_APENAS_B,
  TIPO_TECLADO_APENAS_XYSW,
  TIPO_TECLADO_APENAS_XSW,
  TIPO_TECLADO_APENAS_YSW,
  TIPO_TECLADO_APENAS_XY,
  TIPO_TECLADO_APENAS_X,
  TIPO_TECLADO_APENAS_Y,
  TIPO_TECLADO_APENAS_SW,
  TIPO_TECLADO_CRONOMETRO_START,
  TIPO_TECLADO_CRONOMETRO_PAUSE
};

#define INTERVALO_PARA_ZERAR_CRONOMETRO 2000

enum TecladoPlacar { 
    TECLADO_PLACAR_NADA,    //0
    TECLADO_PLACAR_A_MAIS,  //1
    TECLADO_PLACAR_A_MENOS, //2
    TECLADO_PLACAR_B_MAIS,  //3
    TECLADO_PLACAR_B_MENOS, //4
    TECLADO_PLACAR_X_MAIS,  //5
    TECLADO_PLACAR_X_MENOS, //6
    TECLADO_PLACAR_Y_MAIS,  //7
    TECLADO_PLACAR_Y_MENOS, //8
    TECLADO_PLACAR_SW       //9
};

int read = 1234;


unsigned long tempoAMais = 0;
bool pressionadoAMais = false;
bool pressionadoPimeiraVezAMais = false;
bool tempoCompleAMais = false;

unsigned long tempoAMenos = 0;
bool pressionadoAMenos = false;
bool pressionadoPimeiraVezAMenos = false;
bool tempoCompleAMenos = false;

unsigned long tempoBMais = 0;
bool pressionadoBMais = false;
bool pressionadoPimeiraVezBMais = false;
bool tempoCompleBMais = false;

unsigned long tempoBMenos = 0;
bool pressionadoBMenos = false;
bool pressionadoPimeiraVezBMenos = false;
bool tempoCompleBMenos = false;


bool piscaPimeiraVezA = true;
bool piscaPimeiraVezB = true;
unsigned long tempoPiscaA = 0;
unsigned long tempoPiscaB = 0;
byte contaPiscadaA = 1;
byte contaPiscadaB = 1;



unsigned long tempoJOY_X_MAIS = 0;
bool pressionadoJOY_X_MAIS = false;
bool pressionadoPimeiraVezJOY_X_MAIS = false;
bool tempoCompleJOY_X_MAIS = false;

unsigned long tempoJOY_X_MENOS = 0;
bool pressionadoJOY_X_MENOS = false;
bool pressionadoPimeiraVezJOY_X_MENOS = false;
bool tempoCompleJOY_X_MENOS = false;

unsigned long tempoJOY_Y_MAIS = 0;
bool pressionadoJOY_Y_MAIS = false;
bool pressionadoPimeiraVezJOY_Y_MAIS = false;
bool tempoCompleJOY_Y_MAIS = false;

unsigned long tempoJOY_Y_MENOS = 0;
bool pressionadoJOY_Y_MENOS = false;
bool pressionadoPimeiraVezJOY_Y_MENOS = false;
bool tempoCompleJOY_Y_MENOS = false;

unsigned long tempoJOY_SW = 0;
bool pressionadoJOY_SW = false;
bool pressionadoPimeiraVezJOY_SW = false;
bool tempoCompleJOY_SW = false;

byte setsTimeA = 0;
byte setsTimeB = 0;
byte quantSets = 0;
bool cursorVolei = true; // true = marcar set , false = sair/finalizar
byte leituraDosBotoes = 0;


struct Time{
  int pontosPorSet[5] = {0, 0, 0, 0, 0};
  int sets = 0;
  int pontosAtual = 0;
  int totalPontos = 0;
};

class Pontuacao{
  private:
    Time timeA, timeB;
    int unsigned contaSet = 1;
    char lastTimeGanhouSet = '.';
    bool jogoFinalizado = false;
    char timeVencedor = '.';

  public:

    void adicionarPontosTimeA()
    {
      if (!jogoFinalizado)
        timeA.pontosAtual++;
    }
    void removerPontosTimeA()
    {
      if (!jogoFinalizado)
        timeA.pontosAtual--;
    }
    
    void adicionarPontosTimeB()
    {
      if (!jogoFinalizado)
        timeB.pontosAtual++;
    }
    void removerPontosTimeB()
    {
      if (!jogoFinalizado)
        timeB.pontosAtual--;
    }

    void setPontosTimeA(int pontosA)
    {
      if (!jogoFinalizado)
        timeA.pontosAtual = pontosA;
    }

    void setPontosTimeB(int pontosB)
    {
      if (!jogoFinalizado)
        timeB.pontosAtual = pontosB;
    }

    int getPontosTimeA()
    {
      return timeA.pontosAtual;
    }

    int getPontosTimeB()
    {
      return timeB.pontosAtual;
    }
  
    int getSetsTimeA()
    {
      return timeA.sets;
    }

    int getSetsTimeB()
    {
      return timeB.sets;
    }

    char getTimeVencedor()
    {
      return timeVencedor;
    }

    int getSet()
    {
      return contaSet;
    }

    bool marcarSet(){

      bool result = false;   

      if (!jogoFinalizado)
      {         

        if (contaSet <= 4 && (timeA.pontosAtual >= 25 || timeB.pontosAtual >= 25))
        {
          if (doisPontosDeDiferenca())
          {
            if (timeGanhouSet() == 'A')
            {
              configFimSet();
              timeA.sets++;
              contaSet++;
              result = true;
            }
            else
            {
              configFimSet();
              timeB.sets++;
              contaSet++;
              result = true;
            }
          }
        }
        else if (contaSet == 5 && (timeA.pontosAtual >= 15 || timeB.pontosAtual >= 15))
        {
          if (doisPontosDeDiferenca())
          {
            if (timeGanhouSet() == 'A')
            {
              configFimSet();
              timeA.sets++;
              contaSet++;
              result = true;
              jogoFinalizado = true;
              timeVencedor = 'A';
            }
            else
            {
              configFimSet();
              timeB.sets++;
              contaSet++;
              result = true;
              jogoFinalizado = true;
              timeVencedor = 'B';
            }
          }
        }

        if (timeA.sets == 3)
        {
          jogoFinalizado = true;
          timeVencedor = 'A';
        }
        if (timeB.sets == 3)
        {
          jogoFinalizado = true;
          timeVencedor = 'B';
        }
      
      }
      return result;
    }

    void configFimSet()
    {
      if (!jogoFinalizado)
      {
        timeA.pontosPorSet[contaSet-1] = timeA.pontosAtual;
        timeB.pontosPorSet[contaSet-1] = timeB.pontosAtual;
        timeB.totalPontos = contaPontosTotal(timeB.pontosPorSet);
        timeA.totalPontos = contaPontosTotal(timeA.pontosPorSet);
        timeA.pontosAtual = 0;
        timeB.pontosAtual = 0;
      }
    }

    bool doisPontosDeDiferenca()
    {
      return (timeA.pontosAtual >= timeB.pontosAtual+2) || (timeA.pontosAtual+2 <= timeB.pontosAtual);
    }

    char timeGanhouSet()
    {
      if (timeA.pontosAtual >= timeB.pontosAtual+2)
        lastTimeGanhouSet = 'A';
      else if (timeA.pontosAtual+2 <= timeB.pontosAtual)
        lastTimeGanhouSet = 'B';

      return lastTimeGanhouSet;
    }

    int contaPontosTotal(int * lista)
    {
      int pontos = 0;
      for (byte i = 0; i < 5; i++)
      {
        pontos+=lista[i];
      }

      return pontos;
    }
  
    void dump()
    {

      if (!jogoFinalizado)
      {
        Serial.print(timeA.pontosAtual); Serial.print("-"); Serial.print(timeA.sets); Serial.print("|");
        Serial.print(timeB.pontosAtual); Serial.print("-"); Serial.print(timeB.sets); Serial.print("|");
        Serial.println(contaSet); 
      }
      else
      {
        Serial.println("Time A ----------------------------------------------"); 
        Serial.print("  total sets "); Serial.println(timeA.sets);
        Serial.print("  pontos por set: [ "); for (byte i = 0; i < 5; i++) {Serial.print(timeA.pontosPorSet[i]); Serial.print(" "); } Serial.println("]");
        Serial.print("  total de pontos: "); Serial.println(timeA.totalPontos);
        
        Serial.println("Time B ----------------------------------------------"); 
        Serial.print("  total sets "); Serial.println(timeB.sets);
        Serial.print("  pontos por set: [ "); for (byte i = 0; i < 5; i++) {Serial.print(timeB.pontosPorSet[i]); Serial.print(" "); } Serial.println("]");
        Serial.print("  total de pontos: "); Serial.println(timeB.totalPontos);
      }
    }

    bool finalizou()
    {
      return jogoFinalizado;
    }

    void zerar()
    {
      timeA.pontosAtual = 0;
      timeA.totalPontos = 0;
      timeA.sets = 0;
      for (byte i = 0; i < 5; i++) timeA.pontosPorSet[i] = 0;

      timeB.pontosAtual = 0;
      timeB.totalPontos = 0;
      timeB.sets = 0;
      for (byte i = 0; i < 5; i++) timeB.pontosPorSet[i] = 0;
      
      contaSet = 1;
      lastTimeGanhouSet = '.';
      jogoFinalizado = false;
      timeVencedor = '.';
    }

};

Pontuacao pontuacao;


void setup()
{

  mx.begin();  // Inicializa a matriz de LEDs
  mx.control(MD_MAX72XX::INTENSITY, 1);  // Define a intensidade da luz (0-15)
  
  mx.clear();
  drawArray(preto, 'e');
  delay(1000);
  drawArray(preto, 'd');


  Serial.begin(9600);

  // initialize with the I2C addr 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  

  // Clear the buffer.
  display.clearDisplay();  
  display.display();
  display.setFont(&FreeSerif9pt7b);
  
  for (int i = 0; i < QUANT_OUTPUTS; i++)
    pinMode(allOutputs[i], OUTPUT);

 
  pinMode(13, OUTPUT);

  pinMode(BTN_MAIS_A, INPUT_PULLUP);
  pinMode(BTN_MENOS_A, INPUT_PULLUP);


  pinMode(BTN_MAIS_B, INPUT_PULLUP);
  pinMode(BTN_MENOS_B, INPUT_PULLUP);


  pinMode(JOY_SW , INPUT_PULLUP);
  //for (int i = MIN_B_A; i < MAX_B_A; i++)
  //{
    //pinMode(pins[i], INPUT_PULLUP);
  //}


  /*
  for( int i = 0; i < 10; i++){
      showNumbers(i*10 + i);
      delay(500);
  }
  for( int i = 9; i > 0; i--){
      showNumbers(i*10 + i);
      delay(500);
  }

  drawArray(feliz, 'e');
//*/
  splash();

  managerTelaMenuPrincipal();

}


void splash(){
  int i = 0;
  for (i = 0; i < 40; i++)
  {
    display.drawBitmap(0, 0,  splash_allArray[i] , 128, 64, WHITE);
    display.display();
    delay(40);
    display.clearDisplay();  
    //display.drawBitmap(0, 0,  epd_bitmap_splash_allArray[i] , 128, 64, BLACK);
    //display.display();
    //delay(1);
  }

  display.fillRect(0, 0, 128, 64, WHITE);

  display.setTextColor(SSD1306_BLACK);
  display.setTextSize(2);             // Draw 2X-scale text
  display.setCursor(20,35);             // Start at top-left corner
  display.print("Placar");
  display.setTextSize(1);  
  display.setCursor(12,60);             // Start at top-left corner
  display.print("2024 - V1.0.0");
  display.display();
  delay(3000);
  display.clearDisplay();  
  
}

/*
enum tipoDeLeituraDosBotoes {
    LEITU_BTN_TODOS,         // 0
    LEITU_BTN_CONFIRMACAO    // 1
};

enum Tela {
    TELA_MENU_PRINCIPAL,         // 0
    TELA_VOLEI,
    TELA_CONFIRMACAO_VOLEI_MARCAR,
    TELA_CONFIRMACAO_VOLEI_SAIR,
    TELA_CRONOMETRO,
    TELA_CONFIRMACAO_CRONOMETRO_SAIR
};

enum Cursor {
    CURSOR_TODOS,
    CURSOR_CONFIRMACAO,
    CURSOR_SELECAO
};

class Menu {
    // Atributos da classe
    Cursor cursor;
    Tela tela;
    Tela telaLast;
    tipoDeLeituraDosBotoes leituraDosBotoes;

public:
    // Método construtor da classe
    Menu(Cursor cursor, Tela tela, tipoDeLeituraDosBotoes leituraDosBotoes) {
        this->cursor = cursor;
        this->tela = tela;
        this->leituraDosBotoes = leituraDosBotoes;
    }

};

 Menu menu(CURSOR_SELECAO, TELA_VOLEI, LEITU_BTN_CONFIRMACAO);

void gerenciadorTelas(Menu menu);
bool mudouTela(Menu menu);
*/
void loop()
{
  //Serial.println(analogRead(JOY_X));
//  gerenciadorTelas(menu);

    

    //managerTelaMenuPrincipal();
//  verificaDestaque();

}
/*
void gerenciadorTelas(Menu menu)
{
  if (mudouTela(menu))
  {
    switch(menu.tela)
    {
      case TELA_MENU_PRINCIPAL:					             break;         
      case TELA_VOLEI:	                          oledVoleiConfirmacaoMarcar(); 				           break;
      case TELA_CONFIRMACAO_VOLEI_MARCAR:					   break;
      case TELA_CONFIRMACAO_VOLEI_SAIR:					     break;
      case TELA_CRONOMETRO:					                 break;
      case TELA_CONFIRMACAO_CRONOMETRO_SAIR:					 break;
    }
  }
}

bool mudouTela(Menu menu)
{
  bool result = false;
  
  if (menu->tela != menu->telaLast)
  {
    menu->telaLast = menu->tela;
    result = true;
  }
  
  return result;
}

*/



int verificaBotoes(int leituraDosBotoes)
{
  
  int result = TECLADO_PLACAR_NADA;

  if (leituraDosBotoes == TIPO_TECLADO_TODOS || leituraDosBotoes == TIPO_TECLADO_APENAS_AB || leituraDosBotoes == TIPO_TECLADO_APENAS_A)
  {
    //--------------------------------------------------------------------------------------------A MAIS
    if (digitalRead(BTN_MAIS_A) == 0) {

      if (pressionadoPimeiraVezAMais)
      {
        pressionadoPimeiraVezAMais = false;
        tempoAMais = millis();
      }
      
      if (millis() - tempoAMais >= INTERVALO_BTN)
      {
        tempoCompleAMais = true;
      }

    }
    else
    {
      pressionadoPimeiraVezAMais = true;
      if(tempoCompleAMais)
      {
        tempoCompleAMais = false;
        result = TECLADO_PLACAR_A_MAIS; 
      }

    }


    //--------------------------------------------------------------------------------------------A MENOS
    if (digitalRead(BTN_MENOS_A) == 0) {

      if (pressionadoPimeiraVezAMenos)
      {
        pressionadoPimeiraVezAMenos = false;
        tempoAMenos = millis();
      }
      
      if (millis() - tempoAMenos >= INTERVALO_BTN)
      {
        tempoCompleAMenos = true;
      }

    }
    else
    {
      pressionadoPimeiraVezAMenos = true;
      if(tempoCompleAMenos)
      {
        tempoCompleAMenos = false;
        result = TECLADO_PLACAR_A_MENOS; 
      }

    }
  }
    
  if (leituraDosBotoes == TIPO_TECLADO_TODOS || leituraDosBotoes == TIPO_TECLADO_APENAS_AB || leituraDosBotoes == TIPO_TECLADO_APENAS_B)
  {
    //--------------------------------------------------------------------------------------------B MAIS
    if (digitalRead(BTN_MAIS_B) == 0) {

      if (pressionadoPimeiraVezBMais)
      {
        pressionadoPimeiraVezBMais = false;
        tempoBMais = millis();
      }
      
      if (millis() - tempoBMais >= INTERVALO_BTN)
      {
        tempoCompleBMais = true;
      }

    }
    else
    {
      pressionadoPimeiraVezBMais = true;
      if(tempoCompleBMais)
      {
        tempoCompleBMais = false;
        result = TECLADO_PLACAR_B_MAIS; 
      }

    }

    //--------------------------------------------------------------------------------------------B MENOS
    if (digitalRead(BTN_MENOS_B) == 0) {

      if (pressionadoPimeiraVezBMenos)
      {
        pressionadoPimeiraVezBMenos = false;
        tempoBMenos = millis();
      }
      
      if (millis() - tempoBMenos >= INTERVALO_BTN)
      {
        tempoCompleBMenos = true;
      }

    }
    else
    {
      pressionadoPimeiraVezBMenos = true;
      if(tempoCompleBMenos)
      {
        tempoCompleBMenos = false;
        result = TECLADO_PLACAR_B_MENOS; 
      }
    }
  }

  if (leituraDosBotoes == TIPO_TECLADO_TODOS || leituraDosBotoes == TIPO_TECLADO_APENAS_XY || leituraDosBotoes == TIPO_TECLADO_APENAS_XYSW || leituraDosBotoes == TIPO_TECLADO_APENAS_XSW ||  leituraDosBotoes == TIPO_TECLADO_APENAS_X)
  {
    //--------------------------------------------------------------------------------------------X MAIS
    if (analogRead(JOY_X) >= 700) {

      if (pressionadoPimeiraVezJOY_X_MAIS)
      {
        pressionadoPimeiraVezJOY_X_MAIS = false;
        tempoJOY_X_MAIS = millis();
      }
      
      if (millis() - tempoJOY_X_MAIS >= INTERVALO_BTN)
      {
        tempoCompleJOY_X_MAIS = true;
      }

    }
    else
    {
      pressionadoPimeiraVezJOY_X_MAIS = true;
      if(tempoCompleJOY_X_MAIS)
      {
        //piscaPimeiraVezB = true;
        tempoCompleJOY_X_MAIS = false;
        

        result = TECLADO_PLACAR_X_MAIS; 
      }
    }


    //--------------------------------------------------------------------------------------------X MENOS
    if (analogRead(JOY_X) <= 200) {

      if (pressionadoPimeiraVezJOY_X_MENOS)
      {
        pressionadoPimeiraVezJOY_X_MENOS = false;
        tempoJOY_X_MENOS = millis();
      }
      
      if (millis() - tempoJOY_X_MENOS >= INTERVALO_BTN)
      {
        tempoCompleJOY_X_MENOS = true;
      }

    }
    else
    {
      pressionadoPimeiraVezJOY_X_MENOS = true;
      if(tempoCompleJOY_X_MENOS)
      {
        //piscaPimeiraVezB = true;
        tempoCompleJOY_X_MENOS = false;
        

        result = TECLADO_PLACAR_X_MENOS;
      }

      

    }
  }

  if (leituraDosBotoes == TIPO_TECLADO_TODOS || leituraDosBotoes == TIPO_TECLADO_APENAS_XY || leituraDosBotoes == TIPO_TECLADO_APENAS_XYSW || leituraDosBotoes == TIPO_TECLADO_APENAS_YSW || leituraDosBotoes == TIPO_TECLADO_APENAS_Y)
  {
      //--------------------------------------------------------------------------------------------Y MAIS

    if (analogRead(JOY_Y) >= 700) {

      if (pressionadoPimeiraVezJOY_Y_MAIS)
      {
        pressionadoPimeiraVezJOY_Y_MAIS = false;
        tempoJOY_Y_MAIS = millis();
      }
      
      if (millis() - tempoJOY_Y_MAIS >= INTERVALO_BTN)
      {
        tempoCompleJOY_Y_MAIS = true;
      }

    }
    else
    {
      pressionadoPimeiraVezJOY_Y_MAIS = true;
      if(tempoCompleJOY_Y_MAIS)
      {
        //piscaPimeiraVezB = true;
        tempoCompleJOY_Y_MAIS = false;
        
        // sair
        cursorVolei = false;
        /*
        turnOffCursorVoleiClicked();
        display.drawBitmap(44, 48,  epd_bitmap_allArray[4] , 12, 12, BLACK);
        display.drawBitmap(78, 48,  epd_bitmap_allArray[4] , 12, 12, WHITE);
        display.display();
        //*/
        result = TECLADO_PLACAR_Y_MAIS; 
      }
    }

    //--------------------------------------------------------------------------------------------Y MENOS
    if (analogRead(JOY_Y) <= 200) {

      if (pressionadoPimeiraVezJOY_Y_MENOS)
      {
        pressionadoPimeiraVezJOY_Y_MENOS = false;
        tempoJOY_Y_MENOS = millis();
      }
      
      if (millis() - tempoJOY_Y_MENOS >= INTERVALO_BTN)
      {
        tempoCompleJOY_Y_MENOS = true;
      }

    }
    else
    {
      pressionadoPimeiraVezJOY_Y_MENOS = true;
      if(tempoCompleJOY_Y_MENOS)
      {
        //piscaPimeiraVezB = true;
        tempoCompleJOY_Y_MENOS = false;
        
        // marcar sets
        cursorVolei = true;
        /*
        turnOffCursorVoleiClicked();
        display.drawBitmap(44, 48,  epd_bitmap_allArray[4] , 12, 12, WHITE);
        display.drawBitmap(78, 48,  epd_bitmap_allArray[4] , 12, 12, BLACK);
        display.display();
        //*/
        result = TECLADO_PLACAR_Y_MENOS; 
      }
    }
  }
  
  if (leituraDosBotoes == TIPO_TECLADO_TODOS || leituraDosBotoes == TIPO_TECLADO_APENAS_XYSW || leituraDosBotoes == TIPO_TECLADO_APENAS_XSW || leituraDosBotoes == TIPO_TECLADO_APENAS_YSW || leituraDosBotoes == TIPO_TECLADO_APENAS_SW || leituraDosBotoes == TIPO_TECLADO_CRONOMETRO_START || 
  leituraDosBotoes == TIPO_TECLADO_CRONOMETRO_PAUSE)
  {
    //--------------------------------------------------------------------------------------------JOY_SW
    if (digitalRead(JOY_SW) == 0) {

      Serial.println("SW");

      if (pressionadoPimeiraVezJOY_SW)
      {
        pressionadoPimeiraVezJOY_SW = false;
        tempoJOY_SW = millis();
      }
      
      if (millis() - tempoJOY_SW >= INTERVALO_BTN)
      {
        tempoCompleJOY_SW = true;
      }

    }
    else
    {
      pressionadoPimeiraVezJOY_SW = true;
      if(tempoCompleJOY_SW)
      {
        //piscaPimeiraVezB = true;
        tempoCompleJOY_SW = false;
        leituraDosBotoes = 0;

        

        result = TECLADO_PLACAR_SW; 
      }
    }
  }



  if (leituraDosBotoes == TIPO_TECLADO_CRONOMETRO_START || leituraDosBotoes == TIPO_TECLADO_CRONOMETRO_PAUSE){


    //--------------------------------------------------------------------------------------------A MAIS
    if (leituraDosBotoes == TIPO_TECLADO_CRONOMETRO_PAUSE)
    {
      if (digitalRead(BTN_MAIS_A) == 0) 
        result = TECLADO_PLACAR_A_MAIS; 
    }
    else if (leituraDosBotoes == TIPO_TECLADO_CRONOMETRO_START)
    {
      //--------------------------------------------------------------------------------------------A MAIS
      if (digitalRead(BTN_MAIS_A) == 0) 
      {
        if (pressionadoPimeiraVezAMais)
          {
            pressionadoPimeiraVezAMais = false;
            tempoAMais = millis();
          }
          
          if (millis() - tempoAMais >= INTERVALO_BTN)
          {
            tempoCompleAMais = true;
          }

        }
        else
        {
          pressionadoPimeiraVezAMais = true;
          if(tempoCompleAMais)
          {
            tempoCompleAMais = false;
            result = TECLADO_PLACAR_A_MAIS; 
          }

      }
    }


     


    //--------------------------------------------------------------------------------------------A MENOS
    if (digitalRead(BTN_MENOS_A) == 0) {

      if (pressionadoPimeiraVezAMenos)
      {
        pressionadoPimeiraVezAMenos = false;
        tempoAMenos = millis();
      }
      
      if (millis() - tempoAMenos >= INTERVALO_PARA_ZERAR_CRONOMETRO)
      {
        tempoCompleAMenos = true;
      }

    }
    else
    {
      pressionadoPimeiraVezAMenos = true;
      if(tempoCompleAMenos)
      {
        tempoCompleAMenos = false;
        result = TECLADO_PLACAR_A_MENOS; 
      }

    }    

  }

  Serial.print("x: "); Serial.println(analogRead(JOY_Y));

  return result;

}

void verificaDestaque()
{
  if (pontuacao.getPontosTimeA() != 0 || pontuacao.getPontosTimeB() != 0)
  {
      if (contaPontosALast != pontuacao.getPontosTimeA())
      {
        if(piscaPimeiraVezA){
        tempoPiscaA = millis();
        piscaPimeiraVezA = false;
        contaPiscadaA = 1;
        }

        if(contaPiscadaA <= 6){
          if (millis() - tempoPiscaA < 400){
            if (contaPiscadaA > 1){
                turnOffA();
                turnOffOledAVolei();
            }
          }

          if (millis() - tempoPiscaA > 400 && millis() - tempoPiscaA <900){
            dislpayTimeA();
            oledTimeAVolei();
          }

          if (millis() - tempoPiscaA >900)
          {
            tempoPiscaA += 900;
            contaPiscadaA++;
          }
        }
        else{
          contaPiscadaA = 1;
          contaPontosALast = pontuacao.getPontosTimeA();
          piscaPimeiraVezA = true;
        }


      }

      if (contaPontosBLast != pontuacao.getPontosTimeB())
      {
        if(piscaPimeiraVezB){
        tempoPiscaB = millis();
        piscaPimeiraVezB = false;
        contaPiscadaB = 1;
        }

        if(contaPiscadaB <= 6){
          if (millis() - tempoPiscaB < 400){
            if (contaPiscadaB > 1){
                turnOffB();
                turnOffOledBVolei();
            }
          }

          if (millis() - tempoPiscaB > 400 && millis() - tempoPiscaB <900){
            dislpayTimeB();
            oledTimeBVolei();
          }

          if (millis() - tempoPiscaB >900)
          {
            tempoPiscaB += 900;
            contaPiscadaB++;
          }
        }
        else{
          contaPiscadaB = 1;
          contaPontosBLast = pontuacao.getPontosTimeB();
          piscaPimeiraVezB = true;
        }


      }      
   }
}


void turnOffCursorVoleiClicked()
{
  display.drawBitmap(78, 48,  epd_bitmap_allArray[5] , 12, 12, BLACK);
  display.drawBitmap(44, 48,  epd_bitmap_allArray[5] , 12, 12, BLACK);
}

void turnOffCursorVoleiSelected()
{
  display.drawBitmap(44, 48,  epd_bitmap_allArray[4] , 12, 12, BLACK);
  display.drawBitmap(78, 48,  epd_bitmap_allArray[4] , 12, 12, BLACK);
}

void turnOffCursorVoleiAll()
{
  turnOffCursorVoleiSelected();
  turnOffCursorVoleiClicked();
}


void turnOffA()
{
  oneDigit(10, 0, false);
  oneDigit(10, 1, false);
}

void turnOffB()
{
  oneDigit(10, 2, false);
  oneDigit(10, 3, false);
}

void dislpayTimeA()
{
  oneDigit(pontuacao.getPontosTimeA()/10, 0, true);
  oneDigit(pontuacao.getPontosTimeA() - ((pontuacao.getPontosTimeA()/10) * 10), 1, true);
}

void dislpayTimeB()
{
  oneDigit(pontuacao.getPontosTimeB()/10, 2, true);
  oneDigit(pontuacao.getPontosTimeB() - ((pontuacao.getPontosTimeB()/10) * 10), 3, true);
}


  
  
void turnOffOledAVolei()
{
  display.fillRect(85, 3, 40, 35, BLACK); // A
  display.setTextColor(SSD1306_BLACK);
  display.setTextSize(1);             // Draw 2X-scale text
  display.setCursor(67,16);             // Start at top-left corner
  display.print("A");
  display.display();
  display.setTextColor(SSD1306_WHITE);
}

void turnOffOledBVolei()
{
  display.fillRect(3, 3, 40, 35, BLACK); // B
  display.setTextColor(SSD1306_BLACK);
  display.setTextSize(1);             // Draw 2X-scale text
  display.setCursor(48,16);             // Start at top-left corner
  display.print("B");
  display.display();
  display.setTextColor(SSD1306_WHITE);
}



void turnOffOledBSetVolei()
{
  display.fillRect(47, 25, 15, 16, BLACK); // B
  display.fillRect(67, 25, 15, 16, BLACK); // B
}





void oledTimeAVolei()
{
  display.setTextSize(2);             // Draw 2X-scale text
  display.setCursor(88,32);             // Start at top-left corner
  zeroLeft(pontuacao.getPontosTimeA());
  display.setTextSize(1);             // Draw 2X-scale text
  display.setCursor(67,16);             // Start at top-left corner
  display.print("A");
  display.display();
}

void oledTimeBVolei()
{
  display.setTextSize(2);             // Draw 2X-scale text
  display.setCursor(3,32);             // Start at top-left corner
  zeroLeft(pontuacao.getPontosTimeB());
  display.setTextSize(1);             // Draw 2X-scale text
  display.setCursor(48,16);             // Start at top-left corner
  display.print("B");
  display.display();
}



void convertByDigit(int num, int* m, int* c, int* d, int* u)
{
  if (num <= 9999)
  {    
    if (num != G_lastNum)
    {
      *m = num/1000;
      *c = (num - ((*m) * 1000)) / 100;
      *d = (num - (((*m) * 1000) + ((*c) * 100))) / 10;
      *u = num - (((*m) * 1000) + ((*c) * 100) + ((*d) * 10));
      G_lastNum = num;
    }
  }
}



void temperatura(int temp)
{
  oneDigit(temp/10, 0, false);
  oneDigit( temp - ((temp/10)*10) , 1, false);
  oneDigit( 12 , 2, false);
  oneDigit( 15 , 3, false);
}

void hora(int time)
{
  int m, c, d, u;

  if (time >= 0 && time <= 9999)
  {
    convertByDigit(time, &m, &c, &d, &u);
    for (int i = 0; i<2; i++)
    {

      for (int i = 0; i<2; i++)
      {
        turnOffAll();
        delay(300);
        oneDigit(11, 0, false);
        oneDigit(17, 1, false);
        oneDigit(16, 2, false);
        oneDigit(18, 3, false);
        delay(2000);
      }

      for (int i = 0; i<2; i++)
      {
        turnOffAll();
        delay(300);
        oneDigit(m, 0, true);
        oneDigit(c, 1, true);
        oneDigit(d, 2, true);
        oneDigit(u, 3, true);
        delay(2000);
      }
    }
  }
}




///*
unsigned long atualizaTempo()
{
  timerCur = millis();
  return timerCur;
}
//*/


void oneDigit(int num, int digit, bool onlyNumeric)
{
  /*
  switch(digit)
  {
    case 0:
      for (int i = 0; i < 7; i++)
        digitalWrite(arrayD0[i], digits[num][i]);   
    break;

    case 1:
      for (int i = 0; i < 7; i++)
        digitalWrite(arrayD1[i], digits[num][i]);   
    break;    

    case 2:
      for (int i = 0; i < 7; i++)
        digitalWrite(arrayD2[i], digits[num][i]);   
    break;

    case 3:
      for (int i = 0; i < 7; i++)
        digitalWrite(arrayD3[i], digits[num][i]);   
    break;

    default: break;
  }//*/
  if ( (num >=0 && num < (onlyNumeric==true? 10:QUANT_CARACTERES) ) && (digit >= 0 && digit <= 3) )
      for (int i = 0; i < 7; i++)
        digitalWrite(allOutputs[(digit*7)+i], digits[num][i]);   
}

void writeDigits(int num)
{
  int m, c, d, u;
  if (num <= 9999)
  {    
    m = num/1000;
    c = (num - ((m) * 1000)) / 100;
    d = (num - (((m) * 1000) + ((c) * 100))) / 10;
    u = num - (((m) * 1000) + ((c) * 100) + ((d) * 10));
    oneDigit(m, 0, false); oneDigit(c, 1, false); oneDigit(d, 2, false); oneDigit(u, 3, false);
  }
}


void effects(int effect)
{
  switch(effect)
  {
    case 1: break;
    case 2: break;
    case 3: break;
    case 4: break;
    case 5: break;
    case 6: break;
    default: break;
  }
}

void circuloCompleto(int time)
{
  for(byte i = 0; i < 12; i ++){
    digitalWrite(arrayCirculoCompleto[i], 1);
    delay(time);
    digitalWrite(arrayCirculoCompleto[i], 0);
    delay(time/4);
  }
}

void circuloA(int time)
{
  for(byte i = 0; i < 8; i ++){
    digitalWrite(arrayCirculoA[i], 1);
    delay(time);
    digitalWrite(arrayCirculoA[i], 0);
    delay(time/4);
  }
}

void circuloB(int time)
{
  for(byte i = 0; i < 8; i ++){
    digitalWrite(arrayCirculoB[i], 1);
    delay(time);
    digitalWrite(arrayCirculoB[i], 0);
    delay(time/4);
  }
}

void linhas(int time)
{
  for(byte i = 0; i < 4; i ++){
    digitalWrite(arrayLinhaSuperior[i], 1);
    delay(time);
    digitalWrite(arrayLinhaSuperior[i], 0);
    delay(time/4);
  }
  for(byte i = 0; i < 4; i ++){
    digitalWrite(arrayLinhaCentral[i], 1);
    delay(time);
    digitalWrite(arrayLinhaCentral[i], 0);
    delay(time/4);
  }
  for(byte i = 0; i < 4; i ++){
    digitalWrite(arrayLinhaInferior[i], 1);
    delay(time);
    digitalWrite(arrayLinhaInferior[i], 0);
    delay(time/4);
  }
}



void turnOffAll()
{
    for (byte i = 0; i <= QUANT_OUTPUTS; i++)
      digitalWrite(allOutputs[i], 0);
}



void oledVoleiConfirmacaoMarcar()
{
  
  display.clearDisplay();  
  display.display();

  display.drawBitmap(0, 44,  epd_bitmap_allArray[3] , 128, 20, WHITE);

  display.fillRect(3, 3, 40, 35, BLACK);  // Apaga pontos do time B
  display.fillRect(85, 3, 40, 35, BLACK); // Apaga pontos do time A
  
  display.setTextColor(SSD1306_WHITE);  // Deixa o texto com a cor branca



  display.setTextSize(2);               // Deixa o tamanho das letras em 2

  display.setCursor(0,25);              // Escreve a quantidade de pontos do time B
  display.print("Marcar?");


  display.display();                    // Mostra tudo o que foi definido
}



void  oledVolei()
{
  
  display.drawBitmap(44, 0,  placar2 , 40, 45, WHITE);

  display.fillRect(3, 3, 40, 35, BLACK);  // Apaga pontos do time B
  display.fillRect(85, 3, 40, 35, BLACK); // Apaga pontos do time A
  
  display.setTextColor(SSD1306_WHITE);  // Deixa o texto com a cor branca

  display.setTextSize(1);               // Deixa o tamanho das letras em 1

  display.setCursor(48,16);             // Escreve B
  display.print("B");

  turnOffOledBSetVolei();

  display.setCursor(50,38);             // Escreve a quantidade de sets do time B
  display.print(pontuacao.getSetsTimeB());

  display.setCursor(67,16);             // Escreve A
  display.print("A");

  display.setCursor(69,38);             // Escreve a quantidade de sets do time A
  display.print(pontuacao.getSetsTimeA());


  display.setTextSize(2);               // Deixa o tamanho das letras em 2

  display.setCursor(3,32);              // Escreve a quantidade de pontos do time B
  zeroLeft(pontuacao.getPontosTimeB());

  display.setCursor(88,32);             // Escreve a quantidade de pontos do time A
  zeroLeft(pontuacao.getPontosTimeA());

  display.display();                    // Mostra tudo o que foi definido
}

void zeroLeft(int ponto)
{
  if (ponto < 10)
  {
    display.print("0"); 
    display.print(ponto);
  }
  else
    display.print(ponto);

}



void maquinaMenu(MaqMenuTelas maqMenu)
{
  switch(maqMenu)
  {
    case MAQ_MENU_PRINCIPAL:           display.clearDisplay();                                break;         
    case MAQ_VOLEI:                                              break;
    case MAQ_CONFIRMACAO_VOLEI_MARCAR:                           break;
    case MAQ_CONFIRMACAO_VOLEI_SAIR:                             break;
    case MAQ_CRONOMETRO:                                         break;
    case MAQ_CONFIRMACAO_CRONOMETRO_SAIR:                        break;
  }
}




enum CursorMenuPrincipal {      
    CURSOR_MENU_PRINCIPAL_BEGIN,
    CURSOR_MENU_PRINCIPAL_MIDDLE,
    CURSOR_MENU_PRINCIPAL_END
};

void oledMenuPrincipal(String * opcoes, int quant, char* titulo)
{
  CursorMenuPrincipal cursor = CURSOR_MENU_PRINCIPAL_BEGIN;
  byte cursorIncremental = 0;


  display.setTextColor(SSD1306_WHITE);  // Deixa o texto com a cor branca
  display.setTextSize(1);               // Deixa o tamanho das letras em

  display.drawRect(0, 0, 128, 64, SSD1306_WHITE);
  display.setCursor(64 - ((strlen(titulo) * 10)/2), 18);             // Escreve B
  display.print(titulo); 

  OledNavegadoresDePaginasMenuPrincipal(quant, cursor);

  display.drawLine(0, 24, 128, 24, SSD1306_WHITE);

  for (byte i = 0; i < quant; i++)
  {
    display.setCursor(3,40 + (18*i));             // Escreve B
    display.print(opcoes[i]);
  }


  display.display();                    // Mostra tudo o que foi definido
}


void OledNavegaMenuPrincipal(String * opcoes, byte posicaoOpcoesMenu, byte pagina, byte quant, byte cursor)
{

  display.setTextColor(SSD1306_WHITE);  // Deixa o texto com a cor branca
  display.setTextSize(1);               // Deixa o tamanho das letras em

  OledBorrachaMenuPrincipal();

  OledNavegadoresDePaginasMenuPrincipal(quant, cursor);

  byte inicioIndice = pagina==0? 0:pagina+1;

  for (byte i = inicioIndice; i < inicioIndice+1; i++)
  {
    /*
    if (i == posicaoOpcoesMenu)
    {
      display.fillRect(2, 25, 125, 19, BLACK);      
      display.setCursor(3,40 + (18 * (i - inicioIndice) ) );             // Escreve B
      display.setTextColor(SSD1306_WHITE);  // Deixa o texto com a cor branca
      display.print(opcoes[i]);
    }
    else
    {
      display.setCursor(3,40 + (18 * (i - inicioIndice) ) );             // Escreve B
      display.print(opcoes[i]);
    }
    //*/
    display.setCursor(3,40 + (18 * (i - inicioIndice) ) );             // Escreve B
    display.print(opcoes[i]);
  }
  display.display();

}




enum OpcoesMenuPrinicipal {
    MENU_PRINCIPAL_VOLEI = 1,
    MENU_PRINCIPAL_CRONOMETRO
    //MENU_PRINCIPAL_HORA_CLIMA
};




void managerTelaMenuPrincipal()
{

  byte pagina = 1;
  byte lastPagina = 100;
  const byte quantOpcoes = 2;

  display.drawLine(1, 32, 5, 20, SSD1306_WHITE); // Esquerda
  display.drawLine(1, 32, 5, 42, SSD1306_WHITE); // Esquerda
  display.drawLine(127, 32, 123, 20, SSD1306_WHITE); // Direita
  display.drawLine(127, 32, 123, 42, SSD1306_WHITE); // Direita
  
  display.drawLine(2, 32, 5, 20, SSD1306_WHITE); // Esquerda
  display.drawLine(2, 32, 5, 42, SSD1306_WHITE); // Esquerda
  display.drawLine(126, 32, 123, 20, SSD1306_WHITE); // Direita
  display.drawLine(126, 32, 123, 42, SSD1306_WHITE); // Direita

  display.display(); 

  

  while(1)
  {
    
  /*  debug de valores de joyX por o oled

      display.setTextSize(1);  
      display.setTextColor(BLACK);  
      display.setCursor(10, 32);
      display.print(antigo);
      
      
      display.setTextColor(WHITE);  
      display.setCursor(10, 32);
      display.print(antigo = analogRead(JOY_X));
      display.display();
    }
    {
  */
  
    display.setTextColor(SSD1306_WHITE);  // apagar depois
    display.setTextSize(1);  



    int leituraBotoes = verificaBotoes(TIPO_TECLADO_APENAS_XSW);

    if (leituraBotoes != 0){
      Serial.print("leituraBotoes: "); Serial.println(leituraBotoes);
    }

    if (leituraBotoes == TECLADO_PLACAR_X_MENOS)
    {

      pagina++;
      DestaqueDeNavegacaoMenuPrincipalDireita();
      if (pagina > quantOpcoes)
      {
        pagina = 1;
      }
  

    }
    else if (leituraBotoes == TECLADO_PLACAR_X_MAIS)
    {
      pagina--;
      DestaqueDeNavegacaoMenuPrincipalEsquerda();
      if (pagina == 0)
      {
        pagina = quantOpcoes; 
      }

    }
    else if (leituraBotoes == TECLADO_PLACAR_SW)
    {
      switch (pagina)
      {
        case MENU_PRINCIPAL_VOLEI:       display.clearDisplay(); managerVolei(); break;          
        case MENU_PRINCIPAL_CRONOMETRO:  display.clearDisplay(); managerCronometro(); break;
      }
    }


    if (lastPagina != pagina)
    {
      switch (lastPagina)
      {
        case MENU_PRINCIPAL_VOLEI:       OledOpcaoVolei(true); break;          
        case MENU_PRINCIPAL_CRONOMETRO:  OledOpcaoCronometro(true); break;
      }

      switch (pagina)
      {
        case MENU_PRINCIPAL_VOLEI:       OledOpcaoVolei(false); break;          
        case MENU_PRINCIPAL_CRONOMETRO:  OledOpcaoCronometro(false); break;
      }
      lastPagina = pagina;
    }
  }
}

void OledBorrachaMenuPrincipal()
{
  display.fillRect(1, 25, 126, 38, BLACK);
  display.display();
}

void OledNavegadoresDePaginasMenuPrincipal(byte quant, byte cursor)
{
  display.setTextColor(BLACK);  // Deixa o texto com a cor branca
  display.setTextSize(1);              
  display.setCursor(3, 16);             // Escreve B
  display.print("<"); 
  display.setCursor(115, 16);             // Escreve B
  display.print(">"); 
  display.display();

  display.setTextColor(SSD1306_WHITE);  // Deixa o texto com a cor branca

  if (quant>1 && cursor != CURSOR_MENU_PRINCIPAL_END)
  {
    display.setCursor(115, 16);             // Escreve B
    display.print(">"); 
  }
  if (quant>1 && cursor != CURSOR_MENU_PRINCIPAL_BEGIN)
  {
    display.setCursor(3, 16);             // Escreve B
    display.print("<"); 
  }

  display.display();
}


void apagarDestaqueDeNavegacaoMenuPrincipal()
{
  display.drawLine(3, 32, 5, 20, BLACK); // Esquerda
  display.drawLine(3, 32, 5, 42, BLACK); // Esquerda
  display.drawLine(4, 32, 5, 20, BLACK); // Esquerda
  display.drawLine(4, 32, 5, 42, BLACK); // Esquerda
  
  display.drawLine(125, 32, 123, 20, BLACK); // Direita
  display.drawLine(125, 32, 123, 42, BLACK); // Direita
  display.drawLine(124, 32, 123, 20, BLACK); // Direita
  display.drawLine(124, 32, 123, 42, BLACK); // Direita

  display.display();
}

void DestaqueDeNavegacaoMenuPrincipalEsquerda()
{
  display.drawLine(3, 32, 5, 20, SSD1306_WHITE); // Esquerda
  display.drawLine(3, 32, 5, 42, SSD1306_WHITE); // Esquerda
  display.drawLine(4, 32, 5, 20, SSD1306_WHITE); // Esquerda
  display.drawLine(4, 32, 5, 42, SSD1306_WHITE); // Esquerda

  display.display();
}

void DestaqueDeNavegacaoMenuPrincipalDireita()
{
  display.drawLine(125, 32, 123, 20, SSD1306_WHITE); // Direita
  display.drawLine(125, 32, 123, 42, SSD1306_WHITE); // Direita
  display.drawLine(124, 32, 123, 20, SSD1306_WHITE); // Direita
  display.drawLine(124, 32, 123, 42, SSD1306_WHITE); // Direita

  display.display();
}


void OledOpcaoVolei(bool apagar)
{
  if (apagar)
  {
    display.setTextColor(BLACK);  
    display.drawBitmap(44, 0, epd_bitmap_volei, 40, 40, BLACK);
  }
  else
  {
    display.setTextColor(SSD1306_WHITE); 
    display.drawBitmap(44, 0, epd_bitmap_volei, 40, 40, WHITE);
  }

  display.setTextSize(1);              
  display.setCursor(centralizaNomeComLetra1("Volei"), 55);             
  display.print("Volei"); 
  display.display(); 

  apagarDestaqueDeNavegacaoMenuPrincipal();
}


void OledOpcaoCronometro(bool apagar)
{
  if (apagar)
  {
    display.setTextColor(BLACK);  
    display.drawBitmap(44, 0, epd_bitmap_ampulheta, 40, 40, BLACK);
  }
  else
  {
    display.setTextColor(SSD1306_WHITE); 
    display.drawBitmap(44, 0, epd_bitmap_ampulheta, 40, 40, WHITE);
  }
  
  display.setTextSize(1);              
  display.setCursor(centralizaNomeComLetra1("Cronometro"), 55);     
  display.print("Cronometro"); 
  display.display(); 

  apagarDestaqueDeNavegacaoMenuPrincipal();
}

void OledOpcaoHoraClima(bool apagar)
{
  if (apagar)
  {
    display.setTextColor(BLACK);  
    display.drawBitmap(37, 0, epd_bitmap_hora, 53, 40, BLACK);
  }
  else
  {
    display.setTextColor(SSD1306_WHITE); 
    display.drawBitmap(37, 0, epd_bitmap_hora, 53, 40, WHITE);
  }
  
  display.setTextSize(1);              
  display.setCursor(centralizaNomeComLetra1("Hora/Clima"), 55);     
  display.print("Hora/Clima"); 
  display.display(); 

  apagarDestaqueDeNavegacaoMenuPrincipal();
}

byte centralizaNomeComLetra1(char * nome)
{
  byte size = strlen(nome);
  byte result = 0;

  if (size>0)
  {
    if (size >=1 && size <=5)
    {
      result = (63 - ((size * 9)/2) );
    }
      
    else if (size >5 && size <=10)
    {
      result =  (63 - ((size* 8)/2) );
    }

  }
  return result ;
}




enum OpcoesVolei {
    OPCAO_VOLEI_MARCAR,
    OPCAO_VOLEI_SAIR
};


void managerVolei()
{

  byte opcaoVolei = OPCAO_VOLEI_MARCAR;
  byte lastOpcaoVolei = 100;
  bool sair = false;

  oledVolei();
  showNumbers(pontuacao.getSetsTimeA()*10 + pontuacao.getSetsTimeB());
  dislpayTimeA();
  dislpayTimeB();
  DestaqueDeNavegacaoVoleiMarcar();

  while(1)
  {
    display.setTextColor(SSD1306_WHITE);  // apagar depois
    display.setTextSize(1);  
    
    if (!pontuacao.finalizou()) 
      pontuacao.dump();

    int leituraBotoes = verificaBotoes(TIPO_TECLADO_TODOS);
    
    if (leituraBotoes == TECLADO_PLACAR_X_MENOS)
    {
      opcaoVolei = OPCAO_VOLEI_SAIR;
      DestaqueDeNavegacaoVoleiSair();
    }
    else if (leituraBotoes == TECLADO_PLACAR_X_MAIS)
    {
      opcaoVolei =  OPCAO_VOLEI_MARCAR;
      DestaqueDeNavegacaoVoleiMarcar();
    }
    else if (leituraBotoes == TECLADO_PLACAR_SW)
    {

      if (opcaoVolei == OPCAO_VOLEI_SAIR)
      {

        if (managerOledConfirmarSaida())
        {
          voleiPrepararVoltaParaOMenuPrincipal();
          break;
        }
        else
        {
          display.clearDisplay();
          turnOffOledBSetVolei();
          dislpayTimeA();
          dislpayTimeB();
          oledVolei();
          DestaqueDeNavegacaoVoleiSair();
        }

      }
      else
      {
        if(pontuacao.marcarSet())
        {
          if (pontuacao.finalizou()){
            showNumbers(pontuacao.getSetsTimeA()*10 + pontuacao.getSetsTimeB());
            oledVoleiTimeVencedor();
            pontuacao.zerar();
          }
          else
          {
            oledVoleiTimeQueMarcouSets();
          }
          
          display.clearDisplay();  
          oledVolei();
          showNumbers(pontuacao.getSetsTimeA()*10 + pontuacao.getSetsTimeB());
          DestaqueDeNavegacaoVoleiMarcar();
          ligaPlacar();
        }

        pontuacao.dump();
      }
      /*
      switch (opcaoVolei)
      {
        case OPCAO_VOLEI_MARCAR:  break;          
        case OPCAO_VOLEI_SAIR:     break;
      }*/
    }
    else if (leituraBotoes == TECLADO_PLACAR_A_MAIS)
    {
        piscaPimeiraVezA = true;
        
        pontuacao.adicionarPontosTimeA();
        if (pontuacao.getPontosTimeA()>99)
          pontuacao.setPontosTimeA(99);
        if(pontuacao.getPontosTimeA()<=99){
          dislpayTimeA();
        }

    }
    else if (leituraBotoes == TECLADO_PLACAR_A_MENOS)
    {

        piscaPimeiraVezA = true;
        
        pontuacao.removerPontosTimeA();
        if (pontuacao.getPontosTimeA()<0)
          pontuacao.setPontosTimeA(0);
        if(pontuacao.getPontosTimeA()>=0){
          dislpayTimeA();
        }
    }
    else if (leituraBotoes == TECLADO_PLACAR_B_MAIS)
    {
        piscaPimeiraVezB = true;
        
        pontuacao.adicionarPontosTimeB();
        if (pontuacao.getPontosTimeB()>99)
          pontuacao.setPontosTimeB(99);
        if(pontuacao.getPontosTimeB()<=99){
          dislpayTimeB(); 
        }
    }
    else if (leituraBotoes == TECLADO_PLACAR_B_MENOS)
    {

        piscaPimeiraVezB = true;
        
        pontuacao.removerPontosTimeB();
        if (pontuacao.getPontosTimeB()<0)
          pontuacao.setPontosTimeB(0);
        if(pontuacao.getPontosTimeB()>=0){
          dislpayTimeB();
        }
    }

    if (leituraBotoes == TECLADO_PLACAR_A_MAIS || leituraBotoes == TECLADO_PLACAR_A_MENOS || leituraBotoes == TECLADO_PLACAR_B_MAIS || leituraBotoes == TECLADO_PLACAR_B_MENOS)
    {
      oledVolei();
    }

    if (lastOpcaoVolei != opcaoVolei)
    {
      lastOpcaoVolei = opcaoVolei;
    }

    verificaDestaque();
  }
}

void DestaqueDeNavegacaoVoleiMarcar()
{
  display.fillRect(0, 44, 128, 64, BLACK);
  display.drawBitmap(0, 44,  marcar_volei_select , 128, 20, WHITE);

  display.display();
}

void DestaqueDeNavegacaoVoleiSair()
{
  display.fillRect(0, 44, 128, 64, BLACK);
  display.drawBitmap(0, 44,  back_volei_select , 128, 20, WHITE);

  display.display();
}


void desenhaSetasMenuPrincipal()
{
  display.drawLine(1, 32, 5, 20, SSD1306_WHITE); // Esquerda
  display.drawLine(1, 32, 5, 42, SSD1306_WHITE); // Esquerda
  display.drawLine(127, 32, 123, 20, SSD1306_WHITE); // Direita
  display.drawLine(127, 32, 123, 42, SSD1306_WHITE); // Direita
  
  display.drawLine(2, 32, 5, 20, SSD1306_WHITE); // Esquerda
  display.drawLine(2, 32, 5, 42, SSD1306_WHITE); // Esquerda
  display.drawLine(126, 32, 123, 20, SSD1306_WHITE); // Direita
  display.drawLine(126, 32, 123, 42, SSD1306_WHITE); // Direita

  display.display(); 
}

void voleiPrepararVoltaParaOMenuPrincipal()
{
  turnOffAll();
  display.clearDisplay();
  OledOpcaoVolei(false);
  desenhaSetasMenuPrincipal();
  mx.clear();
}

void ligaPlacar()
{
  oneDigit(0, 0, true);
  oneDigit(0, 1, true);
  oneDigit(0, 2, true);
  oneDigit(0, 3, true);
}





void oledConfirmarSaida()
{
  display.clearDisplay();  

  display.drawBitmap(0, 44,  epd_bitmap_yes_no , 128, 20, WHITE);

  display.fillRect(4, 4, 122, 36, SSD1306_WHITE);  // Apaga pontos do time B
 
  
  display.setTextColor(BLACK);  // Deixa o texto com a cor preta

  display.setTextSize(2);               // Deixa o tamanho das letras em 1

  display.setCursor(30,30);             // Escreve B
  display.print("Sair?");

  display.fillRect(65, 45, 62, 19, SSD1306_WHITE);  // Apaga pontos do time B
  
  display.setTextSize(1);    
  display.setCursor(81,58);             // Escreve B
  display.print("Nao");

  display.setTextColor(SSD1306_WHITE);  // Deixa o texto com a cor branca

             // Deixa o tamanho das letras em 1

  display.setCursor(15,58);             // Escreve B
  display.print("Sim");

  display.display();                    // Mostra tudo o que foi definido
}

void oledConfirmarSaidaNao()
{

  display.setTextColor(BLACK);  // Deixa o texto com a cor branca

  display.fillRect(65, 45, 62, 19, SSD1306_WHITE);  // Apaga pontos do time B
  
  display.setTextSize(1);    
  display.setCursor(81,58);             // Escreve B
  display.print("Nao");

  display.setTextColor(SSD1306_WHITE);  // Deixa o texto com a cor branca

             // Deixa o tamanho das letras em 1

  display.fillRect(1, 45, 62, 18, BLACK);  // Apaga pontos do time B

  display.setCursor(15,58);             // Escreve B
  display.print("Sim");

  display.display();                    // Mostra tudo o que foi definido
  
}

void oledConfirmarSaidaSim()
{

  display.setTextColor(SSD1306_WHITE);  // Deixa o texto com a cor branca
  display.fillRect(65, 45, 62, 18, BLACK);  // Apaga pontos do time B
  
  display.setTextSize(1);    
  display.setCursor(81,58);             // Escreve B
  display.print("Nao");

  display.setTextColor(BLACK);  // Deixa o texto com a cor branca

             // Deixa o tamanho das letras em 1

  display.fillRect(1, 45, 62, 18, SSD1306_WHITE);  // Apaga pontos do time B

  display.setCursor(15,58);             // Escreve B
  display.print("Sim");

  display.display();                    // Mostra tudo o que foi definido
  
}



enum OpcoesVoleiSaida {
    OPCAO_VOLEI_SAIDA_SIM,
    OPCAO_VOLEI_SAIDA_NAO
};



bool managerOledConfirmarSaida()
{
  bool result = false;

  byte opcaoSaida = OPCAO_VOLEI_SAIDA_NAO;
  byte lastOpcaoSaida = 100;
  bool sair = false;

  oledConfirmarSaida();

  while(1)
  {
    display.setTextColor(SSD1306_WHITE);  // apagar depois
    display.setTextSize(1);  

    int leituraBotoes = verificaBotoes(TIPO_TECLADO_APENAS_XSW);
    if (leituraBotoes == TECLADO_PLACAR_X_MENOS)
    {
      if (opcaoSaida != OPCAO_VOLEI_SAIDA_NAO)
      {
        opcaoSaida = OPCAO_VOLEI_SAIDA_NAO;
        oledConfirmarSaidaNao();
      }
    }
    else if (leituraBotoes == TECLADO_PLACAR_X_MAIS)
    {
      if (opcaoSaida != OPCAO_VOLEI_SAIDA_SIM)
      {
        opcaoSaida = OPCAO_VOLEI_SAIDA_SIM;
        oledConfirmarSaidaSim();
      }
    }
    else if (leituraBotoes == TECLADO_PLACAR_SW)
    {
      if (opcaoSaida == OPCAO_VOLEI_SAIDA_SIM)
      {
        result = true;
        break;
      }
      else
        break;
        
    }
  }

  return result;
}

void oledVoleiTimeQueMarcouSets()
{
  display.clearDisplay();  

  display.fillRect(0, 0, 128, 64, SSD1306_WHITE);  // Apaga pontos do time B


  for (byte i = 0; i < 11; i++)
  {
    if (i==0 || i%2==0)
    {
      display.setTextColor(BLACK);  // Deixa o texto com a cor preta

      display.setTextSize(2);               // Deixa o tamanho das letras em 1

      display.setCursor(10,30);             // Escreve B
      display.print("Time ");
      display.print(pontuacao.timeGanhouSet());
      
      display.setCursor(25,55);             // Escreve B
      display.print("+ + +");

      display.display();  

     if (pontuacao.timeGanhouSet() == 'A')
     {
        digiteTimeA();
        drawArray(digitsMatriz[pontuacao.getSetsTimeA()], 'e');
     }
     if (pontuacao.timeGanhouSet() == 'B')
     {
        digiteTimeB();
        drawArray(digitsMatriz[pontuacao.getSetsTimeB()], 'd');
     }

      delay(600);
    }
    else
    {
      display.setTextColor(SSD1306_WHITE);  // Deixa o texto com a cor preta

      display.setTextSize(2);               // Deixa o tamanho das letras em 1

      display.setCursor(10,30);             // Escreve B
      display.print("Time ");
      display.print(pontuacao.timeGanhouSet());

      display.setCursor(25,55);             // Escreve B
      display.print("+ + +");

      display.display();  
      turnOffAll();
      
     if (pontuacao.timeGanhouSet() == 'A')
     {
       drawArray(feliz, 'e');
     }
     if (pontuacao.timeGanhouSet() == 'B')
     {
        drawArray(feliz, 'd');
     }


      delay(300);
    }
  }
}



void digiteTimeA()
{
  oneDigit(18, 0, false);
  oneDigit(18, 1, false);
  oneDigit(18, 2, false);
  oneDigit(18, 3, false);
}

void digiteTimeB()
{
  oneDigit(19, 0, false);
  oneDigit(19, 1, false);
  oneDigit(19, 2, false);
  oneDigit(19, 3, false);
}




void oledVoleiTimeVencedor()
{
  display.clearDisplay();  

  display.fillRect(0, 0, 128, 64, SSD1306_WHITE);  // Apaga pontos do time B

  for (byte i = 0; i < 11; i++)
  {
    if (i==0 || i%2==0)
    {
      display.setTextColor(BLACK);  // Deixa o texto com a cor preta

      display.setTextSize(2);               // Deixa o tamanho das letras em 1

      display.setCursor(10,30);             // Escreve B
      display.print("Time ");
      display.print(pontuacao.timeGanhouSet());
      
      display.setCursor(5,55);             // Escreve B
      display.print("venceu!");

      display.display();  

     if (pontuacao.timeGanhouSet() == 'A')
        digiteTimeA();
     if (pontuacao.timeGanhouSet() == 'B')
        digiteTimeB();

      delay(600);
    }
    else
    {
      display.setTextColor(SSD1306_WHITE);  // Deixa o texto com a cor preta

      display.setTextSize(2);               // Deixa o tamanho das letras em 1

      display.setCursor(10,30);             // Escreve B
      display.print("Time ");
      display.print(pontuacao.timeGanhouSet());

      display.setCursor(5,55);             // Escreve B
      display.print("venceu!");

      display.display();  
      turnOffAll();

      delay(100);
    }
  }
}


//MATRIZ LED ==============================================================================


void showNumbers(int n) {

  if (n <= 99 && n >= 0)
  {
    int dezena = n / 10;
    int unidade = n - (dezena*10);

    mx.clear();

  
    for (byte col = 0; col < 8; col++) {
      mx.setColumn(col+8, digitsMatriz[dezena][col]);
      mx.setColumn(col, digitsMatriz[unidade][col]);
    }
  }
  
}

void displaySingleCharacter(uint16_t c) {
  // Verifica se o caractere é válido (letras maiúsculas ou números)

    mx.clear();  // Limpa a matriz
    mx.setChar(0, c);  // Exibe o caractere na posição (0, 0)

}

void drawArray(const byte *person, char matriz) {
    for (byte col = 0; col < 8; col++) 
    {
      if (matriz == 'e')
        mx.setColumn(col+8, person[col]);
      else if (matriz == 'd')
        mx.setColumn(col, person[col]);
      else if (matriz == 't')
      {
        mx.setColumn(col+8, person[col]);
        mx.setColumn(col, person[col]);
      }
    }
}


// CRONOMETRO  ===============================================================================================

enum opecoesCronometro{
  OPCAO_CRONOMETRO_INICIAR,   // A+
  OPCAO_CRONOMETRO_PAUSAR,    // A-
  OPCAO_CRONOMETRO_ZERAR,     // B+
  OPCAO_CRONOMETRO_SAIR       // SW
};

class Cronometro
{
  public:
  unsigned long init_time = 0;
  unsigned long cur_time = 0;
  unsigned long total_time = 0;

  int milissegundos = 0;
  int segundos = 0;
  int minutos = 0;
  int horas = 0;

  int last_milissegundos = 0;
  int last_segundos = 0;
  int last_minutos = 0;
  int last_horas = 0;

  bool run = false;
  bool firstTime = true;
  bool tempoLimite = false;

  //unsigned long teste = 0;

  void start(){
    run = true;
    firstTime = false;
    init_time = millis();
    total_time += cur_time;
  }

  void pause(){
    run = false;
  }

  void reset(){
    init_time = 0;
    cur_time = 0;
    total_time = 0;

    milissegundos = 0;
    segundos = 0;
    minutos = 0;
    horas = 0;

    last_milissegundos = 0;
    last_segundos = 0;
    last_minutos = 0;
    last_horas = 0;

    run = false;    
    firstTime = true;
    tempoLimite = false;
    //teste = 0;
  }

  unsigned long totalMilissegundos()
  {
    return total_time + cur_time;
  }

  void atualizar()
  {
    if (run)
    {
      cur_time = (millis() - init_time);//+ teste;
      /*
      if (cur_time > 10000)
      {
        teste = 59000;
      }
      if (cur_time > 70000)
      {
        teste = 3550000;
      }
      if (cur_time > 3610000)
      {
        teste = 3600000*24;
      }
      //*/


      unsigned long totalMs = totalMilissegundos();
      horas = totalMs/3600000;
      milissegundos = (totalMs%1000)/10;
      minutos = totalMs/60000 - 60*horas;
      segundos = totalMs/1000 - 60*minutos - 3600*horas;

      if (horas>=24){
        pause();
        tempoLimite = true;
      }
    }
  }

  bool diffMs()
  {
    return last_milissegundos != milissegundos;
  }

  bool diffSeg()
  {
    return last_segundos != segundos;
  }

  bool diffMin()
  {
    return last_minutos != minutos;
  }

  bool diffHo()
  {
    return last_horas != horas;
  }


  void updateMs()
  {
    if (diffMs()) 
      last_milissegundos = milissegundos; 
  }

  void updateSeg()
  {
    if (diffSeg()) 
      last_segundos = segundos;
  }

  void updateMin()
  {
    if (diffMin()) 
      last_minutos = minutos;
  }

  void updateHo()
  {
    if (diffHo()) 
      last_horas = horas;
  }

  void dump()
  {
    Serial.print(horas);Serial.print(":");Serial.print(minutos);Serial.print(":");Serial.print(segundos);Serial.print(":");Serial.println(milissegundos);
  }

};
Cronometro cronometro;


void managerCronometro()
{

  byte opcaoCronometro = OPCAO_VOLEI_MARCAR;
  byte lastOpcaoCronometro = 100;
  bool sair = false;

  //ligaPlacar();
  oledCronometro();
  int tipo_tecaldo = TIPO_TECLADO_CRONOMETRO_START;

  while(1)
  {
    display.setTextColor(SSD1306_WHITE);  // apagar depois
    display.setTextSize(1);  

    int leituraBotoes = verificaBotoes(tipo_tecaldo);

    if (leituraBotoes == TECLADO_PLACAR_SW)
    {
      if (managerOledConfirmarSaida())
      {
        cronometroPrepararVoltaParaOMenuPrincipal();
        break;
      } 
      else
      {
        oledCronometro();
      }
    }
    else if (leituraBotoes == TECLADO_PLACAR_A_MAIS)
    {
      // INICIAR / PAUSA
      if (cronometro.run)
      {
        cronometro.pause();
        tipo_tecaldo = TIPO_TECLADO_CRONOMETRO_START;
      }  
      else
      {
        cronometro.start();
        tipo_tecaldo = TIPO_TECLADO_CRONOMETRO_PAUSE;
      }

      oledCronometroAMaisPressionado(cronometro.run);
      oledCronometroAMaisApagado(cronometro.run);
    }
    else if (leituraBotoes == TECLADO_PLACAR_A_MENOS)
    {
      cronometro.reset();
      mx.clear();
      turnOffAll();
      oledCronometro();
      oledCronometroAMenosPressionado();
      oledCronometroAMenosApagado();
    }

    if (cronometro.run)
    {
      cronometro.atualizar();
      gerenciadorTelasCronometro();
      cronometro.dump();          
    }

    if (cronometro.tempoLimite)
    {
      managerTempoLimite();
      cronometro.reset();
      mx.clear();
      oledCronometro();
      oledCronometroAMenosPressionado();
      oledCronometroAMenosApagado();
    }

   /*
    if (leituraBotoes == TECLADO_PLACAR_A_MAIS || leituraBotoes == TECLADO_PLACAR_A_MENOS)
    {
      oledCronometro();
    }
    //*/

  }
}


void cronometroPrepararVoltaParaOMenuPrincipal()
{
  cronometro.pause();
  turnOffAll();
  display.clearDisplay();
  OledOpcaoCronometro(false);
  desenhaSetasMenuPrincipal();
  mx.clear();
}


void managerTempoLimite()
{
  tempoLimite();
  while(1)
  {
    if (verificaBotoes(TIPO_TECLADO_TODOS) != TECLADO_PLACAR_NADA)
    {
      break;
    }
  }
}

void tempoLimite()
{
  display.clearDisplay();  

  display.fillRect(0, 0, 128, 64, SSD1306_WHITE);  // Apaga pontos do time B


  display.setTextColor(BLACK);  // Deixa o texto com a cor preta

  display.setTextSize(2);               // Deixa o tamanho das letras em 1

  display.setCursor(10,25);             // Escreve B
  display.print("Limite");
  display.setCursor(5,52);             // Escreve B
  display.print("atingido!");

  display.display();
}

void gerenciadorTelasCronometro()
{
  display.setTextSize(2);
  if ( (cronometro.diffMs() && cronometro.horas == 0) || (cronometro.diffSeg() && cronometro.horas > 0) )
  {
    display.setTextColor(BLACK);
    display.setCursor(92,32);             // Escreve milissegundos / segundos
    display.print( cronometro.horas == 0 ? cronometro.last_milissegundos/10 : cronometro.last_segundos/10 );
    display.print( cronometro.horas == 0 ? cronometro.last_milissegundos%10 : cronometro.last_segundos%10 );
    
    if ((cronometro.diffMs() && cronometro.horas == 0))
      cronometro.updateMs();
    else if (cronometro.diffSeg() && cronometro.horas > 0)
      cronometro.updateSeg();

    display.setTextColor(SSD1306_WHITE);
    display.setCursor(92,32);             // Escreve milissegundos / segundos
    display.print( cronometro.horas == 0 ? cronometro.milissegundos/10 : cronometro.segundos/10 );
    display.print( cronometro.horas == 0 ? cronometro.milissegundos%10 : cronometro.segundos%10 );
    if (cronometro.minutos < 1 && cronometro.horas < 1)
    {
     matrizSegundos();
    }
  }

  if ( (cronometro.diffSeg() && cronometro.horas == 0) || (cronometro.diffMin() && cronometro.horas > 0) )
  {
    display.setTextColor(BLACK);
    display.setCursor(46,32);             // Escreve segundos / minutos
    display.print( cronometro.horas == 0 ? cronometro.last_segundos/10 : cronometro.last_minutos/10 );
    display.print( cronometro.horas == 0 ? cronometro.last_segundos%10 : cronometro.last_minutos%10 );

    if (cronometro.diffSeg() && cronometro.horas == 0)
      cronometro.updateSeg();
    else if (cronometro.diffMin() && cronometro.horas > 0)
      cronometro.updateMin();
  
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(46,32);             // Escreve segundos / minutos
    display.print( cronometro.horas == 0 ? cronometro.segundos/10 : cronometro.minutos/10 );
    display.print( cronometro.horas == 0 ? cronometro.segundos%10 : cronometro.minutos%10 );
    if (cronometro.horas > 0)
    {
     matrizHoras();
    }
  }

  if ( (cronometro.diffMin() && cronometro.horas == 0) || (cronometro.diffHo() && cronometro.horas > 0) )
  {
    display.setTextColor(BLACK);
    display.setCursor(0,32);             // Escreve minutos / horas
    display.print( cronometro.horas == 0 ? cronometro.last_minutos/10 : cronometro.last_horas/10 );
    display.print( cronometro.horas == 0 ? cronometro.last_minutos%10 : cronometro.last_horas%10 );
    
    if (cronometro.diffMin() && cronometro.horas == 0)
      cronometro.updateMin();
    else if (cronometro.diffHo() && cronometro.horas > 0)
      cronometro.updateHo();

    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,32);             // Escreve minutos / horas
    display.print( cronometro.horas == 0 ? cronometro.minutos/10 : cronometro.horas/10 );
    display.print( cronometro.horas == 0 ? cronometro.minutos%10 : cronometro.horas%10 );

    if (cronometro.minutos > 0 && cronometro.horas < 1)
    {
     matrizMinutos();
    }
    if (cronometro.horas > 0)
    {
     matrizHoras();
    }
  }

  if (cronometro.totalMilissegundos() > 3600000 && cronometro.totalMilissegundos() < 3600100)  
  {
    oledCronometro();
    ///*
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(92,32);             // Escreve milissegundos / segundos
    display.print( cronometro.segundos/10 );
    display.print( cronometro.segundos%10 );
    display.setCursor(46,32);             // Escreve segundos / minutos
    display.print( cronometro.minutos/10 );
    display.print( cronometro.minutos%10 );
    display.setCursor(0,32);             // Escreve minutos / horas
    display.print( cronometro.horas/10 );
    display.print( cronometro.horas%10 );//*/
    
  }

  if (cronometro.minutos == 0 && cronometro.horas == 0)
  {
    tempoDigits(cronometro.segundos/10, cronometro.segundos%10, cronometro.milissegundos/10, cronometro.milissegundos%10);
  }
  else if (cronometro.minutos > 0 && cronometro.horas == 0)
  {
    tempoDigits(cronometro.minutos/10, cronometro.minutos%10, cronometro.segundos/10, cronometro.segundos%10);
  }
  else if (cronometro.horas > 0)
  {
    tempoDigits(cronometro.horas/10, cronometro.horas%10, cronometro.minutos/10, cronometro.minutos%10);
  }

  display.setTextColor(SSD1306_WHITE);  // Deixa o texto com a cor branca
  
  display.setCursor(37,29);             // Escreve B
  display.print(":");
  
  display.setCursor(83,29);             // Escreve B
  display.print(":");
  display.display();
}


void tempoDigits(int m, int c, int d, int u)
{
  oneDigit( m, 0, true);
  oneDigit( c, 1, true);
  oneDigit( d, 2, true);
  oneDigit( u, 3, true);
}


void matrizSegundos()
{
  drawArray(digitsMatriz[10] ,'e');
  drawArray(digitsMatriz[11] ,'d');
}

void matrizMinutos()
{
  drawArray(digitsMatriz[12] ,'e');
  drawArray(digitsMatriz[13] ,'d');
}

void matrizHoras()
{
  drawArray(digitsMatriz[14] ,'e');
  drawArray(digitsMatriz[15] ,'d');
}

void oledCronometro()
{
  display.clearDisplay();

  display.fillRect(2,45,47,18, BLACK);

  display.drawBitmap(0, 44,  epd_bitmap_seletor_cronometro, 128, 20, WHITE);

  display.drawBitmap(34, 47,  epd_bitmap_play, 8, 14, WHITE);

  display.drawBitmap(82, 47,  epd_bitmap_zerar, 14, 14, WHITE);

  display.drawBitmap(102, 47,  epd_bitmap_back2, 24, 15, BLACK);
  
  display.setTextColor(SSD1306_WHITE);  // Deixa o texto com a cor branca

  display.setTextSize(1);               // Deixa o tamanho das letras em 1

  display.setCursor(7, 59);             // Escreve B
  display.print("A+");

  display.setCursor(55, 59);             // Escreve A
  display.print("A-");


  display.setTextSize(2);
  if (cronometro.minutos == 0 && cronometro.horas == 0)
  {
    tempoDigits(cronometro.segundos/10, cronometro.segundos%10, cronometro.milissegundos/10, cronometro.milissegundos%10);
    display.setCursor(92,32);             // Escreve milissegundos / segundos
    display.print( cronometro.milissegundos/10 );
    display.print( cronometro.milissegundos%10 );
    display.setCursor(46,32);             // Escreve segundos / minutos
    display.print( cronometro.segundos/10 );
    display.print( cronometro.segundos%10 );
    display.setCursor(0,32);             // Escreve minutos / horas
    display.print( cronometro.minutos/10 );
    display.print( cronometro.minutos%10 );
    matrizSegundos();
  }
  else if (cronometro.minutos > 0 && cronometro.horas == 0)
  {
    tempoDigits(cronometro.minutos/10, cronometro.minutos%10, cronometro.segundos/10, cronometro.segundos%10);
    display.setCursor(92,32);             // Escreve milissegundos / segundos
    display.print( cronometro.milissegundos/10 );
    display.print( cronometro.milissegundos%10 );
    display.setCursor(46,32);             // Escreve segundos / minutos
    display.print( cronometro.segundos/10 );
    display.print( cronometro.segundos%10 );
    display.setCursor(0,32);             // Escreve minutos / horas
    display.print( cronometro.minutos/10 );
    display.print( cronometro.minutos%10 );
    matrizMinutos();
  }
  else if (cronometro.horas > 0)
  {
    tempoDigits(cronometro.horas/10, cronometro.horas%10, cronometro.minutos/10, cronometro.minutos%10);
    display.setCursor(92,32);             // Escreve milissegundos / segundos
    display.print( cronometro.segundos/10 );
    display.print( cronometro.segundos%10 );
    display.setCursor(46,32);             // Escreve segundos / minutos
    display.print( cronometro.minutos/10 );
    display.print( cronometro.minutos%10 );
    display.setCursor(0,32);             // Escreve minutos / horas
    display.print( cronometro.horas/10 );
    display.print( cronometro.horas%10 );
    matrizHoras();
  }

  display.setCursor(37,29);             // Escreve B
  display.print(":");
  
  display.setCursor(83,29);             // Escreve B
  display.print(":");




  display.display();                    // Mostra tudo o que foi definido

  
  //gerenciadorTelasCronometro();
}





void oledCronometroAMaisPressionado(bool run)
{  
  display.fillRect(2,46,47,16, SSD1306_WHITE);

  if (run)
    display.drawBitmap(34, 47,  epd_bitmap_pause, 8, 14, BLACK);
  else
    display.drawBitmap(34, 47,  epd_bitmap_play, 8, 14, BLACK);
  
  display.setTextColor(BLACK);  // Deixa o texto com a cor branca

  display.setTextSize(1);               // Deixa o tamanho das letras em 1

  display.setCursor(7, 59);             // Escreve B
  display.print("A+");

  display.display();                    // Mostra tudo o que foi definido
}


void oledCronometroAMaisApagado(bool run)
{  
  display.fillRect(2,46,47,16, BLACK);

  if (run)
    display.drawBitmap(34, 47,  epd_bitmap_pause, 8, 14, WHITE);
  else
    display.drawBitmap(34, 47,  epd_bitmap_play, 8, 14, WHITE);
  
  display.setTextColor(WHITE);  // Deixa o texto com a cor branca

  display.setTextSize(1);               // Deixa o tamanho das letras em 1

  display.setCursor(7, 59);             // Escreve B
  display.print("A+");

  display.display();                    // Mostra tudo o que foi definido
}



void oledCronometroAMenosPressionado()
{  
  display.fillRect(51,46,47,16, SSD1306_WHITE);

  display.drawBitmap(82, 47,  epd_bitmap_zerar, 14, 14, BLACK);
  
  display.setTextColor(BLACK);  // Deixa o texto com a cor branca

  display.setTextSize(1);               // Deixa o tamanho das letras em 1

  display.setCursor(55, 59);             // Escreve A
  display.print("A-");

  display.display();                    // Mostra tudo o que foi definido
}


void oledCronometroAMenosApagado()
{  
  display.fillRect(51,46,47,16, BLACK);

  display.drawBitmap(82, 47,  epd_bitmap_zerar, 14, 14, SSD1306_WHITE);
  
  display.setTextColor(SSD1306_WHITE);  // Deixa o texto com a cor branca

  display.setTextSize(1);               // Deixa o tamanho das letras em 1

  display.setCursor(55, 59);             // Escreve A
  display.print("A-");

  display.display();                    // Mostra tudo o que foi definido
}
