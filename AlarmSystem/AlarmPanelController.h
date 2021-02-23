#pragma once
#include "AlarmPanel.h"
#include "AlarmPanelView.h"

class AlarmPanelController
{
private:
	AlarmPanel* _model;
	AlarmPanelView* _view;
	
	int _input_pin{ 0 };
	int _input_password{ 0 };
	 
public:
	AlarmPanelController(AlarmPanel*, AlarmPanelView*);
	void get_input();
	void get_users();
	void set_model(AlarmPanel* model);
	void set_view(AlarmPanelView* view);
	void login();
	void logout(User* user);
	void remove_user(User* user);
	void get_all_login_users();
	void add_user(User user);
};

