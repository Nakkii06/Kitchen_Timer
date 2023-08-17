#include <KitchenShield.h>

#include "KitchenTimer.h"

//sensor header file include, sen[]の要素の名前と同じ
#include "Clock.h"
#include "SetTimeSwitch.h"
#include "ResetSwitch.h"
#include "StartSwitch.h"
#include "PauseSwitch.h"

//actuator header file include, act[]の要素の名前と同じ
#include "ResponseActuator.h"
#include "TimeDisplay.h"
#include "PressedSign.h"
//#include "BGM.h"

//StatePatern
#include "StopState.h"
#include "CountState.h"
#include "PauseState.h"

KitchenTimer::KitchenTimer(Clock* _cl) {
  sen[0] = _cl;
  sen[1] = new SetTimeSwitch();
  sen[2] = new ResetSwitch();
  sen[3] = new StartSwitch(); //本当はupとdownで分けたい
  sen[4] = new PauseSwitch();
  
  for(int i = 0; i < SEN_NUM; i++) {
    sen[i] -> attachObserver(this);
  }

  act[0] = new TimeDisplay();
  act[1] = new PressedSign(); //反応確認装置 本当は操作によって一個一個分けたい
  //act[2] = new BGM(); //最後に鳴らす

  //for State Pattern
  current_state = StopState::getInstance();
  remain_time = 0;

}

KitchenTimer::~KitchenTimer() {
  for (int i = 0; i < SEN_NUM; i++) {
    delete(sen[i]);
  }
  for (int i = 0; i < ACT_NUM; i++) {
    delete(act[i]);
  }
  delete(current_state);
}

void KitchenTimer::update(RequestSensor* rs) {
  ResponseActuator::response res = ResponseActuator::NO_RESPONSE;
  //state patern
  res = current_state->handle(this, rs->getRequest()); 

  for (int i = 0; i < ACT_NUM; i++) {
    act[i]->handle(this, res);
  }
}

void KitchenTimer::handle() {
  for (int i = 0; i < SEN_NUM; i++) {
    sen[i]->handle();
  }
}

int KitchenTimer::getRemainTime() {
  return remain_time;
}

void KitchenTimer::setRemainTime(int time) {
  remain_time = time;
}

void KitchenTimer::addRemainTime(int time) {
  remain_time += time;
}

void KitchenTimer::startClock() {
  sen[0]->startClock();
}

void KitchenTimer::stopClock() {
  sen[0]->stopClock();
}

void KitchenTimer::TransitionTo(State *state){
  if(this->current_state != nullptr)
    delete this->current_state;
  this->current_state = state;
  //this->current_state->set_KitchenTimer(this);
}

