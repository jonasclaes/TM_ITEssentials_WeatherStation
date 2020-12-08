#include "WS_MQTT.h"

using namespace WeatherStation::MQTT;

WS_MQTT::WS_MQTT() = default;

WS_MQTT::~WS_MQTT() = default;

bool WS_MQTT::setup() {
    client.setServer(server, 1883);
//    client.setCallback();
    return true;
}

void WS_MQTT::loop() {
    while (!client.connected()) {
        Serial.println("Attempting MQTT connection...");

        uint32_t chipId{0};
        for(int i=0; i<17; i=i+8) {
            chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
        }

        if (client.connect(("ESP32-" + String(chipId)).c_str(), user, password)) {
            Serial.println("Connected to " + String(server));
        } else {
            Serial.print("Failed, rc=");
            Serial.println(client.state());

            delay(2000);
        }
    }

    client.loop();
}

bool WS_MQTT::sendData(float temperature, float pressure, float lightLevel) {
    String topic{"channels/" + String(channelId) + "/publish/" + String(apiWriteKey)};

    // Provision 512 bytes for data.
    char data[512];
    sprintf(data, "field1=%.3f&field2=%.3f&field3=%.3f", temperature, pressure, lightLevel);

    return client.publish(topic.c_str(), data);
}