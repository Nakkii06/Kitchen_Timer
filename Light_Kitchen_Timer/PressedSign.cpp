#include <KitchenShield.h>

#include "PressedSign.h"

PressedSign::PressedSign() {
  buz = new Buzzer();
  buz->init(7);
}

PressedSign::~PressedSign() {
  delete(buz);
}

void PressedSign::handle(KitchenTimer* timer, ResponseActuator::response res) {
  if (res == ResponseActuator::BUZZ) {
    buz->beep();
  }
}