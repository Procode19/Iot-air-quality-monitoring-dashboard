#include <WiFi.h>
#include "DHT.h"

// ================= DHT22 =================
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// ================= PINS =================
#define GAS_PIN 34
#define LED_PIN 2
#define BUZZER_PIN 15

// ================= WIFI =================
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// ================= THINGSPEAK =================
const char* server = "api.thingspeak.com";
String apiKey = "J2T7XOU8J40XF96T";

WiFiClient client;

// ================= AQI FUNCTION =================
int getAQI(int gasValue) {

  if (gasValue < 1500) {
    return 50;   // Good
  }

  else if (gasValue < 2500) {
    return 100;  // Moderate
  }

  else if (gasValue < 3200) {
    return 150;  // Poor
  }

  else {
    return 250;  // Hazardous
  }
}

// ================= SETUP =================
void setup() {

  Serial.begin(115200);
  dht.begin();

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.println("Connecting to WiFi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");
}

// ================= LOOP =================
void loop() {

  // Read sensors
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int gasValue = analogRead(GAS_PIN);

  // Calculate AQI
  int aqi = getAQI(gasValue);

  // ===== Serial Monitor =====
  Serial.println("---------------------------");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  Serial.print("AQI: ");
  Serial.println(aqi);

  // ===== ALERT SYSTEM =====
  if (aqi > 150) {

    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);

    Serial.println("⚠ HIGH POLLUTION ALERT");
  }

  else {

    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }

  // ===== SEND DATA TO THINGSPEAK =====
  if (client.connect(server, 80)) {

    String url = "/update?api_key=" + apiKey +
                 "&field1=" + String(temperature) +
                 "&field2=" + String(humidity) +
                 "&field3=" + String(aqi) +
                 "&field4=" + String(gasValue);

    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + server + "\r\n" +
                 "Connection: close\r\n\r\n");

    Serial.println("✅ Data sent to ThingSpeak");
  }

  client.stop();

  delay(15000); // ThingSpeak minimum delay
}