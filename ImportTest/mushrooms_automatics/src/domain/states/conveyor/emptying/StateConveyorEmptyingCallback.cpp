/* 
* StateConveyorEmptyingCallback.cpp
*
* Created: 21.08.2019 2:04:07
* Author: Admin
*/


#include "StateConveyorEmptyingCallback.h"

StateConveyorEmptyingCallback::StateConveyorEmptyingCallback(Relay* pRelay,
	Display* pDisplay,
	Lights* pLights,
	ScreenInfo* pScreenInfo)
: StateChangeCallbackBase(pRelay, pDisplay, pLights, pScreenInfo){
}

// default destructor
StateConveyorEmptyingCallback::~StateConveyorEmptyingCallback()
{
} //~StateConveyorEmptyingCallback

void StateConveyorEmptyingCallback::onEnterState() {
	// выключаем мотор
	getRelay()->setEnabled(false);
	// обновляем экран
	getScreenInfo()->conveyerOn = false;
	getDisplay()->updateScreen(getScreenInfo());
}

void StateConveyorEmptyingCallback::onExitStateState() {
}