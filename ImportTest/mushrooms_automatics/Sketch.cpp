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

//Beginning of Auto generated function prototypes by Atmel Studio

void switchRelay(int relay, bool isOn);
void initRelays();
//End of Auto generated function prototypes by Atmel Studio


#define PIN_CONVEYOR 3
#define PIN_FILLER 4



/**
 * Выводы реле
 */
 #define PIN_RELAY_CONVEYER 3
 #define PIN_RELAY_FILLER 4
 // типы реле
 #define RELAY_CONVEYER 1
 #define RELAY_FILLER 2

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

void setup() {
	// инициализация экрана
	pDisplay = new Display();
	pDisplay->init();
	// лампочек состояния
	pLights = new Lights();
	pLights->init();
	
	initRelays();
	
	char buff[16];
	String line = "";

	screenInfo.schnackOn = false;
	screenInfo.conveyerOn = false;
	screenInfo.countTotal = 12345;
	screenInfo.countDay = 0;
	pDisplay->updateScreen(screenInfo);
}

/**
 * Переключает реле
 */
void switchRelay(int relay, bool isOn) {
  int pin;
  switch (relay) {
    case RELAY_CONVEYER:
      pin = PIN_RELAY_CONVEYER;
      break;
    case PIN_RELAY_FILLER:
    default:
      pin = PIN_RELAY_FILLER;
  }
  digitalWrite(pin, isOn ? HIGH : LOW);
}

/**
 * инициализирует выходы реле
 */
void initRelays() {
  pinMode(PIN_RELAY_CONVEYER, OUTPUT);
  pinMode(PIN_RELAY_FILLER, OUTPUT);
  digitalWrite(PIN_RELAY_CONVEYER, LOW);
  digitalWrite(PIN_RELAY_FILLER, LOW);
}


void loop() {
	int duration_on = 50;
	int diration_off = 50;
	
	  pLights->setLightIndicator(LIGHT_READY);
	  delay(duration_on);                      
	
	  pLights->setLightIndicator(LIGHT_ERROR);
	
	  screenInfo.countTotal++;
	  screenInfo.countDay++;
	  screenInfo.schnackOn = screenInfo.countDay % 2;
	  screenInfo.conveyerOn = screenInfo.countDay % 2;
	  pDisplay->updateScreen(screenInfo);
	  delay(diration_off);
}