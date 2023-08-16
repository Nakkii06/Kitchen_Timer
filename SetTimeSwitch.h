//Light.hから改造

#ifndef SetTime_H
#define SetTime_H

#include <KitchenShield.h>
#include "RequestSensor.h"

class SetTimeSwitch : public RequestSensor {
  private:
    Button* btn0;
    Button* btn1;
    boolean pressed;
    RequestSensor::request req;

  public:
    SetTimeSwitch();
    ~SetTimeSwitch();
    void handle();
};

#endif