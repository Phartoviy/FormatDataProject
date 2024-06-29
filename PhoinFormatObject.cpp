#include "PhoinFormatObject.h"
#include <QString>
#include <regex>
#include "stdlib.h"
PhoinFormatObject::PhoinFormatObject(std::string lineId):line(lineId){}

PhoinFormatObject::PhoinFormatObject()
{
    nameID = "Default name";
}

std::string PhoinFormatObject::getName()
{
    return nameID;
}

bool PhoinFormatObject::getValueInt(std::string tag,int &result)
{
    bool state = true;
    std::string val = getValue(tag,state);
    (state)?result = std::stoi(val):result = 0;
    return state;
}

bool PhoinFormatObject::getValueStr(std::string tag,std::string &result)
{
    bool state = true;
    result = getValue(tag,state);
    return state;
}

bool PhoinFormatObject::getValueDouble(std::string tag,double &result)
{
    bool state = true;
    std::string val = getValue(tag,state);
    result = (state)?std::stod(val.c_str()):0;
    return state;
}

bool PhoinFormatObject::getValueTime(std::string tag,PTime &result)
{
    bool state = true;
    std::string val = getValue(tag,state);
    if (state)
        result = PTime(val);
    else
        result = PTime();
    return state;
}

bool PhoinFormatObject::getValueDate(std::string tag, PDate &result)
{
    bool state = true;
    std::string val = getValue(tag,state);
    if (state)
        result = PDate(val);
    else
        result = PDate("1900-09-09");
    return state;
}

bool PhoinFormatObject::getValueBool(std::string tag, bool &result)
{
    bool state = true;
    std::string val = getValue(tag,state);
    if (state)
        result = (val == "1")?true:false;
    else
        result = false;
    return state;
}

bool PhoinFormatObject::setValueInt(std::string tag, int value)
{
    if (line.find(tag) == std::string::npos)
    {
        std::string attribut = tag+"="+std::to_string(value)+";";
        setValue(attribut);
        return true;
    }
    log.push_back("tag "+tag+" exist");
    return false;
}

bool PhoinFormatObject::isEmpty()
{
    return line.empty();
}

int PhoinFormatObject::countAttrib()
{
    int c = 0;
    for (char ch: line)
    {
        if (ch == ';')
            c++;
    }
    return c;
}

std::vector<std::string> PhoinFormatObject::getlog()
{
    return log;
}

std::string PhoinFormatObject::getValue(std::string tag,bool &s)
{
    std::regex pattern(tag+"=([^;]+)");
    std::smatch match;
    if (std::regex_search(line,match,pattern))
    {
        if (match[1].matched)
        {
            s = true;
            return match[1];
        }
    }
    s = false;
    log.push_back("tag: "+tag+" is not find");
    return "";
}

bool PhoinFormatObject::setValue(std::string attribut)
{
    line += attribut;
    return true;
}
