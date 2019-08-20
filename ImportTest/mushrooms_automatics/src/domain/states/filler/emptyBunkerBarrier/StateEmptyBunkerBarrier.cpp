/* 
* EmptyBunkerBarrier.cpp
*
* Created: 19.08.2019 0:13:48
* Author: Admin
*/


#include "StateEmptyBunkerBarrier.h"

StateEmptyBunkerBarrier::StateEmptyBunkerBarrier(DataReader* pReader) :
	State(pReader)
{
}

// default destructor
StateEmptyBunkerBarrier::~StateEmptyBunkerBarrier()
{
} //~EmptyBunkerBarrier

bool StateEmptyBunkerBarrier::ignorePreviousValue() {
	return true;
}

bool StateEmptyBunkerBarrier::isError() {
	return false;
}

bool StateEmptyBunkerBarrier::checkStateChangeCondition() {
	return getCurrReadings()->mBeginON || getCurrReadings()->mEndON;
}