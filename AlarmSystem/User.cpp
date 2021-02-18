#include "User.h"

int* User::Id()
{
	return &_id;
}

int* User::Pin()
{
	return &_pin;
}

std::string* User::Name()
{
	return &_name;
}

std::string* User::Surname()
{
	return &_surname;
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


