/* 
* OnStateChangeCallback.h
*
* Created: 18.08.2019 4:03:25
* Author: Admin
*/


#ifndef __ONSTATECHANGECALLBACK_H__
#define __ONSTATECHANGECALLBACK_H__

// �������� ��� �������� �� �������� ���������
class OnStateChangeCallback
{
//functions
public:
	
	// ���������� ��� ����� � ���������. ��������, ����� ��������
	// ��������� �� ������ ��� �� �������� ��������� ����������.
	virtual void onEnterState() = 0;
	
	// ���������� ��� ������ �� ���������
	virtual void onExitStateState() = 0;

}; //OnStateChangeCallback

#endif //__ONSTATECHANGECALLBACK_H__
