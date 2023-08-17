#include <KitchenShield.h>

#include "KitchenTimer.h"
#include "RequestSensor.h"

#include "State.h"
#include "StopState.h"
#include "CountState.h"

static StopState* StopState::getInstance() {
  static StopState s;
  return &s;
}

ResponseActuator::response StopState::handle(KitchenTimer* kt, RequestSensor::request req) {
  ResponseActuator::response res = ResponseActuator::NO_RESPONSE;

  switch (req) {
    case RequestSensor::START_COUNT:
      kt->startClock();
      kt->TransitionTo(CountState::getInstance());
      break;
    case RequestSensor::RESET:
      kt->setRemainTime(0);
      res = ResponseActuator::SHOW_TIME;
      kt->TransitionTo(StopState::getInstance()); //meaningless??
      break;
    case RequestSensor::ADD_TIME_ONEMIN:
      kt->addRemainTime(60);
      res = ResponseActuator::SHOW_TIME;  //音もならしたい
      break;
    case RequestSensor::ADD_TIME_TENSEC:
      kt->addRemainTime(10);
      res = ResponseActuator::SHOW_TIME;
      break;
    default:
      break;
  }
  //void StopState::set_KitchenTimer(KitchenTimer *kt){

  //}
}