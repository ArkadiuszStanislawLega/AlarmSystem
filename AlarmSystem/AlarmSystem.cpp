// AlarmSystem.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "AlarmSystem.h"


int main()
{
    MainConsoleController m = MainConsoleController();
    m.Create();
    m.Connect();
    m.PortsStatus();
    return 0;
}
