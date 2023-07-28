#include <Arduino.h>
#include <SPI.h>
#include <RFID_Module.h>   // Libreria per il modulo RFID
#include <WiFi_Module.h>   // Libreria per il modulo Wi-Fi e Bluetooth
#include <NRF24_Module.h>  // Libreria per il modulo NRF24
#include <Adafruit_SSD1306>       // Libreria per il display OLED
#include <FreeRTOS_ARM.h>  // Libreria per FreeRTOS su architettura ARM

// Definizione delle priorità dei task
#define RFID_TASK_PRIORITY   2
#define WIFI_TASK_PRIORITY   3
#define NRF24_TASK_PRIORITY  3
#define OLED_TASK_PRIORITY   1

// Stack size dei task
#define RFID_TASK_STACK_SIZE   256
#define WIFI_TASK_STACK_SIZE   256
#define NRF24_TASK_STACK_SIZE  256
#define OLED_TASK_STACK_SIZE   256

// Handle dei task
TaskHandle_t rfidTaskHandle;
TaskHandle_t wifiTaskHandle;
TaskHandle_t nrf24TaskHandle;
TaskHandle_t oledTaskHandle;

// Dichiarazione dei task
void rfidTask(void *pvParameters);
void wifiTask(void *pvParameters);
void nrf24Task(void *pvParameters);
void oledTask(void *pvParameters);

// Inizializzazione degli oggetti per i moduli
RFID_Module rfidModule;
WiFi_Module wifiModule;
NRF24_Module nrf24Module;
U8G2_SSD1306_128X64_NONAME_1_HW_I2C oledModule(U8G2_R0);

void setup() {
  // Inizializzazione dei moduli
  rfidModule.init();
  wifiModule.init();
  nrf24Module.init();
  oledModule.begin();

  // Connessione WiFi (se necessario)

  // Inizializzazione di altre impostazioni del sistema, se necessario

  // Creazione dei task
  xTaskCreatePinnedToCore(rfidTask, "RFID Task", RFID_TASK_STACK_SIZE, NULL, RFID_TASK_PRIORITY, &rfidTaskHandle, 0);
  xTaskCreatePinnedToCore(wifiTask, "Wi-Fi Task", WIFI_TASK_STACK_SIZE, NULL, WIFI_TASK_PRIORITY, &wifiTaskHandle, 1);
  xTaskCreatePinnedToCore(nrf24Task, "NRF24 Task", NRF24_TASK_STACK_SIZE, NULL, NRF24_TASK_PRIORITY, &nrf24TaskHandle, 0);
  xTaskCreatePinnedToCore(oledTask, "OLED Task", OLED_TASK_STACK_SIZE, NULL, OLED_TASK_PRIORITY, &oledTaskHandle, 1);

  // Avvio del RTOS scheduler
  vTaskStartScheduler();
}

void loop() {
  // Il loop principale è vuoto poiché tutte le attività sono gestite dai task creati dal RTOS
}

// Implementazione dei task
void rfidTask(void *pvParameters) {
  while (true) {
    // Gestione delle operazioni RFID
    // ...
    vTaskDelay(pdMS_TO_TICKS(100)); // Delay di 100 millisecondi
  }
}

void wifiTask(void *pvParameters) {
  while (true) {
    // Gestione delle operazioni Wi-Fi
    // ...
    vTaskDelay(pdMS_TO_TICKS(500)); // Delay di 500 millisecondi
  }
}

void nrf24Task(void *pvParameters) {
  while (true) {
    // Gestione delle operazioni NRF24
    // ...
    vTaskDelay(pdMS_TO_TICKS(200)); // Delay di 200 millisecondi
  }
}

void oledTask(void *pvParameters) {
  while (true) {
    // Gestione delle operazioni OLED
    // ...
    vTaskDelay(pdMS_TO_TICKS(1000)); // Delay di 1 secondo
  }
}