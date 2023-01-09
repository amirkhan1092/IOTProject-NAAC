#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
                          
//#define FIREBASE_HOST "gla-iot-default-rtdb.firebaseio.com"                     //Your Firebase Project URL goes here without "http:" , "\" and "/"
#define FIREBASE_HOST "eons-2c748.firebaseio.com"
//#define FIREBASE_AUTH "sBVKfBFUart3GauAFB8bhRnxM80n0VfCCOrcIm5F" //Your Firebase Database Secret goes here
#define FIREBASE_AUTH "2UQ38EOfDRKEghpNHBaQVV5y4imV0uHaDAvzF4yu"
#define WIFI_SSID "Deskto1"                                               //WiFi SSID to which you want NodeMCU to connect
#define WIFI_PASSWORD "123456789"    

//const int RED = 5;   // D1 R
//const int GREEN = 4; // D2 G
//const int BLUE = 0;  // D3 B
const int RED = D1;   // D1 R
const int GREEN = D2; // D2 G
const int BLUE = D3;  // D3 B


// Declare the Firebase Data object in the global scope
FirebaseData firebaseData;

// Declare global variable to store value
int val=0;
int r, g, b;
//String strData_Last1,strData_Last2;
void setup() {
  Serial.begin(115200);                                   // Select the same baud rate if you want to see the datas on Serial Monitor

  Serial.println("Serial communication started\n\n");  
           
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     //try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);


  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                            //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);   // connect to firebase

  Firebase.reconnectWiFi(true);
  delay(1000);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
 
}

void loop() { 
  if (Firebase.getString(firebaseData, "/IOTOnline/red")) {            
      if(firebaseData.stringData().toInt() >= 120)
      {
        r = LOW;
//      Serial.print("RED");
//      Serial.println(r);
//      delay(100);
      }
      else{
        r = HIGH;
        }
  }
  if (Firebase.getString(firebaseData, "/IOTOnline/green")) {            
      if(firebaseData.stringData().toInt() >=120)
      {
        g = LOW;
//      Serial.print("GREEN");
//      Serial.println(g);
//      delay(100);
      }
      else{
        g = HIGH;
        }
  }
   if (Firebase.getString(firebaseData, "/IOTOnline/blue")) {            
      if(firebaseData.stringData().toInt() >=120)
      {
        b = LOW;
//      Serial.print("Blue");
//      Serial.println(b);
//      delay(100);
      }
      else{
        b=HIGH;
        }
  }
    digitalWrite(BLUE, b);
    digitalWrite(GREEN, g);
    digitalWrite(RED, r);
  delay(1000);
       

}



  
//    }
//    else
//    {
//      Serial.println("Data is not Integer");
//      delay(5000);
//      }                           
//         int r=strId.substring(0,3).toInt();
//         int g=strId.substring(4,7).toInt();
//         int b=strId.substring(8,11).toInt(); 

//         analogWrite(RED,r);
//         analogWrite(GREEN,g);
//         analogWrite(BLUE,b);
      
  
  
