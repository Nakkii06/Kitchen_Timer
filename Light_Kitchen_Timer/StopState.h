#ifndef StopState_H
#define StopState_H

#include <KitchenShield.h>
#include "KitchenTimer.h"
#include "RequestSensor.h"

#include "State.h"

class StopState : public State{
  private:
    //
  public:
    StopState() = default;
    ~StopState();

    //singleton
    StopState(const StopState&) = delete; //not be clonable
    StopState operator=(const StopState&) = delete;
    static StopState* getInstance();
 
    ResponseActuator::response handle(KitchenTimer *kt, RequestSensor::request req);
    void TransitionTo(State* state); //(State* s)
    
};

#endif