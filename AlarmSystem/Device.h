#pragma once
#include <string>
#include <iostream>

using std::to_string;

class Device
{
protected:
	int _id;
	std::string _name;

public:
	Device();
	int GetId();
	std::string GetName();
	std::string GetLabel();

	void SetId(int);
	void SetName(std::string);
};

