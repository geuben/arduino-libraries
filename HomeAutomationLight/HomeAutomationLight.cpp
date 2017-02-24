#include "Arduino.h"
#include "HomeAutomationLight.h"

HomeAutomationLight::HomeAutomationLight(int pin, boolean active_high=true);
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  _active_high = active_high;
  off();
}

boolen HomeAutomationLight::is_on() {
  return _on;
}

void HomeAutomationLight::off() {
  if (_active_high) {
    digitalWrite(_pin, LOW);
  } else {
    digitalWrite(_pin, HIGH);
  }
  _on = false;
}

void HomeAutomationLight::on() {
  if (_active_high) {
    digitalWrite(_pin, HIGH);
  } else {
    digitalWrite(_pin, LOW);
  }
  _on = true;
}

void HomeAutomationLight::toggle() {
  if (is_on()) {
    off();
  } else {
    on();
  }
}

