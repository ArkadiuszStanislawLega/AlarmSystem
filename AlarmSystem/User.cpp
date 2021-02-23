#include "User.h"

int User::GetId()
{
	return _id;
}

int User::GetPin()
{
	return _pin;
}

std::string User::GetName()
{
	return _name;
}

std::string User::GetSurname()
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

std::string User::Introduce()
{
	return _name + " " + _surname;
}


