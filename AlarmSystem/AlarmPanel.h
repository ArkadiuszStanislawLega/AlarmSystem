#pragma once
#include "Device.h"
#include <iostream>

class AlarmPanel : public Device
{
public:
	AlarmPanel(int = 0, std::string = "AlarmPanel");
	virtual void Device::introduce();
};

