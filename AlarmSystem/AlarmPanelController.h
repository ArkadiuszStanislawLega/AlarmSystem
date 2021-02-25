#pragma once
#include "AlarmPanel.h"
#include "AlarmPanelView.h"

class AlarmPanelController
{
private:
	AlarmPanel _model;
	AlarmPanelView _view;
	
	int _input_pin{ 0 };
	int _input_password{ 0 };
	 
public:
	AlarmPanelController(int=0, std::string = "");

	void GetInput();
	void GetUsers();

	void AddUser(User user);
	void GetAllLoginUsers();
	void Login();
	void Logout(User* user);
	void RemoveUser(User* user);
	void TempLogin(User user);
	void ConnectPort(Port* port);
};

