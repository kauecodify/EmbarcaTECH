<img src="https://github.com/user-attachments/assets/0b08ceb0-a126-4d31-b172-6730c338bd7d" width="100" />


# Wokwi - exercícios

1. Elabore um programa para acionar um LED quando o botão A for pressionado 5 vezes, utilizando o temporizador como contador. Quando o valor da contagem atingir 5 vezes, um LED deve ser piscar por 10 segundos na frequência de 10 Hz.

      
2. Na questão anterior, implemente o botão B, para mudar a frequência do LED para 1 Hz.


![image](https://github.com/user-attachments/assets/d01754f1-0352-448a-807d-31cd262dc59d)


3. Elabore um código utilizando a interfaces UART0 e conecte os fios TX e RX atribuídos à essa interface entre. Essa estrutura envia dados e recebe os dados na mesma interface, apenas para verificar seu funcionamento. Utilize a função scanf da biblioteca stdio para enviar via console um dado à placa, em seguida, transmita da UART0 para a UART1, e por fim, transmita o dado recebido para o console utilizando o printf.


![image](https://github.com/user-attachments/assets/61b660a6-570f-43e3-8d8d-5e480b838238)


4. Já para a comunicação I2C, iremos utilizar o DS1307, que é um Real Time Clock – RTC disponível no simulador Wokwi. O endereço I2C do DS1307 é 0x68. Um RTC é um hardware que garante a contagem de tempo na unidade de segundos. Muitos microcontroladores possuem RTC internos, mas alguns fazem uso de hardware externos. Para ler os valores, é necessário inicialmente configurar um valor de data e hora que deve, por exemplo, ser configurado manualmente pelo usuário. Nessa questão você deverá configurar o RTC para 24/09/2024 –13:27:00 e em seguida, realizar a leitura do mesmo a cada 5 segundos, e imprimir na tela do console (Serial USB) o valor lido. Na tabela a seguirão apresentados os principais endereços do RTC DS1307.

![image](https://github.com/user-attachments/assets/ccd0955b-67ac-4b58-8439-2940b43ba50c)

5. Modifique o exemplo de código apresentado na videoaula (reproduzido abaixo) para controlar os três LEDs RGB da placa BitDogLab usando o módulo PWM e interrupções, seguindo as orientações a seguir:

A. O LED vermelho deve ser acionado com um PWM de 1kHz.

B. O duty cycle deve ser iniciado em 5% e atualizado a cada 2 segundos em incrementos de 5%. Quando atingir o valor máximo, deve retornar a 5%.

       ‐ O LED azul deve ser acionado com um PWM de 10kHz.

       
![Captura de tela 2025-01-14 173955](https://github.com/user-attachments/assets/42ea2d98-5390-4782-9377-a407f9c0f2af)

6. Refaça o programa pratico 01 presente no Ebook do Capítulo de ADC, mude a unidade de medida da temperatura de celsius para Fahrenheit.

![Captura de tela 2025-01-16 230035](https://github.com/user-attachments/assets/5d329e87-f9d9-4531-858a-1184de61bdd7)







