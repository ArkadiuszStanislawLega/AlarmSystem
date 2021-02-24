#pragma once
#include <iostream>

class Port;
class MainConsoleView
{

public:
	void PrintWelcome();
	void PrintHelp();
	void PrintPortStatus(Port* ports);
};

