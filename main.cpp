#include "RingWait1.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RingWait1 mainWidget;
    mainWidget.show();
    return a.exec();
}
