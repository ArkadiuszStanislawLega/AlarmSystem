#pragma once
#ifndef MAIN_CONSOLE_CONTROLLER_H
#define MAIN_CONSOLE_CONTROLLER_H
#include <iostream>
#include "MainConsoleView.h"
#include "MainConsole.h"

class MainConsoleController
{
private:
	std::string _currentCommand;

	Commands _command;

	MainConsoleView _view;
	MainConsole _model;

	bool _isWorking;
	

public:
	MainConsoleController();
	virtual ~MainConsoleController();
	void CheckInput();
	void MainLoop();
	void ConvertInput();
	void MakeCommand();
};
#endif