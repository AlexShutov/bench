/* 
* SchnackDataReader.h
*
* Created: 14.08.2019 1:44:50
* Author: Admin
*/


#ifndef __SCHNACKDATAREADER_H__
#define __SCHNACKDATAREADER_H__

#include "../Data.h"

// ����������� ������ �������� �����. ���� 2 ����- �������� �����������, ���������� � 
// �����������, � ����� ��������, ������������ ������� ����� ��������� ��������.
// �� ����� �������� �������� ����� (����������) ����������� ��������� ��������.
class DataReader
{
//functions
public:
	virtual ~DataReader();
	// ���������
	virtual void init() = 0;
	// ��������� ��������� ��������
	virtual void readSchnackData(Data& data) = 0;

}; //SchnackDataReader

#endif //__SCHNACKDATAREADER_H__
