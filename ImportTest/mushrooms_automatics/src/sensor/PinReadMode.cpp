/* 
* Pin.cpp
*
* Created: 23.08.2019 0:48:01
* Author: Admin
*/


#include "PinReadMode.h"
#include <Arduino.h>

// default constructor
PinReadMode::PinReadMode()
{
} //Pin

// default destructor
PinReadMode::~PinReadMode()
{
} //~Pin


void PinReadMode::init(int pinIndex, bool isStateInverted) {
	mIsStateInverted = isStateInverted;
	mPinIndex = pinIndex;
	
	pinMode(pinIndex, INPUT_PULLUP);
}

bool PinReadMode::isOn() {
	bool isHigh = digitalRead(mPinIndex);
	return mIsStateInverted ? !isHigh : isHigh;
}