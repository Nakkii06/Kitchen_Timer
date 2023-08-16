#include <KitchenShield.h>

#include "PauseSwitch.h"
#include "KitchenTimer.h"
#include "RequestSensor.h"

PauseSwitch::PauseSwitch() {
  sw = new Switch();
  sw->init(12); //sw2
  pausing = false;
  setRequest(RequestSensor::NO_REQUEST);
}

PauseSwitch::~PauseSwitch() {
  delete(sw);
}

void PauseSwitch::handle() {
  if(pausing){
    if(sw->isOff()) {
      setRequest(RequestSensor::RESTART_COUNT);
      pausing = false;
      this->notify();
    } else {
      setRequest(RequestSensor::NO_REQUEST);
    }
  } else {
    if(sw->isOn()) {
      setRequest(RequestSensor::PAUSE_COUNT);
      pausing = true;
      this->notify();
    } else {
      setRequest(RequestSensor::NO_REQUEST);
    }
  }
}