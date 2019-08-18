/* 
* StateEmptyBunkerBarrierCallback.h
*
* Created: 19.08.2019 0:21:49
* Author: Admin
*/


#ifndef __STATEEMPTYBUNKERBARRIERCALLBACK_H__
#define __STATEEMPTYBUNKERBARRIERCALLBACK_H__

#include "../../StateChangeCallbackBase.h"

/************************************************************************/
/* Колбэк состояния, проверяющего заполненность бункера.
/* В случае, если бункер заполнен, мы войдем в это состояние и тут же 
/* выйдем из него после первой же проверки. 
/* Когда бункер не заполнен, мы войдем в состояние, будем ждать наполнения 
/* и только потом, когда бункер заполнится, выйдем из этого состояния.
/* Поэтому, чтобы исключить различных проверок, при входе в состояние
/* будем показывать лампочку ошибки, а при выходе гасить лампочки.
/* Следующее состояние после проверки будет ожидание, которое, в свою
/* очередь, снова включит зеленую лампочку готовности.
/* На данной стадии не требуется никаких других обновлений UI.
/************************************************************************/
class StateEmptyBunkerBarrierCallback : public StateChangeCallbackBase
{
//variables
public:
protected:
private:

//functions
public:
	StateEmptyBunkerBarrierCallback(Relay* pRelay,
		Display* pDisplay,
		Lights* pLights,
		ScreenInfo* pScreenInfo);
	
	virtual ~StateEmptyBunkerBarrierCallback();
	
	/************************************************************************/
	/* Показываем лампочку ошибки 
	/************************************************************************/
	virtual void onEnterState();
	/************************************************************************/
	/* Гасим лампочки состояния.
	/************************************************************************/
	virtual void onExitStateState();
	
protected:
private:
	StateEmptyBunkerBarrierCallback( const StateEmptyBunkerBarrierCallback &c );
	StateEmptyBunkerBarrierCallback& operator=( const StateEmptyBunkerBarrierCallback &c );

}; //StateEmptyBunkerBarrierCallback

#endif //__STATEEMPTYBUNKERBARRIERCALLBACK_H__
