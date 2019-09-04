#include <SPI.h>
#include <Ethernet.h>
String readString="";
const int TrigPin=4;
const int EchoPin=5;
boolean blinking=true;
float distance;
int bright=0;
int minDis=3;
int midDis=5;
int largeDis=10;
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(192, 168, 1, 177);
EthernetServer server(80);
EthernetClient client;
void setup() {
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  server.begin();
  pinMode(3,OUTPUT);
  pinMode(TrigPin,OUTPUT);
  pinMode(EchoPin,INPUT);
}
void loop() {
  client = server.available();
  digitalWrite(TrigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin,HIGH);
  delayMicroseconds(12);
  digitalWrite(TrigPin,LOW);
  distance=pulseIn(EchoPin,HIGH)*0.017;
  if(distance<minDis&&blinking){
    digitalWrite(3,HIGH);
    delay(65);
    digitalWrite(3,LOW);
    delay(60);
    analogWrite(3,bright);
  }else if(distance>minDis&&distance<midDis&&blinking){
    digitalWrite(3,HIGH);
    delay(100);
    digitalWrite(3,LOW);
    delay(100);
    analogWrite(3,bright);
  }else if(distance>midDis&&distance<largeDis&&blinking){
    digitalWrite(3,HIGH);
    delay(150);
    digitalWrite(3,LOW);
    delay(150);
    analogWrite(3,bright);
  }
  if(client){
    while (client.connected()){
      if (client.available()){
        char c = client.read();
        readString += c;
        if (c == '\n'){
          if(readString.indexOf("level1")>0){
            analogWrite(3,10);
            bright=10;
            break;}
           if(readString.indexOf("level2")>0){
            analogWrite(3,80);
            bright=80;
            break;}  
           if(readString.indexOf("level3")>0){
            analogWrite(3,250);
            bright=250;
            break;}
          if(readString.indexOf("turnOff")>0){
            analogWrite(3,0);
            bright=0;
            break;}
          if(readString.indexOf("bon")>0){
            blinking=true;
            break;}
          if(readString.indexOf("boff")>0){
            blinking=false;}
          sendHTML(distance);
          break;}}}
    delay(1);
    client.stop();
    readString = "";}}
