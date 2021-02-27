#include "MainConsole.h"

MainConsole::MainConsole()
{
    this->_alarmPanelCounter = { 0 };
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
     std::cout << "_alarmPanelControllers[0] - ConnectPort -  model: " << &this->_alarmPanelControllers[0].GetModel() << std::endl;
     std::cout << "_alarmPanelControllers[0] - ConnectPort - view - model: " << this->_alarmPanelControllers[0].GetView().GetModel() << std::endl;

     this->_alarmPanelControllers[0].ConnectPort(&this->_ports[0]);
 }