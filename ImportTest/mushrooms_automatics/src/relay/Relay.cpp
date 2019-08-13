/* 
* Relay.cpp
*
* Created: 14.08.2019 0:31:23
* Author: Admin
*/

#include <Arduino.h>
#include "Relay.h"

Relay::Relay(int pinNo) : Relay(pinNo, false) {
}

Relay::Relay(int pinNo, bool isInverted) {
	mPinNo = pinNo;
	mIsInverted = isInverted;
}

void Relay::init() {
	pinMode(mPinNo, OUTPUT);
	digitalWrite(mPinNo, getLevel(false));
}

void Relay::setEnabled(bool isEnabled) {
	digitalWrite(mPinNo, getLevel(isEnabled));
	mIsEnabled = isEnabled;
}

bool Relay::isEnabled() {
	return mIsEnabled;
}

bool Relay::getLevel(bool isOn) {
	if (mIsInverted) {
		return isOn ? LOW : HIGH;
	} else {
		return isOn ? HIGH : LOW;
	}
}


// default destructor
Relay::~Relay()
{
} //~Relay
