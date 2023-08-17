#include <KitchenShield.h>

#include "ResetSwitch.h"
#include "KitchenTimer.h"
#include "RequestSensor.h"

ResetSwitch::ResetSwitch() {
  sw = new Switch();
  sw->init(8); //sw4
  turnedOn = false;
  
  //btn0 = new Button();
  //btn1 = new Button();
  //btn0->init(A0);
  //btn1->init(A1);
  setRequest(RequestSensor::NO_REQUEST);
}

ResetSwitch::~ResetSwitch() {
  delete(sw);
  //delete(btn0);
  //delete(btn1);

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
  
  /*
  if (btn0->isPressed() && btn1->isPressed()) {
    btn0->waitForRelease();
    btn1->waitForRelease();
    setRequest(RequestSensor::RESET);
    this->notify();
  }
  */
}