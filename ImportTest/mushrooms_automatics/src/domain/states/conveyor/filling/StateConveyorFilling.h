/* 
* StateConveyorFilling.h
*
* Created: 21.08.2019 2:33:50
* Author: Admin
*/


#ifndef __STATECONVEYORFILLING_H__
#define __STATECONVEYORFILLING_H__

#include "../../../State.h"

/************************************************************************/
/* ��������� ���������� ������� � ���������. ��� ����� � ��������� 
/* �������� ���� �������, ��� ������ �� ��������� - ��������� ������.
/************************************************************************/
class StateConveyorFilling : public State
{
//variables
public:
protected:
private:

//functions
public:
	StateConveyorFilling(DataReader* pReader);
	virtual ~StateConveyorFilling();
	
	/************************************************************************/
	/* �������, ��� ������ �� ����� ����. ������ �������� ��� ���.
	/************************************************************************/
	virtual bool isError();
	
	/************************************************************************/
	/* ������� �� ��������� ����� ������ �������� ������ �������
	/************************************************************************/
	virtual bool checkStateChangeCondition();
	
protected:
private:
	StateConveyorFilling( const StateConveyorFilling &c );
	StateConveyorFilling& operator=( const StateConveyorFilling &c );
	
	/************************************************************************/
	/* ��������� ������ ������� ��������� �������������, ������� �� �����.
	/************************************************************************/
	virtual bool ignorePreviousValue();
	
}; //StateConveyorFilling

#endif //__STATECONVEYORFILLING_H__
