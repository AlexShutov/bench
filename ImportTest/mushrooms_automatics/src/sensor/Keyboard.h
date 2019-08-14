/* 
* Keyboard.h
*
* Created: 14.08.2019 1:49:52
* Author: Admin
*/


#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#include "Keypad.h"

// Клавиатура, используемая для имитирования датчиков в тестовом режиме.
// 1 2
// 3 4
class Keyboard
{
//variables
public:
protected:
private:
	Keypad* mKeypad;
	
//functions
public:

	Keyboard();
	~Keyboard();
	
	// Настраиваем клавиатуру
	void init();
	
	// нажата ли клавиша под номером keyNumber
	bool isPressed(int keyNumber);
	
	// запускает сканирование клавиатуры на множественные нажатия
	void update();
	
protected:

private:
	Keyboard( const Keyboard &c );
	Keyboard& operator=( const Keyboard &c );

}; //Keyboard

#endif //__KEYBOARD_H__
