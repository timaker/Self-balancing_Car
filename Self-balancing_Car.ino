#include "mpu6050.hpp"

MPU6050 mpu;

void setup()
{
    Serial.begin(115200);
    mpu.init();
    mpu.start();
}

void loop()
{
    Serial.println(mpu.anglex);
    delay(1000);
}
