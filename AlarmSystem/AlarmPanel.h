#pragma once
#include <iostream>
#include "Device.h"
#include "User.h"
#include "Port.h"

class AlarmPanel : public Device
{
private:
	const static int MAX_AUTHORIZED_USERS = 10;

	bool _isOn;

	int _usersCounter{ 0 };
	int _loggedUsersCounter{ 0 };

	User _users[MAX_AUTHORIZED_USERS];
	User _loggedUsers[MAX_AUTHORIZED_USERS];

	Port _port;
public:
	AlarmPanel(int = 0, std::string = "AlarmPanel");
	
	virtual int GetId();

	virtual std::string GetLabel();
	virtual std::string GetName();

	int GetUsersCounter();
	int GetLoggedUsersCounter();

	User* GetUsers();
	User* GetLoggedUsers();

	Port* GetPort();
	
	bool IsOn();

	bool IsUserAuthenticated(User* user);
	bool IsUserAdded(User user);
	bool IsUserRemoved(User* user);
	bool IsUserLoggedIn(User* user);
	bool IsLogin(User user);
	bool IsLogout(User* user);
	bool IsConnectPort();
};

