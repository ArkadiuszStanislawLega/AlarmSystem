#include "MainConsole.h"

MainConsole::MainConsole()
{
    this->_alarmPanelCounter = { 0 };

    for (size_t i = 0; i < MAX_NUMBER_OF_PORTS; i++)
    {
        this->_ports[i] = Port(this, Port::GetDeviceCounter(), "Main Console - Port - " + to_string(i+1));
    }
    
}

 Port* MainConsole::GetPorts()
 {
     return this->_ports;
 }

 void MainConsole::Create(int id, std::string name)
 {
     this->_alarmPanelControllers[this->_alarmPanelCounter] = AlarmPanelController(id, name);
     this->_alarmPanelCounter++;
 }

 void MainConsole::Connect()
 {
     this->_alarmPanelControllers[0].ConnectPort(&this->_ports[0]);
     this->_ports[0].Connect(this->_alarmPanelControllers[0].GetModel().GetPort());
 }

 AlarmPanelController* MainConsole::GetControllers()
 {
     return this->_alarmPanelControllers;
 }