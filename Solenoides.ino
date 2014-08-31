int pino[] = {2,3,4,5,6,7,8,9};

byte input = 0;
boolean stringComplete = false;
int pos = 0;

void setup() {
  Serial.begin(9600);
  
  for (int i=0; i<=7; i++) {
    pinMode(pino[i], OUTPUT);
    digitalWrite(pino[i], LOW);
  }
  
  Serial.println("Sistema iniciado...");
}

void loop() {
  if (stringComplete) {
    for (int i=0; i<=7; i++) {
      digitalWrite(pino[i], bitRead(input, i));   
      Serial.print(bitRead(input, i));
    }
    Serial.println(0000);
    stringComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
   char inChar = (char)Serial.read();
   
    if (inChar == 48) {
      bitClear(input, pos);
      pos++;
    }
    
    if (inChar == 49) {
      bitSet(input, pos);
      pos++;
    }

    if (inChar == '\n') {
      stringComplete = true;
      pos = 0;
    }
    
  }
}

