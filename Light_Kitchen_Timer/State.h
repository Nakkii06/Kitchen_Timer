#ifndef State_H
#define State_H

#include"KitchenTimer.h"

class KitchenTimer;

class State {
  protected:
    KitchenTimer* kt;
  public:
    virtual ~State();

    void set_kt(KitchenTimer* kt) {
      this->kt = kt;
    }

    virtual void handle() = 0;
    
};

#endif