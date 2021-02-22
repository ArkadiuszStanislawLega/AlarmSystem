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

    apc.login();
    apc.get_all_login_users();
    User u = User(2, 4321, "Zenon", "Trombka");
    apc.remove_user(&u);
    apc.get_all_login_users();
    apc.get_users();

    //Device* d;
    //d = &ap;
    //d->introduce();
}