#ifndef PauseState_H
#define PauseState_H

#include <KitchenShield.h>
#include "KitchenTimer.h"
#include "RequestSensor.h"
#include "State.h"

class PauseState : public State{
  public:
    static PauseState* getInstance();
    PauseState(const PauseState&) = delete;
    PauseState& operator=(const PauseState&) = delete;
  private:
    PauseState() = default;
    static PauseState *m_pPause;
    ~PauseState() = default;

    ResponseActuator::response handle(KitchenTimer *kt, RequestSensor::request req);
};

#endif