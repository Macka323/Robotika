#include <Arduino.h>
#include "Braccio.h"

Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;

// Joint and id default positions
int id = 0, m1 = 90, m2 = 90, m3 = 90, m4 = 90, m5 = 90, m6 = 73;

void setup()
{
  // Arm Speed
  Serial.begin(115200);
  Braccio.begin();
}

void loop()
{
  // Printing every joint's default position
  Serial.print("  id=");
  Serial.print(id);
  Serial.print("  m1=");
  Serial.print(m1);
  Serial.print("  m2=");
  Serial.print(m2);
  Serial.print("  m3=");
  Serial.print(m3);
  Serial.print("  m4=");
  Serial.print(m4);
  Serial.print("  m5=");
  Serial.print(m5);
  Serial.print("  m6=");
  Serial.println(m6);

  String command = Serial.readStringUntil('\n');

  if (command[0] == 'i' && command[1] == 'd')
  {
    // Multiplies the variables so they fit within the motor's parameters
    id = (command[5] - 48);
    id += (command[4] - 48) * 10;
    id += (command[3] - 48) * 100;
  }
  
  if (command[0] == 'm')
  {
    // Switches between each joint
    switch (command[1])
    {
    case '1':
      m1 = (command[5] - 48);
      m1 += (command[4] - 48) * 10;
      m1 += (command[3] - 48) * 100;
      break;
    case '2':
      m2 = (command[5] - 48);
      m2 += (command[4] - 48) * 10;
      m2 += (command[3] - 48) * 100;
      break;
    case '3':
      m3 = (command[5] - 48);
      m3 += (command[4] - 48) * 10;
      m3 += (command[3] - 48) * 100;
      break;
    case '4':
      m4 = (command[5] - 48);
      m4 += (command[4] - 48) * 10;
      m4 += (command[3] - 48) * 100;
      break;
    case '5':
      m5 = (command[5] - 48);
      m5 += (command[4] - 48) * 10;
      m5 += (command[3] - 48) * 100;
      break;
    case '6':
      m6 = (command[5] - 48);
      m6 += (command[4] - 48) * 10;
      m6 += (command[3] - 48) * 100;
      break;
    default:
      break;
    }
  }

  // Inserting the movement variables
  Braccio.ServoMovement(10, m1, m2, m3, m4, m5, m6);
  Serial.print("end=");
  Serial.println(id);
}
