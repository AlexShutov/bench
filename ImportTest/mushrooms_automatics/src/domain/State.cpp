/* 
* State.cpp
*
* Created: 18.08.2019 2:28:45
* Author: Admin
*/

#include "Arduino.h"
#include "State.h"

State::State(DataReader* pReader) {
	mpReader = pReader;
}


// virtual destructor
State::~State()
{
} //~State

void State::initState() {
	// считываем начальные данные
	mpReader->readSchnackData(mPreviousReadings);
	mCurrReadings = mPreviousReadings;
	// раз состояние проинициализировано, то мы на нем находимся, 
	// вызовем действие входа в состояние
	if (mpStateChangeCallback) {
		mpStateChangeCallback->onEnterState();
	}
}

void State::updateReadings() {
	mPreviousReadings = mCurrReadings;
	mpReader->readSchnackData(mCurrReadings);	
}

bool State::pollState() {
	updateReadings();
	if (isStateChanged() && checkStateChangeCondition()) {
		if (mpStateChangeCallback) {
			mpStateChangeCallback->onExitStateState();
		}
		return true;
	}
	return false;
}

bool State::isStateChanged() {
	return *getPreviousReadings() != *getCurrReadings();
}

void State::setStateChangeCallback(OnStateChangeCallback* pCallback) {
	mpStateChangeCallback = pCallback;
}

Data* State::getCurrReadings() {
	return &mCurrReadings;
}

Data* State::getPreviousReadings() {
	return &mPreviousReadings;	
}

void State::setNextState(State* pState) {
	mpNextState = pState;
}

State* State::getNextState() {
	return mpNextState;
}