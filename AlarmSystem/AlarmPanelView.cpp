#include "AlarmPanelView.h"

int AlarmPanelView::Id()
{
	return _id;
}

std::string AlarmPanelView::Name()
{
	return _name;
}

AlarmPanelView::AlarmPanelView(int id, std::string name )
{
	_id = id;
	_name = name;
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
	std::cout << "Witaj " << user.Name() << std::endl;
}

void AlarmPanelView::print_logged_out(User user)
{
	std::cout << "Do widzenia " << user.Name() << std::endl;
}

void AlarmPanelView::set_controller(AlarmPanelController* controller)
{
	_controller = controller;
}

void AlarmPanelView::print_all_logged_in(User* users)
{
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << users->introduce() << std::endl;
		users++;
	}
}

void AlarmPanelView::print_added_user_to_db(User* user)
{
	std::cout << "Dodano uzytkownika " << user->Id() << " do bazy danych w ";
	print();
}