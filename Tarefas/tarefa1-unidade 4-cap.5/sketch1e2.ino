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

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonAPin, INPUT_PULLUP);
  pinMode(buttonBPin, INPUT_PULLUP);
  Serial.begin(9600);
  initializeOLED();
  displayText("Sistema Inicializado");
  delay(2000);
  clearDisplay();
}

void loop() {
  buttonAState = digitalRead(buttonAPin);
  buttonBState = digitalRead(buttonBPin);

  if (buttonAState != lastButtonAState) {
    if (buttonAState == LOW) {
      buttonPressCount++;
      Serial.print("Comando Botão A: Contagem de pressões: ");
      Serial.println(buttonPressCount);
      displayText("Press. Bot. A: ");
    }
    delay(50);
  }
  lastButtonAState = buttonAState;

  if (buttonBState != lastButtonBState) {
    if (buttonBState == LOW) {
      isLowFrequency = !isLowFrequency;
      Serial.print("Comando Botão B: Mudança de frequência para ");
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
