void setup() {
  // put your setup code here, to run once:
pinMode(13, OUTPUT);
pinMode(8, OUTPUT);
pinMode(53, OUTPUT);
}

void loop() 
{

  // put your main code here, to run repeatedly:

digitalWrite(13, HIGH);

digitalWrite(53, HIGH);

digitalWrite(8, HIGH);

delay(2000);

digitalWrite(13, LOW);
digitalWrite(53, LOW);
digitalWrite(8, LOW);
delay(2000);





}
