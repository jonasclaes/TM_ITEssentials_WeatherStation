/**
 * Author: Jonas Claes <r0841639>
 * Description: Weather station based on I²C sensors. 
 */

#include "App.h"

WeatherStation::App app;

void setup() {
  if (!app.setup()) {
    ESP.restart();
  }
}

void loop() {
  app.loop();
}