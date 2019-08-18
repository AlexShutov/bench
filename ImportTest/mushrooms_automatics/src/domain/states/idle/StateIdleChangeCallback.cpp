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
	//getDisplay()->updateScreen(getScreenInfo());
	//getDisplay()->clear();
	getDisplay()->logMessage(0, String("WAITING"));
	getStateIndicators()->setLightIndicator(LIGHT_READY);
}

void StateIdleChangeCallback::onExitStateState() {
	getStateIndicators()->setLightIndicator(LIGHT_OFF);
}