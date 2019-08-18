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
#include "../sensor/DataReader.h"

class State
{
//functions
public:
	
	// @param pReader - �������� ����������� ������.
	State(DataReader* pReader);
	
	virtual ~State();
	
	// ���������, ����� �� ���������� � ���������� ���������
	virtual bool checkStateChangeCondition() = 0;
	
	// ��������� �� ������ �� ���� ��������� 
	virtual bool isError() = 0;
	
	// �������� ��� �������� �� ��������� ���������
	virtual void doOnStateChange() = 0;
	
	// ��������� � ��������� ���������.
	virtual void updateReadings();
	
	// ������ ������� ���������
	Data* getCurrReadings();
	// ������ ���������� ���������
	Data* getPreviousReadings();
	
	bool isStateChanged();
	
private:
	DataReader* mpReader;
	
	// ���������� ���������
	Data mPreviousReadings;
	// ������� ���������
	Data mCurrReadings;
	
}; //State

#endif //__STATE_H__
