#include <WiFi.h>

const char* ssid = "Chocos";
const char* password = "titos3641";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.print("Local IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New client connected");
    String response = "Hello from ESP32-S3!";
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();
    client.println("<html>");
    client.println("<body>");
    client.println("<h1>" + response + "</h1>");
    client.println("</body>");
    client.println("</html>");
    delay(5000);
    client.stop();
    Serial.println("Client disconnected");
  }
}
