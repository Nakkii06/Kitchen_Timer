#ifndef ResetSwitch_H
#define ResetSwitch_H

#include <KitchenShield.h>
#include "RequestSensor.h"

class ResetSwitch : public RequestSensor {
  private:
    Switch* sw;
    boolean turnedOn;
    RequestSensor::request req;
  public:
    ResetSwitch();
    ~ResetSwitch();
    void handle();
};

#endif