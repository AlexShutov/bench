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
	getDisplay()->logMessage(0, String("idle init readings"));
	// считываем начальные данные
	mpReader->readSchnackData(mPreviousReadings);
	mCurrReadings = mPreviousReadings;
	// раз состояние проинициализировано, то мы на нем находимся, 
	// вызовем действие входа в состояние
	delay(1000);
	if (mpStateChangeCallback) {
		getDisplay()->logMessage(0, String("entering state"));
		mpStateChangeCallback->onEnterState();
	}
}

void State::updateReadings() {
	getDisplay()->logMessage(0, String("Updating data"));
	mPreviousReadings = mCurrReadings;
	mpReader->readSchnackData(mCurrReadings);	
	delay(500);	
}

bool State::pollState() {
	updateReadings();
	if (isStateChanged() && checkStateChangeCondition()) {
		if (mpStateChangeCallback) {
			getDisplay()->logMessage(0, String("Exiting state"));
			mpStateChangeCallback->onExitStateState();
		}
		return true;
	}
	return false;
}

bool State::isStateChanged() {
	boolean changed = *getPreviousReadings() != *getCurrReadings();
	if (changed) {
		getDisplay()->logMessage(0, String("readings changed"));
	} else {
		getDisplay()->logMessage(0, String("readings the same"));
	}
	delay(500);
	return changed;
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