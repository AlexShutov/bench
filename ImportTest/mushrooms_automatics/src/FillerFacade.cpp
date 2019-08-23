/* 
* FillerFacade.cpp
*
* Created: 19.08.2019 1:03:03
* Author: Admin
*/


#include "FillerFacade.h"

FillerFacade::FillerFacade(ScreenInfo* pScreenInfo,
	Relay* pSchnack,		
	Display *pDisplay,
	StatsViewModel* pStatsViewModel,
	Lights *pLights,
	DataReader* pSchnackReader,
	DataReader* pConveyorReader)
{
	mpScreenInfo = pScreenInfo;
	mpSchnack = pSchnack;
	mpDisplay = pDisplay;
	mpStatsViewModel = pStatsViewModel;
	mpLights = pLights;
	mpSchnackReader = pSchnackReader;
	mpConveyorReader = pConveyorReader;
} 

FillerFacade::~FillerFacade()
{
} //~FillerFacade

void FillerFacade::initStateIdle() {
	pStateIdle = new StateIdle(mpSchnackReader);
	pCallbackIdle = new StateIdleCallback(mpSchnack, mpDisplay, 
		mpLights, mpScreenInfo);
	pStateIdle->setStateChangeCallback(pCallbackIdle);
}

void FillerFacade::initStateFilling() {
	pStateFilling = new StateFilling(mpSchnackReader);
	pCallbackFilling = new StateFilliingCallback(mpSchnack, mpDisplay,
		mpLights, mpScreenInfo);
	pStateFilling->setStateChangeCallback(pCallbackFilling);
}

void FillerFacade::initStateUiUpdate() {
	pStateUiUpdate = new StateUiUpdate(mpSchnackReader);
	pCallbackUiUpdate = new StateUiUpdateCallback(mpSchnack, mpDisplay,
		mpStatsViewModel, mpLights, mpScreenInfo);
	pStateUiUpdate->setStateChangeCallback(pCallbackUiUpdate);
}

void FillerFacade::initStateEmptyBunkerBarrier() {
	pStateEmptyBunkerBarrier = new StateEmptyBunkerBarrier(mpConveyorReader);
	pStateEmptyBunkerCallback = new StateEmptyBunkerBarrierCallback(mpSchnack, 
		mpDisplay, mpLights, mpScreenInfo);
	pStateEmptyBunkerBarrier->setStateChangeCallback(pStateEmptyBunkerCallback);
}

void FillerFacade::init() {
	initStateIdle();
	initStateFilling();
	initStateUiUpdate();
	initStateEmptyBunkerBarrier();
	
	// за ожиданием следует наполнение
	pStateIdle->setNextState(pStateFilling);
	// за наполнением следует обновление UI
	pStateFilling->setNextState(pStateUiUpdate);
	// за обновлением Ui следует проверка наполненности бункера
	pStateUiUpdate->setNextState(pStateEmptyBunkerBarrier);
	// После проверки наполненности бункера идет ожидание
	pStateEmptyBunkerBarrier->setNextState(pStateIdle);
	
	// начнем с ожидания наполнения бункера)
	pCurrState = pStateEmptyBunkerBarrier;
	// инициализируем состояние
	pCurrState->initState();
}

void FillerFacade::pollSchnack() {
	if (pCurrState->pollState()) {
		pCurrState = pCurrState->getNextState();
		pCurrState->initState();
	}
}