/* 
* StateValidationCallback.cpp
*
* Created: 18.08.2019 22:45:39
* Author: Admin
*/

#include "StateUiUpdateCallback.h"

StateUiUpdateCallback::StateUiUpdateCallback(Relay* pRelay,
	Display* pDisplay,
	Lights* pLights,
	ScreenInfo* pScreenInfo)
: StateChangeCallbackBase(pRelay, pDisplay, pLights, pScreenInfo){
}

// default destructor
StateUiUpdateCallback::~StateUiUpdateCallback()
{
} //~StateValidationCallback

void StateUiUpdateCallback::onEnterState() {
}

void StateUiUpdateCallback::onExitStateState() {
	// ��������� �������� ������
	getScreenInfo()->countDay++;
	getScreenInfo()->countTotal++;
	getDisplay()->updateScreen(getScreenInfo());
	// TODO: ��������� �������� � ������, ��� ����� ������ ��� ����������.
}