#pragma once
#include <iostream>

class View
{
protected:
	int _id{ 0 };
	std::string _name;

public:
	virtual int* GetId() = 0;
	virtual std::string* GetName() = 0;
	virtual std::string Label() = 0;
};

