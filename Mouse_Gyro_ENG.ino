/* Code to control the mouse pointer
 * through the movement of the head
 * Change values at vx and vy (+300 and -100 in my case)
 * using the TEST code to make your project work.
 * 
 * Gabry295
 */

#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
//#include <Mouse.h>

MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
int vx, vy;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  mpu.initialize();
  if (!mpu.testConnection()) {
    while (1);
    }
}
 void prt(int a,int b,int c,int d,int e,int f)
 {
  Serial.print(a);
  Serial.print("   ");
  Serial.print(b);
  Serial.print("   ");
  Serial.print(c);
  Serial.print("   ");
  Serial.print(d);
  Serial.print("   ");
  Serial.print(e);
  Serial.print("   ");
  Serial.println(f);
 }
void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  vx = -(gx+300)/80;  // "+300" because the x axis of gyroscope give values about -350 while it's not moving. Change this value if you get something different using the TEST code, chacking if there are values far from zero.
  vy = (gy)/80; 
  prt(ax,ay,az,gx,gy,gz);
//  Mouse.move(vx, vy);
  
  delay(20);
}
