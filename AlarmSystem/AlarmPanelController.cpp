#include "AlarmPanelController.h"

AlarmPanelController::AlarmPanelController(int id, std::string name)
{
	this->_model = AlarmPanel(id, name);
	this->_view = AlarmPanelView(&_model, id, name);

	std::cout << "AlarmPanelController - model: " << &this->_model << std::endl;
	std::cout << "AlarmPanelController - view - model: " << this->_view.GetModel() << std::endl;
}

AlarmPanel AlarmPanelController::GetModel()
{
	return this->_model;
}

AlarmPanelView AlarmPanelController::GetView()
{
	return this->_view;
}

void AlarmPanelController::GetInput()
{
	std::cin >> this->_input_password >> this->_input_pin;
}

void AlarmPanelController::GetUsers()
{
	this->_view.PrintUsers();
}


void AlarmPanelController::AddUser(User user)
{
	if (this->_model.IsUserAdded(user))
		this->_view.PrintAddedUser(&user);
	else
		this->_view.PrintFailAddUser(&user);
}

void AlarmPanelController::GetAllLoginUsers()
{
	this->_view.PrintLoggedInUsers();
}

void AlarmPanelController::Login()
{
	this->_view.PrintLogin();
	this->_view.PrintLoggedIn(User(123,32123, "Mortadela", "Tarabaniaz"));
}

void AlarmPanelController::Logout(User* user)
{
	if (this->_model.IsLogout(user))
		this->_view.PrintLoggedOut(user);
}

void AlarmPanelController::RemoveUser(User* user)
{
	if (this->_model.IsUserRemoved(user))
		this->_view.PrintRemoveUser(user);
}

void AlarmPanelController::TempLogin(User user)
{
	if (this->_model.IsLogin(user))
		this->_view.PrintLoggedIn(user);
	else
		this->_view.PrintFailToLogin();
}

void AlarmPanelController::ConnectPort(Port* port)
{
	std::cout << "AlarmPanelController - ConnectPort - model: " << &this->_model << std::endl;
	std::cout << "AlarmPanelController - ConnectPort - view - model: " << this->_view.GetModel() << std::endl;

	this->_model.GetPort()->Connect(port);
	this->_view.PrintConnectPort(port);
}