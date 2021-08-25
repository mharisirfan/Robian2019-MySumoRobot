int m1 = 5;
int m2 = 6;
int m3 = 7;
int m4 = 8;

int numr = 128;
int numl = 115;

long counter=0;
long DV=0;
long factor = 5;
long timer = 0;
void backward(double t) {
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}

void forward(double t) {
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
  digitalWrite(m3, LOW);
  digitalWrite(m4, HIGH);
}

void right(double t) {
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, HIGH);
}

void left(double t) {
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}

void setup() {
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(13, OUTPUT);

  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
  digitalWrite(13, LOW);

  Serial.begin(9600);
}


char input;
void loop() {
  if(Serial.available() > 0) {
    timer = millis();
    input = Serial.read();
    DV = counter*factor;
    Serial.println(DV);
  //  Serial.println(input);
    if (input == 'f') {
     // forward(10);
     motorSpeed(128+DV,128+DV);
    }
    else if (input == 'b') {
     // backward(10);
     DV = counter*factor;
     motorSpeed(-128-DV,-128-DV);
    }
    else if (input == 'r') {
      motorSpeed(-128,128);
    }
    else if (input == 'l') {
     // left(10);
     motorSpeed(128,-128);
    }
    counter++;
  }
  else if(millis()-timer > 150)
  {
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW); 
  counter = 1;
  }
  
}

void motorSpeed(int right, int left)//hehehe
{
  if(left>255)
  {
    left = 255;
  }
  else if (left < -255)
  {
    left = -255;
  }
  if(right > 255)
  {
    right = 255;
  }
  else if(right < -255)
  {
    right=-255;
  }
  if(left < 0)
  {digitalWrite(m1,LOW);
  analogWrite(m2,abs(left));
  }else
  {
    digitalWrite(m2,LOW);
  analogWrite(m1,abs(left));
  }
  if(right < 0)
  {digitalWrite(m3,LOW);
  analogWrite(m4,abs(right));
  }else
  {
    digitalWrite(m4,LOW);
  analogWrite(m3,abs(right));
  }
}
