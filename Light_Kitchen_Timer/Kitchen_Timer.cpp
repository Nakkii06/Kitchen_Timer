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

  current_status = KitchenTimer::STOP;
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

  switch(current_status) {//状態遷移図に従う
    case KitchenTimer::STOP: //初期停止中
      switch(rs -> getRequest()) {
        case RequestSensor::START_COUNT:  
            current_status = KitchenTimer::COUNT_DOWN;
            sen[0]->startClock();
          break;
        case RequestSensor::RESET:
          remain_time = 0;
          res = ResponseActuator::SHOW_TIME;
          current_status = KitchenTimer::STOP;
          break;
        case RequestSensor::ADD_TIME_ONEMIN:
          remain_time += 60;
          res = ResponseActuator::SHOW_TIME; //音もならしたい
          break;
        case RequestSensor::ADD_TIME_TENSEC:
          remain_time += 10;
          res = ResponseActuator::SHOW_TIME;
          break;
        default:
          break;
      }

    case KitchenTimer::COUNT_DOWN://カウントダウン中
      switch(rs -> getRequest()) {
        case RequestSensor::SECOND_PASS: 
          if(remain_time == 0) {
            res = ResponseActuator::BGM;
            current_status = KitchenTimer::STOP; //よくない，次押されるのを待って止める
          } else {
            remain_time--;
            res = ResponseActuator::SHOW_TIME;
          }     
          break;
        case RequestSensor::PAUSE_COUNT:
          res = ResponseActuator::SHOW_TIME; //meaningless??
          current_status = KitchenTimer::PAUSING;
          break;
        default:
          break;
      }
    
    case KitchenTimer::PAUSING: //一時停止　カウントダウン中のみを実装
      switch(rs -> getRequest()) {
        case RequestSensor::RESTART_COUNT:
          res = ResponseActuator::SHOW_TIME; //meaningless??
          current_status = KitchenTimer::COUNT_DOWN;
          break;
        case RequestSensor::RESET:
          remain_time = 0;
          res = ResponseActuator::SHOW_TIME;
          current_status = KitchenTimer::STOP;
          break;
        default:
          break;
      }
      break;

    default:
      break;
  }
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