#ifndef StartSwitch_H
#define StartSwitch_H

#include <KitchenShield.h>
#include "RequestSensor.h"

class StartSwitch : public RequestSensor {
  private:
    Switch* sw;
    boolean turnedOn;
    RequestSensor::request req;
  public:
    StartSwitch();
    ~StartSwitch();
    void handle();
};

#endif