#include "paramchecker.h"

#include <iostream>

uint8_t Connect(std::function<void(int, double)>)
{
    return 255;
}

bool isWithinLimits(double input, std::pair<double, double> limits)
{
    if (input < limits.first || input > limits.second)
        return false;
    return true;
}


std::string CheckLimits(int type, double value)
{
    std::string Update = "";
    Limits allLimits;
    if (type == TOTALTIME)
        currentParameters[type] = currentParameters[type] + value;
    else
        currentParameters[type] = value;
    if (!isWithinLimits(value, allLimits.GetLimits(type)))
    {
        return InformationRunning[type];
    }

    return Update;
}

void GetMachineDataCallback(int type, double value)
{
   auto info =  CheckLimits(type, value);
   if (!info.empty())
       std::cout << info;
}
