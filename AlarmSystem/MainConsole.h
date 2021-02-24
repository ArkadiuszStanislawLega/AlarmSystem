#pragma once
#include <iostream>
#include "Commands.h"
#include "AlarmPanel.h"
#include "AlarmPanelView.h"
#include "AlarmPanelController.h"

class MainConsole : public Device
{
private:
    static const int MAX_NUMBER_OF_PORTS {10};
    static const int MAX_NUMBER_OF_DEVICES{ 10 };

    int _alarmPanelCounter;

    Port _ports[MAX_NUMBER_OF_PORTS];
    AlarmPanelController _alarmPanelControllers[MAX_NUMBER_OF_DEVICES];

public:
    MainConsole();
    virtual int GetId();
    virtual std::string GetName();
    virtual std::string GetLabel();
    // Port* GetPorts();
    // void Create(int, std::string);
    // void Connect();
};