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
/* �������� ������ �� ���������� ������ ��� ���������� �������� ��� 
/* �������� ����� �����������
/************************************************************************/
class StateChangeCallbackBase : OnStateChangeCallback
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
	
	
//functions
public:
	StateChangeCallbackBase(Relay* pRelay, Display* pDisplay, Lights* pLights);
	~StateChangeCallbackBase();
	
	// ����� ������ �� ������
	virtual void onStateChanged() = 0;
	
	// ���������
	Relay* getRelay() { return mpRelay; }
	Display* getDisplay() { return mpDisplay; }
	Lights* getStateIndicators() { return mpLights; }
	
protected:
private:
	StateChangeCallbackBase( const StateChangeCallbackBase &c );
	StateChangeCallbackBase& operator=( const StateChangeCallbackBase &c );

}; //StateChangeCallbackBase

#endif //__STATECHANGECALLBACKBASE_H__
