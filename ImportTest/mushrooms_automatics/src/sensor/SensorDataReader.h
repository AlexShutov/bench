/* 
* SensorDataReader.h
*
* Created: 23.08.2019 1:57:54
* Author: Admin
*/


#ifndef __SENSORDATAREADER_H__
#define __SENSORDATAREADER_H__

#include "DataReader.h"
#include "PinReadMode.h"

#define SENSOR_PINS_INVERTED true

class SensorDataReader : public DataReader
{
//variables
public:
protected:
private:
	PinReadMode mPinBegin;
	PinReadMode mPinEnd;
	
	int mPinNoBegin;
	int mPinNoEnd;
//functions
public:
	// принимает ножки сенсоров начала и конца
	SensorDataReader(int beginPin, int endPin);
	~SensorDataReader();
	
	virtual void init();
	
	virtual void readData(Data& data);
	
protected:
private:
	SensorDataReader( const SensorDataReader &c );
	SensorDataReader& operator=( const SensorDataReader &c );

}; //SensorDataReader

#endif //__SENSORDATAREADER_H__
