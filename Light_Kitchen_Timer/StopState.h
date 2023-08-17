#ifndef StopState_H
#define StopState_H

#include <KitchenShield.h>
#include "KitchenTimer.h"
#include "RequestSensor.h"
#include "State.h"

class StopState : public State{
  /*
  protected:
    StopState() {}
    static StopState* m_pStop;
  public:
    //singleton
    // (type_Name const&) is equivalent to (const type_Name &)
    StopState(const StopState&) = delete;
    StopState& operator=(const StopState&) = delete;
    static StopState *getInstance();
 
    ResponseActuator::response handle(KitchenTimer *kt, RequestSensor::request req);
    void TransitionTo(State* state); //(State* s)
    //void set_KitchenTimer(KitchenTimer *kt);
    */
  
  public:
    static StopState* getInstance();
    StopState(const StopState&) = delete;
    StopState& operator=(const StopState&) = delete;
  private:
    StopState() = default;
    static StopState *m_pStop;
    ~StopState() = default;

    ResponseActuator::response handle(KitchenTimer *kt, RequestSensor::request req);
};

#endif