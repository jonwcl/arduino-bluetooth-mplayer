#include "Global.h"

const int sensorPin = A1;

void setup(){
Serial.begin(9600); 
Serial.println("start"); 
}

void highChirp (int intensity, int chirpsNumber) {
int i;
int x;

for (int veces = 0; veces <= chirpsNumber; veces++) {
for (i = 100; i > 0; i--) {
for (x = 0; x < intensity; x++) {
digitalWrite (3, HIGH);
delayMicroseconds (i);
digitalWrite (3, LOW);
delayMicroseconds (i);
}
}
}
}

void lowChirp(int intensity, int chirpsNumber) {
int i;
int x;

for (int veces = 0; veces <= chirpsNumber; veces++) {

for (i = 0; i < 200; i++) {
digitalWrite (3, HIGH); 
delayMicroseconds(i);
digitalWrite(3, LOW);
delayMicroseconds(i); 
}

for (i = 90; i > 80; i--) {
for ( x = 0; x < 5; x++) {
digitalWrite (3, HIGH);
delayMicroseconds (i);
digitalWrite (3, LOW);
delayMicroseconds (i);
}
}
}
}

void tweet(int intensity, int chirpsNumber) {

int i;
int x;

//normal chirpsNumber 3, normal intensity 5

for (int veces = 0; veces < chirpsNumber; veces++) {

for (int i = 80; i > 0; i--) {
for (int x = 0; x < intensity; x++) {
digitalWrite (3, HIGH); 
delayMicroseconds (i); 
digitalWrite (3, LOW); delayMicroseconds (i); 
} 
} 
}

delay(1000);

}

void loop() { //if the soil moisture level is low play chirps 

int reading = analogRead(sensorPin);
float voltage = reading * 3.3;
voltage /= 1024.0; 
float temperatureC = (voltage - 0.5) * 100 ;

Serial.print("Temperature: ");
Serial.println(temperatureC);

if (soilMoisture.read() < 600) {

for (int i = 0; i < 5; i++ ) {

//makes the sound according to: intensity, varies: normally 5. number of times: how many times tweets, rormally 3-6 

highChirp(5, 2); 
delay(100); 
lowChirp(5, 2); 
delay(100); 
tweet(2, 2);

//delay between the closer tweets 

delay(400); }


//general delay after a series of tweets 

//delay(random(20000)); 
} 


Serial.print("Soil Moisture: ");
Serial.println(soilMoisture.read());
}






