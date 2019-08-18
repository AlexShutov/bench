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

void State::initState() {
	mpReader->readSchnackData(mPreviousReadings);
}

void State::updateReadings() {
	mPreviousReadings = mCurrReadings;
	mpReader->readSchnackData(mCurrReadings);		
}

PollResult State::pollState() {
	updateReadings();
	if (isError()) {
		return PollResult::ERROR_STATE;
	}
	if (isStateChanged() && checkStateChangeCondition()) {
		if (mpStateChangeCallback) {
			mpStateChangeCallback->onStateChanged();
		}
		return PollResult::STATE_CHANGED;
	}
	return PollResult::KEEP_STATE;
}

bool State::isStateChanged() {
	return *getPreviousReadings() != *getCurrReadings();
}

void State::setStateChangeCallback(OnStateChangeCallback* pCallback) {
	mpStateChangeCallback = pCallback;
}

Data* State::getCurrReadings() {
	return &mPreviousReadings;
}

Data* State::getPreviousReadings() {
	return &mCurrReadings;	
}