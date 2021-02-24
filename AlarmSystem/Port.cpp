#include "Port.h"


int Port::_deviceCounter = 0;

Port::Port(int id, std::string name)
{
    this->_id = id;
    this->_name = name;
    this->_isConnected = false;
    this->_deviceCounter++;
}


Port::Port(Device* parent, int id, std::string name)
{
    this->_id = id == 0 ? this->_deviceCounter : id;
    this->_name = name;
    this->_isConnected = false;
    this->_parent = parent;
    this->_deviceCounter++;
}

int Port::GetId()
{
    return this->_id;
}

std::string Port::GetName()
{
    return this->_name;
}

std::string Port::GetLabel()
{
    return "" + this->_id;
}

bool Port::IsConnected()
{
    return this->_isConnected;
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