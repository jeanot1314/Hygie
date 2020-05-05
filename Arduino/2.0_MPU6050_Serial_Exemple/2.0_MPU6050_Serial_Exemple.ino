#include <Wire.h>

// i2c address of the mpu‐6050

const int MPU_ADDR = 0x68;

// variables

int16_t xAccel, yAccel, zAccel, temp, xGyro, yGyro, zGyro;

void setup()

{

// initialize the i2c library

Wire.begin();

// begin communication with the mpu‐6050

Wire.beginTransmission(MPU_ADDR);

// write to the power management register

Wire.write(0x6B);

// wake up the mpu‐6050

Wire.write(0);

// end communication with the mpu‐6050

Wire.endTransmission(true);

// initialize the serial port

Serial.begin(9600);

}

void loop()

{

// read the mpu data

readMpuData();

/*

  * put your code for the digital letter scale here

  */

// delay

delay(500);

}

void readMpuData()

{

// begin communication with the mpu‐6050

Wire.beginTransmission(MPU_ADDR);

// write to the first data register

Wire.write(0x3B);

// end communication

Wire.endTransmission(false);

// request fourteen register reads from the mpu‐6050

Wire.requestFrom(MPU_ADDR, 14, true);

// read registers 0x3B (ACCEL_XOUT_H) and 0x3C (ACCEL_XOUT_L)    

xAccel = Wire.read() << 8 | Wire.read();

// read registers 0x3D (ACCEL_YOUT_H) and 0x3E (ACCEL_YOUT_L)    

yAccel = Wire.read() << 8 | Wire.read();

// read registers 0x3F (ACCEL_ZOUT_H) and 0x40 (ACCEL_ZOUT_L)

zAccel = Wire.read() << 8 | Wire.read();

// read registers 0x41 (TEMP_OUT_H) and 0x42 (TEMP_OUT_L)

temp   = Wire.read() << 8 | Wire.read();

// convert the temperature to celsius

temp   = ((temp / 340.00) + 36.53);

// read registers 0x43 (GYRO_XOUT_H) and 0x44 (GYRO_XOUT_L)

xGyro = Wire.read() << 8 | Wire.read();

// read registers 0x45 (GYRO_YOUT_H) and 0x46 (GYRO_YOUT_L)

yGyro = Wire.read() << 8 | Wire.read();

// read registers 0x47 (GYRO_ZOUT_H) and 0x48 (GYRO_ZOUT_L)

zGyro = Wire.read() << 8 | Wire.read();

// print out the results

Serial.print("AX = "); Serial.print(xAccel); // X Raw Value

Serial.print(" | AY = "); Serial.print(yAccel); // Y Raw Value

Serial.print(" | AZ = "); Serial.print(zAccel); // Z Raw Value

Serial.print(" | C = "); Serial.print(temp);

Serial.print(" | GX = "); Serial.print(xGyro);

Serial.print(" | GY = "); Serial.print(yGyro);

Serial.print(" | GZ = "); Serial.println(zGyro);

}
