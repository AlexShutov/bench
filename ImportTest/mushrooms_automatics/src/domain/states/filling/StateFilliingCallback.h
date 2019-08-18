/* 
* StateFilliingCallback.h
*
* Created: 18.08.2019 20:42:55
* Author: Admin
*/


#ifndef __STATEFILLIINGCALLBACK_H__
#define __STATEFILLIINGCALLBACK_H__

#include "../../StateChangeCallbackBase.h"


/************************************************************************/
/* ������ ��������� ���������� ����� ������.  
/************************************************************************/
class StateFilliingCallback :  public StateChangeCallbackBase
{
//variables
public:
protected:
private:

//functions
public:
	StateFilliingCallback(Relay* pRelay,
						  Display* pDisplay,
						  Lights* pLights,
						  ScreenInfo* pScreenInfo);
	virtual ~StateFilliingCallback();
	
	/************************************************************************/
	/* ��� ������ ���������� �������� ���� � ��������� �������� ����������.
	/************************************************************************/
	virtual void onEnterState();
	/************************************************************************/
	/* ��� ��������� ���������� ��������� ����, �� �� �������� �������� 
	/* ����������, �.�. �� ��������� ���� ����� ������������� �������� 
	/* ������������� ������� � ��������.
	/************************************************************************/
	virtual void onExitStateState();
	
	
protected:
private:
	StateFilliingCallback( const StateFilliingCallback &c );
	StateFilliingCallback& operator=( const StateFilliingCallback &c );

}; //StateFilliingCallback

#endif //__STATEFILLIINGCALLBACK_H__
