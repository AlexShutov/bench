/* 
* StateValidationCallback.cpp
*
* Created: 18.08.2019 22:45:39
* Author: Admin
*/

#include "StateUiUpdateCallback.h"

StateUiUpdateCallback::StateUiUpdateCallback(Relay* pRelay,
	Display* pDisplay,
	StatsViewModel* pStatsViewModel,
	Lights* pLights,
	ScreenInfo* pScreenInfo)
: StateChangeCallbackBase(pRelay, pDisplay, pLights, pScreenInfo) {
	mpStatsViewModel = pStatsViewModel;
}

// default destructor
StateUiUpdateCallback::~StateUiUpdateCallback()
{
} //~StateValidationCallback

void StateUiUpdateCallback::onEnterState() {
}

void StateUiUpdateCallback::onExitStateState() {
	// Обновляем счетчики мешков
	mpStatsViewModel->increment();
	mpStatsViewModel->updateDisplay(getDisplay(), *getScreenInfo());
}