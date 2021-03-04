#pragma once
#ifndef MAIN_CONSOLE_VIEW_H
#define MAIN_CONSOLE_VIEW_H
#include <iostream>
#include "View.h"
#include "AlarmPanelView.h"

class Port;
class MainConsoleView : View
{
private:

public:
	MainConsoleView();
	std::string Label();
	void PrintWelcome();
	void PrintHelp();
	void PrintPortStatus(Port*, int);
	void PrintConnectPort(Port*, Port*);
	void CreateNewAlarmPanel();
	void CreatedNewAlarmPanel();
	void CreatedNewAlarmPanelFailed();
	void PrintAlarmPanels(AlarmPanel*, int);
	void PrintGetIdOfAlarmPanel();
	void PrintRemovedAlarmPanelSuccessful();
	void PrintRemovedAlarmPanelFailed();

};
#endif

