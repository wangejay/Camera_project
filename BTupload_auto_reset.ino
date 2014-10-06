
#define RESET_PIN 7
#define RESET_CMD_SIZE 4

char myChar;

static char RESET_CMD[RESET_CMD_SIZE] = {0x30, 0x20, 0x30, 0x20};

void reset() {
    Serial.print("Reset");
    digitalWrite(RESET_PIN, LOW);
    delay(100); 
    digitalWrite(RESET_PIN, HIGH);
}

void setup() {
  digitalWrite(RESET_PIN, HIGH);
  Serial.begin(115200);   
  Serial.println("Start");
  pinMode(RESET_PIN, OUTPUT);  
}

void loop() {
  while (Serial.available()) {
    for (int i=0; i<RESET_CMD_SIZE; i++) {
        myChar = Serial.read();
        if (myChar == RESET_CMD[i]) {
            if (i < RESET_CMD_SIZE - 1) 
              continue;
            else 
              reset();
        } else {
            break;
        }
    }
  }
}

