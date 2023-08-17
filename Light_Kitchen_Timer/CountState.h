#ifndef CountState_H
#define CountState_H

#include <KitchenShield.h>
#include "KitchenTimer.h"
#include "RequestSensor.h"

#include "State.h"


class CountState : public State{
  public:
    static CountState* getInstance();
    CountState(const CountState&) = delete;
    CountState& operator=(const CountState&) = delete;
  private:
    CountState() = default;
    static CountState *m_pCount;
    ~CountState() = default;

    ResponseActuator::response handle(KitchenTimer *kt, RequestSensor::request req);
    
};

#endif