#include <KitchenShield.h>

#include "KitchenTimer.h"
#include "TimeDisplay.h"

TimeDisplay::TimeDisplay() {
  disp = new Display();
  disp->init();
}

TimeDisplay::~TimeDisplay() {
  delete(disp);
}

void TimeDisplay::handle(KitchenTimer* timer, ResponseActuator::response res) {
  if (res == ResponseActuator::SHOW_TIME || ALARM) {
    t = timer->getRemainTime();
    a = t/600;
    b = (t-a*600)/60;
    c = (t-a*600-b*60)/10;
    d = t-a*600-b*60-c*10; 
    
    disp->writeDigitNum(POS_D1,a,false);
    disp->writeDigitNum(POS_D2,b,false);
    disp->writeColon(COLON_BOTH);
    disp->writeDigitNum(POS_D3,c,false);
    disp->writeDigitNum(POS_D4,d,false);
    disp->update();

  } 
}