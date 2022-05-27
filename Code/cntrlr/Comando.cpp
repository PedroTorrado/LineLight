//RV_2.4

//Code for arduino nano to function as a Bluetooth Master in order to controll the Blinkers main board
//Revision 2.3 of the main board of the Controller
//Code writen and edited by Pedro Torrado

//Diferences from last Revision (1.2 - 2.0)
  //Improved code and performance
  //Improved comments in order to easier understanding
    //MOST IMPORTANT//
  //Created two way signal communication which makes possible :
  //Verification of the signal sent through Serial Monitor and visable LEDs in order to Warn the user in case the communication didn't work as planned

//Differences from 2.0
  //Verification turned into a function in order to reduce delay between comunication and avoid delays

//Differences from 2.1
  //delay functions devided in order to have time to recieve the information without having to wait the full 1000ms

//Differences from 2.2
  //Verification after checking bluetooth signal in order to have better response to led state commands from slave

//Differences from 2.3
  //Connection confirmation
  //Variable request in order to verify the led status

#include <Arduino.h>
#include <SoftwareSerial.h>
SoftwareSerial bt(2, 3);  //RX, TX

#define right_hes 5
#define left_hes 4
#define bt_enable 9
#define left_led 7
#define right_led 8

int left_state = 1;
int right_state = 1;
int verification_code;

void setup() {
  //Bluetooth RX and TX defined
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);

  //HC06 enable pin set to high
  pinMode(9, OUTPUT);
  digitalWrite(bt_enable, HIGH);
  bt.begin(9600);

  //Hall Effect Sensors defined
  pinMode(right_hes, INPUT);
  pinMode(left_hes, INPUT);

  //Verification LEDs defined
  pinMode(left_led, OUTPUT);
  pinMode(right_led, OUTPUT);

  Serial.begin(9600);
  Serial.println("Start Cntrlr");

  bt.write('9');
  Serial.println("Pairing...");
}

void verification(){

  if (bt.available()>0) {
    verification_code = bt.read();
    //Serial.println(verification_code); //Shows the byte sent from the slave for troubleshooting

    if(verification_code == 10){
      digitalWrite(left_led, HIGH);
      //Shows what type of confirmation it has recieved, for troubleshooting in case of led problems
      //Serial.println("left_confirmed_high");
    }
    else if(verification_code == 11){
      digitalWrite(left_led, LOW);
      //Serial.println("left_confirmed_low");
    }
    else if(verification_code == 20){
      digitalWrite(right_led, HIGH);
      //Serial.println("right_confirmed_high");
    }
    else if(verification_code == 21){
      digitalWrite(right_led, LOW);
      //Serial.println("right_confirmed_low");
    }
    else if(verification_code == 91){
      Serial.println("Device Paired");
    }

    else{
      Serial.println("Input error : Not intended result or verification");
    }

  }
  else{
    verification_code = "";
  }

}

void loop() {

  if (bt.available()>0) {
    verification();
  }

  left_state = digitalRead(left_hes);
  right_state = digitalRead(right_hes);
  //Show the output in Serial for troubleshooting
  //Serial.println(right_state);
  if (Serial.available()){
    bt.write(Serial.read());
  }

  if (right_state == LOW) {
    Serial.println("Right");
    //Show the output in Serial for troubleshooting
    //Serial.println('2');
    bt.write('2');
    delay(200);
    verification();
    delay(800);
  }

  if (left_state == LOW) {
    Serial.println("Left");
    //Show the output in Serial for troubleshooting
    //Serial.println('1');
    bt.write('1');
    delay(200);
    verification();
    delay(800);
  }
}
