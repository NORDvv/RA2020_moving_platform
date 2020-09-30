
 
//int reverseSwitch = 2;  // Push button for reverse
int driverPUL = 7;    // PUL- pin
int driverDIR = 6;    // DIR- pinint spd = A0;     // Potentiometer
 
// Variables
 
int pd = 1000;       // Pulse Delay period
boolean setdir = LOW; // Set Direction
int num_rotations = 1;

char comm = 'e';
boolean newCommand = false;

void setup() {
  pinMode (driverPUL, OUTPUT);
  pinMode (driverDIR, OUTPUT);
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
    //digitalWrite(driverDIR,setdir);
    //digitalWrite(driverPUL,HIGH);
    //delayMicroseconds(pd);
    //digitalWrite(driverPUL,LOW);
    //delayMicroseconds(pd);
}

void move(char command) {
  if (command == 'F') {
    Serial.println("Moving forward");
    for (int i = 0; i < 100 * num_rotations; i++) {
    //motorX.step(1);
      counterclockwise1();
    }
  } else if (command == 'B') {
    // move bacwards
    Serial.println("Moving backwards");
    for (int i = 0; i < 100  * num_rotations; i++) {
    //motorX.step(-1);
      clockwise1();
    }
  } else if (command == 'R') {
    // move right -> increase number of rotations by 1
    //Serial.println("Moving right");
    //for (int i = 0; i < 300; i++) {
    //motorY.step(1);
      //clockwise1();
    //}
    num_rotations += 1;
  } else if (command == 'L') {
    // move left -> decrease number of rotations by 1
    //Serial.println("Moving left");
    //for (int i = 0; i < 300; i++) {
    //motorY.step(-1);
    //  counterclockwise1();
    //}
    num_rotations -= 1;
  } else {
    Serial.println("Wrong command");
  }
}

void counterclockwise1 (){
    setdir = LOW;
    for (int i = 0; i < 10; i++)
    {
        digitalWrite(driverDIR,setdir);
        digitalWrite(driverPUL,HIGH);
        delayMicroseconds(pd);
        digitalWrite(driverPUL,LOW);
        delayMicroseconds(pd);
    }
}
/////////////////////////////////////////////////////////////////////////
void clockwise1(){
    setdir = HIGH;
    for (int i = 0; i < 10; i++)
    {
        digitalWrite(driverDIR,setdir);
        digitalWrite(driverPUL,HIGH);
        delayMicroseconds(pd);
        digitalWrite(driverPUL,LOW);
        delayMicroseconds(pd);
    }
}
