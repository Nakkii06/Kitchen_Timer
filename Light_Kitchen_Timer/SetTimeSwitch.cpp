//LightSwitch.cppを改造

#include <KitchenShield.h>

#include "SetTimeSwitch.h"
#include "KitchenTimer.h"
#include "RequestSensor.h"

SetTimeSwitch::SetTimeSwitch() {
  btn0 = new Button();
  btn1 = new Button();
  btn0->init(A0); //red button
  btn1->init(A1); //green button
  pressed = false;
  setRequest(RequestSensor::NO_REQUEST);
}

SetTimeSwitch::~SetTimeSwitch() {
  delete(btn0);
  delete(btn1);
}

void SetTimeSwitch::handle() {
  if(btn1->isPressed()) {
    btn1->waitForRelease();
    setRequest(RequestSensor::ADD_TIME_ONEMIN);
    this->notify();
  } else if(btn0->isPressed()) {
    btn0->waitForRelease();
    setRequest(RequestSensor::ADD_TIME_TENSEC);
    this->notify();
  } else {
    setRequest(RequestSensor::NO_REQUEST);
  }
}