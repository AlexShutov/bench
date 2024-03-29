/* 
* ValidationState.h
*
* Created: 18.08.2019 22:28:16
* Author: Admin
*/


#ifndef __VALIDATIONSTATE_H__
#define __VALIDATIONSTATE_H__

#include "Arduino.h"
#include "../../../State.h"

/************************************************************************/
/* ����������� ��������� ������� �����, �� ������� ���������� ����������
/* �������� ������.
/************************************************************************/
class StateUiUpdate : public State
{
//variables
public:
protected:
private:

//functions
public:
	StateUiUpdate(DataReader* pReader);
	virtual ~StateUiUpdate();
	
	/************************************************************************/
	/* �������, ��� �� ��������� � ��������� ���������, ��
	/* ������ ��� ���� �� �����
	/************************************************************************/
	virtual bool isError();
		
	/************************************************************************/
	/* ��������� ������ �������
	/************************************************************************/
	virtual bool checkStateChangeCondition();
	
protected:
private:
	StateUiUpdate( const StateUiUpdate &c );
	StateUiUpdate& operator=( const StateUiUpdate &c );

	virtual bool runAlways();
}; //ValidationState

#endif //__VALIDATIONSTATE_H__
