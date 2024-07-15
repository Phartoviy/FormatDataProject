#include <QCoreApplication>
#include "PhoinFormatObject.h"
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PhoinFormatObject obj("tag2=12:30:00;tag34=5;tag54=0;");
    obj.updateAttributBool("tag2",1);



    return a.exec();
}
