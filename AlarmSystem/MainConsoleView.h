#pragma once
#ifndef MAIN_CONSOLE_VIEW_H
#define MAIN_CONSOLE_VIEW_H
#include <iostream>
#include "Port.h"

class MainConsoleView
{

public:
	void PrintWelcome();
	void PrintHelp();
	void PrintPortStatus(Port*, int);
};
#endif

