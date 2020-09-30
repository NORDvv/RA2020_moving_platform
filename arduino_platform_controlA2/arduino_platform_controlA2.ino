int motorXconnections[] = {8, 9, 10, 11};
int motorYconnections[] = {3,4, 5, 6};//{4, 3, 6, 5};

int stepsPerRevolution = 100;
int motorSpeed = 5;

char comm = 'e';
boolean newCommand = false;

void setup() {
   //declare the motor pins as outputs
  pinMode(motorXconnections[0], OUTPUT);
  pinMode(motorXconnections[1], OUTPUT);
  pinMode(motorXconnections[2], OUTPUT);
  pinMode(motorXconnections[3], OUTPUT);

  pinMode(motorYconnections[0], OUTPUT);
  pinMode(motorYconnections[1], OUTPUT);
  pinMode(motorYconnections[2], OUTPUT);
  pinMode(motorYconnections[3], OUTPUT);
  Serial.begin(9600);

}

void loop() {
    if ( Serial.available() > 0) {
    char data = Serial.read();
    Serial.println(data); //TODO: delete
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    comm = data;
    newCommand = true;
  }
  if (newCommand) {

    move(comm);
    newCommand = false;
  }
}

void move(char command) {
  if (command == 'F') {
    Serial.println("Moving forward");
    for (int i = 0; i < 300; i++) {
    //motorX.step(1);
      clockwise1(motorXconnections);
    }
  } else if (command == 'B') {
    // move bacwards
    Serial.println("Moving backwards");
    for (int i = 0; i < 300; i++) {
    //motorX.step(-1);
      counterclockwise1(motorXconnections);
    }
  } else if (command == 'R') {
    // move right
    Serial.println("Moving right");
    for (int i = 0; i < 300; i++) {
    //motorY.step(1);
      clockwise3(motorYconnections);
    }
  } else if (command == 'L') {
    // move left
    Serial.println("Moving left");
    for (int i = 0; i < 300; i++) {
    //motorY.step(-1);
      counterclockwise3(motorYconnections);
    }
  } else {
    Serial.println("Wrong command");
  }
}

void counterclockwise1 (int* motorPins){ //taken (with some modifications) from:https://forum.arduino.cc/index.php/topic,85335.0.html
 // 1
 digitalWrite(motorPins[0], HIGH);
 digitalWrite(motorPins[1], LOW);
 digitalWrite(motorPins[2], LOW);
 digitalWrite(motorPins[3], LOW);
 delay(motorSpeed);
 // 2
 digitalWrite(motorPins[0], HIGH);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[2], LOW);
 digitalWrite(motorPins[3], LOW);
 delay (motorSpeed);
 // 3
 digitalWrite(motorPins[0], LOW);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[2], LOW);
 digitalWrite(motorPins[3], LOW);
 delay(motorSpeed);
 // 4
 digitalWrite(motorPins[0], LOW);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[3], LOW);
 delay(motorSpeed);
 // 5
 digitalWrite(motorPins[0], LOW);
 digitalWrite(motorPins[1], LOW);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[3], LOW);
 delay(motorSpeed);
 // 6
 digitalWrite(motorPins[0], LOW);
 digitalWrite(motorPins[1], LOW);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[3], HIGH);
 delay (motorSpeed);
 // 7
 digitalWrite(motorPins[0], LOW);
 digitalWrite(motorPins[1], LOW);
 digitalWrite(motorPins[2], LOW);
 digitalWrite(motorPins[3], HIGH);
 delay(motorSpeed);
 // 8
 digitalWrite(motorPins[0], HIGH);
 digitalWrite(motorPins[1], LOW);
 digitalWrite(motorPins[2], LOW);
 digitalWrite(motorPins[3], HIGH);
 delay(motorSpeed);
}
/////////////////////////////////////////////////////////////////////////
void clockwise1(int* motorPins){
 // 1
 digitalWrite(motorPins[3], HIGH);
 digitalWrite(motorPins[2], LOW);
 digitalWrite(motorPins[1], LOW);
 digitalWrite(motorPins[0], LOW);
 delay(motorSpeed);
 // 2
 digitalWrite(motorPins[3], HIGH);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[1], LOW);
 digitalWrite(motorPins[0], LOW);
 delay (motorSpeed);
 // 3
 digitalWrite(motorPins[3], LOW);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[1], LOW);
 digitalWrite(motorPins[0], LOW);
 delay(motorSpeed);
 // 4
 digitalWrite(motorPins[3], LOW);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[0], LOW);
 delay(motorSpeed);
 // 5
 digitalWrite(motorPins[3], LOW);
 digitalWrite(motorPins[2], LOW);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[0], LOW);
 delay(motorSpeed);
 // 6
 digitalWrite(motorPins[3], LOW);
 digitalWrite(motorPins[2], LOW);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[0], HIGH);
 delay (motorSpeed);
 // 7
 digitalWrite(motorPins[3], LOW);
 digitalWrite(motorPins[2], LOW);
 digitalWrite(motorPins[1], LOW);
 digitalWrite(motorPins[0], HIGH);
 delay(motorSpeed);
 // 8
 digitalWrite(motorPins[3], HIGH);
 digitalWrite(motorPins[2], LOW);
 digitalWrite(motorPins[1], LOW);
 digitalWrite(motorPins[0], HIGH);
 delay(motorSpeed);
}
/*
void counterclockwise2 (int* motorPins){ //taken (with some modifications) from:https://forum.arduino.cc/index.php/topic,85335.0.html
 // 1
 digitalWrite(motorPins[0], HIGH);
 digitalWrite(motorPins[1], LOW);
 digitalWrite(motorPins[2], LOW);
 digitalWrite(motorPins[3], LOW);
 delay(motorSpeed);
 // 2
 digitalWrite(motorPins[0], HIGH);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[2], LOW);
 digitalWrite(motorPins[3], LOW);
 delay (motorSpeed);
 // 3
 digitalWrite(motorPins[0], LOW);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[2], LOW);
 digitalWrite(motorPins[3], LOW);
 delay(motorSpeed);
 // 4
 digitalWrite(motorPins[0], LOW);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[3], LOW);
 delay(motorSpeed);
 // 5
 digitalWrite(motorPins[0], LOW);
 digitalWrite(motorPins[1], LOW);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[3], LOW);
 delay(motorSpeed);
 // 6
 digitalWrite(motorPins[0], LOW);
 digitalWrite(motorPins[1], LOW);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[3], HIGH);
 delay (motorSpeed);
 // 7
 digitalWrite(motorPins[0], LOW);
 digitalWrite(motorPins[1], LOW);
 digitalWrite(motorPins[2], LOW);
 digitalWrite(motorPins[3], HIGH);
 delay(motorSpeed);
 // 8
 digitalWrite(motorPins[0], HIGH);
 digitalWrite(motorPins[1], LOW);
 digitalWrite(motorPins[2], LOW);
 digitalWrite(motorPins[3], HIGH);
 delay(motorSpeed);
}
/////////////////////////////////////////////////////////////////////////
void clockwise2(int* motorPins){
 // 1
 digitalWrite(motorPins[3], LOW);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[0], HIGH);
 delay(motorSpeed);
 // 2
 digitalWrite(motorPins[3], LOW);
 digitalWrite(motorPins[2], LOW);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[0], HIGH);
 delay (motorSpeed);
 // 3
 digitalWrite(motorPins[3], HIGH);
 digitalWrite(motorPins[2], LOW);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[0], HIGH);
 delay(motorSpeed);
 // 4
 digitalWrite(motorPins[3], HIGH);
 digitalWrite(motorPins[2], LOW);
 digitalWrite(motorPins[1], LOW);
 digitalWrite(motorPins[0], HIGH);
 delay(motorSpeed);
 // 5
 digitalWrite(motorPins[3], HIGH);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[1], LOW);
 digitalWrite(motorPins[0], HIGH);
 delay(motorSpeed);
 // 6
 digitalWrite(motorPins[3], HIGH);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[1], LOW);
 digitalWrite(motorPins[0], LOW);
 delay (motorSpeed);
 // 7
 digitalWrite(motorPins[3], HIGH);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[0], LOW);
 delay(motorSpeed);
 // 8
 digitalWrite(motorPins[3], LOW);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[0], LOW);
 delay(motorSpeed);
}*/

void counterclockwise3 (int* motorPins){ //taken (with some modifications) from:https://forum.arduino.cc/index.php/topic,85335.0.html
 // 1
 digitalWrite(motorPins[0], HIGH);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[3], LOW);
 delay(motorSpeed);
 // 2
 digitalWrite(motorPins[0], LOW);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[3], HIGH);
 delay (motorSpeed);
 // 3
 digitalWrite(motorPins[0], HIGH);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[2], LOW);
 digitalWrite(motorPins[3], HIGH);
 delay(motorSpeed);
 // 4
 digitalWrite(motorPins[0], HIGH);
 digitalWrite(motorPins[1], LOW);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[3], HIGH);
 delay(motorSpeed);
 // 5
 digitalWrite(motorPins[0], HIGH);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[3], HIGH);
 delay(motorSpeed);
}
/////////////////////////////////////////////////////////////////////////
void clockwise3(int* motorPins){
 // 1
 digitalWrite(motorPins[0], LOW);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[3], HIGH);
 delay(motorSpeed);
 // 2
 digitalWrite(motorPins[0], HIGH);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[3], LOW);
 delay (motorSpeed);
 // 3
 digitalWrite(motorPins[0], HIGH);
 digitalWrite(motorPins[1], LOW);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[3], HIGH);
 delay(motorSpeed);
 // 4
 digitalWrite(motorPins[0], HIGH);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[2], LOW);
 digitalWrite(motorPins[3], HIGH);
 delay(motorSpeed);
 // 5
 digitalWrite(motorPins[0], HIGH);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[3], HIGH);
 delay(motorSpeed);
}

void counterclockwise4(int* motorPins){ //taken (with some modifications) from:https://forum.arduino.cc/index.php/topic,85335.0.html
 // 1
 digitalWrite(motorPins[0], HIGH);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[3], LOW);
 delay(motorSpeed);
 // 2
 digitalWrite(motorPins[0], LOW);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[3], HIGH);
 delay (motorSpeed);
 // 3
 digitalWrite(motorPins[0], HIGH);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[2], LOW);
 digitalWrite(motorPins[3], HIGH);
 delay(motorSpeed);
 // 4
 digitalWrite(motorPins[0], HIGH);
 digitalWrite(motorPins[1], LOW);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[3], HIGH);
 delay(motorSpeed);
 // 5
 digitalWrite(motorPins[0], HIGH);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[3], HIGH);
 delay(motorSpeed);
}
/////////////////////////////////////////////////////////////////////////
void clockwise4(int* motorPins){
 // 1
 digitalWrite(motorPins[0], LOW);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[3], HIGH);
 delay(motorSpeed);
 // 2
 digitalWrite(motorPins[0], HIGH);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[3], LOW);
 delay (motorSpeed);
 // 3
 digitalWrite(motorPins[0], HIGH);
 digitalWrite(motorPins[1], LOW);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[3], HIGH);
 delay(motorSpeed);
 // 4
 digitalWrite(motorPins[0], HIGH);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[2], LOW);
 digitalWrite(motorPins[3], HIGH);
 delay(motorSpeed);
 // 5
 digitalWrite(motorPins[0], HIGH);
 digitalWrite(motorPins[1], HIGH);
 digitalWrite(motorPins[2], HIGH);
 digitalWrite(motorPins[3], HIGH);
 delay(motorSpeed);
}
