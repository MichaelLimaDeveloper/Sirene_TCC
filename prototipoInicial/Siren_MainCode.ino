//By Miguel Ramos Gil
//Tks!

// ========================================================================================================
#include <virtuabotixRTC.h>                    //Lib to the RTC MODULE DS1302      
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>

// ========================================================================================================
#define   clk   15
#define   dat   4
#define   rst   5
#define   LED_BUILTIN 2

// ========================================================================================================
#define   segL       20
#define   minL       6
#define   horL       7
#define   d_semL      1
#define   d_mesL     17
#define   mesL        7
#define   anoL     2022

const char *ssid = "Miguel"; // Your SSIS
 
const char *password = "244466666"; // Your PASSWORD
 
// ========================================================================================================
virtuabotixRTC   myRTC(clk, dat, rst);         //Declaring objects to the RTC MODULE

// ========================================================================================================
void DS1302();
void week(int dayW);

// ========================================================================================================
void setup()  
{   
   Serial.begin(115200);
 
  Serial.println();                             //Starts the Wireless connetion
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
 }
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  delay(5000);

  
  pinMode(LED_BUILTIN, OUTPUT);  
  Serial.begin(115200);

  //myRTC.setDS1302Time(segL, minL, horL, d_semL, d_mesL, mesL, anoL); // Uncomment this line put the information and upload, 
                                                                      // before this comment the line and upload again
  
} //end setup

// ========================================================================================================
void DS1302()
{
  myRTC.updateTime();         // Take date and time from RTC

                             // Show the informatons in serial montinor
  Serial.print(" -> ");
  week(myRTC.dayofweek);
  Serial.print(" | ");
  Serial.print(myRTC.dayofmonth);
  Serial.print("/");
  Serial.print(myRTC.month);
  Serial.print("/");
  Serial.print(myRTC.year);
  Serial.print(" | ");
  if(myRTC.hours < 10) Serial.print("0");
  Serial.print(myRTC.hours);
  Serial.print(":");
  if(myRTC.minutes < 10) Serial.print("0");
  Serial.print(myRTC.minutes);
  Serial.print(":");
  if(myRTC.seconds < 10) Serial.print("0");
  Serial.println(myRTC.seconds);
  delay(1000);
  
}

// ======================================================================================================== 
void week(int dayW)
{
  
  switch(dayW)
  {
    case 1: Serial.print("Sun"); break;
    case 2: Serial.print("Mon"); break;
    case 3: Serial.print("Tue"); break;
    case 4: Serial.print("Wen"); break;
    case 5: Serial.print("Thu"); break;
    case 6: Serial.print("Fri"); break;       
    case 7: Serial.print("Sat"); break;
   
  }
  
} 

// ======================================================================================================== 
void loop()  
{
   DS1302();

   if(myRTC.dayofweek >= 2 <= 6 && myRTC.hours == 12  && myRTC.minutes == 8 && myRTC.seconds >= 0 && myRTC.seconds <= 10 ||
      myRTC.dayofweek >= 2 <= 6 && myRTC.hours == 12  && myRTC.minutes == 10 && myRTC.seconds >= 0 && myRTC.seconds <= 10 ||
      myRTC.dayofweek >= 2 <= 6 && myRTC.hours == 12  && myRTC.minutes == 12 && myRTC.seconds >= 0 && myRTC.seconds <= 10 ||
      myRTC.dayofweek >= 2 <= 6 && myRTC.hours == 12  && myRTC.minutes == 14 && myRTC.seconds >= 0 && myRTC.seconds <= 10 ||
      myRTC.dayofweek >= 2 <= 6 && myRTC.hours == 12  && myRTC.minutes == 16 && myRTC.seconds >= 0 && myRTC.seconds <= 10 ||
      myRTC.dayofweek >= 2 <= 6 && myRTC.hours == 12  && myRTC.minutes == 18 && myRTC.seconds >= 0 && myRTC.seconds <= 10 ||
      myRTC.dayofweek >= 2 <= 6 && myRTC.hours == 12  && myRTC.minutes == 20 && myRTC.seconds >= 0 && myRTC.seconds <= 10)
   {
    digitalWrite(LED_BUILTIN,HIGH);
    Serial.print("Alarm on\n");
    delay(10000);
    digitalWrite(LED_BUILTIN,LOW);
   } 
   else if(myRTC.dayofweek >= 2 <= 6 && myRTC.hours == 12  && myRTC.minutes == 7 && myRTC.seconds == 30 ||
           myRTC.dayofweek >= 2 <= 6 && myRTC.hours == 12  && myRTC.minutes == 9 && myRTC.seconds == 30 ||
           myRTC.dayofweek >= 2 <= 6 && myRTC.hours == 12  && myRTC.minutes == 11 && myRTC.seconds == 30 ||
           myRTC.dayofweek >= 2 <= 6 && myRTC.hours == 12  && myRTC.minutes == 13 && myRTC.seconds == 30 ||
           myRTC.dayofweek >= 2 <= 6 && myRTC.hours == 12  && myRTC.minutes == 15 && myRTC.seconds == 30 ||
           myRTC.dayofweek >= 2 <= 6 && myRTC.hours == 12  && myRTC.minutes == 17 && myRTC.seconds == 30 ||     
           myRTC.dayofweek >= 2 <= 6 && myRTC.hours == 12  && myRTC.minutes == 19 && myRTC.seconds == 30)
   {
    Serial.print("The Esp will explode -> F Project (MEME) \n");
   }
}

// ========================================================================================================
