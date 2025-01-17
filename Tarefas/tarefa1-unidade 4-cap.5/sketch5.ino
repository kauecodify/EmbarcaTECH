// definindo os pinos dos LEDs RGB
const int redPin = 9;   // LED vermelho conectado ao pino 9 (PWM)
const int greenPin = 10; // LED verde conectado ao pino 10 (PWM)
const int bluePin = 11;  // LED azul conectado ao pino 11 (PWM)

// intervalo para atualizar o duty cycle (2 segundos)
unsigned long previousMillisRed = 0;
const long intervalRed = 2000;  // 2 segundos

// inicio
int dutyCycleRed = 13;  // 5% de duty cycle para o LED vermelho
int dutyCycleGreen = 0; // 0% de intensidade para o LED verde
int dutyCycleBlue = 0;  // 0% de intensidade para o LED azul

void setup() {
  // inicializando os pinos como saída
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // atualizando o duty cycle do LED vermelho a cada 2 segundos
  unsigned long currentMillisRed = millis();
  if (currentMillisRed - previousMillisRed >= intervalRed) {
    // salva o tempo da última atualização
    previousMillisRed = currentMillisRed;

    // atualiza o duty cycle do LED vermelho (incrementa em 5%)
    dutyCycleRed += 13;  // 5% de 255 é aproximadamente 13

    if (dutyCycleRed > 255) {
      dutyCycleRed = 13;  // retorna para 5% de duty cycle
    }
  }

  // LEDs verde e azul (efeito de respiração)
  if (dutyCycleGreen < 255) {
    dutyCycleGreen += 5;  // aumenta o duty cycle do LED verde
  } else {
    dutyCycleGreen = 0;  // reseta o duty cycle do LED verde para 0
  }

  if (dutyCycleBlue < 255) {
    dutyCycleBlue += 5;   // aumenta o duty cycle do LED azul
  } else {
    dutyCycleBlue = 0;    // reseta o duty cycle do LED azul para 0
  }

  // aciona os LEDs com os duty cycles atualizados
  analogWrite(redPin, dutyCycleRed);    // controle do LED vermelho
  analogWrite(greenPin, dutyCycleGreen); // controle do LED verde
  analogWrite(bluePin, dutyCycleBlue);   // controle do LED azul
}
