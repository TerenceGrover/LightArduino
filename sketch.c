String data;
int ledPin1 = 6;  // Adjust these to your setup
int ledPin2 = 11;
int ledPin3 = 10;
int ledPin4 = 9;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
}

void loop() {
    while (Serial.available()) {
      data = Serial.readStringUntil('\n');

      // Split the incoming data into separate volumes
      int commaIndex1 = data.indexOf(',');
      int commaIndex2 = data.indexOf(',', commaIndex1 + 1);
      int commaIndex3 = data.indexOf(',', commaIndex2 + 1);


      int volume1 = map(data.substring(0, commaIndex1).toInt(), 0, 8, 0, 255);
      int volume2 = map(data.substring(commaIndex1 + 1, commaIndex2).toInt(), 0, 8, 0, 255);
      int volume3 = map(data.substring(commaIndex2 + 1, commaIndex3).toInt(), 0, 8, 0, 255);
      int volume4 = map(data.substring(commaIndex3 + 1).toInt(), 0, 8, 0, 255);

      // Write the volumes to the LEDs
      analogWrite(ledPin1, volume1);
      analogWrite(ledPin2, volume2);
      analogWrite(ledPin3, volume3);
      analogWrite(ledPin4, volume4);
    }
  }
