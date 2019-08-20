/* 
* StateConveyorEmptying.h
*
* Created: 21.08.2019 1:51:31
* Author: Admin
*/


#ifndef __STATECONVEYOREMPTYING_H__
#define __STATECONVEYOREMPTYING_H__

#include "../../../State.h"

/************************************************************************/
/* Состояние опустошения бункера с семечкой. В это сосотояние входим 
/* всегда, а выходим только когда будут выключен датчик минимального 
/* заполнения бункера S3. 
/************************************************************************/
class StateConveyorEmptying : public State
{
//variables
public:
protected:
private:

//functions
public:
	StateConveyorEmptying(DataReader* pReader);
	virtual ~StateConveyorEmptying();
	
	/************************************************************************/
	/* Считаем, что ошибки не может быть. Бункер заполнен или нет.
	/************************************************************************/
	virtual bool isError();
	
	/************************************************************************/
	/* Выходим из состояния когда датчик нижнего уровня выключен
	/************************************************************************/
	virtual bool checkStateChangeCondition();
	
	
protected:
private:
	StateConveyorEmptying( const StateConveyorEmptying &c );
	StateConveyorEmptying& operator=( const StateConveyorEmptying &c );
	
	/************************************************************************/
	/* Проверяем только текущее состояние заполненности, история не нужна.
	/************************************************************************/
	virtual bool ignorePreviousValue();

}; //StateConveyorEmptying

#endif //__STATECONVEYOREMPTYING_H__
