#pragma once
#include "View.h"
#include "User.h"

class AlarmPanelController;
class AlarmPanelView : public View
{
private:
	AlarmPanelController* _controller;

public:
	AlarmPanelView(int = 0, std::string = "Alarm Panel View" );

	virtual int View::Id();
	virtual std::string View::Name();

	virtual void View::print();

	void print_authentication(bool);
	void print_login();
	void print_logged_in(User user);
	void print_logged_out(User user); 
	void print_all_logged_in(User* users);
	void print_added_user_to_db(User* user);
	void set_controller(AlarmPanelController* controller);
};

