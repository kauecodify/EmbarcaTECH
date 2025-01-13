<img src="https://github.com/user-attachments/assets/4414aaf1-1b84-45ae-9583-dcb1ac726bda" width="100" />

# IOT - REDE DESCENTRALIZADA

**O projeto utiliza uma Raspberry Pi Zero W como unidade central de comunicação offline, integrando módulos satelitais, LoRa, e Wi-Fi Mesh para transmissão de dados entre dispositivos IoT. Para garantir segurança, emprega criptografia dupla com AES-256 e o protocolo Matrix, assegurando proteção e integridade dos dados em circulação.**

---

# Funcionalidades

*Comunicação via satélite*

*Transmissão direta de pacotes de dados para redes satelitais via RabbitMQ OffLine*

---

# Criptografia Dupla

*AES-256: Primeira camada de criptografia simétrica para proteger os dados*

*Protocolo Matrix (Olm/Megolm): Criptografia ponta a ponta como segunda camada, garantindo segurança adicional*

---

# Rede IoT Descentralizada

*Suporte a LoRa para comunicação de longa distância e baixa energia*

*Wi-Fi Mesh para conectividade local dinâmica entre dispositivos*

*Armazenamento Descentralizado com suporte a blockchain ou IPFS*

---

# Arquitetura do Sistema

**Raspberry Pi Zero W: Controlador central que gerencia a comunicação e a criptografia.**

**Módulo de Comunicação Satelital: Permite o envio de dados via redes como Iridium ou Globalstar.**

**Dispositivos IoT com LoRa e Wi-Fi Mesh: Sensores e atuadores conectados para coleta e envio de dados.**

**Servidor Descentralizado: Baseado em blockchain ou IPFS para armazenamento seguro e distribuído.**


# Fluxo de Dados


**Dados são coletados por sensores IoT e enviados para a Raspberry Pi Zero W via LoRa ou Wi-Fi Mesh.**

*A Raspberry Pi criptografa os dados com AES-256 e encapsula o pacote no protocolo Matrix.*

*O módulo satelital transmite o pacote para a rede satelital.*

*O servidor descentralizado recebe e armazena os dados de forma distribuída.*

---

# Requisitos de Hardware

- 1x Raspberry Pi Zero W
  ![raspberry-removebg-preview](https://github.com/user-attachments/assets/e4405543-d0d9-48d8-b7a1-d02098d01566)


  ![imagem_2025-01-13_091000640-removebg-preview](https://github.com/user-attachments/assets/59c5c5c0-b42c-43cc-ba0f-62ef7aa702e5)
  ![imagem_2025-01-13_091300073-removebg-preview](https://github.com/user-attachments/assets/340e92cd-54f9-42a0-b94a-5f4eb0d2576e)

  - 1x Módulo de comunicação satelital (Iridium 9603 ou Globalstar ST150M.)


![imagem_2025-01-13_091544162-removebg-preview](https://github.com/user-attachments/assets/31c3ec93-2ee7-4930-a12a-60ba71340850)
- Módulos LoRa (SX1276)

![image](https://github.com/user-attachments/assets/93971caa-3d48-4142-b3da-e91dd53e7fc1)
![imagem_2025-01-13_091847941-removebg-preview](https://github.com/user-attachments/assets/1c77275f-aeb4-46df-b298-561a317575b6)
- Módulos Wi-Fi Mesh (ESP32)



- Sensores e atuadores para IoT

- sensor de temperatura > DHT22 ; Biblioteca > Adafruit
![imagem_2025-01-13_123434165-removebg-preview](https://github.com/user-attachments/assets/37e0f30d-cf8a-4542-a0f8-36949b898177)


- sensor de gps satelical > u-blox Neo-6m gps module ; Biblioteca: Python gps library
![imagem_2025-01-13_104607277-removebg-preview](https://github.com/user-attachments/assets/3ab07185-d770-4f6d-8016-913f5f21366d)



---


# Requisitos de Software

Raspbian OS para Raspberry Pi

Biblioteca de Criptografia PyCrypto ou PyCryptodome para AES-256

Implementação do Protocolo Matrix (SDK como matrix-nio para Python)

MQTT ou CoAP para comunicação leve


---

# Configuração e Instalação

Passo 1: Preparação do Ambiente

*Instale o sistema operacional Raspbian na Raspberry Pi Zero W.*

*Configure os módulos LoRa e Wi-Fi Mesh para comunicação local.*


Passo 2: Instalação de Dependências

![image](https://github.com/user-attachments/assets/153b39e2-b4dc-4f7e-baf4-9eb0886ee2e6)

Passo 3: Configuração de Criptografia

Implemente criptografia AES-256 para os dados coletados:

![image](https://github.com/user-attachments/assets/88ccde83-cf57-4927-a947-a162af5655a2)


em modificação...



