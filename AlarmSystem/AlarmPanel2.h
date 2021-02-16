#pragma once
#include <iostream>
#include "Device.h"

class AlarmPanel2 :
    public Device
{
public:
    AlarmPanel2(int = 0, std::string ="Panel alarmowy");
    virtual void introduce();
};

