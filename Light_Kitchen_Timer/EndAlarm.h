#ifndef EndAlarm_H

#include <KitchenShield.h>
#include "ResponseActuator.h"

class EndAlarm : public ResponseActuator {
  private:
    Buzzer* buz;
  public:
    EndAlarm();
    ~EndAlarm();
    void handle(KitchenTimer* timer, ResponseActuator::response res);
    void beet(int k, int l);
};

#endif