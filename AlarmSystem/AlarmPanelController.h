#pragma once
#include "AlarmPanel.h"
#include "AlarmPanelView.h"

class AlarmPanelController
{
private:
	AlarmPanel _model;
	AlarmPanelView _view;

	bool _isConnected;

	std::string _input;
	
	int _input_username{ 0 };
	int _input_password{ 0 };

	void MainLoop();
	void GetInput();
	void ConvertInput();
	void MakeCommand();
	bool GetUserName();
	bool GetUserPassword();
	 
public:
	AlarmPanelController(int=0, std::string = "");

	void GetUsers();

	AlarmPanel GetModel();
	AlarmPanelView GetView();

	void AddUser(User user);
	void GetAllLoginUsers();
	void Login();
	void Logout(User* user);
	void RemoveUser(User* user);
	void TempLogin(User user);
	void ConnectPort(Port* port);
};

