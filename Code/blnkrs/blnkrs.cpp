//RV_2.2

//Code for arduino nano to function as a Bluetooth Slave and receiver to control a group of LEDs to work as Blinkers and road lights
//Revision 2.1 of the main board of the Reciever
//Code written and edited by Pedro Torrado

//Differences from last Revision (1.1)
  //Improved code and performance
  //Improved comments to easier understanding
    //MOST IMPORTANT//
  //Created two-way signal communication which makes possible :
  //Verification of the signal sent through Serial Monitor and visible LEDs to Warn the user in case the communication didn't work as planned

//Differences 2.0
  //Command '0' added for toubleshooting
  //Command '3' removed

//Differences 2.1
  //Connection confirmation
  //leftstate and rightstate functions created
  //Command '9' added to check output status and send validation data

#include <Arduino.h>
#include <SoftwareSerial.h>
SoftwareSerial bt(3, 2);  //RX, TX

#define left_led 7
#define right_led 8

int i;
int left_state = 1;
int right_state = 1;
int lr_state = 0;
int new_left_state = 1;
int new_right_state = 1;
int new_lr_state = 0;
char serial_command;

void setup() {
  pinMode(3, INPUT);
  pinMode(2, OUTPUT);

  pinMode(left_led, OUTPUT);  // sets the digital pin 7 as output
  pinMode(right_led, OUTPUT);  // sets the digital pin 8 as output

  Serial.begin(9600);
  bt.begin(9600);

  Serial.println("Start Blnkrs");

}

void leftstate(){
  if(left_state == 0){
    bt.write(10);
  }
  else if(left_state == 1){
    bt.write(11);
  }
  else {
    Serial.println("Input error : state was changed but the result isn't valid");
  }
}

void rightstate(){
  if (right_state == 1){
    bt.write(21);
  }
  else if (right_state == 0){
    bt.write(20);
  }
  else{
    Serial.println("Input error : state was changed but the result isn't valid");
  }
}

void loop() {

  if(bt.available()>0 or Serial.available()){

    char command = bt.read();
    serial_command = Serial.read();

    leftstate();
    rightstate();

    if (command != ""){
      Serial.println(command);
    }
    else if (serial_command != ""){
      Serial.println(serial_command);
    }

    if(command == '9' or serial_command == '9'){
      Serial.println("Device Paired");
      bt.write(91);

      leftstate();
      rightstate();
    }

    else if (command == '0' or serial_command == '0'){

      //used to troubleshoot communication between modules
      //sends and receives all the information needed for two-way communication and hardware check
      //can't be achieved through hardware

      if(new_lr_state == 1){
        digitalWrite(left_led, HIGH);
        digitalWrite(right_led, HIGH);
        Serial.println("LEFT_&_RIGHT_HIGH");
        lr_state = 0;
        right_state = 0;
        left_state = 0;
      }

      else if(new_lr_state == 0){
        digitalWrite(left_led, LOW);
        digitalWrite(right_led, LOW);
        Serial.println("LEFT_&_RIGHT_LOW");
        lr_state = 1;
        left_state = 1;
        right_state = 1;
      }

      new_lr_state = lr_state;

      if (lr_state == 1){
        bt.write(11);
        bt.write(21);
      }
      else if (lr_state == 0){
        bt.write(10);
        bt.write(20);
      }
      else{
        Serial.println("Input error : the state was changed but the result isn't valid");
      }
    }

    if (command == '1' or serial_command == '1') {

      if (new_left_state == 1) {
        digitalWrite(left_led, HIGH);  // sets the digital pin 7 ON
        Serial.println("LEFT_HIGH");   // print on serial monitor the pin mode
        left_state = 0;
      }
      else if (new_left_state == 0) {
        digitalWrite(left_led, LOW);  // sets the digital pin 7 OFF
        Serial.println("LEFT_LOW");   // print on serial monitor the pin mode
        left_state = 1;
      }

      new_left_state = left_state;

      leftstate();
    }

    if (command == '2' or serial_command == '2') {

      if (new_right_state == 1) {
        digitalWrite(right_led, HIGH);  // sets the digital pin 7 ON
        Serial.println("RIGHT_HIGH");   // print on serial monitor the pin mode
        right_state = 0;
      }

      else if (new_right_state == 0) {
        digitalWrite(right_led, LOW);  // sets the digital pin 7 OFF
        Serial.println("RIGHT_LOW");   // print on serial monitor the pin mode
        right_state = 1;
      }

      new_right_state = right_state;

      rightstate();

    }
  }
}
