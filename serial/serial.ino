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
  String str = Serial.readString();
  Serial.print("me: " + str);
  Serial1.print(str);
}

void serialEvent1() {
  String str = Serial1.readString();
  Serial.print("other: " + str);
}

// Challenge 1: Modify the code so that when one Arduino sends a message,
//   the other Arduino will know who the sender is.
// Challenge 2: Modify the code so you can form a network of 3 Arduinos.
//   Any message sent by one peer can be read by the other two.  Make
//   sure all 3 of them will know who the sender is.
// Challenge 3: Create and implement your own rules so that you can 
//   specify a message to be sent to one or both peers.  You might want to
//   use ArduinoJSON to help you organize your code.
// Challenge 4: Display the received message in the LCD.
