#include "GYSensor.h"
#include <Wire.h>


void GYSensor::init(int address)
{
    this->address_ = address;
    Wire.beginTransmission(address);
    Wire.write(0x6B);
    Wire.write(0);
    Wire.endTransmission();
}


int16_t* GYSensor::GetGyroscope()
{
    int16_t ret[3];
    ret[0] = this->gx_;
    ret[1] = this->gy_;
    ret[2] = this->gz_;
    
    return ret;
}


int16_t GYSensor::GetTemperature()
{
    return this->temp_;
}


void GYSensor::read()
{
    Wire.beginTransmission(this->address_);
    Wire.write(0x3B);
    Wire.endTransmission(false);
    Wire.requestFrom(this->address_, 14, true);
    
    this->ax_ = Wire.read() << 8 | Wire.read();
    this->ay_ = Wire.read() << 8 | Wire.read();
    this->az_ = Wire.read() << 8 | Wire.read();
    this->temp_ = Wire.read() << 8 | Wire.read();
    this->gx_ = Wire.read() << 8 | Wire.read();
    this->gy_ = Wire.read() << 8 | Wire.read();
    this->gz_ = Wire.read() << 8 | Wire.read();
}
