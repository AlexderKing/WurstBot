#ifndef GYSENSOR_H_
#define GYSENSOR_H_

#include <stdint.h>

class GYSensor final
{
public:
    void init(int address);
    int16_t* GetGyroscope();
    int16_t GetTemperature();
    
    void read();
    
private:
    uint16_t ax_, ay_, az_, gx_, gy_, gz_, temp_;
    int address_;
};

#endif
