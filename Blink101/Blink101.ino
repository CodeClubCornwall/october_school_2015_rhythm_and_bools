#define FORWARD_TIME 2000
#define REVERSE_TIME 1000
#define STOP_TIME 1000

void setup() {     
  
  pinMode(2, INPUT); // button 1
  pinMode(3, INPUT); // button 2
  
  pinMode(7, OUTPUT); // ENA Motor 1
  pinMode(8, OUTPUT); // IN1 Motor 1
  pinMode(9, OUTPUT); // IN2 Motor 1

  pinMode(11, OUTPUT); // ENA Motor 2
  pinMode(12, OUTPUT); // IN1 Motor 2
  pinMode(10, OUTPUT); // IN2 Motor 2
}

void loop() {           
  forward_motors();      // movement procces: forward 1 second, stop 1 second, reverse 1 second, stop 1 second, repeat        
  delay(FORWARD_TIME);              
  stop_motors();
  while(1);  
}

void stop_motors () {
  digitalWrite(9, HIGH); // stop 1 sec
  digitalWrite(8, LOW); 
  digitalWrite(7, LOW);
  digitalWrite(10, HIGH); 
  digitalWrite(12, LOW); 
  digitalWrite(11, LOW); 
}

void forward_motors() {
  analogWrite(9, 220);  // reverse 1 sec
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(10, HIGH);  
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);  
}

void reverse_motors() { 
  analogWrite(9, 220); // forward 1 sec
  digitalWrite(8, LOW); 
  digitalWrite(7, HIGH);
  digitalWrite(10, HIGH); 
  digitalWrite(12, LOW); 
  digitalWrite(11, HIGH);
}


