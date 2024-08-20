//EV-UTEM-DASHBOARD-FAVORIOT

#include <Arduino.h>

#include "WiFiS3.h"
#include "arduino_secrets.h"

char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;
char fav_apikey[] = SECRET_APIKEY;
char server[] = "apiv2.favoriot.com";

int status = WL_IDLE_STATUS;
String apikey = fav_apikey; // Replace with your Favoriot API key

WiFiClient client;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect
  }

  // Check for WiFi module
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Please upgrade the firmware");
  }

  // Attempt to connect to WiFi network
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    delay(10000);
  }

  // Print connection details
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Signal strength (RSSI): ");
  Serial.println(WiFi.RSSI());
  Serial.println();

  // Connect to server (already done in the loop that connects to WiFi)
  // if (client.connect(server, 80)) {
  //   Serial.println("connected to server");
  // }

}

void loop() {
  // Assuming all necessary sensor readings are updated here
  // float voltage = getVoltage();       // Replace with the actual function to get voltage
  // float current = getCurrent();       // Replace with the actual function to get current
  // float power = voltage * current;    // Calculating power as an example
  // int throttle = getThrottle();       // Replace with the actual function to get throttle position
  // int motorRpm = getMotorRpm();       // Replace with the actual function to get motor RPM
  // int wheelRpm = getWheelRpm();       // Replace with the actual function to get wheel RPM
  // float speed = getSpeed();           // Replace with the actual function to get speed
  // float temp1 = getTemp1();           // Replace with the actual function to get temperature 1
  // float temp2 = getTemp2();           // Replace with the actual function to get temperature 2
  // float temp3 = getTemp3();           // Replace with the actual function to get temperature 3
  // float temp4 = getTemp4();           // Replace with the actual function to get temperature 4
  // float temp5 = getTemp5();           // Replace with the actual function to get temperature 5
  // float temp6 = getTemp6();           // Replace with the actual function to get temperature 6

  float voltage = 0.5;       // Replace with the actual function to get voltage
  float current = 1.5;       // Replace with the actual function to get current
  float power = voltage * current;    // Calculating power as an example
  int throttle = 20;       // Replace with the actual function to get throttle position
  int motorRpm = 1000;       // Replace with the actual function to get motor RPM
  int wheelRpm = 2500;       // Replace with the actual function to get wheel RPM
  float speed = 25.1;           // Replace with the actual function to get speed
  float temp1 = 25.2;           // Replace with the actual function to get temperature 1
  float temp2 = 26.3;           // Replace with the actual function to get temperature 2
  float temp3 = 27.4;           // Replace with the actual function to get temperature 3
  float temp4 = 28.5;           // Replace with the actual function to get temperature 4
  float temp5 = 29.6;           // Replace with the actual function to get temperature 5
  float temp6 = 30.7;           // Replace with the actual function to get temperature 6

  // Send data to Favoriot platform
  if (client.connect(server, 80)) {
    Serial.println("Sending data...");

    // Create JSON string with multiple data points
    String json = "{\"device_developer_id\":\"evdash_1_device@ev_utem_favoriot\",\"data\":{";
    json += "\"Voltage\":\"" + String(voltage) + "\",";
    json += "\"Current\":\"" + String(current) + "\",";
    json += "\"Power\":\"" + String(power) + "\",";
    json += "\"Throttle\":\"" + String(throttle) + "\",";
    json += "\"MotorRpm\":\"" + String(motorRpm) + "\",";
    json += "\"WheelRpm\":\"" + String(wheelRpm) + "\",";
    json += "\"Speed\":\"" + String(speed) + "\",";
    json += "\"Temp1\":\"" + String(temp1) + "\",";
    json += "\"Temp2\":\"" + String(temp2) + "\",";
    json += "\"Temp3\":\"" + String(temp3) + "\",";
    json += "\"Temp4\":\"" + String(temp4) + "\",";
    json += "\"Temp5\":\"" + String(temp5) + "\",";
    json += "\"Temp6\":\"" + String(temp6) + "\"}}";

    // Serial output for debugging
    Serial.println("\nVoltage : " + String(voltage) + " V");
    Serial.println("Current : " + String(current) + " A");
    Serial.println("Power : " + String(power) + " W");
    Serial.println("Throttle : " + String(throttle));
    Serial.println("Motor RPM : " + String(motorRpm));
    Serial.println("Wheel RPM : " + String(wheelRpm));
    Serial.println("Speed : " + String(speed) + " km/h");
    Serial.println("Temp1 : " + String(temp1) + " °C");
    Serial.println("Temp2 : " + String(temp2) + " °C");
    Serial.println("Temp3 : " + String(temp3) + " °C");
    Serial.println("Temp4 : " + String(temp4) + " °C");
    Serial.println("Temp5 : " + String(temp5) + " °C");
    Serial.println("Temp6 : " + String(temp6) + " °C");

    // Make HTTP request
    client.println("POST /v2/streams HTTP/1.1");
    client.println("Host: apiv2.favoriot.com");
    client.print("apikey: ");
    client.println(apikey);
    client.println("Content-Type: application/json");
    client.println("cache-control: no-cache");
    client.print("Content-Length: ");
    client.println(json.length());
    client.println("Connection: close");
    client.println();
    client.println(json);
    Serial.println("Data sent!");
  } else {
    Serial.println("Connection failed!");
  }

  delay(10000);  // Delay to avoid sending data too frequently
}
