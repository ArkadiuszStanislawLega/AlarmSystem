#pragma once
#ifndef MAIN_CONSOLE_VIEW_H
#define MAIN_CONSOLE_VIEW_H
#include <iostream>
#include "Port.h"
#include "View.h"

class MainConsoleView : View
{

public:
	MainConsoleView();
	std::string Label();
	void PrintWelcome();
	void PrintHelp();
	void PrintPortStatus(Port*, int);
	void PrintConnectPort(Port*, Port*);
};
#endif

