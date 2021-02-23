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

    User users[3];

    users[0] = User(1, 1234, "Mietek", "Szczesniak");
    users[1] = User(2, 4321, "Zenon", "Trombka");
    users[2] = User(3, 5647, "Czesiek", "Pierdzibak");

    size_t users_size = sizeof(users) / sizeof(users[0]);

    for (size_t i = 0; i < users_size; i++)
    {
        apc.add_user(users[i]);
    }

    apc.remove_user(&users[0]);
    apc.get_users();
    apc.remove_user(&users[2]);
    
    apc.get_users();
    apc.get_all_login_users();

    //Device* d;
    //d = &ap;
    //d->introduce();
}
