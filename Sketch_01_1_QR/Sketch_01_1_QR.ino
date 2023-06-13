#include <Freenove_WS2812_Lib_for_ESP32.h>

/**********************************************************************
* Filename    : QR Code
* Description : Make an QR Reader.
* Auther      : www.californiadigital.org
* Modification: 2023/06/12
**********************************************************************/
#include <WiFi.h>
#include "esp_camera.h"
#include <qrcode.h>

#define LED_BUILTIN  2

// Replace with your network credentials
const char* ssid = "Chocos";
const char* password = "titos3641";

// Pin definition for camera
const int cameraPinSda = 26;
const int cameraPinScl = 27;
const int cameraPinReset = 5;

// Image buffer for camera capture
camera_fb_t *cameraFrameBuffer = NULL;

// Function to connect to Wi-Fi
void connectToWiFi() {
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi...");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println("\nConnected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(115200); // Initialize the Serial interface
  delay(2000); // Wait for 2 seconds to allow the Serial interface to stabilize
  pinMode(LED_BUILTIN, OUTPUT);

  connectToWiFi();

  // Initialize camera
  camera_config_t cameraConfig;
  cameraConfig.pin_pwdn = -1; // Not used for OV2640
  cameraConfig.pin_reset = cameraPinReset;
  cameraConfig.pin_xclk = 32;
  cameraConfig.pin_sscb_sda = cameraPinSda;
  cameraConfig.pin_sscb_scl = cameraPinScl;
  cameraConfig.pin_d7 = 35;
  cameraConfig.pin_d6 = 34;
  cameraConfig.pin_d5 = 39;
  cameraConfig.pin_d4 = 36;
  cameraConfig.pin_d3 = 21;
  cameraConfig.pin_d2 = 19;
  cameraConfig.pin_d1 = 18;
  cameraConfig.pin_d0 = 5;
  cameraConfig.pin_vsync = 25;
  cameraConfig.pin_href = 23;
  cameraConfig.pin_pclk = 22;
  
  esp_err_t cameraInitStatus = esp_camera_init(&cameraConfig);
  if (cameraInitStatus != ESP_OK) {
    Serial.printf("Camera initialization failed with error 0x%x", cameraInitStatus);
    return;
  }
  
  // Set camera frame size and format
  /*sensor_t *cameraSensor = esp_camera_sensor_get();
  cameraSensor->set_framesize(cameraSensor, FRAMESIZE_QVGA);
  cameraSensor->set_pixformat(cameraSensor, PIXFORMAT_JPEG);*/
  
  Serial.println("Camera initialized");
}

// the loop function runs over and over again forever
void loop() {
  Serial.println("Hello"); // Print "Hello" to the console
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(2000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(2000);                       // wait for a second
}
