#define BLYNK_PRINT Serial

//settingLibbrary
#include <Servo.h> // ini libbrarry untuk servo
#include <ESP8266WiFi.h> // file untuk modul wifi
#include <BlynkSimpleEsp8266.h> // file untuk blynk

char auth[] = "AJtGgCm5LLxPqFRXuKXPsjPWWCMbfcPv";
char ssid[] = "AndroidAPdcd2";
char pass[] = "hotspot12";

// definisi fungsi servo menjadi 
Servo gerak_servo;

BLYNK_WRITE(V1)
{
  gerak_servo.write(param.asInt());
} // function Blynk untuk mengatur nilai servo dengan pin virtual V1 yang ada pada aplikasi blynk

void setup()
{
  // Debug console
  Serial.begin(9600); // Memulai serial monitor dengan baudrate 9600

  Blynk.begin(auth, ssid, pass); // menjalankan blynk sesuai token, wifi, dan passwordnya

  gerak_servo.attach(2); //setting pin gpio 2 ke servo, D4 = 2
}

void loop()
{
  Blynk.run(); // memulai blynk
}
