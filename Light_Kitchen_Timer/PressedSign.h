//Light.hから改造

#ifndef PressedSign_H
#define PressedSign_H

#include <KitchenShield.h>
#include "ResponseActuator.h"

class PressedSign : public ResponseActuator {
  private:
    Buzzer* buz;
  public:
    PressedSign();
    ~PressedSign();
    void handle(KitchenTimer* timer, ResponseActuator::response res);
};

#endif