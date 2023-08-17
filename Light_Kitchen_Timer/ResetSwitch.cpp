#include <KitchenShield.h>

#include "ResetSwitch.h"
#include "KitchenTimer.h"
#include "RequestSensor.h"

ResetSwitch::ResetSwitch() {
  sw = new Switch();
  sw->init(8); //sw4
  turnedOn = false;
  setRequest(RequestSensor::NO_REQUEST);
}

ResetSwitch::~ResetSwitch() {
  delete(sw);
}

void ResetSwitch::handle() {
  if(sw->isOn()) {
    turnedOn = true;
    setRequest(RequestSensor::NO_REQUEST);
  } else if(turnedOn && sw->isOff()) {
    setRequest(RequestSensor::RESET);
    turnedOn = false;
    this->notify();
  } else {
    setRequest(RequestSensor::NO_REQUEST);
  }
}