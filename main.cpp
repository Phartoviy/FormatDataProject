#include <QCoreApplication>
#include "PhoinFormatObject.h"
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PhoinFormatObject obj("tag=0;tag2=12:30:00;");
    bool ab = 0;
    obj.addAttributBool("tag3",ab);

    auto l = obj.getTagByNO(0);



    return a.exec();
}
