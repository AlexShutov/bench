/* 
* SchnackTestReader.cpp
*
* Created: 14.08.2019 2:53:05
* Author: Admin
*/


#include "TestDataReader.h"

// default constructor
TestDataReader::TestDataReader(Keyboard* pKeyboard, int keyBegin, int keyEnd) {
	mpKeyboard = pKeyboard;
	mKeyBegin = keyBegin;
	mKeyEnd = keyEnd;
} //SchnackTestReader

// default destructor
TestDataReader::~TestDataReader(){
	mpKeyboard = 0;
} //~SchnackTestReader


void TestDataReader::init() {
	// ѕусть клавиатура уже проинициализирована
}

void TestDataReader::readData(Data& data) {
	mpKeyboard->update();
	data.mBeginON = mpKeyboard->isPressed(mKeyBegin);
	data.mEndON = mpKeyboard->isPressed(mKeyEnd);
}