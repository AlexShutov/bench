/* 
* StateIdleChangeCallback.h
*
* Created: 18.08.2019 12:48:35
* Author: Admin
*/


#ifndef __STATEIDLECHANGECALLBACK_H__
#define __STATEIDLECHANGECALLBACK_H__

#include "../src/domain/StateChangeCallbackBase.h"

class StateIdleCallback : public StateChangeCallbackBase
{
//variables
public:
protected:
private:

//functions
public:
	StateIdleCallback(Relay* pRelay,
							Display* pDisplay,
							Lights* pLights,
							ScreenInfo* pScreenInfo);
	virtual ~StateIdleCallback();
	
	/************************************************************************/
	/* ���������� ������� �������� ���������� � ������, ����� ��������� � 
	/* ������ ��������, ��������, ��� ������ ��������� ����.
	/* �������� �������������� ��������� � ������� ������, ����� ������������ 
	/* �������� ������.
	/************************************************************************/
	virtual void onEnterState();
	/************************************************************************/
	/* ����� �������� ����������
	/************************************************************************/
	virtual void onExitStateState();

	
protected:
private:
	StateIdleCallback( const StateIdleCallback &c );
	StateIdleCallback& operator=( const StateIdleCallback &c );

}; //StateIdleChangeCallback

#endif //__STATEIDLECHANGECALLBACK_H__
