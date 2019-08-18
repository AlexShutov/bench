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
	
	// Вызывается при входе в состояние. Например, нужно написать
	// сообщение на экране или же изменить индикатор готовности.
	virtual void onEnterState() = 0;
	
	// Вызывается при выходе из состояния
	virtual void onExitStateState() = 0;

}; //OnStateChangeCallback

#endif //__ONSTATECHANGECALLBACK_H__
