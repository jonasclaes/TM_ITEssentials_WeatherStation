#ifndef WS_APP
#define WS_APP

#include "sensor/BMP280/WSS_BMP280.h"
#include "sensor/BH1750/WSS_BH1750.h"

namespace WeatherStation {
    class App
    {
    private:
        WeatherStation::Sensor::WSS_BMP280 bmp;
        WeatherStation::Sensor::WSS_BH1750 lightSensor;
    public:
        App();
        ~App();

        bool setup();
        void loop();
    };
}

#endif