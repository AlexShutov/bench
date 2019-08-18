/* 
* StateFilliingCallback.cpp
*
* Created: 18.08.2019 20:42:55
* Author: Admin
*/


#include "StateFilliingCallback.h"

StateFilliingCallback::StateFilliingCallback(Relay* pRelay,
		Display* pDisplay,
		Lights* pLights,
		ScreenInfo* pScreenInfo)
: StateChangeCallbackBase(pRelay, pDisplay, pLights,pScreenInfo){
}

// default destructor
StateFilliingCallback::~StateFilliingCallback()
{
} //~StateFilliingCallback

void StateFilliingCallback::onEnterState() {
	getRelay()->setEnabled(true);
	getStateIndicators()->setLightIndicator(LIGHT_OFF);
}

void StateFilliingCallback::onExitStateState() {
	getRelay()->setEnabled(false);
}
