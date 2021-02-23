#pragma once
#include <iostream>

class Device
{
protected:
	int _id{ 0 };
	std::string _name = "Device";

public:
	virtual int GetId() = 0;
	virtual std::string GetName() = 0;
	virtual std::string GetLabel() = 0;
};

