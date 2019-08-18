/* 
* State.h
*
* Created: 14.08.2019 4:28:05
* Author: Admin
*/


#ifndef __STATE_H__
#define __STATE_H__

#include "sensor/Data.h"

class State
{
//variables
public:
protected:
	
	Data mPreviousData;
	Data mCurrData;
	State* pNextState;
	
private:

//functions
public:
	State();
	~State();
	
	virtual void doOnProceed() = 0;
	
	// считывает первоначальное значение
	void init();
	// Определяет, поменялось ли состояние
	bool stateChanged();
	
	// определяет, нужно ли переходить к следующему состоянию
	bool predicate();
	
	// устанавливает следующее состояние
	void setNextState(State* pState);
	
protected:

	virtual void updateData(Data& rData) = 0;
	
private:
	State( const State &c );
	State& operator=( const State &c );

}; //State

#endif //__STATE_H__
