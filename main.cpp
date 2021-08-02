#include "mainmenu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainmenu e;

    e.show();
    return a.exec();
}
