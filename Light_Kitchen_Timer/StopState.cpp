#include <KitchenShield.h>

#include "StopState.h"
#include "KitchenTimer.h"
#include "RequestSensor.h"
#include "State.h"

static StopState* StopState::getInstance() {
  static StopState m_pStop;
  return &m_pStop;
}

ResponseActuator::response StopState::handle(KitchenTimer* kt, RequestSensor::request req) {
  ResponseActuator::response res = ResponseActuator::NO_RESPONSE;

  switch (req) {
    case RequestSensor::START_COUNT:
      kt->startClock();
      TransitionTo(KitchenTimer *kt);
      break;
    case RequestSensor::RESET:
      kt->setRemainTime(0);
      res = ResponseActuator::SHOW_TIME;
      current_status = KitchenTimer::STOP;
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
}