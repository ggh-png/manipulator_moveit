/*
 * rosserial Servo Control Example
 *
 * This sketch demonstrates the control of hobby R/C servos
 * using ROS and the arduiono
 * 
 * For the full tutorial write up, visit
 * www.ros.org/wiki/rosserial_arduino_demos
 *
 * For more information on the Arduino Servo Library
 * Checkout :
 * http://www.arduino.cc/en/Reference/Servo
 */

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include <WProgram.h>
#endif

#include "servo.h" 
#include <ros.h>
#include <std_msgs/UInt16.h>
#include <sensor_msgs/JointState.h>



#define base_joint   0
#define joint_1      1
#define joint_2      3
#define gripper      4

ros::NodeHandle  nh;


float base_angle=      90;
float shoulder_angle=  90;
float elbow_angle=     90;
float wrist_angle=     90;
float gripper_angle=   90;


double radiansToDegrees(float position_radians);
void servo_cb(const sensor_msgs::JointState& cmd_msg);

void servo_cbc( const std_msgs::UInt16& cmd_msg){          //cmd 명령어를 쓰겠다.
 
  LobotSerialServoMove(Serial3, 4, cmd_msg.data, 1000);
  digitalWrite(13, HIGH-digitalRead(13));  //toggle led 
}


   
ros::Subscriber<sensor_msgs::JointState> sub("joint_states", servo_cb);

void setup(){
  Serial3.begin(115200);

  nh.getHardware()->setBaud(115200); 
  nh.initNode(); // 노드명 초기화
  nh.subscribe(sub); //sub 으로 지정
  
  LobotSerialServoMove(Serial3, base_joint, 500,500);
  LobotSerialServoMove(Serial3, joint_1, 500,500);
  LobotSerialServoMove(Serial3, joint_2, 500,500);
  LobotSerialServoMove(Serial3, gripper, 500,500);  
}


void loop(){
  nh.spinOnce();
}


void servo_cb(const sensor_msgs::JointState& cmd_msg){
  base_angle=radiansToDegrees(cmd_msg.position[0]) / 0.24;
  shoulder_angle=radiansToDegrees(cmd_msg.position[1])/ 0.24;
  elbow_angle=radiansToDegrees(cmd_msg.position[2])/ 0.24;
  gripper_angle=radiansToDegrees(cmd_msg.position[3])/ 0.24;

  LobotSerialServoMove(Serial3, base_joint,base_angle ,500);
  LobotSerialServoMove(Serial3, joint_1, shoulder_angle,500);
  LobotSerialServoMove(Serial3, joint_2, elbow_angle,500);
  LobotSerialServoMove(Serial3, gripper, gripper_angle,500);   
 
}


double radiansToDegrees(float position_radians)
{
  position_radians = position_radians + 2.094;
  return position_radians * 57.2958;
}
