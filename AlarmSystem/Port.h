#pragma once
#ifndef PORT_H
#define PORT_H
#include <iostream>
#include <string>
#include "Device.h"

using std::to_string;

class Port : public Device
{
private:
    static int _deviceCounter;
    bool _isConnected;
    Device* _parent;
    Port* _connectedPort;

public:
    Port(int = 0, std::string = "Port");
    Port(Device* parent, int=0, std::string="Port");

    bool IsConnected();
    Device* GetParent();
    Port* GetConnectedPort();
    std::string GetStatus();

    void SetParent(Device* device);
    void Connect(Port* port);
    void Disconnect();
};
#endif