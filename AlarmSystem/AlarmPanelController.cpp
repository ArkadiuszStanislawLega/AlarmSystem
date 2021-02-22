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
	make_fake_db();

}

void AlarmPanelController::get_all_login_users()
{
	_view->print_all_logged_in();
}

void AlarmPanelController::make_fake_db()
{
	User users[3];

	users[0] = User(1, 1234, "Mietek", "Szczesniak");
	users[1] = User(2, 4321, "Zenon", "Trombka");
	users[2] = User(3, 5647, "Czesiek", "Pierdzibak");

	rsize_t users_size = sizeof(users) / sizeof(users[0]);
	
	for (size_t i = 0; i < users_size; i++)
	{
		if (_model->is_user_added(users[i]))
			_view->print_added_user_to_db(&users[i]);

		_model->login(users[i]);
	}
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