/* 
* IdleState.h
*
* Created: 18.08.2019 3:39:24
* Author: Admin
*/


#ifndef __IDLESTATE_H__
#define __IDLESTATE_H__

#include "Arduino.h"
#include "../../State.h"

/************************************************************************/
/* ��������� �������, � ������� ��������� ������������ ����� ����� � 
/* ������ ������ ���������, � ������� ���������� ��������� ������� S1, 
/* ����� ���� ��������� ������ ����� � �������� ��������� �����. � ������ 
/* ��������� ��� �� ����� ��������� ������ ������ ������� s2, �.�. ����� 
/* ����� ��������� �� ������ ������ ���������, � ������� ������ s2 �������.
/* ����� ����, �������� �������� ����� � ����� ���� � �������������� 
/* ����������� � ������������ ������� s2. 
/* � ������ ��������� ����� ���� ��������� ������� s1. (������� 0 -> 1). 
/************************************************************************/
class StateIdle : public State
{
//variables
public:
protected:
private:

//functions
public:
	StateIdle(DataReader* pReader);
	virtual ~StateIdle();
	
	// ��������� ��������� ������� s1 (������� 0 -> 1)
 	virtual bool checkStateChangeCondition();
	
	// ������ ����� � ������, ���� ���������� ��������� ���� ����� 1 (�� �������� �������),
	// ������ ���������� ������ (�� �������� �� ������ ����)
	virtual bool isError();
	
	// ���������� ��������� (����� ���������� ��������� �� ������� ���������)
	virtual void doOnStateChange();
	
protected:
private:
	StateIdle( const StateIdle &c );
	StateIdle& operator=( const StateIdle &c );

}; //IdleState

#endif //__IDLESTATE_H__
