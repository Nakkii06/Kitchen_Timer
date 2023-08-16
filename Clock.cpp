#include <MsTimer2.h>
#include <KitchenShield.h>

#include "Clock.h"
#include "KitchenTimer.h"
#include "RequestSensor.h"

void tick();

Clock::Clock() {
  setInterrupted(false);
  setRequest(RequestSensor::NO_REQUEST);
  MsTimer2::set(1000, tick);
  //MsTimer2::start();
}

Clock::~Clock() { 
  MsTimer2::stop();
}

void Clock::setInterrupted(boolean intr) {
  interrupted = intr;
}

void Clock::handle() {
  if (interrupted) {
    setRequest(RequestSensor::SECOND_PASS); //changehere
    notify();
    setRequest(RequestSensor::NO_REQUEST);
    setInterrupted(false);
  }
}

//test
/*
void Clock::handle(KitchenTimer* timer, ResponseActuator::response res) {
  if (res == ResponseActuator::START_COUNT) {
    MsTimer2::start();

  }
}  
*/


void startClock() {
  MsTimer2::start();
}
