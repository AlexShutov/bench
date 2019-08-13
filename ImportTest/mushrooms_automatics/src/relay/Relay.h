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
	// номер ножки, к которой подключено реле
	int mPinNo;
	bool mIsInverted;
	bool mIsEnabled;
//functions
public:
	// Привязываем реле к ножке контроллера
	Relay(int pinNo);
	// Можно выбрать инверсию сигнала
	Relay(int pinNo, bool isInverted);
		
	~Relay();
	
	void init();
	
	// вкл / выкл
	void setEnabled(bool isEnabled);
	
	// Включено ли реле	
	bool isEnabled();
protected:
private:
	Relay( const Relay &c );
	Relay& operator=( const Relay &c );
	
	// Вспомогательный методы
	bool getLevel(bool isOn);

}; //Relay

#endif //__RELAY_H__
