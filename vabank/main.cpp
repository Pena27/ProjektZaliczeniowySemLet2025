#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QIcon appIcon(":/Ikona.png");
    a.setWindowIcon(appIcon);

    MainWindow w;
    w.show();
    return a.exec();
}
