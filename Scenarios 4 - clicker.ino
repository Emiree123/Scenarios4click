#include <Mouse.h> //includes the mouse library 
#define EMGPin 0 //define the pin 0 or A0 as EMG input 

int click = 2.5; //reference - to be added? should be in ditigal - so ADC = V_in * 1023 /Vref - tentatively 2.5V
int SensorValue = 0; //variable for reading sensor status

void setup (){
  pinMode(5,INPUT); 
  Serial.begin(9600); //initialise the serial communication at 9600 bits per second 
  delay(500);
} 
void loop() {
  if (digitalRead (A5) == HIGH) {
  int val = analogRead (EMGPin); //create an integer variable for the signal input 
  Serial.println(val); //display the variable 
    if (val>SensorValue) { //condition for the mouse click command   
      Mouse.click(); //click command 
      delay(1000); //delay to prevent too many actions at once 
    }
    else {Serial.println("End.");
    Serial.print ("Please connect A5 to 3.3V, to switch off Safety feature.");
    delay (1000);
    }
}
} 