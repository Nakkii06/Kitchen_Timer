#ifndef KitchenTimer_H
#define KitchenTimer_H

#include <KitchenShield.h>

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

class KitchenTimer {
  public:
    KitchenTimer(State *state):state_() {
      
    }

  private:
    RequestSensor* sen[4];
    ResponseActuator* act[2];
    
    State *state_;
    int remain_time = 0;
    
  public:
    KitchenTimer(Clock* _cl);
    ~KitchenTimer();
    int getRemainTime();
    void setRemainTime(int time);
    void addRemainTime(int time);
    //statu getStatus();
    void update(RequestSensor* rs);
    void handle();
};

#endif