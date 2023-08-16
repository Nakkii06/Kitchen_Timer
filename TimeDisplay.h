//Light.hから改造

#ifndef TimeDisplay_H
#define TimeDisplay_H

#include <KitchenShield.h>
#include "ResponseActuator.h"

class TimeDisplay : public ResponseActuator {
  private:
    Display* disp;
    
    int t; //表示用にKitchentTimerのgetRemainTimeを保存
    int a=0, b=0, c=0, d=0;//表示用メソッドの代入用
    
  public:
    TimeDisplay();
    ~TimeDisplay();
    void handle(KitchenTimer* timer, ResponseActuator::response res);
};

#endif