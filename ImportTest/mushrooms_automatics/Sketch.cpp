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

// Ножка для выбора ввода (сенсор (5v)/ Тестовая клавиатура (земля))
#define PIN_INPUT_TYPE 9
// Ножка кнопки для сброса суточного счетчика
#define PIN_RESET_DAY_COUNT 8

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

// Счетчики мешков
StatsViewModel* pStatsViewModel;
// Кнопка сброса суточного счетчика
PinReadMode buttonResetDayCount;
bool buttonResetPrevState;

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
		initSensorDataReader();
	} else {
		initTestKeyboardDataReader();
	}
}

void initStatsViewModel() {
	pStatsViewModel = new StatsViewModel();
	pStatsViewModel->loadStats();
	pStatsViewModel->updateDisplay(pDisplay, screenInfo);
}

void initResetDayCountButton() {
	buttonResetDayCount.init(PIN_RESET_DAY_COUNT, false);
	buttonResetPrevState = buttonResetDayCount.isOn();
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
	// настроим кнопку сброса счетчика мешков
	initResetDayCountButton();
	
	// настройка упраления лентой подачи
	pConveyorFacade = new ConveyorFacade(&screenInfo, 
		pConveyor, pDisplay, pConveyorReader);
	
	// Настройка подсистемы заполнения мешков
	pFillerSubsystem = new FillerFacade(&screenInfo,
		pSchnack, pDisplay, pStatsViewModel, pLights, pSchnackReader, pConveyorReader);
	
	// сначала инициализируем ленту, т.к. начальное состояние шнека зависит 
	// от заполненности бункера семечкой  (лента)
	pConveyorFacade->init();
	pFillerSubsystem->init();	
}

void pollDayCountResetButton() {
	bool isOn = buttonResetDayCount.isOn();
	if (isOn != buttonResetPrevState) {
		delay(50);
		if (isOn != buttonResetPrevState) {
			if (isOn) {
				// кнопка нажата
				pStatsViewModel->resetDayStats();
				pStatsViewModel->updateDisplay(pDisplay, screenInfo);
			}
			buttonResetPrevState = isOn;
		}
	}
}

void loop() {
	pFillerSubsystem->pollSchnack();
	pConveyorFacade->pollConveyor();
	pollDayCountResetButton();
}