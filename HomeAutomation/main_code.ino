#include <SoftwareSerial.h>                                                    //add the soft serial libray
#define rxpin 2                                                                //set the RX pin to pin 2
#define txpin 3  

int bulb1=4;
int bulb2=5;
int tube1 = 6;
int tube2 = 7;
int fan1 = 8; 
int fan2 = 9;
int ovan = 10;
int ac1 = 11;


SoftwareSerial myserial(rxpin, txpin);  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myserial.begin(9600);
//  pinMode(led1, OUTPUT);
  pinMode(bulb1, OUTPUT);
  pinMode(bulb2, OUTPUT);
//  pinMode(bulb3, OUTPUT);
  pinMode(tube1, OUTPUT);
  pinMode(tube2, OUTPUT);
  pinMode(fan1, OUTPUT);
  pinMode(fan2, OUTPUT);
  pinMode(ovan, OUTPUT);
  pinMode(ac1, OUTPUT);

  digitalWrite(bulb1, HIGH);
  digitalWrite(bulb2, HIGH);
  digitalWrite(tube1, HIGH);
  digitalWrite(tube2, HIGH);
  digitalWrite(fan1, HIGH);
  digitalWrite(fan2, HIGH);
  digitalWrite(ovan, HIGH);
  digitalWrite(ac1, HIGH);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(myserial.available())
  {
  String data = myserial.readString();
  Serial.println(data);
  if(data == "b1_on")
    digitalWrite(bulb1, LOW);
  else if(data == "b1_off")
    digitalWrite(bulb1, HIGH);
    
  else if(data == "b2_on")
    digitalWrite(bulb2, LOW);
  else if(data == "b2_off")
    digitalWrite(bulb2, HIGH);

  else if(data == "fan1_on")
    digitalWrite(fan1, LOW);  
  else if(data == "fan1_off")
    digitalWrite(fan1, HIGH);  

  else if(data == "fan2_on")
    digitalWrite(fan2, LOW);  
  else if(data == "fan2_off")
    digitalWrite(fan2, HIGH); 



  else if(data == "t1_on")
    digitalWrite(tube1, LOW);  
  else if(data == "t1_off")
    digitalWrite(tube1, HIGH); 
    
  else if(data == "t2_on")
    digitalWrite(tube2, LOW);  
  else if(data == "t2_off")
    digitalWrite(tube2, HIGH);  

  else if(data == "ov_on")
    digitalWrite(ovan, LOW);  
  else if(data == "ov_off")
    digitalWrite(ovan, HIGH); 

  else if(data == "ac1_on")
    digitalWrite(ac1, LOW);  
  else if(data == "ac1_off")
    digitalWrite(ac1, HIGH);   
    
  }

}
