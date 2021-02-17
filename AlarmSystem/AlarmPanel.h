#pragma once
#include "Device.h"
#include "User.h"
#include <iostream>

class AlarmPanel : public Device
{
private:
	const static int MAX_AUTHORIZED_USERS = 10;

	User _users_database[MAX_AUTHORIZED_USERS];
	User _currently_logged_in[MAX_AUTHORIZED_USERS];
public:
	AlarmPanel(int = 0, std::string = "AlarmPanel");
	bool is_authenticate_user(User user);
	bool is_user_added(User* user);
	virtual void Device::introduce();
	virtual int Device::Id();
	virtual std::string Device::Name();
};

