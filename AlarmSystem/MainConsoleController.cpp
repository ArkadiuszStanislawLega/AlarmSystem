#include "MainConsoleController.h"


MainConsoleController::MainConsoleController()
{
    this->_isWorking = true;

    MainLoop();
}

void MainConsoleController::CheckInput()
{
    std::cin >> this->_currentCommand;
}

void MainConsoleController::MainLoop()
{
    this->_view.PrintWelcome();
    this->_view.PrintPortStatus(this->_model.GetPorts());

    while (this->_isWorking)
    {
        CheckInput();
        ConvertInput();
        MakeCommand();
    }
}


void MainConsoleController::ConvertInput()
{
    if (this->_currentCommand == "exit")
        this->_command = ex;

    if (this->_currentCommand == "help")
        this->_command = help;

    if (this->_currentCommand == "status")
        this->_command = status;

    if (this->_currentCommand == "connect")
        this->_command = connect;

    if (this->_currentCommand == "create")
        this->_command = create;
}

void MainConsoleController::MakeCommand()
{
    switch (this->_command)
    {
    case ex:
        this->_isWorking = false;
        break;

    case help:
        this->_view.PrintHelp();
        break;

    case status:
        this->_model.PortsStatus();
        break;

    case connect:
        this->_model.Connect();
        break;

    case create:
        this->_model.Create(1, "alarm panel");
        break;

    default:
        break;
    }
}
