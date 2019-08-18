/* 
* StateValidationCallback.h
*
* Created: 18.08.2019 22:45:39
* Author: Admin
*/


#ifndef __STATEVALIDATIONCALLBACK_H__
#define __STATEVALIDATIONCALLBACK_H__

#include "../../State.h"
#include "../../StateChangeCallbackBase.h"

/************************************************************************/
/* Данная стадия обновляет UI  
/************************************************************************/
class StateUiUpdateCallback : public StateChangeCallbackBase
{
//variables
public:
protected:
private:
	
//functions
public:
	StateUiUpdateCallback(Relay* pRelay,
		Display* pDisplay,
		Lights* pLights,
		ScreenInfo* pScreenInfo);
	
	virtual ~StateUiUpdateCallback();
	
	/************************************************************************/
	/* Не делаем ничего, обновим ui при выходе из стадии.
	/************************************************************************/
	virtual void onEnterState();
	
	virtual void onExitStateState();
	
protected:
private:
	StateUiUpdateCallback( const StateUiUpdateCallback &c );
	StateUiUpdateCallback& operator=( const StateUiUpdateCallback &c );

}; //StateValidationCallback

#endif //__STATEVALIDATIONCALLBACK_H__
