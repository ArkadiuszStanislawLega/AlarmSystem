#include "AlarmPanelView.h"

int View::Id()
{
	return _id;
}

std::string View::Name()
{
	return _name;
}

AlarmPanelView::AlarmPanelView(int id, std::string name, AlarmPanelController* alarmPanelController)
{
	_id = id;
	_name = name;
	_controller = alarmPanelController;
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
	std::cout << _id << " " << _name;
}