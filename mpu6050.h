#pragma once

#include "i2c.h"

#define	SMPLRT_DIV		0x19	
#define	CONFIG			0x1A	
#define	GYRO_CONFIG		0x1B	
#define	ACCEL_CONFIG	0x1C	
#define	ACCEL_XOUT_H	0x3B	
#define	ACCEL_XOUT_L	0x3C
#define	ACCEL_YOUT_H	0x3D
#define	ACCEL_YOUT_L	0x3E
#define	ACCEL_ZOUT_H	0x3F
#define	ACCEL_ZOUT_L	0x40
#define	TEMP_OUT_H		0x41
#define	TEMP_OUT_L		0x42
#define	GYRO_XOUT_H		0x43
#define	GYRO_XOUT_L		0x44	
#define	GYRO_YOUT_H		0x45
#define	GYRO_YOUT_L		0x46
#define	GYRO_ZOUT_H		0x47
#define	GYRO_ZOUT_L		0x48
#define	PWR_MGMT_1		0x6B	
#define	WHO_AM_I		0x75	
#define	MPU6050_ADDR	0x68	

class MPU6050 {
private:
    I2C *i2c;
public:
    MPU6050(gpio_num_t scl, gpio_num_t sda, i2c_port_t port);
    MPU6050();
    ~MPU6050();
    
    float ay, az, gx;
    float anglex;

    bool init();

    float getAccX();
    float getAccY();
    float getAccZ();

    float getGyroX();
    float getGyroY();
    float getGyroZ();

    short getTemp();

    void update();
};
