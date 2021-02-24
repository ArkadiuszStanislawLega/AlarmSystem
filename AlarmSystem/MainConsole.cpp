#include "MainConsole.h"


MainConsole::MainConsole()
{
    this->_isWorking = true;
    this->_alarmPanelCounter = { 0 };

    PrintWelcome();

    while (this->_isWorking)
    {
        CheckInput();
        ConvertInput();
        MakeCommand();
    }
}

int MainConsole::GetId()
{
    return this->_id;
}

std::string MainConsole::GetName()
{
    return this->_name;
}

std::string MainConsole::GetLabel()
{
    return this->_id + " " + this->_name; 
}

Port* MainConsole::GetPorts()
{
    return _ports;
}

void MainConsole::CheckInput()
{
    std::cin >> this->_currentCommand;
}

void MainConsole::ConvertInput()
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

void MainConsole::MakeCommand()
{
    switch (this->_command)
    {
    case ex:
        this->_isWorking = false;
        break;

    case help:
        PrintHelp();
        break;

    case status:
        PortsStatus();
        break;

    case connect:
        Connect();
        break;

    case create:
        Create();
        break;

    default:
        break;
    }
}

void MainConsole::PrintHelp()
{
    std::cout << "help - pomoc dotyczaca polecen" << std::endl;
    std::cout << "status - pokazuje status portow" << std::endl;
    std::cout << "connect - laczy urzadzenie z wolnym portem" << std::endl;
    std::cout << "create - tworzy wolne urządzenie" << std::endl;
    std::cout << "exit - wyjście z programu" << std::endl;
}

void MainConsole::PrintWelcome()
{
    std::cout << "Wyswietl help - help" << std::endl;
}

void MainConsole::PortsStatus()
{
    size_t size = sizeof(this->_ports)/sizeof(this->_ports[0]);
    Port* pointer = GetPorts();
    
    for (size_t i = 0; i < size; i++)
    {
        std::cout << pointer->GetStatus() << std::endl;
        pointer++;
    }
}

void MainConsole::Create()
{
    this->_alarmPanels[this->_alarmPanelCounter] = AlarmPanel(this->_alarmPanelCounter, "Alarm panel glowny");
    this->_alarmPanelCounter++;
}

void MainConsole::Connect()
{
    this->_ports[0].Connect(this->_alarmPanels[0].GetPort());
    this->_alarmPanels[0].GetPort()->Connect(&this->_ports[0]);
}