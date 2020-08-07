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
bool vitalsAreOk(float bpm, float spo2, float respRate) {
    

    return true;
}

std::string CheckLimits(int type, double value)
{
    std::string Update = "";
    CurrentParameters hrResult;
    Limits allLimits;
    if (type == TOTALTIME)
        hrResult.AddValue(TOTALTIME, value);
    else
    hrResult.SetValue(type, value);
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
