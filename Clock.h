#ifndef Clock_H
#define Clock_H

#include <MsTimer2.h>
#include "RequestSensor.h"

//test
//#include "ResponseActuator.h"

class Clock : public RequestSensor {
  private:
    boolean interrupted;
  public:
    Clock();
    ~Clock();
    void setInterrupted(boolean _intr);
    void handle();
    
    //test
    //void handle(KitchenTimer* timer, ResponseActuator::response res);

    void startClock();
};

#endif