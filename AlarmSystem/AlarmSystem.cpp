// AlarmSystem.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "AlarmPanelController.h"
#include "AlarmPanel.h"
#include "AlarmPanelView.h"

int main()
{
    AlarmPanel ap(1, "Panel Alarmowy milion");
    AlarmPanelView av(&ap, 1, "Pierwszy panel");
    AlarmPanelController apc(&ap, &av);

    av.print();
    av.print_authentication(true);
    av.print_authentication(false);

    apc.login();
    apc.get_all_login_users();
    //Device* d;
    //d = &ap;
    //d->introduce();
}