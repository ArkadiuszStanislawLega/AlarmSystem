#include "MainConsole.h"


MainConsole::MainConsole()
{
    this->_isWorking = true;

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
        
    default:
        break;
    }
}

void MainConsole::PrintHelp()
{
    std::cout << "help - pomoc dotyczaca polecen" << std::endl;
    std::cout << "status - pokazuje status portow" << std::endl;
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