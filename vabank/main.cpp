#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setWindowIcon(QIcon("C:\\Users\\karol\\Documents\\vabank\\ChatGPT Image 9 maj 2025, 09_32_38.png"));
    //wrzucic tego file'a do folderu zasoby w projekcie

    MainWindow w;
    w.show();
    return a.exec();
}
