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

    apc.Login();
    apc.GetAllLoginUsers();

    User users[3];

    users[0] = User(1, 1234, "Mietek", "Szczesniak");
    users[1] = User(2, 4321, "Zenon", "Trombka");
    users[2] = User(3, 5647, "Czesiek", "Pierdzibak");

    size_t users_size = sizeof(users) / sizeof(users[0]);

    for (size_t i = 0; i < users_size; i++)
    {
        apc.AddUser(users[i]);
        apc.TempLogin(users[i]);
    }

    apc.RemoveUser(&users[0]);
    apc.GetUsers();
    apc.RemoveUser(&users[2]);
    
    apc.GetUsers();
    apc.GetAllLoginUsers();
}
