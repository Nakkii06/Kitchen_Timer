#include <KitchenShield.h>

#include "KitchenTimer.h"
#include "EndAlarm.h"

EndAlarm::EndAlarm() {
  buz = new Buzzer();
  buz->init(7);
}

EndAlarm::~EndAlarm() {
  delete(buz);
}

void EndAlarm::handle(KitchenTimer* timer, ResponseActuator::response res) {
  if (res == ResponseActuator::ALARM) {
    beet(LA,250);
    beet(FA,250);
    beet(DO,250);
    beet(FA,250);
    beet(SOL,250);
    beet(DO2,500);
    beet(DO,250);
    beet(SOL,250);
    beet(LA,250);
    beet(SOL,250);
    beet(DO,250);
    beet(FA,1000);
  }
}

void EndAlarm::beet(int k, int l) {
  buz->scale(k);
  buz->times(1,l);
  buz->span(l);
  buz->beep();
  buz->clear();
}

