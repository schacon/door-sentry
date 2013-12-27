/*
  Door Sentry software
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 12;
int ir = 7;
int val = 0;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
  pinMode(ir, INPUT);
  Serial.begin(9600);
}

int dist =0;
int isClose =0;
int isOn =0;

// the loop routine runs over and over again forever:
void loop() {
  dist = analogRead(0);
  isClose =0;
  if(dist < 170) {
    isClose =1;
  }

  val = digitalRead(ir);
  if(val == HIGH){
    if(isClose ==1){
      if(isOn ==1){
        digitalWrite(led, LOW);
        isOn=0;
      } else{
        digitalWrite(led, HIGH);
        isOn =1;
      }
      delay(320);
    }else{
     digitalWrite(led, HIGH);
     isOn =1;
     // hey
    }
  } else{
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    isOn=0;
  }
}
