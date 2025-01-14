#include "WiFi.h"
#include <Wire.h>

#define OLED_I2C_ADDRESS 0x3C
#define OLED_WIDTH 128
#define OLED_HEIGHT 64

const int ledPin = 8;
const int buttonAPin = 7;
const int buttonBPin = 6;

int buttonPressCount = 0;
int buttonAState = 0;
int lastButtonAState = 0;
int buttonBState = 0;
int lastButtonBState = 0;
bool isLowFrequency = false;

#define DS1307_I2C_ADDRESS 0x68

void sendCommand(uint8_t command) {
  Wire.beginTransmission(OLED_I2C_ADDRESS);
  Wire.write(0x00);
  Wire.write(command);
  Wire.endTransmission();
}

void initializeOLED() {
  Wire.begin();
  sendCommand(0xAE);
  sendCommand(0xD5); sendCommand(0x80);
  sendCommand(0xA8); sendCommand(OLED_HEIGHT - 1);
  sendCommand(0xD3); sendCommand(0x00);
  sendCommand(0x40 | 0x00);
  sendCommand(0x8D); sendCommand(0x14);
  sendCommand(0xA1);
  sendCommand(0xC8);
  sendCommand(0xDA); sendCommand(0x12);
  sendCommand(0x81); sendCommand(0xCF);
  sendCommand(0xD9); sendCommand(0xF1);
  sendCommand(0xDB); sendCommand(0x40);
  sendCommand(0xA4);
  sendCommand(0xA6);
  sendCommand(0xAF);
}

void clearDisplay() {
  for (int i = 0; i < 8; i++) {
    sendCommand(0xB0 + i);
    sendCommand(0x00);
    sendCommand(0x10);
    Wire.beginTransmission(OLED_I2C_ADDRESS);
    Wire.write(0x40);
    for (int j = 0; j < OLED_WIDTH; j++) {
      Wire.write(0x00);
    }
    Wire.endTransmission();
  }
}

void displayText(const char* text) {
  clearDisplay();
  sendCommand(0xB0);
  Wire.beginTransmission(OLED_I2C_ADDRESS);
  Wire.write(0x40);
  while (*text) {
    Wire.write(*text++);
  }
  Wire.endTransmission();
}

void writeDS1307(int address, byte value) {
  Wire.beginTransmission(DS1307_I2C_ADDRESS);
  Wire.write(address);
  Wire.write(value);
  Wire.endTransmission();
}

byte readDS1307(int address) {
  Wire.beginTransmission(DS1307_I2C_ADDRESS);
  Wire.write(address);
  Wire.endTransmission();
  Wire.requestFrom(DS1307_I2C_ADDRESS, 1);
  return Wire.read();
}

byte bcdToDec(byte bcd) {
  return (bcd / 16 * 10) + (bcd % 16);
}

void setDS1307Time() {
  writeDS1307(0x00, 0x00);
  writeDS1307(0x01, 0x27);
  writeDS1307(0x02, 0x13);
  writeDS1307(0x04, 0x24);
  writeDS1307(0x05, 0x09);
  writeDS1307(0x06, 0x24);
}

void readDS1307Time() {
  byte second = readDS1307(0x00) & 0x7F;
  byte minute = readDS1307(0x01);
  byte hour = readDS1307(0x02);
  byte day = readDS1307(0x04);
  byte month = readDS1307(0x05);
  byte year = readDS1307(0x06);

  year = bcdToDec(year);
  month = bcdToDec(month);
  day = bcdToDec(day);
  hour = bcdToDec(hour);
  minute = bcdToDec(minute);
  second = bcdToDec(second);

  Serial.print("Hora: ");
  Serial.print(hour, DEC);
  Serial.print(":");
  Serial.print(minute, DEC);
  Serial.print(":");
  Serial.print(second, DEC);
  Serial.print(" Data: ");
  Serial.print(day, DEC);
  Serial.print("/");
  Serial.print(month, DEC);
  Serial.print("/");
  Serial.println(2000 + year, DEC);
}

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonAPin, INPUT_PULLUP);
  pinMode(buttonBPin, INPUT_PULLUP);
  Serial.begin(9600);
  initializeOLED();
  displayText("Sistema Inicializado");
  delay(2000);
  clearDisplay();
  Wire.begin();
  setDS1307Time();
}

void loop() {
  readDS1307Time();
  delay(5000);

  buttonAState = digitalRead(buttonAPin);
  buttonBState = digitalRead(buttonBPin);

  if (buttonAState != lastButtonAState) {
    if (buttonAState == LOW) {
      buttonPressCount++;
      Serial.print("Comando Botao A: Contagem de pressoes: ");
      Serial.println(buttonPressCount);
      displayText("Press. Bot. A: ");
    }
    delay(50);
  }
  lastButtonAState = buttonAState;

  if (buttonBState != lastButtonBState) {
    if (buttonBState == LOW) {
      isLowFrequency = !isLowFrequency;
      Serial.print("Comando Botao B: Mudanca de frequencia para ");
      Serial.println(isLowFrequency ? "1 Hz" : "10 Hz");
      displayText(isLowFrequency ? "Frequencia: 1 Hz" : "Frequencia: 10 Hz");
    }
    delay(50);
  }
  lastButtonBState = buttonBState;

  if (buttonPressCount >= 5) {
    unsigned long startTime = millis();
    unsigned long delayTime = isLowFrequency ? 500 : 50;
    Serial.println("LED piscando...");
    displayText("LED piscando...");
    while (millis() - startTime < 10000) {
      digitalWrite(ledPin, HIGH);
      delay(delayTime);
      digitalWrite(ledPin, LOW);
      delay(delayTime);
    }
    Serial.println("Ciclo de piscagem completo.");
    displayText("Ciclo completo");
    buttonPressCount = 0;
  }
}
