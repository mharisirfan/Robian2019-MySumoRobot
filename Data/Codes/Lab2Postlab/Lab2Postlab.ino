const int in=8;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(in,INPUT);
pinMode(4,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(in)==HIGH)
digitalWrite(4,HIGH);
else
digitalWrite(4,LOW);
}
