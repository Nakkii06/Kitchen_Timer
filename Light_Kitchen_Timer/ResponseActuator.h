#ifndef ResponseActuator_H
#define ResponseActuator_H

#include "RequestSensor.h"

class KitchenTimer; //詳しくはKitchenTimer.hで記述

class ResponseActuator {
  public:
    enum response {
      START_COUNT,
      NO_RESPONSE,
      SHOW_TIME,
      ALARM
    };
    
    virtual void handle(KitchenTimer* timer, response res) = 0;
};

#endif