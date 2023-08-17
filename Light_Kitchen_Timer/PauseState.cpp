#include <KitchenShield.h>

#include "KitchenTimer.h"
#include "RequestSensor.h"

#include "State.h"
#include "StopState.h"
#include "CountState.h"
#include "PauseState.h"


static PauseState* PauseState::getInstance() {
  static PauseState s;
  return &s;
}

ResponseActuator::response PauseState::handle(KitchenTimer* kt, RequestSensor::request req) {
  ResponseActuator::response res = ResponseActuator::NO_RESPONSE;

  switch(req) {
        case RequestSensor::RESTART_COUNT:
          res = ResponseActuator::SHOW_TIME; //meaningless??
          kt->TransitionTo(CountState::getInstance());
          break;
        case RequestSensor::RESET:
          kt->setRemainTime(0);
          res = ResponseActuator::SHOW_TIME;
          kt->TransitionTo(StopState::getInstance());
          break;
        default:
          break;
  }
}