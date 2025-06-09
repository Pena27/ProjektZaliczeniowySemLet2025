#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setWindowIcon(QIcon("../zasoby/ChatGPT Image 9 maj 2025, 09_32_38.png"));

    MainWindow w;
    w.show();
    return a.exec();
}
