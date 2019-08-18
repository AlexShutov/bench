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
/* ������ ���������, ������������ ������������� �������.
/* � ������, ���� ������ ��������, �� ������ � ��� ��������� � ��� �� 
/* ������ �� ���� ����� ������ �� ��������. 
/* ����� ������ �� ��������, �� ������ � ���������, ����� ����� ���������� 
/* � ������ �����, ����� ������ ����������, ������ �� ����� ���������.
/* �������, ����� ��������� ��������� ��������, ��� ����� � ���������
/* ����� ���������� �������� ������, � ��� ������ ������ ��������.
/* ��������� ��������� ����� �������� ����� ��������, �������, � ����
/* �������, ����� ������� ������� �������� ����������.
/* �� ������ ������ �� ��������� ������� ������ ���������� UI.
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
	/* ���������� �������� ������ 
	/************************************************************************/
	virtual void onEnterState();
	/************************************************************************/
	/* ����� �������� ���������.
	/************************************************************************/
	virtual void onExitStateState();
	
protected:
private:
	StateEmptyBunkerBarrierCallback( const StateEmptyBunkerBarrierCallback &c );
	StateEmptyBunkerBarrierCallback& operator=( const StateEmptyBunkerBarrierCallback &c );

}; //StateEmptyBunkerBarrierCallback

#endif //__STATEEMPTYBUNKERBARRIERCALLBACK_H__
