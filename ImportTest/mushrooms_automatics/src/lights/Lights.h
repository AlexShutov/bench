/* 
* Lights.h
*
* Created: 13.08.2019 2:58:03
* Author: Admin
*/


#ifndef __LIGHTS_H__
#define __LIGHTS_H__

#include "../src/ProcessState.h"

/**
 * Ножки индикаторов состояния
 */
#define PIN_STATE_READY 7
#define PIN_STATE_ERROR 6

/************************************************************************/
/* Предназначен для работы с индикаторами состояния                     */
/* ГОТОВ / ОШИБКА / В Работе											*/
/************************************************************************/
class Lights
{
	
	
//variables
public:

	//инициализирует индикаторы
	void init();

	// устанавливаем состояние 
	void setLightIndicator(ProcessState state);
	
protected:
private:

//functions
public:
	Lights();
	~Lights();
protected:
private:
	Lights( const Lights &c );
	Lights& operator=( const Lights &c );

}; //Lights

#endif //__LIGHTS_H__
