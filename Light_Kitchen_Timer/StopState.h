#ifndef StopState_H
#define StopState_H

#include <KitchenShield.h>
#include "KitchenTimer.h"
#include "RequestSensor.h"

#include "State.h"

class StopState : public State{
  public:
    
 
    ResponseActuator::response handle(KitchenTimer *kt, RequestSensor::request req);
    void TransitionTo(KitchenTimer *kt); //(State* s)
    
};

#endif