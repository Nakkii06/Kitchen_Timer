#ifndef State_H
#define State_H

#include <KitchenShield.h>
#include "KitchenTimer.h"
#include "RequestSensor.h"

class State {
  public:
  virtual ResponseActuator::response handle(KitchenTimer *kt, RequestSensor::request req) = 0;
  virtual void
};

#endif