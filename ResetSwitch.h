//Light.hから改造

#ifndef ResetSwitch_H
#define ResetSwitch_H

#include <KitchenShield.h>
#include "RequestSensor.h"

class ResetSwitch : public RequestSensor {
  private:
    Switch* sw;

    //Button* btn0;
    //Button* btn1;

    RequestSensor::request req;
    
  public:
    ResetSwitch();
    ~ResetSwitch();
    void handle();
};

#endif