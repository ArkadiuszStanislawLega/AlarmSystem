#include "MainConsoleView.h"

void MainConsoleView::PrintHelp()
{
    std::cout << "help - pomoc dotyczaca polecen" << std::endl;
    std::cout << "status - pokazuje status portow" << std::endl;
    std::cout << "connect - laczy urzadzenie z wolnym portem" << std::endl;
    std::cout << "create - tworzy wolne urzadzenie" << std::endl;
    std::cout << "exit - wyjœcie z programu" << std::endl;
}

void MainConsoleView::PrintWelcome()
{
    std::cout << "Wyswietl help - help" << std::endl;
}


void MainConsoleView::PrintPortStatus(Port* ports)
{
    int size = sizeof(ports) / sizeof(ports[0]);

    for (size_t i = 0; i < size; i++)
    {
        std::cout << ports << std::endl;
        ports++;
    }
}
