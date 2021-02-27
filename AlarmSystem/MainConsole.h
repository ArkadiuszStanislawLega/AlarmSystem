#pragma once
#ifndef MAIN_CONSOLE_H
#define MAIN_CONSOLE_H
#include <iostream>
#include "Commands.h"
#include "AlarmPanel.h"
#include "AlarmPanelView.h"
#include "AlarmPanelController.h"

class MainConsole : public Device
{
public:
    static const int MAX_NUMBER_OF_PORTS {10};
    static const int MAX_NUMBER_OF_DEVICES {10};
    MainConsole();
    Port* GetPorts();
    void Create(int, std::string);
    void Connect();

    AlarmPanelController* GetControllers();

private:
    int _alarmPanelCounter;
    Port _ports[MAX_NUMBER_OF_PORTS];
    AlarmPanelController _alarmPanelControllers[MAX_NUMBER_OF_DEVICES];
};
#endif