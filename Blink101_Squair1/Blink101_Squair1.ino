#define FORWARD_TIME 1000    // delay after forward
#define REVERSE_TIME 1000    // delay after reverse
#define STOP_TIME 1000       // delay after stop
#define TURN_TIME 1050 // delay after turn
int count = 0;
void setup() {     
  
  pinMode(2, INPUT);   // button 1
  pinMode(3, INPUT);   // button 2
  
  pinMode(7, OUTPUT);  // ENA Motor 1
  pinMode(8, OUTPUT);  // IN1 Motor 1
  pinMode(9, OUTPUT);  // IN2 Motor 1

  pinMode(11, OUTPUT); // ENA Motor 2
  pinMode(12, OUTPUT); // IN1 Motor 2
  pinMode(10, OUTPUT); // IN2 Motor 2
  
  pinMode(4, INPUT);   // frontal sensors
}

void loop() {           
 turns();
  forward_motors();
  delay(FORWARD_TIME);
  stop_motors();
}
void turns(){
  forward_motors();           
  delay(FORWARD_TIME);              
  turn_right_motors();
  delay(TURN_TIME);
  forward_motors();              
  delay(FORWARD_TIME);              
  turn_right_motors();
  delay(TURN_TIME);
  forward_motors();              
  delay(FORWARD_TIME);              
  turn_right_motors();
  delay(TURN_TIME);
  forward_motors();              
  delay(FORWARD_TIME);  
  forward_motors();   // part 2        
  delay(FORWARD_TIME);              
  turn_left_motors();
  delay(1050);
  forward_motors();              
  delay(FORWARD_TIME);              
  turn_left_motors();
  delay(1050);
  forward_motors();              
  delay(FORWARD_TIME);              
  turn_left_motors();
  delay(950);
  forward_motors();              
  delay(FORWARD_TIME);  
  stop_motors();  
  while (1);
}

void stop_motors () {
  digitalWrite(9, HIGH);  // stop 1 sec
  digitalWrite(8, LOW); 
  digitalWrite(7, LOW);
  digitalWrite(10, HIGH); 
  digitalWrite(12, LOW); 
  digitalWrite(11, LOW); 
}

void forward_motors() {
  analogWrite(9, 220);    // reverse 1 sec
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(10, HIGH);  
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);  
}

void reverse_motors() { 
  analogWrite(9, 220);    // forward 1 sec
  digitalWrite(8, LOW); 
  digitalWrite(7, HIGH);
  digitalWrite(10, HIGH); 
  digitalWrite(12, LOW); 
  digitalWrite(11, HIGH);
}

void turn_right_motors() {
  analogWrite(9, 220);    // reverse 1 sec
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(10, HIGH);  
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);  
}

void turn_left_motors() {
  analogWrite(9, 220);    // reverse 1 sec
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(10, HIGH);  
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);  
}

void stop_near_wall() {
  
}
