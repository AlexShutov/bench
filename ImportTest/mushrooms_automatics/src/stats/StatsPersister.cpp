/* 
* StatsPersister.cpp
*
* Created: 23.08.2019 2:39:25
* Author: Admin
*/


#include "StatsPersister.h"

#define STATS_MEMORY_OFFSET 0

// default constructor
StatsPersister::StatsPersister()
{
} //StatsPersister

// default destructor
StatsPersister::~StatsPersister()
{
} //~StatsPersister

void StatsPersister::readStats(StatsData& statsData) {
	statsData.dayCount = EEPROMReadlong(STATS_MEMORY_OFFSET);
	statsData.totalCount = EEPROMReadlong(STATS_MEMORY_OFFSET + sizeof(long));
}

void StatsPersister::saveStats(StatsData& stats) {
	EEPROMWritelong(STATS_MEMORY_OFFSET, stats.dayCount);
	EEPROMWritelong(STATS_MEMORY_OFFSET + sizeof(long), stats.totalCount);
}

// взял из интернета
void StatsPersister::EEPROMWritelong(int address, long value)
{
	//Decomposition from a long to 4 bytes by using bitshift.
	//One = Most significant -> Four = Least significant byte
	char four = (value & 0xFF);
	char three = ((value >> 8) & 0xFF);
	char two = ((value >> 16) & 0xFF);
	char one = ((value >> 24) & 0xFF);

	//Write the 4 bytes into the eeprom memory.
	EEPROM.write(address, four);
	EEPROM.write(address + 1, three);
	EEPROM.write(address + 2, two);
	EEPROM.write(address + 3, one);
}

long StatsPersister::EEPROMReadlong(long address)
{
	//Read the 4 bytes from the eeprom memory.
	long four = EEPROM.read(address);
	long three = EEPROM.read(address + 1);
	long two = EEPROM.read(address + 2);
	long one = EEPROM.read(address + 3);

	//Return the recomposed long by using bitshift.
	return ((four << 0) & 0xFF) + ((three << 8) & 0xFFFF) + 
		((two << 16) & 0xFFFFFF) + ((one << 24) & 0xFFFFFFFF);
}