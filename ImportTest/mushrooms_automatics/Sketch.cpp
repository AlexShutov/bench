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
#include "src/sensor/SchnackTestReader.h"

/**
 * Выводы реле
 */
 #define PIN_RELAY_CONVEYER 3
 #define PIN_RELAY_SCHNACK 4


// текущие данные экрана
ScreenInfo screenInfo;

// Бизнес - логика)

/**
 * Состояние лотка подачи (какие датчики включены)
 */
struct SchnackState {
  bool s1On;
  bool s2On;
};

/**
 * Фаза работы (звено конечного автомата)
 */
struct SchnackPhase {
  // следующая фаза, в данном случае возможен лишь один переход
  SchnackPhase* pNextPhase;
  // Отслеживаем переход от предыдущего к текущему состоянию
  SchnackState* pPrevState;
  // Условие, которое должно выполняться для перехода
  bool (*pPredicate)(SchnackState& prevState, SchnackState& currState);
  // Действие при смене фазы
  void (*pCallback)(void);
};

Display *pDisplay;
Lights *pLights;
// реле
Relay* pSchnack;
Relay* pConveyor;

// клавиатура
Keyboard* pKeyboard;
SchnackDataReader* pSchnackReader;
SchnackData previousReading;
SchnackData currReading;

void updateReadings(bool init);

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
	pSchnackReader = new SchnackTestReader(pKeyboard);
	
	pSchnackReader->readSchnackData(previousReading);
	updateReadings(true);
}

void updateReadings(bool init) {
	pSchnackReader->readSchnackData(currReading);
	if (previousReading != currReading || init) {
		pSchnack->setEnabled(currReading.mBeginON);
		pConveyor->setEnabled(currReading.mEndON);
		
		if (currReading.mBeginON && currReading.mEndON) {
			pLights->setLightIndicator(LIGHT_READY);
			} else {
			pLights->setLightIndicator(LIGHT_ERROR);
		}
		
		//pDisplay->clear();
		//String message = currReading.mBeginON ? String("begin sensor ON") : String("begin sensor off");
		//pDisplay->logMessage(0, message);
		//message = currReading.mEndON ? String("end sensor ON") : String("end sensor off");
		//pDisplay->logMessage(1, message);
		previousReading = currReading;
	}
	
}

void loop() {
	int duration_on = 10;
	int duration_off = 10;
	
	  //pLights->setLightIndicator(LIGHT_READY);
	  
	  
	  //delay(duration_on);                      
	
	  //pLights->setLightIndicator(LIGHT_ERROR);
	  updateReadings(false);
	   
	  //delay(duration_off);
}