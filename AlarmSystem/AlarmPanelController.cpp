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
	make_fake_db();

}

void AlarmPanelController::make_fake_db()
{
	User* users;
	users = new User[10];

	users[0] = User(1, 1234, "Mietek", "Szczesniak");
	users[1] = User(2, 4321, "Zenon", "Trombka");
	users[2] = User(3, 5647, "Czesiek", "Pierdzibak");

	std::cout << "Wielkosc tablicy: "<< sizeof(users) << std::endl;
	
	for (size_t i = 0; i < sizeof(users); i++)
	{
		if (_model->is_user_added(users))
			_view->print_added_user_to_db(users);

		_model->is_authenticate_user(users[i]);

		users++;
	}

}