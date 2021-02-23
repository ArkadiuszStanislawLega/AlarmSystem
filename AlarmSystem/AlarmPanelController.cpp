#include "AlarmPanelController.h"

AlarmPanelController::AlarmPanelController(AlarmPanel* model, AlarmPanelView* view)
{
	_model = model;
	_view = view;
}

void AlarmPanelController::get_input()
{
	std::cin >> _input_password >> _input_pin;
}

void AlarmPanelController::get_users()
{
	_view->print_all_users_from_db();
}

void AlarmPanelController::set_model(AlarmPanel* model)
{
	_model = model;
}

void AlarmPanelController::set_view(AlarmPanelView* view)
{
	_view = view;
}

void AlarmPanelController::login()
{
	_view->print_login();
	_view->print_logged_in(User(123,32123, "Mortadela", "Tarabaniaz"));
}

void AlarmPanelController::get_all_login_users()
{
	_view->print_all_logged_in();
}

void AlarmPanelController::add_user(User user)
{
	if (_model->is_user_added(user))
		_view->print_added_user_to_db(&user);
	else
		_view->print_fail_to_add_user(&user);
}

void AlarmPanelController::logout(User* user)
{
	if (_model->logout(user))
		_view->print_logged_out(user);
}

void AlarmPanelController::remove_user(User* user)
{
	if (_model->is_user_removed(user))
		_view->print_remove_user_from_db(user);
}

void AlarmPanelController::temp_login(User user)
{
	if (_model->login(user))
		_view->print_logged_in(user);
	else
		_view->print_fail_to_login();
}