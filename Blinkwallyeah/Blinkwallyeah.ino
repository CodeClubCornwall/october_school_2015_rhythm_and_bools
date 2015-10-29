#include <NewPing.h>

#define FORWARD_TIME 1000    // delay after forward
#define REVERSE_TIME 1000    // delay after reverse
#define STOP_TIME 1000       // delay after stop
#define TURN_TIME 1050 // delay after turn

#define MAX_DISTANCE 200 // Maximum distance (in cm) to ping.
#define PING_INTERVAL 33 // Milliseconds between sensor pings (29ms is about the min to avoid cross-sensor echo).

unsigned long pingTimer; // Holds the times when the next ping should happen for each sensor.
unsigned int forward_sensor_cm;         // Where the ping distances are stored.

NewPing forward_sensor =      // Sensor object array.
  NewPing(4, 5, MAX_DISTANCE); // Each sensor's trigger pin, echo pin, and max distance to ping.







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
  
  Serial.begin(115200);
}

void loop() {           
  forward_motors();
  delay(50);
  
  forward_sensor.ping_timer(echoCheck);
  Serial.println(forward_sensor_cm);
  if (forward_sensor_cm < 26 and forward_sensor_cm != 0)
  {
    stop_motors ();
    turn_left_motors();
    delay(TURN_TIME);
    while(1);
  }
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
  digitalWrite(7, HIGH);
  digitalWrite(10, HIGH);  
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);  
}

void stop_near_wall() {
  
}


void echoCheck() { // If ping received, set the sensor distance to array.
  if (forward_sensor.check_timer())
    forward_sensor_cm = forward_sensor.ping_result / US_ROUNDTRIP_CM;
    
}
