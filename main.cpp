#include <QCoreApplication>
#include "PhoinFormatObject.h"
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PhoinFormatObject obj("tag={0};tag2=12:30:00;");
    obj.addInnerList("tag34=5;tag54=0;");
    auto b = obj.getFormatList("tag");





    return a.exec();
}
