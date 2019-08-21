/* 
* StateConveyorEmptying.cpp
*
* Created: 21.08.2019 1:51:31
* Author: Admin
*/


#include "StateConveyorEmptying.h"

StateConveyorEmptying::StateConveyorEmptying(DataReader* pReader) :
	State(pReader)
{
}

// default destructor
StateConveyorEmptying::~StateConveyorEmptying()
{
} //~StateConveyorEmptying

bool StateConveyorEmptying::ignorePreviousValue() {
	return true;
}


bool StateConveyorEmptying::isError() {
	return false;
}

bool StateConveyorEmptying::checkStateChangeCondition() {
	return !getCurrReadings()->mBeginON &&
		!getCurrReadings()->mEndON;
}