/* 
* Display.h
*
* Created: 13.08.2019 2:02:37
* Author: Admin
*/


#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <avr/pgmspace.h>

#include <LiquidCrystal_I2C.h>
#include "ScreenInfo.h"

class Display
{
//variables
public:
protected:
private:
	LiquidCrystal_I2C* pLCDScreen;
//functions
public:
	Display();
	~Display();
	
	// �-��������, ����� ���� ��������� �������
 	void init();
	

	void clear();
	
	// �������� ����� �� ������
	void updateScreen(ScreenInfo& info);
	void updateScreen(ScreenInfo* pInfo);
	
	// ������� ��������� �� �����
	void logMessage(int row, String message);
	
protected:
private:
	Display( const Display &c );
	Display& operator=( const Display &c );

}; //Display

#endif //__DISPLAY_H__
