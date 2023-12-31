#ifndef Clock_H
#define Clock_H

#include <MsTimer2.h>
#include "RequestSensor.h"

class Clock : public RequestSensor {
  private:
    boolean interrupted;
  public:
    Clock();
    ~Clock();
    void setInterrupted(boolean _intr);
    void handle();
    void startClock();
    void stopClock();
};

#endif