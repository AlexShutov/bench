/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */

#include <Wire.h> 
#include <string.h>
#include <stdlib.h>
#include <Keypad.h>

#include "src/display/screenInfo.h"
#include "src/display/Display.h"
#include "src/lights/Lights.h"
#include "src/relay/Relay.h"

#include "src/sensor/Keyboard.h"
#include "src/sensor/TestDataReader.h"

#include "src/domain/State.h"
// ожидание
#include "src/domain/states/idle/StateIdle.h"
#include "src/domain/states/idle/StateIdleCallback.h"
// наполнение
#include "src/domain/states/filling/StateFilling.h"
#include "src/domain/states/filling/StateFilliingCallback.h"
// Обновление ui
#include "src/domain/states/uiUpdate/StateUiUpdate.h"
#include "src/domain/states/uiUpdate/StateUiUpdateCallback.h"

/**
 * Выводы реле
 */
 #define PIN_RELAY_CONVEYER 3
 #define PIN_RELAY_SCHNACK 4


// текущие данные экрана
ScreenInfo screenInfo;

Display *pDisplay;
Lights *pLights;
// реле
Relay* pSchnack;
Relay* pConveyor;

// клавиатура
Keyboard* pKeyboard;
DataReader* pSchnackReader;
DataReader* pConveyorReader;

// состояние готовности
State* pStateIdle;
StateIdleCallback* pCallbackIdle;
// состояние наполнения
State* pStateFilling;
StateFilliingCallback* pCallbackFilling;
// состояние обновления UI
State* pStateUiUpdate;
StateUiUpdateCallback* pCallbackUiUpdate;

// указывает на текущее состояние автомата
State* pCurrState;


void initStateIdle();
void initStateFilling();
void initStateUiUpdate();

void setup() {
	// инициализация экрана
	pDisplay = new Display();
	pDisplay->init();
	// лампочек состояния
	pLights = new Lights();
	pLights->init();
	// реле
	pSchnack = new Relay(PIN_RELAY_SCHNACK);
	pSchnack->init();
	pConveyor = new Relay(PIN_RELAY_CONVEYER);
	pConveyor->init();
	
	// чтение данных шнека
	pKeyboard = new Keyboard();
	pKeyboard->init();
	
	pSchnackReader = new TestDataReader(pKeyboard, 4, 3);
	pConveyorReader = new TestDataReader(pKeyboard, 2, 1);
	
	initStateIdle();
	initStateFilling();
	initStateUiUpdate();
	
	// за ожиданием следует наполнение
	pStateIdle->setNextState(pStateFilling);
	// за наполнением следует обновление UI
	pStateFilling->setNextState(pStateUiUpdate);
	// за обновлением Ui следует проверка наполненности бункера 
	// (TODO, пока просто ожидание)
	pStateUiUpdate->setNextState(pStateIdle);
	
	// пока что начнем с состояния простоя (нужно будет с ожидания наполнения бункера)
	pCurrState = pStateIdle;
	// инициализируем состояние
	pCurrState->initState();
}

void initStateIdle() {
	pStateIdle = new StateIdle(pSchnackReader);
	pCallbackIdle = new StateIdleCallback(pSchnack, 
		pDisplay, pLights, &screenInfo);
	pStateIdle->setStateChangeCallback(pCallbackIdle);
}

void initStateFilling() {
	pStateFilling = new StateFilling(pSchnackReader);
	pCallbackFilling = new StateFilliingCallback(pSchnack, 
		pDisplay, pLights, &screenInfo);
	pStateFilling->setStateChangeCallback(pCallbackFilling);
}

void initStateUiUpdate() {
	pStateUiUpdate = new StateUiUpdate(pSchnackReader);
	pCallbackUiUpdate = new StateUiUpdateCallback(pSchnack,
		pDisplay, pLights, &screenInfo); 
	pStateUiUpdate->setStateChangeCallback(pCallbackUiUpdate);
}


void loop() {
	if (pCurrState->pollState()) {
		pCurrState = pCurrState->getNextState();
		pCurrState->initState();	
	}
}