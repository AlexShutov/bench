/* 
* StateChangeCallbackBase.h
*
* Created: 18.08.2019 12:34:20
* Author: Admin
*/


#ifndef __STATECHANGECALLBACKBASE_H__
#define __STATECHANGECALLBACKBASE_H__

#include "OnStateChangeCallback.h"
#include "../src/relay/Relay.h"
#include "../src/display/Display.h"
#include "../src/lights/Lights.h"

/************************************************************************/
/* —одержит ссылки на подсистемы станка дл€ выполнени€ действий при 
/* переходе между состо€ни€ми
/************************************************************************/
class StateChangeCallbackBase : OnStateChangeCallback
{
//variables
public:
protected:
private:
	
	// –еле переключени€
	Relay* mpRelay;
	// Ёкран
	Display* mpDisplay;
	// »ндикатор состо€ни€
	Lights* mpLights;
	
	
//functions
public:
	StateChangeCallbackBase(Relay* pRelay, Display* pDisplay, Lights* pLights);
	~StateChangeCallbackBase();
	
	// здесь ничего не делаем
	virtual void onStateChanged() = 0;
	
	// аксессоры
	Relay* getRelay() { return mpRelay; }
	Display* getDisplay() { return mpDisplay; }
	Lights* getStateIndicators() { return mpLights; }
	
protected:
private:
	StateChangeCallbackBase( const StateChangeCallbackBase &c );
	StateChangeCallbackBase& operator=( const StateChangeCallbackBase &c );

}; //StateChangeCallbackBase

#endif //__STATECHANGECALLBACKBASE_H__
