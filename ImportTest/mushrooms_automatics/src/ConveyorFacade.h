/* 
* ConveyorFacade.h
*
* Created: 21.08.2019 1:16:49
* Author: Admin
*/


#ifndef __CONVEYORFACADE_H__
#define __CONVEYORFACADE_H__


// Подключение зависимостей подсистем станка
#include "../src/display/screenInfo.h"
#include "../src/display/Display.h"
#include "../src/relay/Relay.h"
#include "../src/sensor/DataReader.h"

// Зависимости состояний автомата, отвечающего за управление лентой конвейера
#include "../src/domain/State.h"
// Состояние опустошения бункера
#include "../src/domain/states/conveyor/emptying/StateConveyorEmptying.h"
#include "../src/domain/states/conveyor/emptying/StateConveyorEmptyingCallback.h"
// состояние наполнения бункера
#include "../src/domain/states/conveyor/filling/StateConveyorFilling.h"

/************************************************************************/
/* Подсистема, отвечающая за управление лентой подачи
/************************************************************************/
class ConveyorFacade
{
//variables
public:
protected:
private:
	// состояние экрана хранится глобально
	ScreenInfo* mpScreenInfo;
	// управление лентой подачи
	Relay* mpConveyor;
	// экран
	Display *mpDisplay;
	// читатель состояния заполненности бункера
	DataReader* mpConveyorReader;
	
	// состояния автомата
	
	// заполнение бункера
	State* mpStateFilling;
	// опустошение бункера
	State* mpStateEmptying;
	StateConveyorEmptyingCallback* mpStateEmptyingCallback;	
	
	
	// указывает на текущее состояние автомата
	State* pCurrState;
	
//functions
public:
	ConveyorFacade(ScreenInfo* pScreenInfo,
			Relay* pConveyor,
			Display *pDisplay,
			DataReader* pConveyorReader);
	
	~ConveyorFacade();

	// инициализирует управление лентой
	void init();
	
	void pollConveyor();
	
protected:
private:
	ConveyorFacade( const ConveyorFacade &c );
	ConveyorFacade& operator=( const ConveyorFacade &c );

	// методы для инициализации отдельных состояний автомата

	void initStateFilling();
	void initStateEmptying();
	
}; //ConveyorFacade

#endif //__CONVEYORFACADE_H__
