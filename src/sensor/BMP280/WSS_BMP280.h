#ifndef WSS_BMP280_H
#define WSS_BMP280_H

#include "sensor/Sensor.h"
#include <Wire.h>
#include <Adafruit_BMP280.h>

namespace WeatherStation {
    namespace Sensor {
        class WSS_BMP280: public Sensor
        {
        protected:
            Adafruit_BMP280 bmp;
            Adafruit_Sensor *bmp_temp{bmp.getTemperatureSensor()};
            Adafruit_Sensor *bmp_pressure{bmp.getPressureSensor()};
            sensors_event_t temp_event, pressure_event;
        public:
            WSS_BMP280();
            ~WSS_BMP280();

            bool setup();
            void loop();
            void printInfo();
            float getTemperature();
            float getPressure();
        };
    }
}

#endif