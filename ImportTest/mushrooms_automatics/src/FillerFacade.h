/* 
* FillerFacade.h
*
* Created: 19.08.2019 1:03:03
* Author: Admin
*/


#ifndef __FILLERFACADE_H__
#define __FILLERFACADE_H__

// ѕодключение зависимостей подсистем станка
#include "../src/display/screenInfo.h"
#include "../src/display/Display.h"
#include "../src/lights/Lights.h"
#include "../src/relay/Relay.h"
#include "../src/sensor/DataReader.h"

// ѕодключение зависимостей состо€ний автомата, отвечающего за наполнение мешков
#include "../src/domain/State.h"
// ожидание
#include "../src/domain/states/idle/StateIdle.h"
#include "../src/domain/states/idle/StateIdleCallback.h"
// наполнение
#include "../src/domain/states/filling/StateFilling.h"
#include "../src/domain/states/filling/StateFilliingCallback.h"
// ќбновление ui
#include "../src/domain/states/uiUpdate/StateUiUpdate.h"
#include "../src/domain/states/uiUpdate/StateUiUpdateCallback.h"
// ќжидание заполненности бункера
#include "../src/domain/states/emptyBunkerBarrier/StateEmptyBunkerBarrier.h"
#include "../src/domain/states/emptyBunkerBarrier/StateEmptyBunkerBarrierCallback.h"

/************************************************************************/
/* ѕодсистема, отвечающа€ за управление наполнением мешков.
/************************************************************************/
class FillerFacade
{
//variables
public:
protected:
private:
	// состо€ние экрана хранитс€ глобально
	ScreenInfo* mpScreenInfo;
	// управление шнеком
	Relay* mpSchnack;
	// экран
	Display *mpDisplay;
	// индикаторы состо€ни€
	Lights *mpLights;
	// читатели состо€ний шнека и конвейера (дл€ ожидани€ заполнени€)
	DataReader* mpSchnackReader;
	DataReader* mpConveyorReader;
	
	// состо€ни€ автомата
	
	// состо€ние готовности
	State* pStateIdle;
	StateIdleCallback* pCallbackIdle;
	// состо€ние наполнени€
	State* pStateFilling;
	StateFilliingCallback* pCallbackFilling;
	// состо€ние обновлени€ UI
	State* pStateUiUpdate;
	StateUiUpdateCallback* pCallbackUiUpdate;
	// —осто€ние ожидани€ заполненности бункера
	State* pStateEmptyBunkerBarrier;
	StateEmptyBunkerBarrierCallback* pStateEmptyBunkerCallback;

	// указывает на текущее состо€ние автомата
	State* pCurrState;
	
	
//functions
public:
	/************************************************************************/
	/*  можно сделать билдер, но будет просто лишний код
	/************************************************************************/
	FillerFacade(ScreenInfo* pScreenInfo, 
			Relay* pSchnack,
			Display *pDisplay,
			Lights *pLights,
			DataReader* pSchnackReader,
			DataReader* pConveyorReader);
			
	/************************************************************************/
	/* ‘асад принимает ссылки на глобальные обьекты, не надо их  удал€ть
	/************************************************************************/
	~FillerFacade();
	
	//  инициализируем автомат
	void init();
	
	// опрашиваем состо€ние
	void pollSchnack();
	
protected:
private:
	FillerFacade( const FillerFacade &c );
	FillerFacade& operator=( const FillerFacade &c );
	
	// методы дл€ инициализации отдельных состо€ний автомата
	
	void initStateIdle();
	void initStateFilling();
	void initStateUiUpdate();
	void initStateEmptyBunkerBarrier();
	
}; //FillerFacade

#endif //__FILLERFACADE_H__
