/* 
* FillerFacade.h
*
* Created: 19.08.2019 1:03:03
* Author: Admin
*/


#ifndef __FILLERFACADE_H__
#define __FILLERFACADE_H__

// ����������� ������������ ��������� ������
#include "../src/display/screenInfo.h"
#include "../src/display/Display.h"
#include "../src/lights/Lights.h"
#include "../src/relay/Relay.h"
#include "../src/sensor/DataReader.h"

// ����������� ������������ ��������� ��������, ����������� �� ���������� ������
#include "../src/domain/State.h"
// ��������
#include "../src/domain/states/filler//idle/StateIdle.h"
#include "../src/domain/states/filler/idle/StateIdleCallback.h"
// ����������
#include "../src/domain/states/filler/filling/StateFilling.h"
#include "../src/domain/states/filler/filling/StateFilliingCallback.h"
// ���������� ui
#include "../src/domain/states/filler/uiUpdate/StateUiUpdate.h"
#include "../src/domain/states/filler/uiUpdate/StateUiUpdateCallback.h"
// �������� ������������� �������
#include "../src/domain/states/filler/emptyBunkerBarrier/StateEmptyBunkerBarrier.h"
#include "../src/domain/states/filler/emptyBunkerBarrier/StateEmptyBunkerBarrierCallback.h"

/************************************************************************/
/* ����������, ���������� �� ���������� ����������� ������.
/************************************************************************/
class FillerFacade
{
//variables
public:
protected:
private:
	// ��������� ������ �������� ���������
	ScreenInfo* mpScreenInfo;
	// ���������� ������
	Relay* mpSchnack;
	// �����
	Display *mpDisplay;
	// ���������� ���������
	Lights *mpLights;
	// �������� ��������� ����� � ��������� (��� �������� ����������)
	DataReader* mpSchnackReader;
	DataReader* mpConveyorReader;
	
	// ��������� ��������
	
	// ��������� ����������
	State* pStateIdle;
	StateIdleCallback* pCallbackIdle;
	// ��������� ����������
	State* pStateFilling;
	StateFilliingCallback* pCallbackFilling;
	// ��������� ���������� UI
	State* pStateUiUpdate;
	StateUiUpdateCallback* pCallbackUiUpdate;
	// ��������� �������� ������������� �������
	State* pStateEmptyBunkerBarrier;
	StateEmptyBunkerBarrierCallback* pStateEmptyBunkerCallback;

	// ��������� �� ������� ��������� ��������
	State* pCurrState;
	
	
//functions
public:
	/************************************************************************/
	/*  ����� ������� ������, �� ����� ������ ������ ���
	/************************************************************************/
	FillerFacade(ScreenInfo* pScreenInfo, 
			Relay* pSchnack,
			Display *pDisplay,
			Lights *pLights,
			DataReader* pSchnackReader,
			DataReader* pConveyorReader);
			
	/************************************************************************/
	/* ����� ��������� ������ �� ���������� �������, �� ���� ��  �������
	/************************************************************************/
	~FillerFacade();
	
	//  �������������� �������
	void init();
	
	// ���������� ���������
	void pollSchnack();
	
protected:
private:
	FillerFacade( const FillerFacade &c );
	FillerFacade& operator=( const FillerFacade &c );
	
	// ������ ��� ������������� ��������� ��������� ��������
	
	void initStateIdle();
	void initStateFilling();
	void initStateUiUpdate();
	void initStateEmptyBunkerBarrier();
	
}; //FillerFacade

#endif //__FILLERFACADE_H__
