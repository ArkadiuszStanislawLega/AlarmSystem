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
    std::cout << "createap  - tworzy wolne alarm panel" << std::endl;
    std::cout << "removeap  - usuwanie alarm panelu" << std::endl;
    std::cout << "getpanels - wyswietlanie wszystkich paneli" << std::endl;
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


void MainConsoleView::CreateNewAlarmPanel()
{
    std::cout << Label() << "Podaj Id, a nastepnie Nazwe Panelu:" << std::endl;
}

void MainConsoleView::CreatedNewAlarmPanel()
{
    std::cout << Label() << "Poprawnie utworzono nowy Panel." << std::endl;
}

void MainConsoleView::CreatedNewAlarmPanelFailed()
{
    std::cout << Label() << "Nie udalo sie utworzyc nowego Panelu." << std::endl;
}

void MainConsoleView::PrintAlarmPanels(AlarmPanel* alarmPanels, int size)
{
    std::cout << Label() << "Panele alarmowe dostepne w konsoli(" << to_string(size) << "): " << std::endl;
    for (size_t i = 0; i <(size_t) size; i++)
    {
        if (alarmPanels[i].GetId() != 0) 
            std::cout << to_string(i) << ". " << alarmPanels[i].GetLabel() << std::endl;
    }
}

void MainConsoleView::PrintGetIdOfAlarmPanel()
{
    std::cout << Label() << "Podaj numer Id Panelu:" << std::endl;
}

void MainConsoleView::PrintRemovedAlarmPanelSuccessful()
{
    std::cout << Label() << "Poprawnie usunieto Panel." << std::endl;
}

void MainConsoleView::PrintRemovedAlarmPanelFailed()
{
    std::cout << Label() << "Nie udalo sie usunac Panelu." << std::endl;
}