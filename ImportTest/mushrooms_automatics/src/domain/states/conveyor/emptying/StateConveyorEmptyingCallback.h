/* 
* StateConveyorEmptyingCallback.h
*
* Created: 21.08.2019 2:04:07
* Author: Admin
*/


#ifndef __STATECONVEYOREMPTYINGCALLBACK_H__
#define __STATECONVEYOREMPTYINGCALLBACK_H__

#include "../../../StateChangeCallbackBase.h"

/************************************************************************/
/* ������ ��������� ����������� �������
/************************************************************************/
class StateConveyorEmptyingCallback : public StateChangeCallbackBase
{
//variables
public:
protected:
private:

//functions
public:
	StateConveyorEmptyingCallback(Relay* pRelay,
			Display* pDisplay,
			Lights* pLights,
			ScreenInfo* pScreenInfo);
	
	virtual ~StateConveyorEmptyingCallback();
	
	/************************************************************************/
	/* ��������� ������ �����, ��������� �����
	/************************************************************************/
	virtual void onEnterState();
	
	/************************************************************************/
	/* ����� ��� ��������, ����� ��������, ������ �� ������
	/************************************************************************/
	virtual void onExitStateState();
	
protected:
private:
	StateConveyorEmptyingCallback( const StateConveyorEmptyingCallback &c );
	StateConveyorEmptyingCallback& operator=( const StateConveyorEmptyingCallback &c );

}; //StateConveyorEmptyingCallback

#endif //__STATECONVEYOREMPTYINGCALLBACK_H__
