/* 
* SchnackTestReader.h
*
* Created: 14.08.2019 2:53:05
* Author: Admin
*/


#ifndef __SCHNACKTESTREADER_H__
#define __SCHNACKTESTREADER_H__

#define SCHNACK_KEY_S1 = 4
#define SCHNACK_KEY_S2 = 3;

#include "Keyboard.h"
#include "DataReader.h"

// Имитирует считывание показания датчиков при помощи клавиатуры.
// Датчики шнека имитируются клавишами 4 (s1) и 3 (s2)
class TestDataReader : public DataReader 
{
//variables
public:
protected:
private:
	Keyboard* mpKeyboard;
	int mKeyBegin;
	int mKeyEnd;	
//functions
public:
	TestDataReader(Keyboard* pKeyboard, int keyBegin, int keyEnd);
	~TestDataReader();
	
	virtual void init();
	
	virtual void readData(Data& data);
protected:
private:
	TestDataReader( const TestDataReader &c );
	TestDataReader& operator=( const TestDataReader &c );

}; //SchnackTestReader

#endif //__SCHNACKTESTREADER_H__
