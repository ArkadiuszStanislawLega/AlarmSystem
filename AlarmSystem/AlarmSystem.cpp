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

    User u1 = User(1, 1234, "Mietek", "Szczesniak");
    User u2 = User(2, 4321, "Zenon", "Trombka");
    User u3 = User(3, 5647, "Czesiek", "Pierdzibak");

    apc.remove_user(&u1);
    apc.get_users();
    apc.remove_user(&u3);
    
    apc.get_users();
    apc.get_all_login_users();

    //Device* d;
    //d = &ap;
    //d->introduce();
}