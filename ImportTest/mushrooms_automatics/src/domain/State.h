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
#include "../sensor/DataReader.h"

class State
{
//functions
public:
	
	// @param pReader - передаем считыватель данных.
	State(DataReader* pReader);
	
	virtual ~State();
	
	// Проверяет, нужно ли переходить к следующему состоянию
	virtual bool checkStateChangeCondition() = 0;
	
	// Произошла ли ошибка на этом состоянии 
	virtual bool isError() = 0;
	
	// Действие при переходе на следующее состояние
	virtual void doOnStateChange() = 0;
	
	// Считывает и обновляет состояние.
	virtual void updateReadings();
	
	// Отдает текущие показания
	Data* getCurrReadings();
	// Отдает предыдущие показания
	Data* getPreviousReadings();
	
	bool isStateChanged();
	
private:
	DataReader* mpReader;
	
	// предыдущие показания
	Data mPreviousReadings;
	// текущие показания
	Data mCurrReadings;
	
}; //State

#endif //__STATE_H__
