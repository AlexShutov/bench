/* 
* ConveyorFacade.cpp
*
* Created: 21.08.2019 1:16:49
* Author: Admin
*/


#include "ConveyorFacade.h"

ConveyorFacade::ConveyorFacade(ScreenInfo* pScreenInfo,
		Relay* pConveyor,
		Display *pDisplay,
		DataReader* pConveyorReader)
{
	mpScreenInfo = pScreenInfo;
	mpConveyor = pConveyor;
	mpDisplay = pDisplay;
	mpConveyorReader = pConveyorReader;
}

// default destructor
ConveyorFacade::~ConveyorFacade()
{
} //~ConveyorFacade

void ConveyorFacade::init() {
	initStateFilling();
	initStateEmptying();

	mpStateEmptying->setNextState(mpStateFilling);
	mpStateFilling->setNextState(mpStateEmptying);
	// всегда начинаем с состояния опустошения, чтобы учесть случай,
	// когда при запуске в бункере еще есть семечка.
	pCurrState = mpStateEmptying;
	// инициализируем состояние
	pCurrState->initState();
}

void ConveyorFacade::initStateFilling() {
	mpStateFilling = new StateConveyorFilling(mpConveyorReader);
	mpStateFillingCallback = new StateConveyorFillingCallback(mpConveyor,
		mpDisplay, nullptr, mpScreenInfo);
	mpStateFilling->setStateChangeCallback(mpStateFillingCallback);
}

void ConveyorFacade::initStateEmptying() {
	mpStateEmptying = new StateConveyorEmptying(mpConveyorReader);
	// лента не может изменять индикаторы, их меняет только привод шнека
	mpStateEmptyingCallback = new StateConveyorEmptyingCallback(mpConveyor, 
		mpDisplay, nullptr, mpScreenInfo);
	mpStateEmptying->setStateChangeCallback(mpStateEmptyingCallback);
}

void ConveyorFacade::pollConveyor() {
	// TODO:  можно вынести в базовый класс, пока не заморачиваюсь
	if (pCurrState->pollState()) {
		pCurrState = pCurrState->getNextState();
		pCurrState->initState();
	}
}