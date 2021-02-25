#include "AlarmPanelView.h"


AlarmPanelView::AlarmPanelView(int id, std::string name)
{
	this->_id = id;
	this->_name = name;

}
AlarmPanelView::AlarmPanelView(AlarmPanel* model, int id, std::string name )
{	
	this->_id = id;
	this->_name = name;
	this->_model = model;
}


void AlarmPanelView::printStress()
{
	for (size_t i = 0; i < 80; i++)
	{
		std::cout << "_";
	}

	std::cout << std::endl;
}

std::string AlarmPanelView::printTab()
{
	std::string tab;
	for (size_t i = 0; i < this->_name.length() + 2; i++)
	{
		tab += " ";
	}
	return tab;
}

int* AlarmPanelView::GetId()
{
	return &this->_id;
}

std::string* AlarmPanelView::GetName()
{
	return &this->_name;
}

std::string AlarmPanelView::Label()
{
	return this->_name  + "> ";
}

void AlarmPanelView::SetController(AlarmPanelController* controller)
{
	this->_controller = controller;
}

void AlarmPanelView::PrintAddedUser(User* user)
{
	std::cout << Label() << "Dodano uzytkownika " << user->Introduce() << "  do bazy danych." << std::endl;
}

void AlarmPanelView::PrintAuthentication(bool authenticated)
{
	if (authenticated)
		std::cout << "Zalogowany" << std::endl;
	else
		std::cout << "Nie zalogowany" << std::endl;
}

void AlarmPanelView::PrintFailAddUser(User* user)
{
	std::cout << Label() << "Blad podczas dodawa uzytkownika " << user->Introduce() << std::endl;
}

void AlarmPanelView::PrintFailToLogin()
{
	std::cout << Label() << "Bledne dane logowania." << std::endl;
}

void AlarmPanelView::PrintLoggedIn(User user)
{
	std::cout << "Witaj " << user.GetName() << std::endl;
}

void AlarmPanelView::PrintLoggedInUsers()
{
	std::cout << Label() << "Aktualnie zalogowani uzytkownicy(" << this->_model->GetLoggedUsersCounter() << "): "<< std::endl;

	for (size_t i = 0; i < (size_t)this->_model->GetLoggedUsersCounter(); i++)
	{
		std::cout << printTab() << this->_model->GetLoggedUsers()[i].GetId() << ". " << this->_model->GetLoggedUsers()[i].Introduce() << std::endl;
	}
}

void AlarmPanelView::PrintLoggedOut(User* user)
{
	std::cout << "Wylogowano " << user->Introduce() << std::endl;
}

void AlarmPanelView::PrintLogin()
{
	std::cout << "Podaj numer ID, a nastepnie pin." << std::endl;
}

void AlarmPanelView::PrintRemoveUser(User* user)
{
	std::cout << Label() << "Usunieto uzytkownika " << user->Introduce() << "." << std::endl;
}

void AlarmPanelView::PrintUsers()
{
	std::cout << Label() << "Uzytkownicy w bazie danych(" << this->_model->GetUsersCounter() << "):" << std::endl;
	User* pointer = this->_model->GetUsers();
	for (size_t i = 0; i < (size_t)this->_model->GetUsersCounter(); i++)
	{
		std::cout << printTab() << pointer->GetId() << ". " << pointer->Introduce() << std::endl;
		pointer++;
	}
}
 
void AlarmPanelView::PrintConnectPort(Port* port)
{
	std::cout << Label() << "Polaczono port " << this->_model->GetPort()->GetLabel() << "->" << port->GetLabel() << std::endl;
}



