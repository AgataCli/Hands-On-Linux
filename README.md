

# DevTITANS 05 - HandsOn Linux - Equipe 04

Bem-vindo ao repositório da Equipe 04 do HandsON de Linux do DevTITANS! Este projeto contém um firmware para o ESP32 escrito em formato Arduino `.ino`, bem como um driver do kernel Linux escrito em C. O objetivo é demonstrar como criar uma solução completa de hardware e software que integra um dispositivo ESP32 com um sistema Linux.

## Tabela de Conteúdos

- [Contribuidores](#contribuidores)
- [Introdução](#introdução)
- [Recursos](#recursos)
- [Requisitos](#requisitos)
- [Configuração de Hardware](#configuração-de-hardware)
- [Instalação](#instalação)
- [Uso](#uso)
- [Contato](#contato)

## Contribuidores

<img src="https://github.com/AgataCli/Hands-On-Linux/blob/92dbef2c245a1983053dd462abad7d8b99e3aed2/images/Agatha.png" width="180" > <img src="https://github.com/AgataCli/Hands-On-Linux/blob/b43f34f45ce84abe07cd6b193156b51ce192f66e/images/Cristiano.png" width="180" >
<img src="https://github.com/AgataCli/Hands-On-Linux/blob/b43f34f45ce84abe07cd6b193156b51ce192f66e/images/Guiherme.png" width="180" >
<img src="https://github.com/AgataCli/Hands-On-Linux/blob/b43f34f45ce84abe07cd6b193156b51ce192f66e/images/Lucas.png" width="180" >
<img src="https://github.com/AgataCli/Hands-On-Linux/blob/b43f34f45ce84abe07cd6b193156b51ce192f66e/images/Samuelson.png" width="180" >

- **Ágata Clícia Santos Brazão: Desenvolvedor do Firmware e Driver Linux, Escritor da Documentação**

- **Cristiano Coimbra Goes: Desenvolvedor do Firmware e Driver Linux**

- **Guilherme Silveira Duarte: Desenvolvedor do Firmware e Driver Linux, Escritor da Documentação**

- **Lucas do Nascimento Silva: Desenvolvedor do Driver Linux, Escritor da Documentação**

- **Samuelson de Brito Mesquita: Desenvolvedor do Firmware e Driver Linux**

## Introdução

Este projeto serve como um exemplo para desenvolvedores interessados em construir e integrar soluções de hardware personalizadas com sistemas Linux. Inclui os seguintes componentes:
- Firmware para o microcontrolador ESP32 para lidar com operações específicas do dispositivo.
- Um driver do kernel Linux que se comunica com o dispositivo ESP32, permitindo troca de dados e controle.

## Recursos

- **Firmware ESP32:**
  - Aquisição básica de dados de sensores.
  - Comunicação via Serial com o driver Linux.
  
- **Driver do Kernel Linux:**
  - Rotinas de inicialização e limpeza.
  - Operações de arquivo de dispositivo (`GET_LED`, `SET_LED`, `GET_LDR`).
  - Comunicação com o ESP32 via Serial.

## Requisitos

- **Hardware:**
  - Placa de Desenvolvimento ESP32
  - Máquina Linux
  - Protoboard e Cabos Jumper
  - Sensor LDR
  
- **Software:**
  - Arduino IDE
  - Kernel Linux 4.0 ou superior
  - GCC 4.8 ou superior
  - Make 3.81 ou superior

## Configuração de Hardware

1. **Conecte o ESP32 à sua Máquina Linux:**
    - Use um cabo USB.
    - Conecte os sensores ao ESP32 conforme especificado no firmware.

2. **Garanta a alimentação e conexões adequadas:**
    - Use um protoboard e cabos jumper para montar o circuito.
    - Consulte o diagrama esquemático fornecido no diretório `esp32` para conexões detalhadas.

## Instalação

### Firmware ESP32

1. **Abra o Arduino IDE e carregue o firmware:**
    ```sh
    Arquivo -> Abrir -> Selecione `smartlamp.ino`
    ```

2. **Configure a Placa e a Porta:**
    ```sh
    Ferramentas -> Placa -> Node32s
    Ferramentas -> Porta -> Selecione a porta apropriada
    ```

3. **Carregue o Firmware:**
    ```sh
    Sketch -> Upload (Ctrl+U)
    ```

### Driver Linux

1. **Clone o Repositório:**
    ```sh
    git clone https://github.com/seuusuario/Hands-On-Linux.git
    cd Hands-On-Linux
    ```

2. **Compile o Driver:**
    ```sh
    cd smartlamp-kernel-module
    make
    ```

3. **Carregue o Driver:**
    ```sh
    sudo insmod smartlamp.ko
    ```

4. **Verifique o Driver:**
    ```sh
    dmesg | tail
    ```

## Uso

Depois que o driver e o firmware estiverem configurados, você poderá interagir com o dispositivo ESP32 através do sistema Linux.

- **Escrever para o Dispositivo:**
    ```sh
    echo "GET_LED" > /sys/kernel/smartlamp/led
    ```

- **Ler do Dispositivo:**
    ```sh
    cat /sys/kernel/smartlamp/led
    ```

- **Verificar Mensagens do Driver:**
    ```sh
    dmesg | tail
    ```

- **Remover o Driver:**
    ```sh
    sudo rmmod smartlamp
    ```

# DevTITANS 05 - HandsOn Internet das Coisas

### Codigo Fonte que implementa o led do Capslock
Se seu computador não possuir led no capslock, conecte um teclado que possua e entre no diretório:
  ```sh
cd /sys/class/leds
```

Dê um ls no diretório, procure pelo input34::scrolllock e entre nele (pode ser um número diferente, veja como está no seu)
  ```sh
cd input34::scrolllock
```

Coloque o terminal em sudo bash
  ```sh
sudo bash
```

Altere o estado do led
  ```sh
echo 1 > brightness
```
  ```sh
echo 0 > brightness
```

Para perguntas, sugestões ou feedback, entre em contato com o mantenedor do projeto em [maintainer@example.com](mailto:maintainer@example.com).
