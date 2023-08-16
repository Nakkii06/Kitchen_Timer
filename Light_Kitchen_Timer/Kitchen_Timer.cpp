#include <KitchenShield.h>

#include "KitchenTimer.h"

//sensor header file include, sen[]の要素の名前と同じ
#include "Clock.h"
#include "SetTimeSwitch.h"
#include "ResetSwitch.h"
#include "StartSwitch.h"

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
  
  for(int i = 0; i < 4; i++) {
    sen[i] -> attachObserver(this);
  }

  act[0] = new TimeDisplay();
  act[1] = new PressedSign(); //反応確認装置 本当は操作によって一個一個分けたい
  //act[2] = new BGM(); //最後に鳴らす
}

KitchenTimer::~KitchenTimer() {
  for (int i = 0; i < 4; i++) {
    delete(sen[i]);
  }
  for (int i = 0; i < 2; i++) {
    delete(act[i]);
  }
}

void KitchenTimer::update(RequestSensor* rs) {
  ResponseActuator::response res = ResponseActuator::NO_RESPONSE;
  status s = stop;

  switch(s) {//状態遷移図に従う
    case stop: //初期停止中
      switch(rs -> getRequest()) {
        case RequestSensor::START_COUNT:
          //アップかダウンをremain_timeから判別，clockをスタートさせる
          if(remain_time == 0) {
            //FIXME
            //res = ResponseActuator:: START_COUNT;
            //RequestSensor::Clock->startClock();
            MsTimer2::start();
            s = countUp;
          } else if(remain_time != 0) {
            //FIXME
            //res = ResponseActuator:: START_COUNT;
            //RequestSensor::Clock->startClock();
            s = countDown;
            MsTimer2::start();
          }
          break;

        case RequestSensor::RESET:
          remain_time = 0;
          res = ResponseActuator::SHOW_TIME;
          s = stop;
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

    case countUp://カウントアップ中
      switch(rs -> getRequest()) {
        case RequestSensor::SECOND_PASS:
          remain_time++;
          res = ResponseActuator::SHOW_TIME;
          break;

        default:
          break;
      }

    case countDown://カウントダウン中
      switch(rs -> getRequest()) {
        case RequestSensor::SECOND_PASS: 
          if(remain_time == 0) {
            res = ResponseActuator::BGM;
            s = stop; //よくない，次押されるのを待って止める
             break;
          } else {
            remain_time--;
            res = ResponseActuator::SHOW_TIME;
            break;
          }     

        default:
          break;
      }

    default:
      break;
  }
  for (int i = 0; i < 2; i++) {
    act[i]->handle(this, res);
  }
}



void KitchenTimer::handle() {
  for (int i = 0; i < 4; i++) {
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