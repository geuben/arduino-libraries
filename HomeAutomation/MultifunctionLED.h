#ifndef MULTIFUNCTION_LED_H
#define MULTIFUNCTION_LED_H
#include "Arduino.h"

class MultifunctionLED
{
  public:
    MultifunctionLED(int pin);
    void on();
    void off(); 
    void fade_cont(unsigned int period, int max_brightness);
    void stop_fade();
    void update();
  private:
    void update_fade_cont();

    int _pin;
    boolean _active_high;
    boolean _on;
    int _displace;
    unsigned int _fade_period;
    int _fade_max_brightness;
    boolean _fade_cont;
    long _fade_time;
};
#endif
