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
/* �������� ������ �� ���������� ������ ��� ���������� �������� ��� 
/* �������� ����� �����������
/************************************************************************/
class StateChangeCallbackBase : public OnStateChangeCallback
{
//variables
public:
protected:
private:
	
	// ���� ������������
	Relay* mpRelay;
	// �����
	Display* mpDisplay;
	// ��������� ���������
	Lights* mpLights;
	// ��������� ������ �������� ��������, �.�., ��������, ������ ����� ������� �� ����� ���
	ScreenInfo* mpScreenInfo;
	
//functions
public:
	StateChangeCallbackBase(Relay* pRelay, 
							Display* pDisplay, 
							Lights* pLights,
							ScreenInfo* pScreenInfo);
	virtual ~StateChangeCallbackBase();
	
	// ����� ������ �� ������
	virtual void onExitStateState() = 0;
	virtual void onEnterState() = 0;
	
	// ���������
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
