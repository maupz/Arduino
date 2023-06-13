void setup() {
  Serial.begin(115200); // Initialize the Serial interface
  delay(2000); // Wait for 2 seconds to allow the Serial interface to stabilize
}

void loop() {
  Serial.println("Hello"); // Print "Hello" to the console
  delay(1000); // Wait for a second
}
