// AlarmSystem.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "AlarmSystem.h"



int main()
{
    auto model = MainConsole();
    auto view = MainConsoleView();
    auto controller  = MainConsoleController();

    controller.SetModel(&model);
    controller.SetView(&view);
    controller.MainLoop();
    //controller.Create();
    //controller.Connect();
    //controller.PortsStatus();
    //controller.Enter();
     
    return 0;
}
