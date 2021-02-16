#include "AlarmPanel.h"
#include "Device.h"
#include <iostream>

class AlarmPanel : public Device
{
public:

	AlarmPanel(std::string name, int id)
	{
		_id = id;
		_name = name;
	}

	virtual void introduce()
	{
		std::cout << _id << _name;
	}
};
