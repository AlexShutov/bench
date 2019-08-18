/* 
* StateChangeCallbackBase.h
*
* Created: 18.08.2019 12:34:20
* Author: Admin
*/


#ifndef __STATECHANGECALLBACKBASE_H__
#define __STATECHANGECALLBACKBASE_H__

#include "Arduino.h"
#include "OnStateChangeCallback.h"
#include "../src/relay/Relay.h"
#include "../src/display/Display.h"
#include "../src/lights/Lights.h"

/************************************************************************/
/* Содержит ссылки на подсистемы станка для выполнения действий при 
/* переходе между состояниями
/************************************************************************/
class StateChangeCallbackBase : public OnStateChangeCallback
{
//variables
public:
protected:
private:
	
	// Реле переключения
	Relay* mpRelay;
	// Экран
	Display* mpDisplay;
	// Индикатор состояния
	Lights* mpLights;
	// состояние экрана хранится отдельно, т.к., например, колбэк может вывести на экран лок
	ScreenInfo* mpScreenInfo;
	
//functions
public:
	StateChangeCallbackBase(Relay* pRelay, 
							Display* pDisplay, 
							Lights* pLights,
							ScreenInfo* pScreenInfo);
	virtual ~StateChangeCallbackBase();
	
	// здесь ничего не делаем
	virtual void onExitStateState() = 0;
	virtual void onEnterState() = 0;
	
	// аксессоры
	Relay* getRelay() { return mpRelay; }
	Display* getDisplay() { return mpDisplay; }
	Lights* getStateIndicators() { return mpLights; }
	ScreenInfo* getScreenInfo() { return mpScreenInfo;}
	
protected:
private:
	StateChangeCallbackBase( const StateChangeCallbackBase &c );
	StateChangeCallbackBase& operator=( const StateChangeCallbackBase &c );

}; //StateChangeCallbackBase

#endif //__STATECHANGECALLBACKBASE_H__
