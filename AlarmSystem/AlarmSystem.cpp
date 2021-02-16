// AlarmSystem.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "AlarmPanel.h"

int main()
{
    AlarmPanel ap(1, "Panel Alarmowy milion");

    Device* d;
    d = &ap;
    d->introduce();
}