/* 
* State.h
*
* Created: 18.08.2019 2:28:46
* Author: Admin
*/


#ifndef __STATE_H__
#define __STATE_H__
/************************************************************************/
/* Моделирует состояние автомата                                        */
/************************************************************************/

#include "../Data.h"
#include "OnStateChangeCallback.h"
#include "../sensor/DataReader.h"
#include "../display/Display.h"

class State
{
//functions
public:
	
	// @param pReader - передаем считыватель данных.
	State(DataReader* pReader);
	
	virtual ~State();
	
	// Устанавливает колбэк выхода из текущего состояния автомата
	void setStateChangeCallback(OnStateChangeCallback* pCallback);
	
	// инициализирует значение состояния, считывая значение как предыдущее
	void initState();
	
	// Обрабатывает состояние - обновляет данные, проверяет их на ошибку. 
	// В случае отсутствия ошибки проверяет предикат перехода. Если переходить не нужно, 
	// то возврашает false. При переходе же происходит вызов колбэка перехода и возвращается true
	bool pollState();
	
	// следующее состояние
	State* getNextState();
	void setNextState(State* pNextState);
	
	// Отдает текущие показания
	Data* getCurrReadings();
	
	// Отдает предыдущие показания
	Data* getPreviousReadings();
	
private:
	// Считывает и обновляет состояние.
	virtual void updateReadings();
	
	// Поменялось ли состояние
	bool isStateChanged();
	
protected:
	
	// Проверяет, нужно ли переходить к следующему состоянию
	virtual bool checkStateChangeCondition() = 0;
	
	/************************************************************************/
	/* Для некоторых состояний (например, валидация), не нужно, чтобы состояния
	/* ввода менялись.
	/************************************************************************/
	virtual bool runAlways(); 
	
private:
	DataReader* mpReader;
	
	// следующее состояние
	State* mpNextState;
	
	// колбэк изменения состояния
	OnStateChangeCallback *mpStateChangeCallback;
	
	// предыдущие показания
	Data mPreviousReadings;
	// текущие показания
	Data mCurrReadings;

}; //State

#endif //__STATE_H__
