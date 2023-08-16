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

void Clock::startClock() {
  MsTimer2::start();
}

void Clock::stopClock() {
  MsTimer2::stop();
}


