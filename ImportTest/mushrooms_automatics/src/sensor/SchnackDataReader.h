/* 
* SchnackDataReader.h
*
* Created: 14.08.2019 1:44:50
* Author: Admin
*/


#ifndef __SCHNACKDATAREADER_H__
#define __SCHNACKDATAREADER_H__

#include "Data.h"

// Считыватель данных датчиков шнека. Есть 2 типа- тестовый считыватель, работающий с 
// клавиатурой, а также реальный, опрашивающий датчики через оптронную развязку.
// Мы можем включить тестовый режим (клавиатура) посредством замыкания контакта.
class SchnackDataReader
{
//functions
public:
	virtual ~SchnackDataReader();
	// настройка
	virtual void init() = 0;
	// считываем показания датчиков
	virtual void readSchnackData(Data& data) = 0;

}; //SchnackDataReader

#endif //__SCHNACKDATAREADER_H__
