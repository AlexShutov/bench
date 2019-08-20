/* 
* ConveyorFacade.h
*
* Created: 21.08.2019 1:16:49
* Author: Admin
*/


#ifndef __CONVEYORFACADE_H__
#define __CONVEYORFACADE_H__


// ����������� ������������ ��������� ������
#include "../src/display/screenInfo.h"
#include "../src/display/Display.h"
#include "../src/relay/Relay.h"
#include "../src/sensor/DataReader.h"

// ����������� ��������� ��������, ����������� �� ���������� ������ ���������
#include "../src/domain/State.h"
// ��������� ����������� �������
#include "../src/domain/states/conveyor/emptying/StateConveyorEmptying.h"
#include "../src/domain/states/conveyor/emptying/StateConveyorEmptyingCallback.h"
// ��������� ���������� �������
#include "../src/domain/states/conveyor/filling/StateConveyorFilling.h"

/************************************************************************/
/* ����������, ���������� �� ���������� ������ ������
/************************************************************************/
class ConveyorFacade
{
//variables
public:
protected:
private:
	// ��������� ������ �������� ���������
	ScreenInfo* mpScreenInfo;
	// ���������� ������ ������
	Relay* mpConveyor;
	// �����
	Display *mpDisplay;
	// �������� ��������� ������������� �������
	DataReader* mpConveyorReader;
	
	// ��������� ��������
	
	// ���������� �������
	State* mpStateFilling;
	// ����������� �������
	State* mpStateEmptying;
	StateConveyorEmptyingCallback* mpStateEmptyingCallback;	
	
	
	// ��������� �� ������� ��������� ��������
	State* pCurrState;
	
//functions
public:
	ConveyorFacade(ScreenInfo* pScreenInfo,
			Relay* pConveyor,
			Display *pDisplay,
			DataReader* pConveyorReader);
	
	~ConveyorFacade();

	// �������������� ���������� ������
	void init();
	
	void pollConveyor();
	
protected:
private:
	ConveyorFacade( const ConveyorFacade &c );
	ConveyorFacade& operator=( const ConveyorFacade &c );

	// ������ ��� ������������� ��������� ��������� ��������

	void initStateFilling();
	void initStateEmptying();
	
}; //ConveyorFacade

#endif //__CONVEYORFACADE_H__
