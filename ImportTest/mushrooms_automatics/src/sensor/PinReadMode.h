/* 
* Pin.h
*
* Created: 23.08.2019 0:48:01
* Author: Admin
*/


#ifndef __PIN_H__
#define __PIN_H__


class PinReadMode
{
//variables
public:
protected:
private:

	int mPinIndex;
	bool mIsStateInverted;

//functions
public:
	PinReadMode();
	~PinReadMode();
	
	void init(int pinIndex, bool isStateInverted);
	
	/************************************************************************/
	/* Включена ли данная ножка
	/************************************************************************/
	bool isOn();
	
protected:
private:
	PinReadMode( const PinReadMode &c );
	PinReadMode& operator=( const PinReadMode &c );

}; //Pin

#endif //__PIN_H__
