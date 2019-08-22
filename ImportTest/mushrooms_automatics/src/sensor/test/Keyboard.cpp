/* 
* Keyboard.cpp
*
* Created: 14.08.2019 1:49:52
* Author: Admin
*/

#include <Keypad.h>
#include "Keyboard.h"


const byte ROWS = 2; //2 строки
const byte COLS = 2; //2 столбца
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
	{'1','2'},
	{'3','4'}
};
byte rowPins[ROWS] = {14, 15}; //ножки выводов для строк клавиатуры
byte colPins[COLS] = {16, 17}; //ножки выводов столбцов клавиатуры


// default constructor
Keyboard::Keyboard()
{
} //Keyboard

// default destructor
Keyboard::~Keyboard()
{
	delete mKeypad;
	mKeypad = 0;
} //~Keyboard

void Keyboard::init() {
	mKeypad = new Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
}

void Keyboard::update() {
	mKeypad->getKeys();
}

bool Keyboard::isPressed(int keyNumber) {
	char keyCode=keyNumber+'0';
	return -1 != mKeypad-> findInList(keyCode);
}