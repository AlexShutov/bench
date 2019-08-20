/* 
* StateIdleChangeCallback.cpp
*
* Created: 18.08.2019 12:48:34
* Author: Admin
*/

#include "StateIdleCallback.h"

StateIdleCallback::StateIdleCallback(Relay* pRelay,
	Display* pDisplay,
	Lights* pLights,
	ScreenInfo* pScreenInfo)
: StateChangeCallbackBase(pRelay, pDisplay, pLights,pScreenInfo){
}

// default destructor
StateIdleCallback::~StateIdleCallback()
{
} //~StateIdleChangeCallback

void StateIdleCallback::onEnterState() {
	// При входе в ожидание шнек выключен
	getScreenInfo()->schnackOn = false;
	getDisplay()->updateScreen(getScreenInfo());

	getStateIndicators()->setLightIndicator(LIGHT_READY);
}

void StateIdleCallback::onExitStateState() {
}