#include "PTime.h"

PTime::PTime()
{
    timeStr = "00:00:00";
}

PTime::PTime(std::string t):timeStr(t)
{}

std::string PTime::getData()
{
    return timeStr;
}
