#include "AlarmPanelController.h"

AlarmPanelController::AlarmPanelController(AlarmPanel* model, AlarmPanelView* view)
{
	this->_model = model;
	this->_view = view;
}

void AlarmPanelController::GetInput()
{
	std::cin >> this->_input_password >> this->_input_pin;
}

void AlarmPanelController::GetUsers()
{
	this->_view->PrintUsers();
}

void AlarmPanelController::SetModel(AlarmPanel* model)
{
	this->_model = model;
}

void AlarmPanelController::SetView(AlarmPanelView* view)
{
	this->_view = view;
}

void AlarmPanelController::Login()
{
	this->_view->PrintLogin();
	this->_view->PrintLoggedIn(User(123,32123, "Mortadela", "Tarabaniaz"));
}

void AlarmPanelController::GetAllLoginUsers()
{
	this->_view->PrintLoggedInUsers();
}

void AlarmPanelController::AddUser(User user)
{
	if (this->_model->IsUserAdded(user))
		this->_view->PrintAddedUser(&user);
	else
		this->_view->PrintFailAddUser(&user);
}

void AlarmPanelController::Logout(User* user)
{
	if (this->_model->IsLogout(user))
		this->_view->PrintLoggedOut(user);
}

void AlarmPanelController::RemoveUser(User* user)
{
	if (this->_model->IsUserRemoved(user))
		this->_view->PrintRemoveUser(user);
}

void AlarmPanelController::TempLogin(User user)
{
	if (this->_model->IsLogin(user))
		this->_view->PrintLoggedIn(user);
	else
		this->_view->PrintFailToLogin();
}