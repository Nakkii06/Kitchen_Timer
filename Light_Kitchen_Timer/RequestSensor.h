#ifndef RequestSensor_H
#define RequestSensor_H

#include <KitchenShield.h>

class KitchenTimer;

class RequestSensor {
  public:
    enum request {
      NO_REQUEST,
      START_COUNT,
      PAUSE_COUNT,
      RESTART_COUNT,
      ADD_TIME_ONEMIN,
      ADD_TIME_TENSEC,
      RESET,
      SECOND_PASS
    };

  private:
    KitchenTimer* observer;
    request req;
  
  public:
    virtual ~RequestSensor();
    virtual void attachObserver(KitchenTimer* timer);
    virtual void detachObserver();
    virtual void setRequest(request r);
    virtual request getRequest();
    virtual void notify();
    virtual void handle() = 0;

    //for Clock class
    virtual void startClock();
    virtual void stopClock();
};

#endif