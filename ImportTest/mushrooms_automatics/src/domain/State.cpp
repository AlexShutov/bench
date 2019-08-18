/* 
* State.cpp
*
* Created: 18.08.2019 2:28:45
* Author: Admin
*/


#include "State.h"

State::State(DataReader* pReader) {
	mpReader = pReader;
}


// virtual destructor
State::~State()
{
} //~State

void State::updateReadings() {
	mPreviousReadings = mCurrReadings;
	mpReader->readSchnackData(mCurrReadings);		
}

bool State::isStateChanged() {
	return *getPreviousReadings() != *getCurrReadings();
}

Data* State::getCurrReadings() {
	return &mPreviousReadings;
}

Data* State::getPreviousReadings() {
	return &mCurrReadings;	
}