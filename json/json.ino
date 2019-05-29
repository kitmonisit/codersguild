#include <ArduinoJson.h>

void setup() {
  // Setup the serial ports
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  // Nothing to do here.  All actions are triggered by data coming into
  // the Serial buffers.
}

void serialEvent() {
  Serial1.print(serialize_json());
}

void serialEvent1() {
  Serial.print(deserialize_json());
}

String serialize_json() {
  // Initialize space in memory where characters are stored.
  char output[1024];
  char msg[1024];

  // Read out the Serial receive buffer.
  String str = Serial.readString();

  // Convert str into a char array and store in msg.
  str.toCharArray(msg, sizeof(msg));

  // Prepare the JSON document
  const int capacity = JSON_OBJECT_SIZE(2);
  StaticJsonDocument<capacity> doc;
  // Fill out the JSON document
  doc["sender"].set("Kit");
  doc["message"].set(msg);

  // Print out own message locally
  const char* sender = doc["sender"];
  const char* message = doc["message"];
  Serial.print(String(sender) + ": " + String(message));

  // Serialize the JSON document so it can be send out via Serial1
  serializeJson(doc, output);
  return String(output);
}

String deserialize_json() {
  // Read out the Serial1 receive buffer
  String input = Serial1.readString();

  // Prepare the JSON document
  DynamicJsonDocument doc(1024);
  // Parse the raw String that came from the receive buffer
  deserializeJson(doc, input);
  // Extract the data
  const char* sender = doc["sender"];
  const char* message = doc["message"];

  // Prepare the String so that it can be printed out to Serial
  return String(sender) + ": " + String(message);
}
