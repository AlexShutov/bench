/* 
* StateEmptyBunkerBarrierCallback.cpp
*
* Created: 19.08.2019 0:21:49
* Author: Admin
*/


#include "StateEmptyBunkerBarrierCallback.h"

StateEmptyBunkerBarrierCallback::StateEmptyBunkerBarrierCallback(Relay* pRelay,
	Display* pDisplay,
	Lights* pLights,
	ScreenInfo* pScreenInfo)
: StateChangeCallbackBase(pRelay, pDisplay, pLights, pScreenInfo){
}


// default destructor
StateEmptyBunkerBarrierCallback::~StateEmptyBunkerBarrierCallback()
{
} //~StateEmptyBunkerBarrierCallback

void StateEmptyBunkerBarrierCallback::onEnterState() {
	getStateIndicators()->setLightIndicator(LIGHT_ERROR);
}

void StateEmptyBunkerBarrierCallback::onExitStateState() {
	getStateIndicators()->setLightIndicator(LIGHT_OFF);
}