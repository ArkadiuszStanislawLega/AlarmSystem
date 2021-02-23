#include <iostream>
#include "Port.h"
#include "Commands.h"

class MainConsole : public Device
{
private:
    static const int MAX_NUMBER_OF_PORTS {10};

    Port _ports[MAX_NUMBER_OF_PORTS];

    std::string _currentCommand;
    Commands _command;

    bool _isWorking;

    void CheckInput();
    void ConvertInput();
    void MakeCommand();
    void PrintHelp();
    void PrintWelcome();
    void PortsStatus();

public:
    MainConsole();
    virtual int GetId();
    virtual std::string GetName();
    virtual std::string GetLabel();
    Port* GetPorts();
};