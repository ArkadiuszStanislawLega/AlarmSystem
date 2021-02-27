#pragma once
#ifndef VIEW_H
#define VIEW_H
#include <iostream>
#include <string>

using std::to_string;

class View
{
protected:
	int _id{ 0 };
	std::string _name;

public:
	int GetId();
	std::string GetName();
	std::string Label();
	void SetName(std::string);
	void SetId(int);
};
#endif

