/* 
* StateChangeCallbackBase.cpp
*
* Created: 18.08.2019 12:34:20
* Author: Admin
*/


#include "StateChangeCallbackBase.h"


StateChangeCallbackBase::StateChangeCallbackBase(Relay* pRelay, Display* pDisplay, Lights* pLights) 
: mpRelay(pRelay), mpLights(pLights), mpDisplay(pDisplay) {
} 


StateChangeCallbackBase::~StateChangeCallbackBase()
{
} 
