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

	User u1(1, 1234, "Mietek", "Szczesniak");
	User u2(2, 4321, "Zenon", "Trombka");
	User u3(3, 5647, "Czesiek", "Pierdzibak");

	if (_model->is_user_added(&u1))
		_view->print_added_user_to_db(&u1);

	_model->is_authenticate_user(u1);
	_model->is_authenticate_user(u2);
	_model->is_authenticate_user(u3);
}
