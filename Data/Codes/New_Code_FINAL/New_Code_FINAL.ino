#include <SoftwareSerial.h> 
int bluetoothTx = 1; // bluetooth tx to 2 pin
int bluetoothRx = 0; // bluetooth rx to 3 pin
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
//Front Motor Pins  
int Enable1 = 9;
int Motor1_Pin1 = 5;  
int Motor1_Pin2 = 6;  

//Back Motor Pins      
int Motor2_Pin1 = 7; 
int Motor2_Pin2 = 8;
int Enable2 = 10; 


int horn = 13;

char command ; //variable to store the data
int velocity = 0; //Variable to control the speed of motor

void setup() 
{       
  //Set the baud rate of serial communication and bluetooth module at same rate.
  Serial.begin(9600);  
 bluetooth.begin(9600);
 
  //Setting the L298N, LED and RGB LED pins as output pins.
  pinMode(Motor1_Pin1, OUTPUT);  
  pinMode(Motor1_Pin2, OUTPUT);
  pinMode(Enable1, OUTPUT);
  pinMode(Motor2_Pin1, OUTPUT);  
  pinMode(Motor2_Pin2, OUTPUT);
  pinMode(Enable2, OUTPUT); 
 
  pinMode(horn, OUTPUT);
 

  //Setting the enable and RGB LED pins as HIGH.
  digitalWrite(Enable1, LOW);
  digitalWrite(Enable2, LOW);

}

void loop(){
    if(bluetooth.available() > 0){  //Checking if there is some data available or not
    command = bluetooth.read();   //Storing the data in the 'command' variable
    Serial.println(command);      //Printing it on the serial monitor
    
    //Change pin mode only if new command is different from previous.   
    switch(command){
    case 'F':  //Moving the Car Forward
      digitalWrite(Motor2_Pin2, LOW);
      digitalWrite(Motor2_Pin1, HIGH);
      digitalWrite(Motor1_Pin1, LOW);
      digitalWrite(Motor1_Pin2, LOW);
      break;
    case 'B':  //Moving the Car Backward
      digitalWrite(Motor2_Pin1, LOW);
      digitalWrite(Motor2_Pin2, HIGH);
      digitalWrite(Motor1_Pin1, LOW);
      digitalWrite(Motor1_Pin2, LOW);
      break;
    case 'L':  //Moving the Car Left
      digitalWrite(Motor1_Pin1, LOW);
      digitalWrite(Motor1_Pin2, HIGH);
      digitalWrite(Motor2_Pin1, LOW);
      digitalWrite(Motor2_Pin2, LOW);
      break;
    case 'R':   //Moving the Car Right
      digitalWrite(Motor1_Pin2, LOW);
      digitalWrite(Motor1_Pin1, HIGH);  
      digitalWrite(Motor2_Pin1, LOW);
      digitalWrite(Motor2_Pin2, LOW);
      break;
    case 'S':   //Stop
      digitalWrite(Motor2_Pin2, LOW);
      digitalWrite(Motor2_Pin1, LOW);
      digitalWrite(Motor1_Pin2, LOW);
      digitalWrite(Motor1_Pin1, LOW);
      break; 
    case 'I':  //Moving the Car Forward right
      digitalWrite(Motor2_Pin2, LOW);
      digitalWrite(Motor2_Pin1, HIGH);
      digitalWrite(Motor1_Pin2, LOW);
      digitalWrite(Motor1_Pin1, HIGH);
      break; 
    case 'J':  //Moving the Car backward right
      digitalWrite(Motor1_Pin2, LOW);
      digitalWrite(Motor1_Pin1, HIGH);
      digitalWrite(Motor2_Pin1, LOW);
      digitalWrite(Motor2_Pin2, HIGH);
      break;        
    case 'G':  //Moving the Car Forward left
      digitalWrite(Motor2_Pin2, LOW);
      digitalWrite(Motor2_Pin1, HIGH);
      digitalWrite(Motor1_Pin1, LOW);
      digitalWrite(Motor1_Pin2, HIGH);
      break; 
    case 'H':  //Moving the Car backward left
      digitalWrite(Motor2_Pin1, LOW);
      digitalWrite(Motor2_Pin2, HIGH);
      digitalWrite(Motor1_Pin1, LOW);
      digitalWrite(Motor1_Pin2, HIGH);
      break;
    
    case 'V':  //Horn On
      tone(horn,494);
      break; 
    case 'v':  //Horn OFF 
       noTone(horn);
      break;   
    case 'x': //Turn ON Everything

    break;
    case 'X': //Turn OFF Everything
      
    break;

    //Controlling the Speed of Car  
    default:  //Get velocity
      if(command=='q'){
        velocity = 255;  //Full velocity
        analogWrite(Enable2, velocity);
      }
      else{ 
        //Chars '0' - '9' have an integer equivalence of 48 - 57, accordingly.
        if((command >= 48) && (command <= 57)){ 
          //Subtracting 48 changes the range from 48-57 to 0-9.
          //Multiplying by 25 changes the range from 0-9 to 0-225.
          velocity = (command - 48)*25;       
          analogWrite(Enable2, velocity);
        }
      }
      }
    }
    
  } 
