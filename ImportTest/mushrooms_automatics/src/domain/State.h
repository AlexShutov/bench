/* 
* State.h
*
* Created: 18.08.2019 2:28:46
* Author: Admin
*/


#ifndef __STATE_H__
#define __STATE_H__
/************************************************************************/
/* ���������� ��������� ��������                                        */
/************************************************************************/

#include "../Data.h"
#include "OnStateChangeCallback.h"
#include "../sensor/DataReader.h"
#include "../display/Display.h"

class State
{
//functions
public:
	
	// @param pReader - �������� ����������� ������.
	State(DataReader* pReader);
	
	virtual ~State();
	
	// ������������� ������ ������ �� �������� ��������� ��������
	void setStateChangeCallback(OnStateChangeCallback* pCallback);
	
	// �������������� �������� ���������, �������� �������� ��� ����������
	void initState();
	
	// ������������ ��������� - ��������� ������, ��������� �� �� ������. 
	// � ������ ���������� ������ ��������� �������� ��������. ���� ���������� �� �����, 
	// �� ���������� false. ��� �������� �� ���������� ����� ������� �������� � ������������ true
	bool pollState();
	
	// ��������� ���������
	State* getNextState();
	void setNextState(State* pNextState);
	
	// ������ ������� ���������
	Data* getCurrReadings();
	
	// ������ ���������� ���������
	Data* getPreviousReadings();
	
private:
	// ��������� � ��������� ���������.
	virtual void updateReadings();
	
	// ���������� �� ���������
	bool isStateChanged();
	
protected:
	
	// ���������, ����� �� ���������� � ���������� ���������
	virtual bool checkStateChangeCondition() = 0;
	
	/************************************************************************/
	/* ��� ��������� ��������� (��������, ���������), �� �����, ����� ���������
	/* ����� ��������.
	/************************************************************************/
	virtual bool runAlways(); 
	
private:
	DataReader* mpReader;
	
	// ��������� ���������
	State* mpNextState;
	
	// ������ ��������� ���������
	OnStateChangeCallback *mpStateChangeCallback;
	
	// ���������� ���������
	Data mPreviousReadings;
	// ������� ���������
	Data mCurrReadings;

}; //State

#endif //__STATE_H__
