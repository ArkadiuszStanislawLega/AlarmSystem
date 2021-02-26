#include "Device.h"

Device::Device()
{
    this->_id = 0;
    this->_name = "Device";
}

int Device::GetId()
{
	return  this->_id;
}

std::string Device::GetName()
{
	return  this->_name;
}

std::string Device::GetLabel()
{
    return to_string(this->_id) + " " + this->_name;
}
