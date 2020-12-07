#include "WSS_BH1750.h"

using namespace WeatherStation::Sensor;

WSS_BH1750::WSS_BH1750() {}

WSS_BH1750::~WSS_BH1750() {}

bool WSS_BH1750::setup() {
    return lightSensor.begin(BH1750::ONE_TIME_HIGH_RES_MODE);
}

void WSS_BH1750::loop() {
    float lightLevel = lightSensor.readLightLevel();

    if (lightLevel < 0) {
        // Error has occurred!
    } else if (lightLevel > 40000.0) {
        lightSensor.setMTreg(32);
    } else if (lightLevel > 10.0) {
        lightSensor.setMTreg(69);
    } else if (lightLevel <= 10.0) {
        lightSensor.setMTreg(138);
    }
}

float WSS_BH1750::getLightLevel() {
    return lightSensor.readLightLevel();
}