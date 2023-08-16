#ifndef RequestSensor_H
#define RequestSensor_H

#include <KitchenShield.h>

class KitchenTimer; //詳しくはKitchenTimer.hで記述

class RequestSensor {
  public:
    enum request {
      NO_REQUEST,
      START_COUNT,
      PAUSE,
      RESTART,
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
};

#endif