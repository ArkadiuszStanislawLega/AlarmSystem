#include "AlarmPanelView.h"

int* AlarmPanelView::Id()
{
	return &_id;
}

std::string* AlarmPanelView::Name()
{
	return &_name;
}

AlarmPanelView::AlarmPanelView(AlarmPanel* model, int id, std::string name )
{
	_id = id;
	_name = name;
	_model = model;
}

void AlarmPanelView::print_authentication(bool authenticated)
{
	if (authenticated)
		std::cout << "Zalogowany" << std::endl;
	else
		std::cout << "Nie zalogowany" << std::endl;
}

void AlarmPanelView::print()
{
	std::cout << _id << " " << _name << std::endl;
}

void AlarmPanelView::print_login()
{
	std::cout << "Podaj numer ID, a nastepnie pin." << std::endl;
}

void AlarmPanelView::print_logged_in(User user)
{
	std::cout << "Witaj " << user.name() << std::endl;
}

void AlarmPanelView::print_logged_out(User user)
{
	std::cout << "Do widzenia " << user.name() << std::endl;
}

void AlarmPanelView::set_controller(AlarmPanelController* controller)
{
	_controller = controller;
}

void AlarmPanelView::print_all_logged_in()
{
	std::cout << "Uzytkownikow zalogowanych w " + _model->label() << " aktualnie jest " << _model->users_logged_in() << std::endl;

	for (size_t i = 0; i < (size_t)_model->users_logged_in(); i++)
	{
		std::cout << _model->get_logged_in_users()[i].introduce() << std::endl;
	}
}

void AlarmPanelView::print_added_user_to_db(User* user)
{
	std::cout << "Dodano uzytkownika " << user->introduce() << " do bazy danych w ";
	print();
}