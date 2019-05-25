
#include<DHT.h>
#include<HCSR04.h>
#include<BTHC05.h>
#define RX D5
#define TX D8
#define DHTPIN D2
#define DHTTYPE DHT11
#define TRIG D3
#define ECHO D4
#define BUZZER D6
#define IR D7
String blueread="";
String blue1="humidity";
String blue2="temp";
String blue3="distance";
String blue4="buzzer";
UltraSonicDistanceSensor mydis(TRIG,ECHO);
DHT mydht(DHTPIN,DHTTYPE);

BTHC05 blue(RX,TX);



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mydht.begin();
     blue.begin(9600);
     blue.println("bluetooth on....");
  pinMode(BUZZER,OUTPUT);
  pinMode(IR,INPUT);
    if(blue.available()){
  blue.println("bluetooth on....");
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  float hum=mydht.readHumidity();
  float temp=mydht.readTemperature();
  int dist=mydis.measureDistanceCm();
  bool sense=digitalRead(D7);
delay(500);
  //..............................//
  if(dist>=50&&dist<=100)
  digitalWrite(BUZZER,HIGH);
  else
  digitalWrite(BUZZER,LOW);
  //................................//
  if(sense==false)
  digitalWrite(BUZZER,HIGH);
  else
  digitalWrite(BUZZER,LOW);
  //.................................//
blueread=blue.readStringUntil('\n');
if(blueread==blue1)
blue.print("humidity is "+String(hum)+"\n");
if(blueread==blue2)
blue.print("temparature is "+String(temp)+"C"+"\n");
if(blueread==blue3)
blue.print("distance is "+String(dist)+"cm"+"\n");

blueread="";

Serial.print("Humidity-"+String(hum)+"\n");
Serial.print("temperature-"+String(temp)+"\n");
Serial.print("distance-"+String(dist)+"\n");
Serial.print("\n");
Serial.print(sense);


}
