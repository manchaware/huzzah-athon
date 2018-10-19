#include <WiFiClientSecure.h>

// WiFi credentials.
const char* WIFI_SSID = "flow-iot";
const char* WIFI_PASS = "";

const char* host = "wifitest.adafruit.com";
const int httpPort = 80;

// Use WiFiClient class to create TCP connections
//WiFiClientSecure client;
WiFiClient client;

void setup() {
  Serial.begin(115200);

  // Giving it a little time because the serial monitor doesn't immediately attach.

  delay(2000);

  Serial.println();
  Serial.println("Running Firmware.");

  connect();
}

void loop() {
  Serial.println("");
  Serial.print("connecting to ");
  Serial.println(host);

  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    delay(10000);
    return;
  }

  // We now create a URI for the request
  String url = "/testwifi/index.html";
  Serial.print("Requesting URL: ");
  Serial.println(url);

  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
  delay(500);

  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println();
  Serial.println("closing connection");

  delay(10000);
}

void connect() {
  // Connect to Wifi.
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
