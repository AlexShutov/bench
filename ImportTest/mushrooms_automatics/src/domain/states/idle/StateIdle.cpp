/* 
* IdleState.cpp
*
* Created: 18.08.2019 3:39:24
* Author: Admin
*/


#include "StateIdle.h"

// default constructor
StateIdle::StateIdle(DataReader* pReader) : 
	State(pReader)
{
} //IdleState

// default destructor
StateIdle::~StateIdle()
{
} //~IdleState

bool StateIdle::checkStateChangeCondition() {
	bool previouslyOff = !getPreviousReadings()->mBeginON;
	bool nowON = getCurrReadings()->mBeginON;
	
	return previouslyOff && nowON;
}

bool StateIdle::isError() {
	return getPreviousReadings()->mBeginON == true;
}

void StateIdle::doOnStateChange() {
	// TODO
}
