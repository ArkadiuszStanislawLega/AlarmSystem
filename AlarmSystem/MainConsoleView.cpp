#include "MainConsoleView.h"

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

void MainConsoleView::PrintPortStatus( Port* ports)
{
    for (size_t i = 0; ; i++)
    {
        if(ports == nullptr) break;
        std::cout << ports->GetStatus() << std::endl;
        ports++;
    }
}
