#include "Port.h"

class MainConsole
{
private:
    static const int MAX_NUMBER_OF_PORTS {10};
    Port _ports[MAX_NUMBER_OF_PORTS];

public:
    Port* GetPorts();
};