#ifndef PTIME_H
#define PTIME_H
#include <iostream>

class PTime
{
    std::string timeStr{""};
public:
    PTime();
    PTime(std::string t);
    std::string getData();
};

#endif // PTIME_H
