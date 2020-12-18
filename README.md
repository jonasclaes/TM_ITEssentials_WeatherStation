# Thomas More - IT Essentials - Project: Weather Station

This is a project that has been assigned by the teachers of the course IT Essentials at Thomas More Campus Geel to us. The purpose is to teach us some IoT things and provide us with practical experience.

The project consists out of 3 main parts.
- Adafruit ESP32 Feather
  
  This is the development board that we will be using.
- BMP280

  This is a Adafruit BMP280 breakout board which contains the Bosch BMP280 pressure and temperature sensor. This is being controlled through the I2C bus.

- BH1750

  This is a Adafruit BH1750 breakout board which contains a light sensor. This is being controlled through the I2C bus.

The following picture is made by me to show the setup that we're talking about here.
![ESP32-BMP280-BH1750](assets/images/IMG_Overview.JPG)

Since we're using multiple components, we have to design a wiring diagram. I have done this using Fritzing.
![Wiring-Diagram](docs/schematic.png)

I have also created a breadboard layout for reference.
![Breadboard-Diagram](docs/breadboard_layout.png)

