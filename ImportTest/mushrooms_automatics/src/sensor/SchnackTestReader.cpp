/* 
* SchnackTestReader.cpp
*
* Created: 14.08.2019 2:53:05
* Author: Admin
*/


#include "SchnackTestReader.h"

// default constructor
SchnackTestReader::SchnackTestReader(Keyboard* pKeyboard) {
	mpKeyboard = pKeyboard;
} //SchnackTestReader

// default destructor
SchnackTestReader::~SchnackTestReader(){
	mpKeyboard = 0;
} //~SchnackTestReader


void SchnackTestReader::init() {
	// ѕусть клавиатура уже проинициализирована
}

void SchnackTestReader::readSchnackData(Data& data) {
	mpKeyboard->update();
	data.mBeginON = mpKeyboard->isPressed(4);
	data.mEndON = mpKeyboard->isPressed(3);
}