/* 
* StatsPersister.h
*
* Created: 23.08.2019 2:39:25
* Author: Admin
*/


#ifndef __STATSPERSISTER_H__
#define __STATSPERSISTER_H__

#include <EEPROM.h>
#include "StatsData.h"

/************************************************************************/
/* ��������� �������� � ���������� ������ � ��������� �� �������� 
/************************************************************************/
class StatsPersister
{
//variables
public:
protected:
private:

//functions
public:
	StatsPersister();
	~StatsPersister();
	
	// ��������� ����������
	void readStats(StatsData& statsData);
	// ��������� ���������� � ���������� ������
	void saveStats(StatsData& stats);
	
protected:
private:
	StatsPersister( const StatsPersister &c );
	StatsPersister& operator=( const StatsPersister &c );
	
	void EEPROMWritelong(int address, long value);
	long EEPROMReadlong(long address);
}; //StatsPersister

#endif //__STATSPERSISTER_H__
