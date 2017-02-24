#ifndef HOME_AUTOMATOION_LIGHT_H
#define HOME_AUTOMATOION_LIGHT_H
#include "Arduino.h"

class HomeAutomationLight
{
  public:
    HomeAutomationLight(int pin, boolean active_high);
    boolean is_on();
    void on();
    void off();
    void toggle();
  private:
    int _pin;
    boolean _on;
    boolean _active_high;
}
#endif
