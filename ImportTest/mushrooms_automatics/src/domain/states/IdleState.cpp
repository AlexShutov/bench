/* 
* IdleState.cpp
*
* Created: 18.08.2019 3:39:24
* Author: Admin
*/


#include "IdleState.h"

// default constructor
IdleState::IdleState(DataReader* pReader) : 
	State(pReader)
{
} //IdleState

// default destructor
IdleState::~IdleState()
{
} //~IdleState

bool IdleState::checkStateChangeCondition() {
	return false;
}

bool IdleState::isError() {
	return getPreviousReadings()->mBeginON == true;
}

void IdleState::doOnStateChange() {
	// TODO
}