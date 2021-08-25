#include <ArduinoRobotMotorBoard.h>
#include <EasyTransfer2.h>
#include <LineFollow.h>
#include <Multiplexer.h>

#include <ArduinoRobot.h>
#include <Arduino_LCD.h>
#include <Compass.h>
#include <EasyTransfer2.h>
#include <EEPROM_I2C.h>
#include <Fat16.h>
#include <Fat16Config.h>
#include <Fat16mainpage.h>
#include <Fat16util.h>
#include <FatStructs.h>
#include <Multiplexer.h>
#include <SdCard.h>
#include <SdInfo.h>
#include <Squawk.h>
#include <SquawkSD.h>

void setup() {
  // put your setup code here, to run once:
Robot.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
Robot.motorsWrite(255,255); //Make the robot go forward, full speed
  delay(1000);
  Robot.motorsWrite(0,0); //Make the robot stop
  delay(1000);
  Robot.motorsWrite(255,-255);//Make the robot rotate right, full speed
  delay(1000);
  Robot.motorsWrite(0,0); //Make the robot stop
  delay(1000);
}
