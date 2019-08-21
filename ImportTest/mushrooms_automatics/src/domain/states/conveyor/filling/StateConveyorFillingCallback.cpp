/* 
* StateConveyorFillingCallback.cpp
*
* Created: 21.08.2019 2:48:44
* Author: Admin
*/


#include "StateConveyorFillingCallback.h"

StateConveyorFillingCallback::StateConveyorFillingCallback(Relay* pRelay,
				Display* pDisplay,
		Lights* pLights,
		ScreenInfo* pScreenInfo)
: StateChangeCallbackBase(pRelay, pDisplay, pLights, pScreenInfo){
}

// default destructor
StateConveyorFillingCallback::~StateConveyorFillingCallback()
{
} //~StateConveyorFillingCallback

void StateConveyorFillingCallback::onEnterState() {
	// включаем мотор
	getRelay()->setEnabled(true);
	// обновляем экран
	getScreenInfo()->conveyerOn = true;
	getDisplay()->updateScreen(getScreenInfo());
}

void StateConveyorFillingCallback::onExitStateState() {
}