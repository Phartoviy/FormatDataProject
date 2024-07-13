#include "PhoinFormatObject.h"
#include <QString>
#include <regex>
#include "stdlib.h"
#include <sstream>
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

PhoinFormatObject PhoinFormatObject::getFormatList(std::string tag)
{
    int number = getNumberByTagList(tag);
    if (number != -1)
        return getListByNumber(number);
    else
        return PhoinFormatObject();
}

bool PhoinFormatObject::addAttributInt(std::string tag, int value)
{
    if (line.find(tag) == std::string::npos)
    {
        std::string attribut = tag+"="+std::to_string(value)+";";
        setValue(attribut);
        return true;
    }
    log.push_back("Тег "+tag+" уже существует");
    return false;
}

bool PhoinFormatObject::addAttributDouble(std::string tag, double value)
{
    if (line.find(tag) == std::string::npos)
    {
        std::ostringstream stream;
        stream << value;
        std::string attribut = tag+"="+stream.str()+";";
        setValue(attribut);
        return true;
    }
    log.push_back("Тег "+tag+" уже существует");
    return false;
}

bool PhoinFormatObject::addAttributBool(std::string tag, bool value)
{
    if (line.find(tag) == std::string::npos)
    {
        std::string attribut = tag+"="+std::to_string(value)+";";
        setValue(attribut);
        return true;
    }
    log.push_back("Тег "+tag+" уже существует");
    return false;
}

bool PhoinFormatObject::addAttributTime(std::string tag, PTime value)
{
    if (line.find(tag) == std::string::npos)
    {
        std::string attribut = tag+"="+value.getData()+";";
        setValue(attribut);
        return true;
    }
    log.push_back("Тег "+tag+" уже существует");
    return false;
}

bool PhoinFormatObject::addAttributDate(std::string tag, PDate value)
{
    if (line.find(tag) == std::string::npos)
    {
        std::string attribut = tag+"="+value.getData()+";";
        setValue(attribut);
        return true;
    }
    log.push_back("Тег "+tag+" уже существует");
    return false;
}

bool PhoinFormatObject::addAttributStr(std::string tag, std::string value)
{
    if (line.find(tag) == std::string::npos)
    {
        std::string attribut = tag+"="+value+";";
        setValue(attribut);
        return true;
    }
    log.push_back("Тег "+tag+" уже существует");
    return false;
}

std::set<std::string> PhoinFormatObject::getTags()
{
    std::set<std::string> listTags{};
    size_t pos = 0;
    std::string temp = line;
    while((pos = temp.find('=')) != std::string::npos)
    {
        std::string tag = temp.substr(0,pos);
        temp.erase(0,temp.find(';')+1);
        listTags.insert(tag);
    }
    return listTags;
}

std::string PhoinFormatObject::getTagByNO(int num)
{
    auto tags = getTags();
    int i = 0;
    for (auto it = tags.begin();it != tags.end();++it)
    {
        if (i == num)
            return *it;
        i++;
    }
    return "";

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

std::string PhoinFormatObject::getRecentLog()
{
    return log.back();
}

void PhoinFormatObject::setData(std::string l)
{
    line = l;
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
    log.push_back("Тег: "+tag+" не найден");
    return "";
}

bool PhoinFormatObject::setValue(std::string attribut)
{
    line += attribut;
    return true;
}

PhoinFormatObject PhoinFormatObject::getListByNumber(int number)
{
    if (innerLists.size() > number)
    {
        return innerLists[number];
    }
    log.push_back("Лист номер "+std::to_string(number)+" не найден");
    return PhoinFormatObject();
}

int PhoinFormatObject::getNumberByTagList(std::string tag)
{
    std::regex pattern(tag+"=\\{([^\\{\\}]*)\\}");
    std::smatch match;
    if (std::regex_search(line,match,pattern))
    {
        if (match[1].matched)
        {
            auto n = std::stoi(match[1]);
            return n;
        }
    }
    log.push_back("Тег: "+tag+" не найден");
    return -1;
}

void PhoinFormatObject::addInnerList(std::string lineAttribut, std::string tag)
{
    if (!lineAttribut.empty())
    {
        int sizeCurrent = innerLists.size();
        line += tag+"="+"{"+std::to_string(sizeCurrent)+"};";
        innerLists.push_back(PhoinFormatObject(lineAttribut));
    }
    else
    {
        log.push_back("Данные списка пустые");
    }
}

bool PhoinFormatObject::deleteAttribut(std::string tag)
{
    size_t startPos = line.find(tag+"=");
    if (startPos != std::string::npos)
    {
        size_t endPos = line.find(";",startPos);
        if (endPos != std::string::npos)
        {
            std::string tempStr = line.substr(startPos,endPos-startPos+1);
            if (tempStr.find("{")!= std::string::npos)
            {
                innerLists.erase(innerLists.begin()+getNumberByTagList(tag));
            }
            line.erase(startPos,endPos-startPos+1);
        }
        return true;
    }
    log.push_back("тег "+tag+" не найден");
    return false;
}
