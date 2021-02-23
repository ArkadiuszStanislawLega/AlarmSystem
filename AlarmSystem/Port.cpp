#include "Port.h"

Port::Port(int id, std::string name)
{
    this->_id = id;
    this->_name = name;
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
    return this->_id + " " + this->_name;
}

bool Port::IsConnected()
{
    return this->_isConnected;
}

MainConsole* Port::GetParent()
{
    return this->_parent;
}