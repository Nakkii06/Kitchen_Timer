#include <MsTimer2.h>
#include <KitchenShield.h>

#include"KitchenTimer.h"
#include "Clock.h"

KitchenTimer* kt;
Clock* cl;
State* s;
void tick() {
  cl -> setInterrupted(true);
}

void setup() {
  cl = new Clock();
  kt = new KitchenTimer(cl, s);

}

void loop() {
  kt ->handle();
  
}