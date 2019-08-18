/* 
* ValidationState.cpp
*
* Created: 18.08.2019 22:28:16
* Author: Admin
*/


#include "StateUiUpdate.h"

StateUiUpdate::StateUiUpdate(DataReader* pReader) :
	State(pReader)
{
}

// default destructor
StateUiUpdate::~StateUiUpdate()
{
} //~ValidationState

// для обновления UI не нужна проверка изменения данных
bool StateUiUpdate::runAlways() {
	return true;
}

bool StateUiUpdate::isError() {
	return false;
}

bool StateUiUpdate::checkStateChangeCondition() {
	return true;
}