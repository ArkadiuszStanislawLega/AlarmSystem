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
	void print_stress();
	std::string print_tab();

public:
	AlarmPanelView(AlarmPanel*, int = 0, std::string = "Alarm Panel View");

	virtual int* View::Id();
	virtual std::string* View::Name();

	virtual std::string View::label();

	void print_authentication(bool);
	void print_login();
	void print_logged_in(User user);
	void print_logged_out(User* user); 
	void print_all_logged_in();
	void print_added_user_to_db(User* user);
	void print_remove_user_from_db(User* user);
	void print_all_users_from_db();
	void set_controller(AlarmPanelController* controller);
};

