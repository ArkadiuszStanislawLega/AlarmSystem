#include "View.h"

int View::GetId()
{
	return this->_id;
}

std::string View::GetName()
{
	return this->_name;
}

void View::SetId(int id)
{
	this->_id = id;
}

void View::SetName(std::string name)
{
	this->_name = name;
}

std::string View::Label()
{
	return to_string(this->_id) + " " + this->_name;
}