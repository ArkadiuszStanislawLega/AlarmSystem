#pragma once
#include <iostream>

class View
{
protected:
	int _id;
	std::string _name;

public:
	virtual void print() = 0;
	virtual int Id() = 0;
	virtual std::string Name() = 0;
};

