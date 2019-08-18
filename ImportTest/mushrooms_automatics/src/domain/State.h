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
#include "PollResult.h"
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
	
	// ��������� �� ������ �� ���� ��������� 
	virtual bool isError() = 0;
	
	// �������������� �������� ���������, �������� �������� ��� ����������
	void initState();
	
	// ������������ ��������� - ��������� ������, ��������� �� �� ������. 
	// � ������ ���������� ������ ��������� �������� ��������. ���� ���������� �� �����, 
	// �� ���������� false. ��� �������� �� ���������� ����� ������� �������� � ������������ true
	PollResult pollState();
	
	// ������ ������� ���������
	Data* getCurrReadings();
	// ������ ���������� ���������
	Data* getPreviousReadings();
	
	
private:
	
	// ��������� � ��������� ���������.
	virtual void updateReadings();
	
	// ���������� �� ���������
	bool isStateChanged();
	
private:
	DataReader* mpReader;
	
	// ������ ��������� ���������
	OnStateChangeCallback *mpStateChangeCallback;
	
	// ���������� ���������
	Data mPreviousReadings;
	// ������� ���������
	Data mCurrReadings;

}; //State

#endif //__STATE_H__
