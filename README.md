# 🎛️ Controle de Servomotor por PWM com Raspberry Pi Pico W

## 📌 Descrição do Projeto

Este projeto implementa o controle de um **servomotor** utilizando **PWM (Pulse Width Modulation)** com o **Raspberry Pi Pico W**. Através do **Pico SDK**, o sistema ajusta o ângulo do servomotor simulando seu comportamento no simulador **Wokwi**. Além disso, um experimento adicional com a ferramenta **BitDogLab** investiga o impacto da rotina em um LED RGB.

---

## 🛠️ Funcionalidades

- **Controle de posição do servomotor** via PWM.
- **Três posições estáticas**: 0°, 90° e 180°.
- **Movimentação periódica** entre 0° e 180° com transições suaves.
- **Simulação utilizando o Wokwi**.
- **Experimento com LED RGB na ferramenta BitDogLab**.

---

## 🔧 Hardware Necessário - Presentes no WOkwi ou na Placa de Desenvolvimento BitDogLab

- **Microcontrolador Raspberry Pi Pico W**.
- **Servomotor – Motor Micro Servo Padrão (Wokwi)**.
- **LED RGB – GPIO 12 (para experimento adicional)**.
- **Fonte de alimentação adequada**.

---

## 📝 Código Principal

O código principal:

- **Configura o PWM no GPIO 22** com frequência de **50Hz**.
- **Define três posições fixas para o servomotor** (0°, 90°, 180°).
- **Implementa uma rotina de movimentação periódica** entre 0° e 180° com ajustes suaves.
- **Realiza testes adicionais com o LED RGB na ferramenta BitDogLab**.

---

## 📌 Como Rodar o Projeto

### **Softwares Necessários**

1. **VS Code** com a extensão **Raspberry Pi Pico** instalada.
2. **CMake** e **Ninja** configurados.
3. **SDK do Raspberry Pi Pico** corretamente configurado.
4. Simulador **Wokwi** instalado e integrado ao VS Code.

### **Clonando o Repositório**

Para começar, clone o repositório no seu computador:

```bash
git clone https://github.com/EdnaRodrigues/Servo
cd Servo
```

---

### **Execução do Projeto no VS Code**

#### **1. Importar o Projeto**

Após clonar o repositório:

1. Abra o **VS Code**.
2. No menu **Raspberry Pi Pico**, selecione **Import Project**.
3. Escolha a pasta clonada e clique em **Import**.

#### **2. Compilar o Código**

1. Clique no ícone **Raspberry Pi Pico** no lado esquerdo do VS Code.
2. Escolha a opção **Compile Project** para compilar o código.

---

### **Execução no Simulador Wokwi**

#### **1. Configurar o Simulador Wokwi**

1. Abra o arquivo `diagram.json` incluído no repositório.
2. Certifique-se de que o arquivo JSON está configurado corretamente para a simulação do hardware necessário:
   - Servomotor conectado ao GPIO 22.
   - LED RGB devidamente conectado aos GPIOs 11, 12 e 13.

#### **2. Executar a Simulação**

1. Abra o arquivo fonte do código em C intitulado `servo.c` e insira um dos pinos disponíveis, na linha 5 do código, para escolha da saída em PWM:
``` c
#define PWM_PIN 22 // Pino conectado a GPIO como PWM
```
O número 22 (valor original) pode ser trocado pelos valores:
- 11 - LED na cor verde;
- 12 - LED na cor azul;
- 13 - LED na cor vermelha;
- 22 - Servo motor (wokwi).

2. Compile o código novamente.
3. Abra o painel do simulador Wokwi no VS Code.
4. Clique em **Play** para iniciar a simulação.

---

### **Execução na Placa BitDogLab**

#### **1. Coloque em Modo Reboot**

1. Aperte o botão **BOOTSEL** no microcontrolador Raspberry Pi Pico W.
2. Ao mesmo tempo, aperte o botão de **Reset**.

#### **2. Escolha o pino do LED a ser acionado**

1. Abra o arquivo fonte do código em C intitulado `servo.c` e insira um dos pinos disponíveis, na linha 5 do código, para escolha da saída em PWM:
``` c
#define PWM_PIN 22 // Pino conectado a GPIO como PWM
```
O número 22 deverá ser trocado por um dos valores a seguir:
- 11 - LED na cor verde;
- 12 - LED na cor azul;
- 13 - LED na cor vermelha.
2. Compile o código novamente.

#### **3. Upload de Arquivo **`servo.uf2`**

1. Abra a pasta `build` incluída no repositório.
2. Mova o arquivo `servo.uf2` para a placa de desenvolvimento.

#### **4. Acompanhar Execução do Programa**

1. Observe as mudanças de intensidade no LED escolhido.

---

## 🔍 Observações do Experimento com LED RGB na BitDogLab

### **Comportamento Observado**

É possível ver a mudança abrupta após os ciclos de 5 segundos, assim como a partir dos 15 segundos de programa o sistema faz a mudança gradual de intensidade da luz. Como esperado ao alterarmos a tensão média fornecida com o PWM.

---

## 📽️ Vídeo de Demonstração

[Assista ao vídeo explicativo aqui!](https://youtu.be/DXyqvSCaMXw)

---

## ✉️ Contato

Caso tenha dúvidas ou sugestões, entre em contato com o desenvolvedor.
