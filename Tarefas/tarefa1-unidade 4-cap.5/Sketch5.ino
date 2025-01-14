#define LED_RED_PIN 9
#define LED_BLUE_PIN 10

int dutyCycleRed = 13;
int increment = 13;
unsigned long previousMillis = 0;
const long interval = 2000;

void setup() {
  Serial.begin(9600);
  delay(1000);

  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);

  TCCR1A = (1 << COM1A1) | (1 << WGM11);
  TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS10);
  ICR1 = 16000;
  OCR1A = dutyCycleRed * ICR1 / 255;

  TCCR2A = (1 << COM2A1) | (1 << WGM21) | (1 << WGM20);
  TCCR2B = (1 << CS20);
  OCR2A = 128;

  Serial.println("Sistema iniciado.");
  Serial.println("LED Vermelho (PWM a 1kHz) e LED Azul (PWM a 10kHz) estão ativos.");
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    dutyCycleRed += increment;
    if (dutyCycleRed > 255) {
      dutyCycleRed = 13;
    }

    OCR1A = dutyCycleRed * ICR1 / 255;

    Serial.print("Duty cycle do LED vermelho: ");
    Serial.print(dutyCycleRed * 100 / 255);
    Serial.println("%");

    Serial.println("LED azul com PWM de 10kHz.");
  }
}
