#ifndef PHOINFORMATOBJECT_H
#define PHOINFORMATOBJECT_H
#include "PTime.h"
#include "PDate.h"
#include <vector>
#include <set>
#include <QTime>
class PhoinFormatObject
{
    std::string nameID{""};
    std::string line{""};
    std::vector<std::string> log{};
    std::vector<PhoinFormatObject> innerLists{};
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
    PhoinFormatObject getFormatList(std::string tag);

    bool addAttributInt(std::string tag, int value);
    bool addAttributDouble(std::string tag, double value);
    bool addAttributBool(std::string tag, bool value);
    bool addAttributTime(std::string tag, PTime value);
    bool addAttributDate(std::string tag, PDate value);
    bool addAttributStr(std::string tag, std::string value);

    std::set<std::string> getTags();
    std::string getTagByNO(int num);

    bool isEmpty();
    int countAttrib();
    std::vector<std::string> getlog();
    std::string getRecentLog();

    void setData(std::string l);
    void addInnerList(std::string lineAttribut);
private:
    std::string getValue(std::string tag,bool &s);
    bool setValue(std::string attribut);
    PhoinFormatObject getListByNumber(int number);

};

#endif // PHOINFORMATOBJECT_H
