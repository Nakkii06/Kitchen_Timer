#include <KitchenShield.h>

#include "StartSwitch.h"
#include "KitchenTimer.h"
#include "RequestSensor.h"

StartSwitch::StartSwitch() {
  //btn = new Button();
  //btn->init(A0);

  sw = new Switch();
  sw->init(13); //sw1
  turnedOn = false;
  setRequest(RequestSensor::NO_REQUEST);
}

StartSwitch::~StartSwitch() {
  //delete(btn);

  delete(sw);
}

void StartSwitch::handle() {
  if(sw->isOn()) {
    turnedOn = true;
    setRequest(RequestSensor::NO_REQUEST);
  } else if(turnedOn && sw->isOff()) {
    setRequest(RequestSensor::START_COUNT);
    turnedOn = false;
    this->notify();
  } else {
    setRequest(RequestSensor::NO_REQUEST);
  }
}