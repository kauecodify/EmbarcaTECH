#include <Arduino.h>

// definição do pino do sensor de temperatura (exemplo usando um sensor de temperatura analógico)
const int sensorTempPin = A0;

// definição do pino do LED
const int ledPin = 13;  // LED no pino digital 13

void setup() {
  Serial.begin(9600);  // inicializa o monitor serial
  pinMode(sensorTempPin, INPUT);  // define o pino do sensor como entrada
  pinMode(ledPin, OUTPUT);  // define o pino do LED como saída
}

void loop() {
  digitalWrite(ledPin, HIGH);  // acende o LED indicando que o processo está ocorrendo

  int sensorValue = analogRead(sensorTempPin);  // lê o valor do sensor
  float voltage = sensorValue * (5.0 / 1023.0);  // converte para tensão
  float temperatureCelsius = (voltage - 0.5) * 100.0;  // fórmula para converter a tensão para temperatura em celsius

  // conversão para fahrenheit
  float temperatureFahrenheit = (temperatureCelsius * 9.0 / 5.0) + 32;

  // exibe no console
  Serial.print("temperatura em celsius: ");
  Serial.print(temperatureCelsius);
  Serial.print("°C, ");
  Serial.print("temperatura em fahrenheit: ");
  Serial.print(temperatureFahrenheit);
  Serial.println("°F");

  digitalWrite(ledPin, LOW);  // apaga o LED após a leitura

  delay(1000);  // atraso de 1 segundo entre as leituras
}
