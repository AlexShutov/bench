/* 
* StatsViewModel.cpp
*
* Created: 23.08.2019 3:40:55
* Author: Admin
*/


#include "StatsViewModel.h"

// default constructor
StatsViewModel::StatsViewModel()
{
} //StatsViewModel

// default destructor
StatsViewModel::~StatsViewModel()
{
} //~StatsViewModel

void StatsViewModel::loadStats() {
	mPersister.readStats(mStatistics);
}

void StatsViewModel::increment() {
	mStatistics.dayCount++;
	mStatistics.totalCount++;
	mPersister.saveStats(mStatistics);
}

void StatsViewModel::resetDayStats() {
	mStatistics.dayCount = 0;
	mPersister.saveStats(mStatistics);
}

void StatsViewModel::resetTotalStats() {
	mStatistics.dayCount = 0;
	mStatistics.totalCount = 0;
	mPersister.saveStats(mStatistics);
}

void StatsViewModel::updateDisplay(Display* pDisplay, ScreenInfo& pDisplayInfo) {
	pDisplayInfo.countDay = mStatistics.dayCount;
	pDisplayInfo.countTotal = mStatistics.totalCount;
	pDisplay->updateScreen(pDisplayInfo);
}