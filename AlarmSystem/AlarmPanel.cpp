#include "AlarmPanel.h"


AlarmPanel::AlarmPanel(int id, std::string name)
{
	_id = id;
	_name = name;
}

User* AlarmPanel::get_logged_in_users()
{
	return _currently_logged_in;
}


int* AlarmPanel::Id()
{
	return &_id;
}

std::string* AlarmPanel::Name()
{
	return &_name;
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

bool AlarmPanel::is_user_added(User user)
{
	std::cout << "Proba dodania uzytkownika " << user.introduce() << std::endl;
	std::cout << "*************************" << std::endl;

	if (!is_authenticate_user(user)) {
		_users_database[_user_counter] = user;
		_user_counter++;
		return true;
	}

	return false;

}
