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
}

void ConveyorFacade::initStateFilling() {
	
}

void ConveyorFacade::initStateEmptying() {
	
}

void ConveyorFacade::pollConveyor() {
	
}