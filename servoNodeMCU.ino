/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#include <Servo.h>
#define ledPin 2 //onboard led
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

int servoPin = 15;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "rgq0oh02_Ih1JHXHC7zl6tgQUGX2cekq";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Math Maestro";
char pass[] = "*******";

// Servo instance
Servo myservo;

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Blynk.begin(auth, ssid, pass);

  //Attach servo
  myservo.attach(servoPin);
  myservo.write(0);

  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
}

//
BLYNK_WRITE(V2) // Must tally with virtual pin V2 on Blynk app
{
  int buttonState = param.asInt();
  if (buttonState == 1)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}

BLYNK_WRITE(V3) // Must tally with virtual pin V3 on on Blynk app
{
  int sliderValue = param.asInt();
  myservo.write(sliderValue);
}
