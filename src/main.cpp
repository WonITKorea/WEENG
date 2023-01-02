#include <Arduino.h>
#include <ArduinoJson.h>

const int BuzzerPin = 2; // Buzzer Pin Set
const int RelayPin = 3;  // Relay Pin Set for LED ON/OFF
int buzzerState = 0;
int relayState = 0;
const int InputPin = 4;
void buzz();

void setup()
{
  pinMode(BuzzerPin, OUTPUT);
  pinMode(RelayPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{

  DynamicJsonDocument doc(200);
  char json[200];
  json[] = Serial.readString();

  // Deserialize the JSON document
  DeserializationError error = deserializeJson(doc, json);

  // Test if parsing succeeds.
  if (error)
  {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }

  // Fetch values.
  //

  const char *sensor = doc["sensor"];
  int State = doc["data"][1];

  // Print values.
  Serial.println("Sensor Variant: ");
  Serial.print(sensor);
  Serial.println("Active: ");
  Serial.print(State, 1);
  delay(3000);
}

void buzz()
{

}