// AlarmSystem.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "AlarmSystem.h"



int main()
{
    auto model = MainConsole();
    auto controller  = MainConsoleController();
    controller.SetModel(&model);
    controller.Create();
    controller.Connect();
    controller.PortsStatus();
    return 0;
}
