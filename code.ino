#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int motorPin1 = 8;
int motorPin2 = 9;
int enablePin = 10;

float threshold = 30.0;   // Temperature threshold

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
}

void loop() {
  float temperature = dht.readTemperature();

  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  if (temperature > threshold) {
    // Turn motor ON
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);

    int speedValue = map(temperature, 30, 40, 150, 255);
    speedValue = constrain(speedValue, 150, 255);
    analogWrite(enablePin, speedValue);

    Serial.println("Fan ON");
  } 
  else {
    // Turn motor OFF
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    analogWrite(enablePin, 0);

    Serial.println("Fan OFF");
  }

  delay(2000);
}
