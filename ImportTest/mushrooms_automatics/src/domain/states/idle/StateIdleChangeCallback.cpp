/* 
* StateIdleChangeCallback.cpp
*
* Created: 18.08.2019 12:48:34
* Author: Admin
*/


#include "StateIdleChangeCallback.h"

StateIdleChangeCallback::StateIdleChangeCallback(Relay* pRelay, Display* pDisplay, Lights* pLights) 
: StateChangeCallbackBase(pRelay, pDisplay, pLights){
}

// default destructor
StateIdleChangeCallback::~StateIdleChangeCallback()
{
} //~StateIdleChangeCallback

void StateIdleChangeCallback::onStateChanged() {
	// TODO
}