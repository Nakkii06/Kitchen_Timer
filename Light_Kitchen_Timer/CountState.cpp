#include <KitchenShield.h>

#include "KitchenTimer.h"
#include "RequestSensor.h"

#include "State.h"
#include "CountState.h"
#include "StopState.h"
#include "PauseState.h"

static CountState* CountState::getInstance() {
  static CountState s;
  return &s;
}

ResponseActuator::response CountState::handle(KitchenTimer* kt, RequestSensor::request req) {
  ResponseActuator::response res = ResponseActuator::NO_RESPONSE;
  switch(req) {
        case RequestSensor::SECOND_PASS: 
          kt->addRemainTime(-1);
          res = ResponseActuator::SHOW_TIME;

          if(kt->getRemainTime() == 0) {
            res = ResponseActuator::ALARM;
            kt->stopClock();
            kt->TransitionTo(StopState::getInstance());
          }
          break;
        case RequestSensor::PAUSE_COUNT:
          res = ResponseActuator::SHOW_TIME; //meaningless??
          kt->stopClock();
          kt->TransitionTo(PauseState::getInstance());
          break;
        default:
          break;
  }
}