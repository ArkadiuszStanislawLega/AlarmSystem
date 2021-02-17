#include "AlarmPanel.h"


AlarmPanel::AlarmPanel(int id, std::string name)
{
	_id = id;
	_name = name;
}


int AlarmPanel::Id()
{
	return _id;
}

std::string AlarmPanel::Name()
{
	return _name;
}

void AlarmPanel::introduce()
{
	std::cout << _id << " " << _name << std::endl;
}

bool AlarmPanel::is_authenticate_user(User user)
{
	for (size_t i = 0; i < sizeof(_users_database); i++)
	{
		if (user.Id() == _users_database[i].Id())
			return true;
	}

	return false;
}

bool AlarmPanel::is_user_added(User* user)
{
	for (size_t i = 0; i < MAX_AUTHORIZED_USERS; i++)
	{
		if (_users_database[i].Id() == user->Id())
		{
			return false;
		}
	}


	for (size_t i = 0; i < MAX_AUTHORIZED_USERS; i++)
	{
		if (_users_database[i].Id() == 0)
		{
			_users_database[i] = User(user->Id(), user->Pin(), user->Name(), user->Surname());
			return true;
		}
	}

	return false;

}
