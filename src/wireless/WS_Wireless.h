#ifndef WS_WIRELESS_H
#define WS_WIRELESS_H

#include <WiFi.h>
#include "config.h"

namespace WeatherStation {
    namespace Wireless
    {
        class WS_Wireless
        {
        private:
            const char *ssid = WS_WIFI_SSID;
            const char *password = WS_WIFI_PASSWORD;
        public:
            WS_Wireless();
            ~WS_Wireless();

            bool connect();
        };
    }
}

#endif