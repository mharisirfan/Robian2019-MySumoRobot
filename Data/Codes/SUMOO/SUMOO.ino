//// Muhammad Haris Irfan - FA18-BCE-090 - Open Source Awami Code- Sada-e-Jariah //// 
const int RM1 = 5;
const int RM2 = 6;
const int LM1 = 7;
const int LM2 = 8;
const int ENA = 9;
const int ENB = 10;
const int HORN  = 13;
void setup() {
 
  Serial.begin(9600);
  
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  pinMode(ENA,OUTPUT);
 pinMode(ENB,OUTPUT);
  pinMode(HORN,OUTPUT);

  digitalWrite(RM1,HIGH);
  digitalWrite(RM2,HIGH);
  digitalWrite(LM1,HIGH);
  digitalWrite(LM2,HIGH);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(HORN,LOW);

  Serial.println("Ready");
}

void loop() {
  // put your main code here, to run repeatedly:
//// Muhammad Haris Irfan - FA18-BCE-090 - Open Source Awami Code- Sada-e-Jariah ////
  char input;
  if(Serial.available() > 0){
    input = Serial.read();

    switch(input){
      case 'F':
     
analogWrite(ENA, 0);
       analogWrite(ENB, 0);
        digitalWrite(RM1,HIGH);
        digitalWrite(RM2,LOW);
        digitalWrite(LM1,HIGH);
        digitalWrite(LM2,LOW);
          
        Serial.println("Forward");
        break;
      case 'B':
      
 analogWrite(ENA, 0);
       analogWrite(ENB, 0);
        digitalWrite(RM1,LOW);
        digitalWrite(RM2,HIGH);
        digitalWrite(LM1,LOW);
        digitalWrite(LM2,HIGH);
        Serial.println("Backward");
        
        break;
      case 'L': //Clockwise axis left
      
        
          analogWrite(ENA, 255);
        analogWrite(ENB, 0);
        digitalWrite(RM1,HIGH);
        digitalWrite(RM2,LOW);
        digitalWrite(LM1,LOW);
        digitalWrite(LM2,LOW);

        
        Serial.println("Clockwise axis left");
        break;
       
      case 'R'://Clockwise axis right

          analogWrite(ENA, 0);
        analogWrite(ENB, 255);
        digitalWrite(RM1,LOW);     
        digitalWrite(RM2,LOW);
        digitalWrite(LM1,HIGH);
        digitalWrite(LM2,LOW);
        Serial.println("Clockwise axis right");
        break;
      case 'G': //Forward left

        analogWrite(ENA, 150);
        analogWrite(ENB, 0);
      
        digitalWrite(RM1,HIGH);
        digitalWrite(RM2,LOW);
        digitalWrite(LM1,HIGH);
        digitalWrite(LM2,LOW);

        Serial.println("Forward left");
        break;
      case 'I': //Forward right 
//// Muhammad Haris Irfan - FA18-BCE-090 - Open Source Awami Code- Sada-e-Jariah ////
       analogWrite(ENA, 0);
       analogWrite(ENB, 150);

      
        digitalWrite(RM1,HIGH);
        digitalWrite(RM2,LOW);
        digitalWrite(LM1,HIGH);
        digitalWrite(LM2,LOW);
        Serial.println("Forward right");
        break;

      case 'J': //backward left

        analogWrite(ENA, 0);
        analogWrite(ENB, 150);
      
        digitalWrite(RM1,LOW);
        digitalWrite(RM2,HIGH);
        digitalWrite(LM1,LOW);
        digitalWrite(LM2,HIGH);

        Serial.println("backward left");
        break;
      case 'H': //backward right 

       analogWrite(ENA, 150);
       analogWrite(ENB, 0);

      
        digitalWrite(RM1,LOW);
        digitalWrite(RM2,HIGH);
        digitalWrite(LM1,LOW);
        digitalWrite(LM2,HIGH);
        Serial.println("Backward right");
        break;

        
      case 'S': //Stop

      //// Muhammad Haris Irfan - FA18-BCE-090 - Open Source Awami Code- Sada-e-Jariah ////
        digitalWrite(RM1,LOW);
        digitalWrite(RM2,LOW);
        digitalWrite(LM1,LOW);
        digitalWrite(LM2,LOW);
        Serial.println("Stop");
        break;
      
        case 'V':
        digitalWrite(HORN,HIGH);
        break;
        
        case 'v':
        digitalWrite(HORN,LOW);
        break;
    }
  }
}

//// Muhammad Haris Irfan - FA18-BCE-090 - Open Source Awami Code- Sada-e-Jariah ////
