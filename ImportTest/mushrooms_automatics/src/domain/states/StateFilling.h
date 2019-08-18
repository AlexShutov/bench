/* 
* StateFilling.h
*
* Created: 18.08.2019 4:51:16
* Author: Admin
*/


#ifndef __STATEFILLING_H__
#define __STATEFILLING_H__

#include "../State.h"

class StateFilling : State
{
//variables
public:
protected:
private:

//functions
public:
	StateFilling(DataReader* pReader);
	~StateFilling();
	
	// Мешок наполняется до тех пор, пока не сработает датчик s2, 
	// находящийся в конце линии. Этот датчик удален на длину мешка и замкнется 
	// только тогда, когда мешок заполнится. 
	// Т.к. мы перешли на это состояние, то не стоит проверять датчик s1 - 
	// он уже был замкнут на предыдущем состоянии простоя.
	virtual bool checkStateChangeCondition();
	
protected:
private:
	StateFilling( const StateFilling &c );
	StateFilling& operator=( const StateFilling &c );

}; //StateFilling

#endif //__STATEFILLING_H__
