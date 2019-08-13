/* 
* Lights.cpp
*
* Created: 13.08.2019 2:58:03
* Author: Admin
*/

#include <Arduino.h>
#include "Lights.h"

// default constructor
Lights::Lights()
{
} //Lights


void Lights::init() {
	pinMode(PIN_STATE_READY, OUTPUT);
	pinMode(PIN_STATE_ERROR, OUTPUT);
	digitalWrite(PIN_STATE_READY, LOW);
	digitalWrite(PIN_STATE_ERROR, LOW);
}

void Lights::setLightIndicator(State state) {
	switch (state) {
		case LIGHT_READY:
			digitalWrite(PIN_STATE_READY, HIGH);
			digitalWrite(PIN_STATE_ERROR, LOW);
			break;
		case LIGHT_ERROR:
			digitalWrite(PIN_STATE_READY, LOW);
			digitalWrite(PIN_STATE_ERROR, HIGH);
			break;
		default:
			digitalWrite(PIN_STATE_READY, LOW);
			digitalWrite(PIN_STATE_ERROR, LOW);
	}
}

// default destructor
Lights::~Lights()
{
} //~Lights
