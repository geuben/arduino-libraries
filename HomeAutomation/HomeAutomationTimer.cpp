#include "HomeAutomationTimer.h"
#include "Arduino.h"

HomeAutomationTimer::HomeAutomationTimer(unsigned long timer_ms, 
                                         Callback trigger_function,
                                         Callback expire_function) {
  _timer_ms = timer_ms;
  _trigger_function = trigger_function;
  _expire_function = expire_function;
  _triggered = false;
}

void HomeAutomationTimer::trigger() {
  _trigger_function();
  _trigger_time_ms = millis();
  _triggered = true;
}

void HomeAutomationTimer::update() {
  if (_triggered) {
    if (millis() - _trigger_time_ms > _timer_ms) {
      _expire_function();
      _triggered = false;
    }
  }
}
