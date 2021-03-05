#include "MainConsole.h"

MainConsole::MainConsole()
{
    this->_alarmPanelCounter = { 0 };

    for (size_t i = 0; i < MAX_NUMBER_OF_PORTS; i++)
    {
        this->_ports[i] = Port(this, Port::GetDeviceCounter(), "Main Console - Port - " + to_string(i+1));
    }
    
}

int MainConsole::GetAlarmPanelCounter()
{
    return this->_alarmPanelCounter;
}

 Port* MainConsole::GetPorts()
 {
     return this->_ports;
 }

 bool MainConsole::ConnectPort(Port* port)
 {
     for (size_t i = 0; i < MAX_NUMBER_OF_PORTS; i++)
     {
         if (!this->_ports[i].IsConnected())
         {
             this->_ports[i].Connect(port);
             port->Connect(&this->_ports[i]);
             return true;
         }
     }

     return false;
 }

 bool MainConsole::DisconnectPort(int portNumber)
 {
     for (size_t i = 0; i < MAX_NUMBER_OF_PORTS; i++)
     {
         if (this->_ports[i].GetId() == portNumber)
         {
             if (this->_ports[i].IsConnected())
             {
                 this->_ports[i].Disconnect();
                 return true;
             }
         }
     }
     return false;
 }

 bool MainConsole::CreateAlarmPanel(AlarmPanel alarmPanel)
 {
     if (alarmPanel.GetId() != 0)
     {
         for (size_t i = 0; i < MAX_NUMBER_OF_DEVICES; i++)
         {
             if (this->_alarmPanels[i].GetId() == 0)
             {
                 this->_alarmPanels[i] = alarmPanel;
                 this->_alarmPanelCounter++;
                 return true;
             }
         }
     }

     return false;
 }

 AlarmPanel* MainConsole::GetAlarmPanels()
 {
     return this->_alarmPanels;
 }

 bool MainConsole::RemoveAlarmPanel(int id)
 {
     for (size_t i = 0; i < MAX_NUMBER_OF_DEVICES; i++)
     {
         if (this->_alarmPanels[i].GetId() == id)
         {
             this->_alarmPanels[i] = 0;
             this->_alarmPanelCounter--;
             return true;
         }
     }

     return false;
 }

 Port* MainConsole::FindPort(int id)
 {
     Port* port = FindPortMainConsole(id);
     if (port != 0 && port->GetId() == id)
         return port;

     else
     {
         auto alrmPanel = FindAlarmPanel(id);
         if (alrmPanel != 0)
         {
             port = alrmPanel->GetPort();
             if (port != 0)
                 return port;
         }
     }

     return 0;
 }

 Port* MainConsole::FindPortMainConsole(int id)
 {
     for (size_t i = 0; i < MAX_NUMBER_OF_PORTS; i++)
     {
         if (this->_ports[i].GetId() != false && this->_ports[i].GetId() == id)
             return &this->_ports[i];
     }

     return 0;
 }

 AlarmPanel* MainConsole::FindAlarmPanel(int id)
 {
     for (size_t i = 0; i < MAX_NUMBER_OF_DEVICES; i++)
     {
         if (this->_alarmPanels[i].GetId() == id)
             return &this->_alarmPanels[i];
     }
     return 0;

 }