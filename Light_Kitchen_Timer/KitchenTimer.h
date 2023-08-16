#ifndef KitchenTimer_H
#define KitchenTimer_H

#include <KitchenShield.h>
#include "State.h"

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
  private:
    RequestSensor* sen[4];
    ResponseActuator* act[2];
    
    State* state; //state_
    int remain_time = 0;
    
  public:
    KitchenTimer(Clock* _cl, State* state);
    ~KitchenTimer();
    int getRemainTime();
    void setRemainTime(int time);
    void addRemainTime(int time);
    //statu getStatus();
    void update(RequestSensor* rs);
    void handle();

    void TransitionTo(State* state);
};

#endif