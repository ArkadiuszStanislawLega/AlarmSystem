// AlarmSystem.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "AlarmPanel.h"

int main()
{
    AlarmPanel ap();

    Device* d;
    d = &ap;
    d->introduce();
}