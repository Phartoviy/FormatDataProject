#include <QCoreApplication>
#include "PhoinFormatObject.h"
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PhoinFormatObject obj("tag=0;tag2=12:30:00;");
    int ab = 6;
    obj.setValueInt("tag2",ab);
    //qDebug() << ab;



    return a.exec();
}
