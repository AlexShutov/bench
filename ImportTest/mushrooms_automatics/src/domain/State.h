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

class State
{
//functions
public:
	
	// @param pReader - �������� ����������� ������.
	State(DataReader* pReader);
	
	virtual ~State();
	
	// ������������� ������ ������ �� �������� ��������� ��������
	void setStateChangeCallback(OnStateChangeCallback* pCallback);
	
	// ���������, ����� �� ���������� � ���������� ���������
	virtual bool checkStateChangeCondition() = 0;
	
	// �������������� �������� ���������, �������� �������� ��� ����������
	void initState();
	
	// ������������ ��������� - ��������� ������, ��������� �� �� ������. 
	// � ������ ���������� ������ ��������� �������� ��������. ���� ���������� �� �����, 
	// �� ���������� false. ��� �������� �� ���������� ����� ������� �������� � ������������ true
	bool pollState();
	
	// ������ ������� ���������
	Data* getCurrReadings();
	// ������ ���������� ���������
	Data* getPreviousReadings();
	
	// ��������� ���������
	State* getNextState() { return mpNextState; }
	void setNextState(State* pNextState);
	
private:
	
	// ��������� � ��������� ���������.
	virtual void updateReadings();
	
	// ���������� �� ���������
	bool isStateChanged();
	
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
