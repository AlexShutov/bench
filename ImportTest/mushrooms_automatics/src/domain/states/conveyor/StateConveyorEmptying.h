/* 
* StateConveyorEmptying.h
*
* Created: 21.08.2019 1:51:31
* Author: Admin
*/


#ifndef __STATECONVEYOREMPTYING_H__
#define __STATECONVEYOREMPTYING_H__

#include "../../../State.h"

/************************************************************************/
/* ��������� ����������� ������� � ��������. � ��� ���������� ������ 
/* ������, � ������� ������ ����� ����� �������� ������ ������������ 
/* ���������� ������� S3. 
/************************************************************************/
class StateConveyorEmptying : public State
{
//variables
public:
protected:
private:

//functions
public:
	StateConveyorEmptying(DataReader* pReader);
	virtual ~StateConveyorEmptying();
	
	/************************************************************************/
	/* �������, ��� ������ �� ����� ����. ������ �������� ��� ���.
	/************************************************************************/
	virtual bool isError();
	
	/************************************************************************/
	/* ������� �� ��������� ����� ������ ������� ������ ��������
	/************************************************************************/
	virtual bool checkStateChangeCondition();
	
	
protected:
private:
	StateConveyorEmptying( const StateConveyorEmptying &c );
	StateConveyorEmptying& operator=( const StateConveyorEmptying &c );
	
	/************************************************************************/
	/* ��������� ������ ������� ��������� �������������, ������� �� �����.
	/************************************************************************/
	virtual bool ignorePreviousValue();

}; //StateConveyorEmptying

#endif //__STATECONVEYOREMPTYING_H__
