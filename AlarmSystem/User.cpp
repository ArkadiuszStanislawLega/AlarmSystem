#include "User.h"

int User::id()
{
	return _id;
}

int User::pin()
{
	return _pin;
}

std::string User::name()
{
	return _name;
}

std::string User::surname()
{
	return _surname;
}

User::User(int id, int pin, std::string name, std:: string surname)
{
	_id = id;
	_pin = pin;
	_name = name;
	_surname = surname;
}

std::string User::introduce()
{
	return _name + " " + _surname;
}


