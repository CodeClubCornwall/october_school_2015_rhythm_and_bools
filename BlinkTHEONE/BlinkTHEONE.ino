#include <NewPing.h>

#define FORWARD_TIME 1000    // delay after forward
#define REVERSE_TIME 200    // delay after reverse
#define STOP_TIME 1000       // delay after stop
#define TURN_TIME 500 // delay after turn

#define MAX_DISTANCE 200// Maximum distance (in cm) to ping.
#define PING_INTERVAL 33 // Milliseconds between sensor pings (29ms is about the min to avoid cross-sensor echo).

unsigned long pingTimer; // Holds the times when the next ping should happen for each sensor.
unsigned int forward_sensor_cm;         // Where the ping distances are stored.
unsigned int drop_sensor_cm;         // Where the ping distances are stored.

   
NewPing drop_sensor = NewPing(13, 17, MAX_DISTANCE); // Each sensor's trigger pin, echo pin, and max distance to ping.   
NewPing forward_sensor = NewPing(4, 5, MAX_DISTANCE); // Each sensor's trigger pin, echo pin, and max distance to ping.

int right_l_sensor = 0;   //right light sensor
int middle_l_sensor = 0;  //middle light sensor
int left_l_sensor = 0;    //left light sensor

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
  
  digitalWrite(14, HIGH); // left light sensor
  digitalWrite(15, HIGH); // middle light sensor
  digitalWrite(16, HIGH); // right light sensor
   
  Serial.begin(115200);
}

void loop() {  
 

  Serial.println(analogRead(0));
  //forward_sensor.ping_timer(echoCheck_F);
  //Serial.println(forward_sensor_cm);
  //drop_sensor.ping_timer(echoCheck_D);
  //Serial.println(drop_sensor_cm);
  //delay(50);  
  Serial.print(analogRead(0));
  Serial.print("  ");
  Serial.print(analogRead(1));
  Serial.print("  ");
  Serial.println(analogRead(2));

  //delay(50);
  forward_sensor_cm = forward_sensor.ping_cm();
  if (forward_sensor_cm < 26)
  {
      reverse_motors();
      delay (REVERSE_TIME);
  } else { 
    if (analogRead(0) < analogRead(1) && analogRead(0) < analogRead(2))
      turn_left_motors();
    else if (analogRead(2) < analogRead(1) && analogRead(2) < analogRead(0))
      turn_right_motors();
    else
      forward_motors();
  }     
  delay(50);
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
  
  //ernie
if (forward_sensor_cm < 11)
{
  analogWrite(9, 204);    // reverse 1 sec
  analogWrite(8, 204);
  digitalWrite(7, LOW);
  analogWrite(10, 204);  
  analogWrite(12, 204);
  digitalWrite(11, LOW);
}
     
  //bert
else
{
  analogWrite(9, 135);    // reverse 1 sec
  analogWrite(8, 135);
  digitalWrite(7, LOW);
  analogWrite(10, 135);  
  analogWrite(12, 135);
  digitalWrite(11, LOW);  
}
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


void echoCheck_F() { // If ping received, set the sensor distance to array.
  if (forward_sensor.check_timer())
    forward_sensor_cm = forward_sensor.ping_result / US_ROUNDTRIP_CM;
    
}

void echoCheck_D() { // If ping received, set the sensor distance to array.
  if (drop_sensor.check_timer())
    drop_sensor_cm = drop_sensor.ping_result / US_ROUNDTRIP_CM;
    
}
