#pragma once
#include "Device.h"
#include "User.h"
#include <iostream>

class AlarmPanel : public Device
{
private:
	const static int MAX_AUTHORIZED_USERS = 10;

	User _users[MAX_AUTHORIZED_USERS];
	User _loggedUsers[MAX_AUTHORIZED_USERS];

	int _usersCounter{ 0 };
	int _loggedUsersCounter{ 0 };

public:
	AlarmPanel(int = 0, std::string = "AlarmPanel");

	int UsersCounter();
	int LoggedUsersCounter();

	bool IsUserAuthenticated(User* user);
	bool IsUserAdded(User user);
	bool IsUserRemoved(User* user);
	bool IsUserLoggedIn(User* user);
	bool IsLogin(User user);
	bool IsLogout(User* user);

	User* GetUsers();
	User* GetLoggedUsers();

	virtual int GetId();

	virtual std::string GetLabel();
	virtual std::string GetName();
};

