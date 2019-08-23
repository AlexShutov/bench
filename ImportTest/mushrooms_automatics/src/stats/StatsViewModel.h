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
/* Меняет статистику и обновляет UI (a.k.a. ViewModel).
/************************************************************************/
class StatsViewModel
{
//variables
public:
protected:
private:
	
	// сохранятель состояния
	StatsPersister mPersister;
	// статистика мешков
	StatsData mStatistics;
	
//functions
public:
	StatsViewModel();
	~StatsViewModel();
	
	//  загружает статистику и показывает её на экране
	void loadStats();
	
	// увеличивает число мешков
	void  increment();
	
	// сбрасывает дневной счетчик
	void resetDayStats();
	
	// сбрасывает общий счетчик
	void resetTotalStats();
	
	// показывает обновленные счетчики на экране (немного не SOLID - S)
	void updateDisplay(Display* pDisplay, ScreenInfo& pDisplayInfo);
	
protected:
private:
	StatsViewModel( const StatsViewModel &c );
	StatsViewModel& operator=( const StatsViewModel &c );

}; //StatsViewModel

#endif //__STATSVIEWMODEL_H__
