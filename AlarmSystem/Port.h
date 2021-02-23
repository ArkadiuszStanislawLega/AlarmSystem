#include <iostream>
#include "Device.h"

class MainConsole;
class AlarmPanel;
class Port : public Device
{
private:
    bool _isConnected;
    Device* _parent;

public:
    Port(int=0, std::string="Port");
    virtual int GetId();
    virtual std::string GetName();
    virtual std::string GetLabel();

    bool IsConnected();
    Device* GetParent();
    std::string GetStatus();
};