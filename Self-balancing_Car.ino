#include "mpu6050.h"
#include <Ticker.h>

Ticker ticker_mpu;
MPU6050 mpu;

void update()
{
    mpu.update();
}

void setup()
{
    Serial.begin(115200);
    mpu.init();
    ticker_mpu.attach_ms(5, update);
}

void loop()
{
    Serial.println(mpu.anglex);
    delay(1000);
}
