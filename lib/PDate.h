#ifndef PDATE_H
#define PDATE_H
#include <iostream>

class PDate
{
    std::string dateStr{""};
public:
    PDate();
    PDate(std::string d);
    std::string getData();
};

#endif // PDATE_H
