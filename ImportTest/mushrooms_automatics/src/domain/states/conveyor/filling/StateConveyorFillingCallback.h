/* 
* StateConveyorFillingCallback.h
*
* Created: 21.08.2019 2:48:45
* Author: Admin
*/


#ifndef __STATECONVEYORFILLINGCALLBACK_H__
#define __STATECONVEYORFILLINGCALLBACK_H__

#include "../../../StateChangeCallbackBase.h"

/************************************************************************/
/* ������ ��������� ���������� �������
/************************************************************************/
class StateConveyorFillingCallback : public StateChangeCallbackBase
{
//variables
public:
protected:
private:

//functions
public:
	StateConveyorFillingCallback(Relay* pRelay,
			Display* pDisplay,
			Lights* pLights,
			ScreenInfo* pScreenInfo);
	
	virtual ~StateConveyorFillingCallback();
	
	/************************************************************************/
	/* �������� �����, ��������� �����
	/************************************************************************/
	virtual void onEnterState();
	
	/************************************************************************/
	/* ��� ������ ��������� �����, ����� ��������� �� ��������� ���������.
	/************************************************************************/
	virtual void onExitStateState();
	
protected:
private:
	StateConveyorFillingCallback( const StateConveyorFillingCallback &c );
	StateConveyorFillingCallback& operator=( const StateConveyorFillingCallback &c );

}; //StateConveyorFillingCallback

#endif //__STATECONVEYORFILLINGCALLBACK_H__
