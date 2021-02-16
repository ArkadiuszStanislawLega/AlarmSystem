#include "AlarmPanel.h"
#include "Device.h"
#include <iostream>


AlarmPanel::AlarmPanel(int id, std::string name)
{
	_id = id;
	_name = name;
}

void AlarmPanel::introduce()
{
	std::cout << _id << " " << _name;
}
