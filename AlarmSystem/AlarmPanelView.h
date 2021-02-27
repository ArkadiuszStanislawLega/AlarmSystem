#pragma once
#include "View.h"
#include "User.h"
#include "AlarmPanel.h"

class AlarmPanelController;
class AlarmPanelView : public View
{
private:
	AlarmPanelController* _controller;
	void printStress();
	std::string printTab();

public:
	AlarmPanelView(int = 0, std::string = "Alarm Panel View");

	std::string Label();

	void SetController(AlarmPanelController* controller);

	void PrintAddedUser(User* user);
	void PrintAuthentication(bool);
	void PrintFailAddUser(User* user);
	void PrintFailToLogin();
	void PrintLoggedIn(User user);
	void PrintLoggedInUsers(User*, int);
	void PrintLoggedOut(User* user); 
	void PrintLogin();
	void PrintRemoveUser(User* user);
	void PrintUsers(User*, int);
	void PrintConnectPort(Port* port, AlarmPanel*);
};

