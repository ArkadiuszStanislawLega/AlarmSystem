#pragma once
#ifndef MAIN_CONSOLE_CONTROLLER_H
#define MAIN_CONSOLE_CONTROLLER_H
#include <iostream>
#include "MainConsoleView.h"
#include "MainConsole.h"
#include "AlarmPanelController.h"
#include "Commands.h"

class MainConsoleController
{
private:
	std::string _currentCommand;

	Commands _command;

	MainConsoleView* _view;
	MainConsole* _model; 

	bool _isWorking;
	void CheckInput();
	void ConvertInput();
	void MakeCommand();
	void CreateNewAlarmPanel();
	void RemoveAlarmPanel();

	Port* FindPort(int);

public:
	MainConsoleController();
	void MainLoop();

	void PortsStatus();
	void Connect();
	void Create();
	void Enter();

	void GetAlarmPanels();

	AlarmPanelController GetAlarmPanelController();
	MainConsoleView* GetView();
	MainConsole* GetModel();

	void SetModel(MainConsole*);
	void SetView(MainConsoleView*);
};
#endif