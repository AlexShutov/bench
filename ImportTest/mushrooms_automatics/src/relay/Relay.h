/* 
* Relay.h
*
* Created: 14.08.2019 0:31:23
* Author: Admin
*/


#ifndef __RELAY_H__
#define __RELAY_H__


class Relay
{
//variables
public:
protected:
private:
	// ����� �����, � ������� ���������� ����
	int mPinNo;
	bool mIsInverted;
	bool mIsEnabled;
//functions
public:
	// ����������� ���� � ����� �����������
	Relay(int pinNo);
	// ����� ������� �������� �������
	Relay(int pinNo, bool isInverted);
		
	~Relay();
	
	void init();
	
	// ��� / ����
	void setEnabled(bool isEnabled);
	
	// �������� �� ����	
	bool isEnabled();
protected:
private:
	Relay( const Relay &c );
	Relay& operator=( const Relay &c );
	
	// ��������������� ������
	bool getLevel(bool isOn);

}; //Relay

#endif //__RELAY_H__
