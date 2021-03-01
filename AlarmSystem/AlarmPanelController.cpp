#include "AlarmPanelController.h"

AlarmPanelController::AlarmPanelController(int id, std::string name)
{
	this->_model = AlarmPanel(id, name);
	this->_view = AlarmPanelView(id, name);
}

void AlarmPanelController::MainLoop()
{
	while (this->_isConnected)
	{
		GetInput();
		ConvertInput();
		MakeCommand();
	}
}

void AlarmPanelController::ConvertInput()
{

}

void AlarmPanelController::MakeCommand()
{

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
	std::cin >> this->_input;
}

void AlarmPanelController::GetUsers()
{
	this->_view.PrintUsers(this->_model.GetUsers(), this->_model.GetUsersCounter());
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
	this->_view.PrintLoggedInUsers(this->_model.GetLoggedUsers(), this->_model.GetLoggedUsersCounter());
}

bool AlarmPanelController::GetUserName()
{
	std::cin >> this->_input_username;
	//TODO: Zrobic walidacje i porownanie z baza danych
	return true;
}

bool AlarmPanelController::GetUserPassword()
{
	std::cin >> this->_input_password;
	//TODO: Zrobic walidacje i porownanie z baza danych
	return true;
}

void AlarmPanelController::Login()
{
	this->_view.PrintLogin();
	if (GetUserName() && GetUserPassword())
	{
		User tempLogIn = User(123, 32123, "Mortadela", "Tarabaniaz");
		if (this->_model.IsLogin(tempLogIn))
		{
			this->_view.PrintLoggedIn(tempLogIn);
			this->MainLoop();
		}
		else
			this->_view.PrintFailToLogin();
	}
	else
		this->_view.PrintFailToLogin();

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
	this->_model.GetPort()->Connect(port);
	this->_view.PrintConnectPort(port, &this->_model);
}