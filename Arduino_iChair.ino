int headPin = A0; // Head switch
int slPin = A1; // Shoulder Left Switch
int srPin = A2; // Shoulder Right Switch
int spinePin = A3; // Bottom Switch
int bottomPin = A4; // Spine Switch


int ledPin = 7;


void setup () {
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  
  digitalWrite(ledPin, LOW);
}

void loop () {
  
  int val1 = checkSwitches();
  delay(20);
  int val2 = checkSwitches();
  
  if (val1 == val2){
    char as_val;
  
    as_val = val1 & 0xff;
  
    Serial.write((const uint8_t *) &as_val, 1);
  
    if (val1 == 48){
      digitalWrite(ledPin, LOW); 
    }else{
      digitalWrite(ledPin, HIGH); 
    }
  
    delay(500); 
  }
  
}

int checkSwitches () {
  
  int h = anVal(analogRead(headPin));
  int sl = anVal(analogRead(slPin));
  int sr = anVal(analogRead(srPin));
  int s = anVal(analogRead(spinePin));
  int b = anVal(analogRead(bottomPin));
  
  int checkVal = (h * 1) + (sl * 2) + (sr * 4) + (s * 8) + (b * 16);
  
  checkVal += 48;
  
  return checkVal;
}

int invert (int value) {
  int inv_val;
  
  inv_val = ~value;
  inv_val &= 1;
  return (inv_val);
}

int anVal (int value) {
 if (value >= 800){
  return 0;
 } else{
  return 1; 
 }
  
}
