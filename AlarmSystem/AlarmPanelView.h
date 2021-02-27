#pragma once
#include "View.h"
#include "User.h"
#include "AlarmPanel.h"

class AlarmPanelController;
class AlarmPanelView : public View
{
private:
	AlarmPanelController* _controller;
	AlarmPanel* _model;
	void printStress();
	std::string printTab();

public:
	AlarmPanelView(int = 0, std::string = "Alarm Panel View");
	AlarmPanelView(AlarmPanel*, int = 0, std::string = "Alarm Panel View");

	std::string Label();
	AlarmPanel* GetModel();

	void SetController(AlarmPanelController* controller);

	void PrintAddedUser(User* user);
	void PrintAuthentication(bool);
	void PrintFailAddUser(User* user);
	void PrintFailToLogin();
	void PrintLoggedIn(User user);
	void PrintLoggedInUsers();
	void PrintLoggedOut(User* user); 
	void PrintLogin();
	void PrintRemoveUser(User* user);
	void PrintUsers();
	void PrintConnectPort(Port* port);
};

