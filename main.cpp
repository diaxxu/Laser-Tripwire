#include <WiFi.h>
#include <HTTPClient.h>
#include "../include/secrets.h"

#define LDR_PIN 34           // Analog pin connected to LDR
#define THRESHOLD 2000       // Tune this depending on your light level
bool alarmTriggered = false;

void sendTelegramAlert() {
  HTTPClient http;
  String message = "🛑 INTRUDER ALERT: Laser beam interrupted!";
  String url = "https://api.telegram.org/bot" + String(TELEGRAM_TOKEN) +
               "/sendMessage?chat_id=" + TELEGRAM_CHAT_ID +
               "&text=" + message;

  http.begin(url);
  int httpResponseCode = http.GET();

  if (httpResponseCode > 0) {
    Serial.println("Telegram message sent!");
  } else {
    Serial.print("Error sending Telegram message: ");
    Serial.println(httpResponseCode);
  }

  http.end();
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(LDR_PIN, INPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n✅ WiFi Connected!");
  Serial.println(WiFi.localIP());
}

void loop() {
  int lightValue = analogRead(LDR_PIN);
  Serial.println(lightValue);

  if (lightValue < THRESHOLD && !alarmTriggered) {
    alarmTriggered = true;
    Serial.println("🚨 Laser beam broken!");
    sendTelegramAlert();
    delay(5000); // prevent spamming
  } else if (lightValue >= THRESHOLD && alarmTriggered) {
    alarmTriggered = false;
    Serial.println("🔁 Beam restored");
  }

  delay(200);
}
