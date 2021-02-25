#include "MainConsole.h"

MainConsole::MainConsole()
{
    this->_alarmPanelCounter = { 0 };
}

int MainConsole::GetId()
{
    return this->_id;
}

std::string MainConsole::GetName()
{
    return this->_name;
}

std::string MainConsole::GetLabel()
{
    return this->_id + " " + this->_name; 
}

 Port* MainConsole::GetPorts()
 {
     return this->_ports;
 }

// void MainConsole::Create(int id, std::string name)
// {
//     this->_alarmPanelControllers[this->_alarmPanelCounter] = AlarmPanelController(id, name);
//     this->_alarmPanelCounter++;
// }

// void MainConsole::Connect()
// {
//     this->_alarmPanelControllers[0].ConnectPort(&this->_ports[0]);
// }