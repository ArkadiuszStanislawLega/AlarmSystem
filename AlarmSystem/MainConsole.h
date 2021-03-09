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

    AlarmPanel* GetAlarmPanels();

    Port* GetPorts();

    int GetAlarmPanelCounter();

    bool ConnectPort(int, int);
    bool CreateAlarmPanel(AlarmPanel);
    bool DisconnectPort(int);
    bool RemoveAlarmPanel(int);

    Port* FindPort(int);
    

private:
    int _alarmPanelCounter;
    Port _ports[MAX_NUMBER_OF_PORTS];
    AlarmPanel _alarmPanels[MAX_NUMBER_OF_DEVICES];

    Port* FindPortMainConsole(int);
    AlarmPanel* FindAlarmPanel(int);
    bool IsIdUsed(int);

};
#endif