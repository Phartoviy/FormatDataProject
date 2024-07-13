#include <QCoreApplication>
#include "PhoinFormatObject.h"
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PhoinFormatObject obj("tag2=12:30:00;tag34=5;tag54=0;");
    obj.addInnerList("tag340=5;tag540=0;","tag");
    auto flag = obj.getFormatList("tag");
    obj.addAttributBool("tag55",false);
    auto delFlag = obj.deleteAttribut("tag");



    return a.exec();
}
