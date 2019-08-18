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
	
	// ����� ����������� �� ��� ���, ���� �� ��������� ������ s2, 
	// ����������� � ����� �����. ���� ������ ������ �� ����� ����� � ��������� 
	// ������ �����, ����� ����� ����������. 
	// �.�. �� ������� �� ��� ���������, �� �� ����� ��������� ������ s1 - 
	// �� ��� ��� ������� �� ���������� ��������� �������.
	virtual bool checkStateChangeCondition();
	
protected:
private:
	StateFilling( const StateFilling &c );
	StateFilling& operator=( const StateFilling &c );

}; //StateFilling

#endif //__STATEFILLING_H__
