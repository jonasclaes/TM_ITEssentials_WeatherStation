#ifndef WSS_SENSOR_H
#define WSS_SENSOR_H

namespace WeatherStation {
    namespace Sensor {
        class Sensor
        {
        public:
            virtual bool setup();
            virtual void loop();
        };
    }
}

#endif