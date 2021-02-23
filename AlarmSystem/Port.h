#include <iostream>
#include "Device.h"

class MainConsole;
class Port : public Device
{
private:
    bool _isConnected;
    MainConsole* _parent;

public:
    Port(int=0, std::string="Port");
    virtual int GetId();
    virtual std::string GetName();
    virtual std::string GetLabel();

    bool IsConnected();
    MainConsole* GetParent();
};