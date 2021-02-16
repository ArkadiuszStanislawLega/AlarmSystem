#include "AlarmPanel2.h"
#include <iostream>

AlarmPanel2::AlarmPanel2(int id, std::string name)
{
	_id = id;
	_name = name;

}

void AlarmPanel2::introduce()
{
	std::cout << "Alarm panel" << _id << " " << _name << std::endl;
}
