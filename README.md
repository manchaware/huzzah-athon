# HUZZAH-athon


## Dependencies

**Arduino IDE**  
Download `1.8.7` from [Arduino.cc](https://www.arduino.cc/en/Main/Software)

**ESP32 Drivers**  
Download `VCP` from [Silabs](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)

**ESP32 Board Definitions**  
*After* installing Arduino and the ESP32 drivers, install the board definitions so it shows up in the Arduino IDE  
https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/boards_manager.md

**NeoTrellis Libraries**  
https://learn.adafruit.com/adafruit-neotrellis/arduino-code

## Test your EPS32 internet connection
Clone this repo into your Arduino project directory (most likely `/Documents/Arduino`)  

Open `WiFiTest.ino`

Connect your HUZZAH32 via USB and make sure it's selected by choosing `/dev/cu.SLAB_USBtoUART` from `Tools > Port:` menu

Upload your sketch by hitting the right-facing arrow (or `CMD+U`)

Open your serial monitor by hitting the magnifying glass on the far right (or `SHIFT+CMD+M`)

You should see:
```
connecting to wifitest.adafruit.com
Requesting URL: /testwifi/index.html
HTTP/1.1 200 OK
Server: nginx/1.10.3 (Ubuntu)
Date: Fri, 19 Oct 2018 22:27:51 GMT
Content-Type: text/html
Content-Length: 73
Last-Modified: Thu, 16 Feb 2017 17:42:29 GMT
Connection: close
ETag: "58a5e485-49"
Accept-Ranges: bytes

This is a test of the CC3000 module!
If you can read this, its working :)
closing connection
```
**If that works, congrats, your Adafruit HUZZAH32 works! Time for a beer!**

If it doesn't, make sure you update your wifi credentials to connect to your network
```
// WiFi credentials.
const char* WIFI_SSID = "flow-iot";
const char* WIFI_PASS = "";
```

## Reference
**Adafruit NeoTrellis**  
https://learn.adafruit.com/adafruit-neotrellis

**Adafruit HUZZAH32 - ESP32 Feather**  
https://learn.adafruit.com/adafruit-huzzah32-esp32-feather/overview
