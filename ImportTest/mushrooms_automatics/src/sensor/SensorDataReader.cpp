/* 
* SensorDataReader.cpp
*
* Created: 23.08.2019 1:57:54
* Author: Admin
*/


#include "SensorDataReader.h"

SensorDataReader::SensorDataReader(int beginPin, int endPin) {
	mPinNoBegin = beginPin;
	mPinNoEnd = endPin;
}

// default destructor
SensorDataReader::~SensorDataReader()
{
} //~SensorDataReader

void SensorDataReader::init() {
	mPinBegin.init(mPinNoBegin, SENSOR_PINS_INVERTED);
	mPinEnd.init(mPinNoEnd, SENSOR_PINS_INVERTED);
}

void SensorDataReader::readData(Data& data) {
	data.mBeginON = mPinBegin.isOn();
	data.mEndON = mPinBegin.isOn();
}
