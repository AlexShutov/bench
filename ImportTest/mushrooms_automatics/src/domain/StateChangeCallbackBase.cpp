/* 
* StateChangeCallbackBase.cpp
*
* Created: 18.08.2019 12:34:20
* Author: Admin
*/


#include "StateChangeCallbackBase.h"


StateChangeCallbackBase::StateChangeCallbackBase(Relay* pRelay, 
		Display* pDisplay, 
		Lights* pLights,
		ScreenInfo* pScreenInfo) 
:	mpRelay(pRelay), 
	mpLights(pLights), 
	mpDisplay(pDisplay), 
	mpScreenInfo(pScreenInfo) {
} 


StateChangeCallbackBase::~StateChangeCallbackBase()
{
} 
