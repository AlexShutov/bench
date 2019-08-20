/* 
* StateConveyorFilling.h
*
* Created: 21.08.2019 2:33:50
* Author: Admin
*/


#ifndef __STATECONVEYORFILLING_H__
#define __STATECONVEYORFILLING_H__

#include "../../../State.h"

/************************************************************************/
/* Состояние наполнения бункера с семечками. При входе в состояние 
/* включаем реле привода, при выходе из состояния - отключаем привод.
/************************************************************************/
class StateConveyorFilling : public State
{
//variables
public:
protected:
private:

//functions
public:
	StateConveyorFilling(DataReader* pReader);
	virtual ~StateConveyorFilling();
	
	/************************************************************************/
	/* Считаем, что ошибки не может быть. Бункер заполнен или нет.
	/************************************************************************/
	virtual bool isError();
	
	/************************************************************************/
	/* Выходим из состояния когда датчик верхнего уровня включен
	/************************************************************************/
	virtual bool checkStateChangeCondition();
	
protected:
private:
	StateConveyorFilling( const StateConveyorFilling &c );
	StateConveyorFilling& operator=( const StateConveyorFilling &c );
	
	/************************************************************************/
	/* Проверяем только текущее состояние заполненности, история не нужна.
	/************************************************************************/
	virtual bool ignorePreviousValue();
	
}; //StateConveyorFilling

#endif //__STATECONVEYORFILLING_H__
