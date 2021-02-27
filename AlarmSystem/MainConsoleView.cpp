#include "MainConsoleView.h"

MainConsoleView::MainConsoleView()
{
    this->_name = "Main Console";
}


std::string MainConsoleView::Label()
{
    return this->_name + "> ";
}

void MainConsoleView::PrintHelp()
{
    std::cout << "help      - pomoc dotyczaca polecen" << std::endl;
    std::cout << "status    - pokazuje status portow" << std::endl;
    std::cout << "connect   - laczy urzadzenie z wolnym portem" << std::endl;
    std::cout << "create    - tworzy wolne urzadzenie" << std::endl;
    std::cout << "exit      - wyjscie z programu" << std::endl;
}

void MainConsoleView::PrintWelcome()
{
    std::cout << "Wyswietl help - help" << std::endl;
}

void MainConsoleView::PrintPortStatus( Port* ports, int size)
{
    for (size_t i = 0; i < (size_t)size; i++)
    {
        std::cout << (ports+i)->GetStatus() << std::endl;
    }
}

void MainConsoleView::PrintConnectPort(Port* port, Port* port2)
{
    std::cout << Label() << "Polaczono porty: " << port->GetLabel() << " -> " << port2->GetLabel() << std::endl;
}
