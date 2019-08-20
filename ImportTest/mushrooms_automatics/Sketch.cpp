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

#include "../src/FillerFacade.h"
#include "../src/ConveyorFacade.h"

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

FillerFacade* pFillerSubsystem;
ConveyorFacade* pConveyorFacade;

void setup() {
	// инициализация экрана
	pDisplay = new Display();
	pDisplay->init();
	// TODO: считать статистику
	// покажем счетчики и состояние
	pDisplay->updateScreen(&screenInfo);
	
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
	
	// настройка упраления лентой подачи
	pConveyorFacade = new ConveyorFacade(&screenInfo, 
		pConveyor, pDisplay, pConveyorReader);
	
	// Настройка подсистемы заполнения мешков
	pFillerSubsystem = new FillerFacade(&screenInfo,
		pSchnack, pDisplay, pLights, pSchnackReader, pConveyorReader);
	
	// сначала инициализируем ленту, т.к. начальное состояние шнека зависит 
	// от заполненности бункера семечкой  (лента)
	pConveyorFacade->init();
	pFillerSubsystem->init();
}

void loop() {
	pFillerSubsystem->pollSchnack();
	pConveyorFacade->pollConveyor();
}