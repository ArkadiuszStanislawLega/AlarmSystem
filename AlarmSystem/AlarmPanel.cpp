#include "AlarmPanel.h"
#include <string>

using std::to_string;

AlarmPanel::AlarmPanel(int id, std::string name)
{
	_id = id;
	_name = name;
}

bool AlarmPanel::login(User user)
{
	if (is_authenticate_user(&user))
	{
		_currently_logged_in[_users_logged_in] = user;
		_users_logged_in++;
		return true;
	}

	return false;

}

User* AlarmPanel::get_logged_in_users()
{
	return _currently_logged_in;
}

int AlarmPanel::users_logged_in()
{
	return _users_logged_in;
}

int AlarmPanel::Id()
{
	return _id;
}

std::string AlarmPanel::Name()
{
	return _name;
}

std::string AlarmPanel::label()
{
	return "ID: " + to_string(_id) + ", " + _name;;
}

bool AlarmPanel::is_authenticate_user(User* user)
{
	for (size_t i = 0; i < _users_counter_in_db; i++)
	{
		if (user->id() == _users_database[i].id())
			return true;
	}

	return false;
}

bool AlarmPanel::is_user_added(User user)
{
	if (!is_authenticate_user(&user)) {
		_users_database[_users_counter_in_db] = user;
		_users_counter_in_db++;
		return true;
	}

	return false;
}
