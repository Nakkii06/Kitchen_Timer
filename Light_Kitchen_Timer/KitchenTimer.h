#ifndef KitchenTimer_H
#define KitchenTimer_H

#include <KitchenShield.h>

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
#include "State.h"

//sen[]とact[]の数を一斉定義
#define SEN_NUM 5
#define ACT_NUM 2

class KitchenTimer {
  private:
    RequestSensor* sen[SEN_NUM];
    ResponseActuator* act[ACT_NUM];
    
    State *current_state;
    int remain_time;
    
  public:
    KitchenTimer(Clock* _cl);
    ~KitchenTimer();
    int getRemainTime();
    void setRemainTime(int time);
    void addRemainTime(int time);
    void update(RequestSensor* rs);
    void handle();
    void startClock();
    void stopClock();

    //for State patern
    void TransitionTo(State *state);
};

#endif