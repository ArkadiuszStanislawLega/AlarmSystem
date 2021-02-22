#pragma once
#include <iostream>

class View
{
protected:
	int _id{ 0 };
	std::string _name;

public:
	virtual std::string label() = 0;
	virtual int* Id() = 0;
	virtual std::string* Name() = 0;
};

