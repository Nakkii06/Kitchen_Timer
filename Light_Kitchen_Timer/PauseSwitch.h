#ifndef PauseSwitch_H
#define PauseSwitch_H

#include <KitchenShield.h>
#include "RequestSensor.h"

class PauseSwitch : public RequestSensor {
  private:
    Switch* sw;
    boolean pausing; //切り替えを記録
    RequestSensor::request req;

  public:
    PauseSwitch();
    ~PauseSwitch();
    void handle();
};

#endif