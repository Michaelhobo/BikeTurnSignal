#include <helper_3dmath.h>
#include <MPU6050.h>
#include <MPU6050_6Axis_MotionApps20.h>
#include <MPU6050_9Axis_MotionApps41.h>

#include <I2Cdev.h>

#include <Wire.h>

int EL_toggle = 9;
int x_accel = A1;
int y_accel = A2;
int z_accel = A3;

// The bias specifies the smallest value for a still sensor reading
int x_bias = 401;
int y_bias = 401;
int z_bias = 391;

// The value of gravity in one direction
double g_x = 204.0;
double g_y = 206.0;
double g_z = 206.0;

int panel_on = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(EL_toggle, OUTPUT);
  pinMode(x_accel, INPUT);
  pinMode(y_accel, INPUT);
  pinMode(z_accel, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  double x = (analogRead(x_accel) - x_bias)/g_x;
  double y = (analogRead(y_accel) - y_bias)/g_y;
  double z = (analogRead(z_accel) - z_bias)/g_z;
  if (z_up(z)) {
    panel_on = 1;
    EL_on();
  } else {
    EL_off();
    panel_on = 0;
  }
  String output = "x: ";
  output += x;
  output += ", y: ";
  output += y;
  output +=", z: ";
  output += z;
  output += "\n";
  Serial.print(output);
}

// find closeness to given angle

/* Whether the z axis is facing "up" */
bool z_up(int z) {
  if (panel_on) {
    return (z > 60);
  } else {
    return (z > 80);
  }
}

/* Turn EL panel on */
void EL_on() {
  digitalWrite(EL_toggle, HIGH);
}

/* Turn El panel off */
void EL_off() {
  digitalWrite(EL_toggle, LOW);
}

