#pragma once
#include <iostream>

class Device
{
protected:
	int _id{ 0 };
	std::string _name = "Device";

public:
	virtual void introduce() = 0;
};

