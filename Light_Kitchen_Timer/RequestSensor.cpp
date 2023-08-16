#include "RequestSensor.h"
#include "KitchenTimer.h"

RequestSensor::~RequestSensor() {
  detachObserver();
}

void RequestSensor::attachObserver(KitchenTimer* timer) {
  observer = timer;
}

void RequestSensor::detachObserver() {
  observer = NULL;
}

RequestSensor::request RequestSensor::getRequest() {
  return req;
}

void RequestSensor::setRequest(RequestSensor::request r) {
  req = r;
}

void RequestSensor::notify() {
  if (observer != NULL) {
    observer->update(this);
  }
}

void RequestSensor::startClock(){}
void RequestSensor::stopClock(){}