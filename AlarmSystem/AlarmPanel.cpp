#include "AlarmPanel.h"
#include <string>

using std::to_string;

AlarmPanel::AlarmPanel(int id, std::string name)
{
	_id = id;
	_name = name;
}

int AlarmPanel::users_couter_in_db()
{
	return _users_counter_in_db;
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

User* AlarmPanel::get_users()
{
	return _users_database;
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

bool AlarmPanel::is_user_currently_logged_in(User* user)
{
	for (size_t i = 0; i < _users_logged_in; i++)
	{
		if (_currently_logged_in[i].id() == user->id())
			return true;
	}

	return false;
}

bool AlarmPanel::logout(User* user)
{
	for (size_t i = 0; i < _users_logged_in; i++)
	{
		if (_currently_logged_in[i].id() == user->id())
		{
			_currently_logged_in[i] = NULL;
			_users_logged_in--;
			return true;
		}
	}

	return false;
}

bool AlarmPanel::is_user_removed(User* user)
{
	if (is_authenticate_user(user))
	{
		if (is_user_currently_logged_in(user))
		{
			logout(user);
			for (size_t i = 0; i < _users_counter_in_db; i++)
			{
				_users_database[i] = NULL;
				_users_counter_in_db--;
				return true;
			}
		}
	}
	return false;
}