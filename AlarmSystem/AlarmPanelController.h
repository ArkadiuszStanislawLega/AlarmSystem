#pragma once
#include "MainConsoleController.h"

class MainConsoleController;
class AlarmPanelController
{
private:
	MainConsoleController* _parent;

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
	AlarmPanelController();
	AlarmPanelController(MainConsoleController*);

	void GetUsers(int);

	void AddUser(User user);
	void GetAllLoginUsers();
	void Login();
	void Logout(User* user);
	void RemoveUser(User* user);
	void TempLogin(User user);
	void ConnectPort(Port* port);
};

