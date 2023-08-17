#ifndef State_H
#define State_H

#include <KitchenShield.h>
#include "KitchenTimer.h"
#include "RequestSensor.h"
class KitchenTimer;

class State {
  protected:
    KitchenTimer *_kt;  
  public:
    //virtual ~State(); //コメントアウトしないとundefined reference to `State::~State()'
    virtual ResponseActuator::response handle(KitchenTimer *kt, RequestSensor::request req) = 0;
    //void set_KitchenTimer(KitchenTimer *kt){this->_kt = kt;}
};

#endif