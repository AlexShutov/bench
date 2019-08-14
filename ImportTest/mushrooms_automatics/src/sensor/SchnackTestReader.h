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
#include "SchnackDataReader.h"

// Имитирует считывание показания датчиков при помощи клавиатуры.
// Датчики шнека имитируются клавишами 4 (s1) и 3 (s2)
class SchnackTestReader : public SchnackDataReader 
{
//variables
public:
protected:
private:
	
	Keyboard* mpKeyboard;	
//functions
public:
	SchnackTestReader(Keyboard* pKeyboard);
	~SchnackTestReader();
	
	virtual void init();
	
	virtual void readSchnackData(SchnackData& data);
protected:
private:
	SchnackTestReader( const SchnackTestReader &c );
	SchnackTestReader& operator=( const SchnackTestReader &c );

}; //SchnackTestReader

#endif //__SCHNACKTESTREADER_H__
