#include "Port.h"

int Port::_deviceCounter = 1;

Port::Port(int id, std::string name)
{
    this->_id = id == 0 ? this->_deviceCounter : id;
    this->_name = name;
    this->_isConnected = false;
    this->_deviceCounter++;
}

Port::Port(Device* parent, int id, std::string name)
{
    this->_id = id == 0 ? this->_deviceCounter : id;
    this->_name = name;
    this->_isConnected = {false};
    this->_parent = parent;
    this->_deviceCounter++;
}

bool Port::IsConnected()
{
    return this->_isConnected;
}

Port* Port::GetConnectedPort()
{
    return this->_connectedPort;
}

Device* Port::GetParent()
{
    return this->_parent;
}

void Port::SetParent(Device* device)
{
    this->_parent = device;
}

std::string Port::GetStatus()
{
    if (this->_isConnected) 
        return GetLabel() + " polaczony ";
    else
        return GetLabel() + " rozlaczony";
}

void Port::Connect(Port* port)
{
    this->_connectedPort = port;
    this->_isConnected = true;
}

void Port::Disconnect()
{
    this->_connectedPort = 0;
    this->_isConnected = false;
}