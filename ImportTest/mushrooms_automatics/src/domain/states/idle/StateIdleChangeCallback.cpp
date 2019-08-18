/* 
* StateIdleChangeCallback.cpp
*
* Created: 18.08.2019 12:48:34
* Author: Admin
*/

#include "StateIdleChangeCallback.h"

StateIdleChangeCallback::StateIdleChangeCallback(Relay* pRelay,
	Display* pDisplay,
	Lights* pLights,
	ScreenInfo* pScreenInfo)
: StateChangeCallbackBase(pRelay, pDisplay, pLights,pScreenInfo){
}

// default destructor
StateIdleChangeCallback::~StateIdleChangeCallback()
{
} //~StateIdleChangeCallback

void StateIdleChangeCallback::onEnterState() {
	getDisplay()->clear();
	getDisplay()->updateScreen(getScreenInfo());
	getDisplay()->logMessage(0, String("READY"));
	getStateIndicators()->setLightIndicator(LIGHT_READY);
}

void StateIdleChangeCallback::onExitStateState() {
	delay(1000);
	getDisplay()->logMessage(0, String("WORKING"));
	// Начнет работать мотор, погасим зеленую лампочку
	getStateIndicators()->setLightIndicator(LIGHT_OFF);
}