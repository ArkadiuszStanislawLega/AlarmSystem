#pragma once
#include "Device.h"
#include "User.h"
#include <iostream>

class AlarmPanel : public Device
{
private:
	User _users_database[10];
public:
	AlarmPanel(int = 0, std::string = "AlarmPanel");
	bool authenticate_user(User user);
	virtual void Device::introduce();
	virtual int Device::Id();
	virtual std::string Device::Name();
};

