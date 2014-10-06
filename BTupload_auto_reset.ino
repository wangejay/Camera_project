
#define RESET_PIN 7
#define RESET_CMD_SIZE 4

char myChar;
int i=0; 
static char RECEIVE_RESET_CMD[RESET_CMD_SIZE] = {0x00, 0x00, 0x00, 0x00};

void reset() {
    Serial.println("Reset");
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
    myChar = Serial.read();
    if (myChar == 0x30 || myChar == 0x20) {
      RECEIVE_RESET_CMD[i]=myChar; 
      if (RECEIVE_RESET_CMD[0] == 0x30 && 
          RECEIVE_RESET_CMD[1] == 0x20 && 
          RECEIVE_RESET_CMD[2] == 0x30 && 
          RECEIVE_RESET_CMD[3] == 0x20 ) {
         reset(); 
      }
      i++; 
    }
    else { i=0;}
  }
}

