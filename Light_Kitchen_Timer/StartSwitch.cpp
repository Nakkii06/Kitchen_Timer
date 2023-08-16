#include <KitchenShield.h>

#include "StartSwitch.h"
#include "KitchenTimer.h"
#include "RequestSensor.h"

StartSwitch::StartSwitch() {
  //btn = new Button();
  //btn->init(A0);

  sw = new Switch();
  sw->init(13); //sw1
  setRequest(RequestSensor::NO_REQUEST);
}

StartSwitch::~StartSwitch() {
  //delete(btn);

  delete(sw);
}

void StartSwitch::handle() {
  if(sw->isOn()) {
    setRequest(RequestSensor::START_COUNT);
    this->notify();
  } else {
    setRequest(RequestSensor::NO_REQUEST);
  }
}