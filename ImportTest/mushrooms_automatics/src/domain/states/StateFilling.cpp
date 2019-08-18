/* 
* StateFilling.cpp
*
* Created: 18.08.2019 4:51:16
* Author: Admin
*/

#include "StateFilling.h"

// default constructor
StateFilling::StateFilling(DataReader* pReader)
	: State(pReader)
{
} //StateFilling

// default destructor
StateFilling::~StateFilling()
{
} //~StateFilling

bool StateFilling::checkStateChangeCondition() {
	return getCurrReadings()->mEndON;
}