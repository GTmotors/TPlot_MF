#include <ESP8266WiFi.h>
#include "secrets.h" // Inclure le fichier secrets.h

void setup() {
  Serial.begin(9600);
  delay(100);

  // Connexion au réseau WiFi
  WiFi.begin(ssid, password); // Utilisation des variables du fichier secrets.h

  Serial.println("Connexion au réseau WiFi en cours...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Connexion WiFi établie !");
}

void loop() {
  // Lecture de la qualité du signal WiFi (RSSI)
  int32_t rssi = WiFi.RSSI();

  Serial.print("Qualité du signal WiFi (RSSI) : ");
  Serial.print(rssi);
  Serial.println(" dBm");

  delay(10000); // Attente de 10 secondes entre chaque lecture
}
