#include <iostream>
#include "Commands.h"
#include "AlarmPanel.h"

class MainConsole : public Device
{
private:
    static const int MAX_NUMBER_OF_PORTS {10};
    static const int MAX_NUMBER_OF_DEVICES{ 10 };

    int _alarmPanelCounter;

    Port _ports[MAX_NUMBER_OF_PORTS];
    AlarmPanel _alarmPanels[MAX_NUMBER_OF_DEVICES];

    std::string _currentCommand;
    Commands _command;

    bool _isWorking;

    void CheckInput();
    void ConvertInput();
    void MakeCommand();
    void PrintHelp();
    void PrintWelcome();
    void PortsStatus();
    void Create();
    void Connect();

public:
    MainConsole();
    virtual int GetId();
    virtual std::string GetName();
    virtual std::string GetLabel();
    Port* GetPorts();
};