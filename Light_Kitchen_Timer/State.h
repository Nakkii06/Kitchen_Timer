#ifndef State_H
#define State_H

#include <KitchenShield.h>
#include "KitchenTimer.h"
#include "RequestSensor.h"
class KitchenTimer;

class State {
  public:
    ~State();
    virtual ResponseActuator::response handle(KitchenTimer *kt, RequestSensor::request req) = 0;
    virtual void TransitionTo(State *state) = 0;
};

#endif