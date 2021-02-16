#pragma once
#include <iostream>

class User
{
private:
	int _id{ 0 };
	int _pin{ 0 };
	std::string _name;
	std::string _surname;


public:
	User(int= 0, int = 0, std::string = "Name", std::string = "Surname");
	std::string introduce();
	int Id();
	int Pin();
	std::string Name();
	std::string Surname();
};

