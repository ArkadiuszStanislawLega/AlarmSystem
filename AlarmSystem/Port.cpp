#include "Port.h"

Port::Port(int id, std::string name)
{
    this->_id = id;
    this->_name = name;
    this->_isConnected = false;
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

std::string Port::GetStatus()
{
    if (this->_isConnected) 
        return GetLabel() + " polaczony" + this->_parent->GetLabel();
    else
        return GetLabel() + " rozlaczony";
}