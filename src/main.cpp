#include <Arduino.h>
#include <ArduinoJson.h>

const int buzzerPin = 2; // Buzzer Pin Set
const int relayPin = 3;  // Relay Pin Set for LED ON/OFF
int buzzerState = 0;
int relayState = 0;
const int inputPin = 4;
void buzz();

void setup()
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{

  DynamicJsonDocument doc(200);
  char json[200];

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
  if (sensor == "buzzer")
  {
    if (State == 1)
    {
      buzz();
    }
    else if (State == 0)
    {
      noTone(buzzerPin);
    }
  }
  delay(3000);
}

void buzz() // Buzzer Tone adjustment
{
  tone(buzzerPin, 1000); // Send 1KHz sound signal...
  delay(1000);           // ...for 1 sec
  noTone(buzzerPin);     // Stop sound...
  delay(1000);           // ...for 1sec
}