/* 
* StateIdleChangeCallback.h
*
* Created: 18.08.2019 12:48:35
* Author: Admin
*/


#ifndef __STATEIDLECHANGECALLBACK_H__
#define __STATEIDLECHANGECALLBACK_H__

#include "../src/domain/StateChangeCallbackBase.h"

class StateIdleChangeCallback : public StateChangeCallbackBase
{
//variables
public:
protected:
private:

//functions
public:
	StateIdleChangeCallback(Relay* pRelay, Display* pDisplay, Lights* pLights);
	virtual ~StateIdleChangeCallback();
	
	virtual void onStateChanged();
	
protected:
private:
	StateIdleChangeCallback( const StateIdleChangeCallback &c );
	StateIdleChangeCallback& operator=( const StateIdleChangeCallback &c );

}; //StateIdleChangeCallback

#endif //__STATEIDLECHANGECALLBACK_H__
