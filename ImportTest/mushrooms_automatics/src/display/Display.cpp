/* 
* Display.cpp
*
* Created: 13.08.2019 2:02:37
* Author: Admin
*/

#include "Display.h"


String STR_ON = String("ON");
String STR_OFF = String("OFF");

// default constructor
Display::Display()
{
} //Display

// default destructor
Display::~Display()
{
	pLCDScreen->clear();
	delete pLCDScreen;
	pLCDScreen = 0;
} //~Display

void Display::init() {
	pLCDScreen = new LiquidCrystal_I2C(0x27, 16, 2);
	pLCDScreen->begin();
	pLCDScreen->backlight();
}

void Display::clear() {
	pLCDScreen->clear();
}

/**
 * Обновляет экран
 */
void Display::updateScreen(ScreenInfo& info) {
	pLCDScreen->clear();
	String line = String("SCH ") +(info.schnackOn ? STR_ON : STR_OFF )+
	String(",CONV ") + (info.conveyerOn ? STR_ON : STR_OFF);
	pLCDScreen->setCursor(0,0);
	pLCDScreen->print(line);
	pLCDScreen->setCursor(0,1);
	line = String("T:") + String(info.countTotal) + String(", D:") +
	String(info.countDay);
	pLCDScreen->print(line);
}

void Display::logMessage(int row, String message) {
	pLCDScreen->setCursor(0, row);
	pLCDScreen->print(message);
}