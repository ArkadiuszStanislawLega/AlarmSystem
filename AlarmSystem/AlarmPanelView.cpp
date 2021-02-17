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
	std::cout << _id << " " << _name;
}

void AlarmPanelView::set_controller(AlarmPanelController* controller)
{
	_controller = controller;
}