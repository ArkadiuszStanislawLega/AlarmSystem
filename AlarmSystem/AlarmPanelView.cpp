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
void AlarmPanelView::print_stress()
{
	for (size_t i = 0; i < 80; i++)
	{
		std::cout << "_";
	}

	std::cout << std::endl;
}

void AlarmPanelView::print_authentication(bool authenticated)
{
	if (authenticated)
		std::cout << "Zalogowany" << std::endl;
	else
		std::cout << "Nie zalogowany" << std::endl;
}

std::string AlarmPanelView::label()
{
	return _name  + "> ";
}

void AlarmPanelView::print_login()
{
	std::cout << "Podaj numer ID, a nastepnie pin." << std::endl;
}

void AlarmPanelView::print_logged_in(User user)
{
	std::cout << "Witaj " << user.name() << std::endl;
}

void AlarmPanelView::print_logged_out(User* user)
{
	std::cout << "Wylogowano " << user->introduce() << std::endl;
}

void AlarmPanelView::set_controller(AlarmPanelController* controller)
{
	_controller = controller;
}

void AlarmPanelView::print_all_logged_in()
{
	std::cout << label() << "Aktualnie zalogowani uzytkownicy(" << _model->users_logged_in() << "): "<< std::endl;

	for (size_t i = 0; i < (size_t)_model->users_logged_in(); i++)
	{
		std::cout <<print_tab() << _model->get_logged_in_users()[i].id() << ". " << _model->get_logged_in_users()[i].introduce() << std::endl;
	}
}

void AlarmPanelView::print_added_user_to_db(User* user)
{
	std::cout << label() << "Dodano uzytkownika " << user->introduce() << "  do bazy danych." << std::endl;
}

void AlarmPanelView::print_remove_user_from_db(User* user)
{
	std::cout << label() << "Usunieto uzytkownika " << user->introduce() << "." << std::endl;
}


void AlarmPanelView::print_all_users_from_db()
{
	std::cout << label() << "Uzytkownicy w bazie danych(" << _model->users_couter_in_db() << "):" << std::endl;
	User* pointer = _model->get_users();
	for (size_t i = 0; i < _model->users_couter_in_db(); i++)
	{
		std::cout << print_tab() << pointer->id() << ". " << pointer->introduce() << std::endl;
		pointer++;
	}
}

std::string AlarmPanelView::print_tab()
{
	std::string tab;
	for (size_t i = 0; i < _name.length()+2; i++)
	{
		tab += " ";
	}
	return tab;
}