#include "PDate.h"

PDate::PDate()
{

}

PDate::PDate(std::string d):dateStr(d)
{}

std::string PDate::getData()
{
    return dateStr;
}
