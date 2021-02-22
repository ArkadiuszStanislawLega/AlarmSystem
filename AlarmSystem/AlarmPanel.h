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
	int _users_counter_in_db{ 0 };
	int _users_logged_in{ 0 };

	void sort_users();

public:
	AlarmPanel(int = 0, std::string = "AlarmPanel");
	int users_logged_in();
	int users_couter_in_db();

	bool is_authenticate_user(User* user);
	bool is_user_added(User user);
	bool is_user_removed(User* user);
	bool is_user_currently_logged_in(User* user);
	bool login(User user);
	bool logout(User* user);

	User* get_logged_in_users();
	User* get_users();

	virtual std::string Device::label();
	virtual int Device::Id();
	virtual std::string Device::Name();
};

