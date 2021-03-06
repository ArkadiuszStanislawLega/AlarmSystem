#include "AlarmPanel.h"
#include <string>

using std::to_string;

AlarmPanel::AlarmPanel(int id, std::string name)
{
	 this->_id = id;
	 this->_name = name;
	 this->_port = Port(this, 0, "Port - Alarm Panel " + to_string(this->_id));
}


int AlarmPanel::GetUsersCounter()
{
	return this->_usersCounter;
}

bool AlarmPanel::IsLogin(User user)
{
	if (IsUserAuthenticated(&user))
	{
		this->_loggedUsers[_loggedUsersCounter] = user;
		this->_loggedUsersCounter++;
		return true;
	}

	return false;
}

User* AlarmPanel::GetUsers()
{
	return this->_users;
}

Port* AlarmPanel::GetPort()
{
	return &this->_port;
}

bool AlarmPanel::IsOn()
{
	return this->_isOn;
}

User* AlarmPanel::GetLoggedUsers()
{
	return  this->_loggedUsers;
}

int AlarmPanel::GetLoggedUsersCounter()
{
	return  this->_loggedUsersCounter;
}

bool AlarmPanel::IsUserAdded(User user)
{
	if (!IsUserAuthenticated(&user)) {
		this->_users[this->_usersCounter] = user;
		this->_usersCounter++;
		return true;
	}

	return false;
}

bool AlarmPanel::IsUserAuthenticated(User* user)
{
	for (size_t i = 0; i < (size_t)this->_usersCounter; i++)
	{
		if (user->GetId() == this->_users[i].GetId())
			return true;
	}

	return false;
}

bool AlarmPanel::IsUserRemoved(User* user)
{
	//TODO: Make authentication of user whom user this function.
	IsLogout(user);
	for (size_t i = 0; i < (size_t)this->_usersCounter; i++)
	{
		if (this->_users[i].GetId() == user->GetId())
		{
			 this->_usersCounter--;
			 this->_users[i] = this->_users[this->_usersCounter];
			 this->_users[this->_usersCounter] = 0;
			return true;
		}
	}
	return false;
}

bool AlarmPanel::IsUserLoggedIn(User* user)
{
	for (size_t i = 0; i < (size_t)this->_loggedUsersCounter; i++)
	{
		if (this->_loggedUsers[i].GetId() == user->GetId())
			return true;
	}

	return false;
}

bool AlarmPanel::IsLogout(User* user)
{
	for (size_t i = 0; i < (size_t)this->_loggedUsersCounter; i++)
	{
		if (this->_loggedUsers[i].GetId() == user->GetId())
		{
			 this->_loggedUsersCounter--;
			 this->_loggedUsers[i] = this->_loggedUsers[this->_loggedUsersCounter];
			 this->_loggedUsers[this->_loggedUsersCounter] = 0;
			return true;
		}
	}

	return false;
}
