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
 * ����� ����������� ���������
 */
#define PIN_STATE_READY 7
#define PIN_STATE_ERROR 6

/************************************************************************/
/* ������������ ��� ������ � ������������ ���������                     */
/* ����� / ������ / � ������											*/
/************************************************************************/
class Lights
{
	
	
//variables
public:

	//�������������� ����������
	void init();

	// ������������� ��������� 
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
