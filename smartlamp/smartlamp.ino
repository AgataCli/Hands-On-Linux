// Defina os pinos de LED e LDR
// Defina uma variável com valor máximo do LDR (4000)
// Defina uma variável para guardar o valor atual do LED (10)

#include "DHT.h"

#define DHTPIN 15
#define DHTTYPE DHT11 

int ledPin = 26; //trocar para o esp
int ldrPin = 34; //trocar para o esp
int ledValue = 10;     // Valor inicial do LED (10%)
int ldrMax = 4000;

DHT dht(DHTPIN, DHTTYPE);


void setup() {
    Serial.begin(9600);  // Inicializa a comunicação serial
    pinMode(ledPin, OUTPUT);  // Define o pino do LED como saída
    Serial.println("SmartLamp Initialized.");
    ledUpdate(1);  // Atualiza o valor inicial do LED
    processCommand("GET_LDR");
}

void loop() {
    // Aguarda um comando da serial
    if (Serial.available()) {
        String comando = Serial.readStringUntil('\n');  // Lê a linha da serial
        processCommand(comando);  // Processa o comando
    }
}

// Função para processar os comandos recebidos
void processCommand(String command) {
    command.trim();  // Remove espaços ou quebras de linha extras

    if (command.startsWith("SET_LED")) {
        int spaceIndex = command.indexOf(' ');
        if (spaceIndex != -1) {
            int value = command.substring(spaceIndex + 1).toInt();  // Extrai o valor
            if (value >= 0 && value <= 100) {
                Serial.println("RES SET_LED 1");
                ledUpdate(value);  // Atualiza o LED com o valor
            } else {
                Serial.println("RES SET_LED -1");
            }
        } else {
            Serial.println("RES SET_LED -1");
        }
    } else if (command.equals("GET_LED")) {
        Serial.print("RES GET_LED ");
        Serial.println(ledValue);
    } else if (command.equals("GET_LDR")){
      	Serial.print("RES GET_LDR ");
      	Serial.println(ldrGetValue());
    } else if(command.equals("GET_HUM")) {
        Serial.print("RES GET_HUM ");
        Serial.println(humGetValue());
    } else if(command.equals("GET_TEMP")) {
        Serial.print("RES GET_TEMP ");
        Serial.println(tempGetValue());
    } else {
        Serial.println("ERR Unknown command.");
    }
}

// Função para atualizar o valor do LED
void ledUpdate(int value) {
    ledValue = value;  
    int pwmValue = map(value, 0, 100, 0, 255);  
    analogWrite(ledPin, pwmValue);  
}

int ldrGetValue() {
  int valueLdr = analogRead(ldrPin);
  int value = map(valueLdr,0,ldrMax,0,100);
  return value; 
}

int humGetValue() {
  float h = dht.readHumidity();
  return h;
}

int tempGetValue() {
  float t = dht.readTemperature();
  return t;
}
