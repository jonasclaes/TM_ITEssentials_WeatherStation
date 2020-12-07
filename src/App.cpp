#include "App.h"

using namespace WeatherStation;

App::App()
{
}
    
App::~App()
{
}

bool App::setup()
{
    Serial.begin(9600);
    Serial.println();
    Serial.println("WeatherStation");
    Serial.println("Initializing...");

    Serial.println();

    if (!bmp.setup()) {
        Serial.println("Could not setup BMP280 sensor.");
        return false;
    } else {
        Serial.println("Setup BMP280 sensor.");
        bmp.printInfo();
    }

    Serial.println();

    if (!lightSensor.setup()) {
        Serial.println("Could not setup BH1750 sensor.");
        return false;
    } else {
        Serial.println("Setup BH1750 sensor.");
    }

    Serial.println();

    if (!wireless.connect()) {
        Serial.println("Could not setup WiFi.");
        return false;
    } else {
        Serial.println("Setup WiFi.");
    }

    Serial.println();

    Serial.println("Initialized!");

    return true;
}

void App::loop() {
    // Process sensors
    bmp.loop();
    lightSensor.loop();

    Serial.print("Temperature: ");
    Serial.print(bmp.getTemperature());
    Serial.println(" °C");

    Serial.print("Pressure: ");
    Serial.print(bmp.getPressure());
    Serial.println(" hPa");

    Serial.print("Light level: ");
    Serial.print(lightSensor.getLightLevel());
    Serial.println(" lx");

    Serial.println();
    delay(2000);
}