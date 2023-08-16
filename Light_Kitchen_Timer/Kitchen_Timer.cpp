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
  current_state = new StopState;
  remain_time = 0;

}

KitchenTimer::~KitchenTimer() {
  for (int i = 0; i < SEN_NUM; i++) {
    delete(sen[i]);
  }
  for (int i = 0; i < ACT_NUM; i++) {
    delete(act[i]);
  }
}

void KitchenTimer::update(RequestSensor* rs) {
  ResponseActuator::response res = ResponseActuator::NO_RESPONSE;
  res = state->handle(this, rs.getRequest()); //state patern

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