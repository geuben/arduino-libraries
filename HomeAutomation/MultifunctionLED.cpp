#include "MultifunctionLED.h"
#include "Arduino.h"

MultifunctionLED::MultifunctionLED(int pin)
  : _pin(pin), _active_high(false), _on(false), _displace(1000), _fade_time(0)
{}

void MultifunctionLED::off() {
  if (_active_high) {
    digitalWrite(_pin, LOW);
  } else {
    digitalWrite(_pin, HIGH);
  }
  _on = false;
}

void MultifunctionLED::on() {
  if (_active_high) {
    digitalWrite(_pin, HIGH);
  } else {
    digitalWrite(_pin, LOW);
  }
  _on = true;
}

void MultifunctionLED::fade_cont(unsigned int period, int max_brightness) {
  _fade_period = period;
  _fade_max_brightness = max_brightness;
  _fade_cont = true;
}

void MultifunctionLED::stop_fade() {
  _fade_cont = false;
  off();
}

void MultifunctionLED::update() {
  if (_fade_cont) {
    update_fade_cont();
  }
}

void MultifunctionLED::update_fade_cont() {
  _fade_time = millis();
  int brightness_factor = map(100-_fade_max_brightness, 0, 100, 0, 127);
  int value = (128 + brightness_factor)+(127 - brightness_factor)*cos(2*PI/_fade_period*(_displace-_fade_time));
  analogWrite(_pin, value);
}
