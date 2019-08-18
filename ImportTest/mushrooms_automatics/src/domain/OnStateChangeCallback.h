/* 
* OnStateChangeCallback.h
*
* Created: 18.08.2019 4:03:25
* Author: Admin
*/


#ifndef __ONSTATECHANGECALLBACK_H__
#define __ONSTATECHANGECALLBACK_H__

// Действие при переходе из текущего состояния
class OnStateChangeCallback
{
//functions
public:
	
	virtual void onStateChanged() = 0;

}; //OnStateChangeCallback

#endif //__ONSTATECHANGECALLBACK_H__
