#include "WS_Wireless.h"

using namespace WeatherStation::Wireless;

WS_Wireless::WS_Wireless() {}

WS_Wireless::~WS_Wireless() {}

bool WS_Wireless::connect() {
    Serial.print("Connecting to ");
    Serial.print(ssid);
    
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        attempts++;
        
        if (attempts > 10) return false;
    }
    Serial.println();
    Serial.println("WiFi connected.");
    Serial.println("IPv4 address: " + WiFi.localIP().toString());
    Serial.println("IPv6 address: " + WiFi.localIPv6().toString());
    return true;
}
