#include <KitchenShield.h>

#include "StopState.h"
#include "KitchenTimer.h"
#include "State.h"

static StopState* getInstance() {
      static StopState m_pStop;
      return &m_pStop;
}

ResponseActiatpr::response 