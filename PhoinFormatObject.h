#ifndef PHOINFORMATOBJECT_H
#define PHOINFORMATOBJECT_H
#include "PTime.h"
#include "PDate.h"
#include <vector>
#include <QTime>
class PhoinFormatObject
{
    std::string nameID{""};
    std::string line{""};
    std::vector<std::string> log{};
public:
    PhoinFormatObject();
    std::string getName();
    PhoinFormatObject(std::string lineId);
    bool getValueInt(std::string tag,int &result);
    bool getValueStr(std::string tag,std::string &result);
    bool getValueDouble(std::string tag,double &result);
    bool getValueTime(std::string tag,PTime &result);
    bool getValueDate(std::string tag,PDate &result);
    bool getValueBool(std::string tag, bool &result);

    bool setValueInt(std::string tag, int value);

    bool isEmpty();
    int countAttrib();
    std::vector<std::string> getlog();
private:
    std::string getValue(std::string tag,bool &s);
    bool setValue(std::string attribut);
};

#endif // PHOINFORMATOBJECT_H
