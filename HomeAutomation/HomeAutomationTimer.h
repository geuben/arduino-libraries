#ifndef HOME_AUTOMATION_TIMER_H
#define HOME_AUTOMATION_TIMER_H
#include "Arduino.h"
#include <ArdComLib.h>
#include <ArduinoJson.h>

class HomeAutomationTimer
{
  public:
    using Callback = vl::Func<void()>;

    HomeAutomationTimer(unsigned long timer_ms, 
                        Callback trigger_function,
                        Callback expire_function);
    void trigger();
    void update();
  private:
    boolean _triggered;
    unsigned long _timer_ms;
    unsigned long _trigger_time_ms;
    Callback _trigger_function;
    Callback _expire_function;
};
#endif
