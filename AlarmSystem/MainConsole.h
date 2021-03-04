#pragma once
#ifndef MAIN_CONSOLE_H
#define MAIN_CONSOLE_H
#include <iostream>
#include "AlarmPanel.h"

class MainConsole : public Device
{
public:
    static const int MAX_NUMBER_OF_PORTS {10};
    static const int MAX_NUMBER_OF_DEVICES {10};

    MainConsole();

    Port* GetPorts();
    bool ConnectPort(Port*);
    bool DisconnectPort(int);

    bool CreateAlarmPanel(AlarmPanel);
    AlarmPanel* GetAlarmPanels();
    bool RemoveAlarmPanel(int);
    int GetAlarmPanelCounter();
    

private:
    int _alarmPanelCounter;
    Port _ports[MAX_NUMBER_OF_PORTS];
    AlarmPanel _alarmPanels[MAX_NUMBER_OF_DEVICES];
};
#endif