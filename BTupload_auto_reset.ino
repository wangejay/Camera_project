
#define ResetPin 7

char myChar ;
int i=0; 

void setup() {
  digitalWrite(ResetPin, HIGH);
  Serial.begin(115200);   
  Serial.println("Start");
  pinMode(ResetPin, OUTPUT);  
}

void loop() {
  while (Serial.available()) {
    myChar = Serial.read();
    if (myChar == 0x30 || myChar== 0x20) 
      {
        i++;
        if (i==4)
        {
        Serial.print("Reset");
        digitalWrite(ResetPin, LOW);
        delay(100); 
        digitalWrite(ResetPin, HIGH);
        i=0;
        }
      }
      else
      {
      i=0; 
      }
    Serial.print(myChar); //echo
     Serial.print(",");
  }
}
