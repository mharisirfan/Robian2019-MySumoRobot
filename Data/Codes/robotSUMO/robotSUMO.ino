/* RC_Bluetooth_2018_v6
 * By:    Khamlek HOMSOMBATH
 * Date:  Jan 17, 2018
 * Download Controller for Android : https://play.google.com/store/apps/details?id=com.lekpkd.duinojoy
 */

#include <SoftwareSerial.h>

// arduino>>bluetooth
// D10 (as RX)   >>>  Tx
// D11 (as TX)  >>>  Rx
SoftwareSerial bluetooth(10, 11); // RX, TX
#define ledpin 13 // Connected to LED
#define PWMA 5
#define AIN2 6
#define AIN1 7
#define STBY 8
#define BIN1 9
#define BIN2 10
#define PWMB 11

void setup() {
  Serial.begin(19200); 
  bluetooth.begin(9600);
  
  pinMode(ledpin,OUTPUT);
  pinMode(PWMA,OUTPUT); // PWM A
  pinMode(PWMB,OUTPUT); // PWM B
  pinMode(BIN1,OUTPUT); // B
  pinMode(BIN2,OUTPUT); // B
  pinMode(AIN1,OUTPUT); // A
  pinMode(AIN2,OUTPUT); // A
  pinMode(STBY,OUTPUT); // STBY

  digitalWrite(STBY,1);

  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
}

String data = "";
void loop() {
  while(bluetooth.available()){
    char a = bluetooth.read();
    if(a==')') {
      setData(data);
      data = "";
      return;
    }
    data += a;
  }
}

int ledVal = 0;
void setData(String data){
  data.trim();

  int index = data.indexOf(",");
  if(index != -1){
    int angle = data.substring(0,index).toInt();
    int strength = data.substring(index + 1).toInt();

    digitalWrite(BIN1,0);
    digitalWrite(BIN2,0);
    digitalWrite(AIN1,0);
    digitalWrite(AIN2,0);
    if (angle < 180){
      digitalWrite(BIN1,1);
      digitalWrite(AIN1,1);

      if(angle < 90){
        analogWrite(PWMA, strength * 255 / 100);
        analogWrite(PWMB, strength * (angle * 255 / 90) / 100);
      }else if(angle > 90){
        analogWrite(PWMA, strength * ((180 - angle) * 255 / 90) / 100);
        analogWrite(PWMB, strength * 255 / 100);
      }else{
        analogWrite(PWMA, strength * 255 / 100);
        analogWrite(PWMB, strength * 255 / 100);
      }
    }else if(angle > 180){
      digitalWrite(BIN2,1);
      digitalWrite(AIN2,1);
      
      if(angle > 270){
        analogWrite(PWMA, strength * 255 / 100);
        analogWrite(PWMB, strength * ((360 - angle) * 255 / 90) / 100);
      }else if(angle < 270){
        analogWrite(PWMA, strength * ((90 - (270 - angle)) * 255 / 90) / 100);
        analogWrite(PWMB, strength * 255 / 100);
      }else{
        analogWrite(PWMA, strength * 255 / 100);
        analogWrite(PWMB, strength * 255 / 100);
      }
    }
    return;
  }

  if(data.equals("a")){
    if(ledVal==1) ledVal=0; else ledVal=1;
    digitalWrite(ledpin, ledVal);
    return;
  }
  
  Serial.print("Recieved: ");
  Serial.println(data);
}
