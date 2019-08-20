/* 
* StateConveyorFilling.cpp
*
* Created: 21.08.2019 2:33:50
* Author: Admin
*/


#include "StateConveyorFilling.h"

StateConveyorFilling::StateConveyorFilling(DataReader* pReader) :
	State(pReader)
{
}

// default destructor
StateConveyorFilling::~StateConveyorFilling()
{
} //~StateConveyorFilling


bool StateConveyorFilling::ignorePreviousValue() {
	return true;
}

bool StateConveyorFilling::isError() {
	return false;
}

bool StateConveyorFilling::checkStateChangeCondition() {
	return getCurrReadings()->mEndON;
}