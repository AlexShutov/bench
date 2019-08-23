/* 
* StatsViewModel.h
*
* Created: 23.08.2019 3:40:55
* Author: Admin
*/


#ifndef __STATSVIEWMODEL_H__
#define __STATSVIEWMODEL_H__

#include "StatsPersister.h"
#include "../src/display/Display.h"

/************************************************************************/
/* ������ ���������� � ��������� UI (a.k.a. ViewModel).
/************************************************************************/
class StatsViewModel
{
//variables
public:
protected:
private:
	
	// ����������� ���������
	StatsPersister mPersister;
	// ���������� ������
	StatsData mStatistics;
	
//functions
public:
	StatsViewModel();
	~StatsViewModel();
	
	//  ��������� ���������� � ���������� � �� ������
	void loadStats();
	
	// ����������� ����� ������
	void  increment();
	
	// ���������� ������� �������
	void resetDayStats();
	
	// ���������� ����� �������
	void resetTotalStats();
	
	// ���������� ����������� �������� �� ������ (������� �� SOLID - S)
	void updateDisplay(Display* pDisplay, ScreenInfo& pDisplayInfo);
	
protected:
private:
	StatsViewModel( const StatsViewModel &c );
	StatsViewModel& operator=( const StatsViewModel &c );

}; //StatsViewModel

#endif //__STATSVIEWMODEL_H__
