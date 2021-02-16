#include "AlarmPanel.h"
#include "Device.h"


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
	std::cout << _id << " " << _name;
}

bool AlarmPanel::authenticate_user(User user)
{
	for (size_t i = 0; i < sizeof(_users_database); i++)
	{
		if (user.Id() == _users_database[i].Id())
			return true;
	}

	return false;
}
