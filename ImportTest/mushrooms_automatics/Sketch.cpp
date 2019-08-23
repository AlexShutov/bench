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

// чтение данных с сенсоров
#include "../src/sensor/PinReadMode.h"
#include "../src/sensor/SensorDataReader.h"

// чтение  показаний с тестовой клавиатуры
#include "src/sensor/test/Keyboard.h"
#include "src/sensor/test/TestDataReader.h"

#include "src/stats/StatsViewModel.h"

#include "../src/FillerFacade.h"
#include "../src/ConveyorFacade.h"

#include <EEPROM.h>

/**
 * Выводы реле
 */
 #define PIN_RELAY_CONVEYER 3
 #define PIN_RELAY_SCHNACK 4

// ножки подключения одинаковые для клавиатуры и сенсора
#define PIN_SCHNACK_BEGIN 14
#define PIN_SCHNACK_END 15
#define PIN_CONVEYOR_BEGIN 16
#define PIN_CONVEYOR_END 17

#define PIN_INPUT_TYPE 9

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

// отвечает за показ статистики на экране
StatsViewModel* pStatsViewModel;

FillerFacade* pFillerSubsystem;
ConveyorFacade* pConveyorFacade;

void initTestKeyboardDataReader() {
	// чтение данных шнека
	pKeyboard = new Keyboard();
	pKeyboard->init();
	
	pSchnackReader = new TestDataReader(pKeyboard, 4, 3);
	pConveyorReader = new TestDataReader(pKeyboard, 2, 1);
}

void initSensorDataReader() {
	pSchnackReader = new SensorDataReader(PIN_SCHNACK_BEGIN, PIN_SCHNACK_END);
	pConveyorReader = new SensorDataReader(PIN_CONVEYOR_BEGIN,  PIN_CONVEYOR_END);
	
	pSchnackReader->init();
	pConveyorReader->init();
}

void initDataReader() {
	PinReadMode configPin;
	// высокое (по умолчанию) - сенсор, земля - клавиатура
	configPin.init(PIN_INPUT_TYPE, false);
	
	pDisplay->clear();
	
	if (configPin.isOn()) {
		pDisplay->logMessage(0, String("Sensor"));
		initSensorDataReader();
	} else {
		pDisplay->logMessage(0, String("Test keyboard"));
		initTestKeyboardDataReader();
	}
}

void initStatsViewModel() {
	pStatsViewModel = new StatsViewModel();
	pStatsViewModel->loadStats();
	pStatsViewModel->updateDisplay(pDisplay, screenInfo);
}

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
	
	initDataReader();
	
	// инициализация показа статистики - экран уже готов
	initStatsViewModel();
	
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