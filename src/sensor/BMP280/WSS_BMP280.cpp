#include "WSS_BMP280.h"

using namespace WeatherStation::Sensor;

WSS_BMP280::WSS_BMP280() {}

WSS_BMP280::~WSS_BMP280() {
    delete bmp_temp;
    delete bmp_pressure;
}

bool WSS_BMP280::setup() {
    if (!bmp.begin()) {
        return false;
    }

    bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,
                  Adafruit_BMP280::SAMPLING_X2,
                  Adafruit_BMP280::SAMPLING_X16,
                  Adafruit_BMP280::FILTER_X16,
                  Adafruit_BMP280::STANDBY_MS_500);
    
    return true;
}

void WSS_BMP280::loop() {
    bmp_temp->getEvent(&temp_event);
    bmp_pressure->getEvent(&pressure_event);
}

void WSS_BMP280::printInfo() {
    bmp_temp->printSensorDetails();
    bmp_pressure->printSensorDetails();
}

float WSS_BMP280::getTemperature() {
    return temp_event.temperature;
}

float WSS_BMP280::getPressure() {
    return pressure_event.pressure;
}