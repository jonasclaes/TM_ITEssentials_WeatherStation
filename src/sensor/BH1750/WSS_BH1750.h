#ifndef WSS_BH1750_H
#define WSS_BH1750_H

#include "sensor/Sensor.h"
#include <Wire.h>
#include <BH1750.h>

namespace WeatherStation {
    namespace Sensor {
        class WSS_BH1750
        {
        protected:
            BH1750 lightSensor;
        public:
            WSS_BH1750();
            ~WSS_BH1750();

            bool setup();
            void loop();
            float getLightLevel();
        };
    }
}

#endif