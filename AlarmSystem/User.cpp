#include "User.h"

int User::GetId()
{
	return this->_id;
}

int User::GetPin()
{
	return this->_pin;
}

std::string User::GetName()
{
	return this->_name;
}

std::string User::GetSurname()
{
	return this->_surname;
}

User::User(int id, int pin, std::string name, std:: string surname)
{
	this->_id = id;
	this->_pin = pin;
	this->_name = name;
	this->_surname = surname;
}

std::string User::Introduce()
{
	return this->_name + " " + this->_surname;
}


