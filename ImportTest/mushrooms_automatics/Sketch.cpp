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
	
	pSchnack->setEnabled(false);
	pConveyor->setEnabled(false);
	
	char buff[16];
	String line = "";

	screenInfo.schnackOn = false;
	screenInfo.conveyerOn = false;
	screenInfo.countTotal = 12345;
	screenInfo.countDay = 0;
	pDisplay->updateScreen(screenInfo);
}


void loop() {
	int duration_on = 20;
	int diration_off = 20;
	
	  pLights->setLightIndicator(LIGHT_READY);
	  pSchnack->setEnabled(true);
	  pConveyor->setEnabled(!pSchnack->isEnabled());
	  
	  delay(duration_on);                      
	
	  pLights->setLightIndicator(LIGHT_ERROR);
	  
	  pSchnack->setEnabled(!pSchnack->isEnabled());
	  pConveyor->setEnabled(!pSchnack->isEnabled());
	
	  screenInfo.countTotal++;
	  screenInfo.countDay++;
	  screenInfo.schnackOn = screenInfo.countDay % 2;
	  screenInfo.conveyerOn = screenInfo.countDay % 2;
	  
	  if (screenInfo.countDay % 100 == 0) {
		pDisplay->updateScreen(screenInfo);
	  }
	  delay(diration_off);
}