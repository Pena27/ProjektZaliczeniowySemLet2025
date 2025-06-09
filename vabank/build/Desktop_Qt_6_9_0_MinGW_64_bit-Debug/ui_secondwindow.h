/********************************************************************************
** Form generated from reading UI file 'secondwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_secondwindow
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_imie;
    QLabel *label_2;
    QLabel *label_balans;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *label_id;
    QPushButton *pushButton_przelew;
    QTableWidget *tableWidget_historia;
    QLabel *label_8;
    QPushButton *pushButton_wyloguj;
    QWidget *page_2;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *label_id_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_przelew_nr__konta;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_przelew_kwota;
    QLabel *label_7;
    QLabel *label_balans_2;
    QPushButton *pushButton_wykonaj_przelew;
    QPushButton *pushButton_powrot;

    void setupUi(QDialog *secondwindow)
    {
        if (secondwindow->objectName().isEmpty())
            secondwindow->setObjectName("secondwindow");
        secondwindow->resize(734, 547);
        stackedWidget = new QStackedWidget(secondwindow);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 20, 711, 521));
        page = new QWidget();
        page->setObjectName("page");
        horizontalLayoutWidget = new QWidget(page);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(90, 10, 241, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        label_imie = new QLabel(horizontalLayoutWidget);
        label_imie->setObjectName("label_imie");
        label_imie->setFont(font);

        horizontalLayout_2->addWidget(label_imie);

        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 100, 181, 61));
        label_2->setFont(font);
        label_balans = new QLabel(page);
        label_balans->setObjectName("label_balans");
        label_balans->setGeometry(QRect(260, 110, 321, 41));
        label_balans->setFont(font);
        horizontalLayoutWidget_2 = new QWidget(page);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(590, 490, 121, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_2);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        label_id = new QLabel(horizontalLayoutWidget_2);
        label_id->setObjectName("label_id");

        horizontalLayout_3->addWidget(label_id);

        pushButton_przelew = new QPushButton(page);
        pushButton_przelew->setObjectName("pushButton_przelew");
        pushButton_przelew->setGeometry(QRect(90, 420, 281, 49));
        pushButton_przelew->setFont(font);
        tableWidget_historia = new QTableWidget(page);
        tableWidget_historia->setObjectName("tableWidget_historia");
        tableWidget_historia->setGeometry(QRect(90, 220, 431, 192));
        label_8 = new QLabel(page);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(90, 180, 281, 41));
        label_8->setFont(font);
        pushButton_wyloguj = new QPushButton(page);
        pushButton_wyloguj->setObjectName("pushButton_wyloguj");
        pushButton_wyloguj->setGeometry(QRect(510, 10, 171, 41));
        pushButton_wyloguj->setFont(font);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        horizontalLayoutWidget_3 = new QWidget(page_2);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(580, 480, 121, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget_3);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        label_id_2 = new QLabel(horizontalLayoutWidget_3);
        label_id_2->setObjectName("label_id_2");

        horizontalLayout_4->addWidget(label_id_2);

        gridLayoutWidget = new QWidget(page_2);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(170, 180, 381, 141));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_przelew_nr__konta = new QLineEdit(gridLayoutWidget);
        lineEdit_przelew_nr__konta->setObjectName("lineEdit_przelew_nr__konta");

        gridLayout_2->addWidget(lineEdit_przelew_nr__konta, 0, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName("label_5");

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName("label_6");

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        lineEdit_przelew_kwota = new QLineEdit(gridLayoutWidget);
        lineEdit_przelew_kwota->setObjectName("lineEdit_przelew_kwota");

        gridLayout_2->addWidget(lineEdit_przelew_kwota, 1, 1, 1, 1);

        label_7 = new QLabel(page_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(250, 110, 63, 20));
        label_balans_2 = new QLabel(page_2);
        label_balans_2->setObjectName("label_balans_2");
        label_balans_2->setGeometry(QRect(370, 110, 63, 20));
        pushButton_wykonaj_przelew = new QPushButton(page_2);
        pushButton_wykonaj_przelew->setObjectName("pushButton_wykonaj_przelew");
        pushButton_wykonaj_przelew->setGeometry(QRect(420, 340, 131, 29));
        pushButton_powrot = new QPushButton(page_2);
        pushButton_powrot->setObjectName("pushButton_powrot");
        pushButton_powrot->setGeometry(QRect(50, 430, 252, 49));
        pushButton_powrot->setFont(font);
        stackedWidget->addWidget(page_2);

        retranslateUi(secondwindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(secondwindow);
    } // setupUi

    void retranslateUi(QDialog *secondwindow)
    {
        secondwindow->setWindowTitle(QCoreApplication::translate("secondwindow", "DockWidget", nullptr));
        label->setText(QCoreApplication::translate("secondwindow", "Witaj,", nullptr));
        label_imie->setText(QString());
        label_2->setText(QCoreApplication::translate("secondwindow", "Stan Konta:", nullptr));
        label_balans->setText(QString());
        label_3->setText(QCoreApplication::translate("secondwindow", "Twoje id:", nullptr));
        label_id->setText(QString());
        pushButton_przelew->setText(QCoreApplication::translate("secondwindow", "Wykonaj przelew", nullptr));
        label_8->setText(QCoreApplication::translate("secondwindow", "Historia przelew\303\263w.", nullptr));
        pushButton_wyloguj->setText(QCoreApplication::translate("secondwindow", "WYLOGUJ", nullptr));
        label_4->setText(QCoreApplication::translate("secondwindow", "Twoje id:", nullptr));
        label_id_2->setText(QString());
        label_5->setText(QCoreApplication::translate("secondwindow", "Numer konta(id):", nullptr));
        label_6->setText(QCoreApplication::translate("secondwindow", "Kwota", nullptr));
        label_7->setText(QCoreApplication::translate("secondwindow", "Balans", nullptr));
        label_balans_2->setText(QString());
        pushButton_wykonaj_przelew->setText(QCoreApplication::translate("secondwindow", "Wykonaj przelew", nullptr));
        pushButton_powrot->setText(QCoreApplication::translate("secondwindow", "Powr\303\263t", nullptr));
    } // retranslateUi

};

namespace Ui {
    class secondwindow: public Ui_secondwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H
