#pragma once
#include <iostream>
#include "Port.h"

class MainConsoleView
{

public:
	void PrintWelcome();
	void PrintHelp();
	void PrintPortStatus(Port*);
};

