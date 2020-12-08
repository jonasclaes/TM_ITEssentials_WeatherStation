#ifndef WS_MQTT_H
#define WS_MQTT_H

#include <WiFiClient.h>
#include <PubSubClient.h>
#include "config.h"

namespace WeatherStation {
    namespace MQTT {
        class WS_MQTT
        {
        private:
            const char* server = WS_MQTT_SERVER;
            const char* user = WS_MQTT_USER;
            const char* password = WS_MQTT_PASSWORD;
            const long channelId = WS_MQTT_CHANNEL_ID;
            const char* apiReadKey = WS_MQTT_READ_API_KEY;
            const char* apiWriteKey = WS_MQTT_WRITE_API_KEY;
        protected:
            WiFiClient wiFiClient;
            PubSubClient client{wiFiClient};
        public:
            WS_MQTT();
            ~WS_MQTT();

            bool setup();
            void loop();
            bool sendData(float temperature, float pressure, float lightLevel);
        };
    }
}

#endif