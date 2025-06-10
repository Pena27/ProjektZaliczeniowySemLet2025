/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QPushButton *pushButton_logowanie_do_banku;
    QPushButton *pushButton_bankomat;
    QWidget *page;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_login;
    QLineEdit *lineEdit_2_password;
    QPushButton *pushButton_login;
    QPushButton *pushButton_zarejestruj_sie;
    QPushButton *pushButton_anuluj_2;
    QWidget *page_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_miasto;
    QLineEdit *lineEdit_ulica;
    QLabel *label_3;
    QLineEdit *lineEdit_nazwisko;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_login_2;
    QLabel *label_6;
    QLineEdit *lineEdit_imie;
    QLabel *label_10;
    QLabel *label_5;
    QLineEdit *lineEdit_numer_telefonu;
    QLineEdit *lineEdit_adres_email;
    QLabel *label_4;
    QLabel *label_11;
    QLineEdit *lineEdit_haslo_2;
    QLabel *label_9;
    QPushButton *pushButton_zarejestruj_sie_2;
    QPushButton *pushButton_anuluj;
    QWidget *page_4;
    QPushButton *pushButton_anuluj_3;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *lineEdit_numer_konta_id_bankomat;
    QLineEdit *lineEdit_kwota_bankomat;
    QPushButton *pushButton_wplata;
    QPushButton *pushButton_wyplata;
    QMenuBar *menubar;
    QMenu *menuBank_muj;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(820, 592);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(10, 0, 801, 561));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        pushButton_logowanie_do_banku = new QPushButton(page_3);
        pushButton_logowanie_do_banku->setObjectName("pushButton_logowanie_do_banku");
        pushButton_logowanie_do_banku->setGeometry(QRect(200, 190, 361, 49));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        pushButton_logowanie_do_banku->setFont(font);
        pushButton_bankomat = new QPushButton(page_3);
        pushButton_bankomat->setObjectName("pushButton_bankomat");
        pushButton_bankomat->setGeometry(QRect(270, 250, 221, 49));
        pushButton_bankomat->setFont(font);
        stackedWidget->addWidget(page_3);
        page = new QWidget();
        page->setObjectName("page");
        groupBox = new QGroupBox(page);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 761, 301));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 50, 121, 51));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        label->setFont(font1);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 120, 121, 51));
        label_2->setFont(font1);
        lineEdit_login = new QLineEdit(groupBox);
        lineEdit_login->setObjectName("lineEdit_login");
        lineEdit_login->setGeometry(QRect(170, 50, 231, 41));
        lineEdit_2_password = new QLineEdit(groupBox);
        lineEdit_2_password->setObjectName("lineEdit_2_password");
        lineEdit_2_password->setGeometry(QRect(170, 120, 231, 41));
        lineEdit_2_password->setEchoMode(QLineEdit::EchoMode::Password);
        pushButton_login = new QPushButton(groupBox);
        pushButton_login->setObjectName("pushButton_login");
        pushButton_login->setGeometry(QRect(80, 220, 141, 51));
        pushButton_login->setFont(font);
        pushButton_zarejestruj_sie = new QPushButton(groupBox);
        pushButton_zarejestruj_sie->setObjectName("pushButton_zarejestruj_sie");
        pushButton_zarejestruj_sie->setGeometry(QRect(460, 220, 261, 51));
        pushButton_zarejestruj_sie->setFont(font);
        pushButton_anuluj_2 = new QPushButton(page);
        pushButton_anuluj_2->setObjectName("pushButton_anuluj_2");
        pushButton_anuluj_2->setGeometry(QRect(0, 480, 121, 51));
        pushButton_anuluj_2->setFont(font);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        gridLayoutWidget = new QWidget(page_2);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(90, 70, 611, 411));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_miasto = new QLineEdit(gridLayoutWidget);
        lineEdit_miasto->setObjectName("lineEdit_miasto");

        gridLayout->addWidget(lineEdit_miasto, 6, 1, 1, 1);

        lineEdit_ulica = new QLineEdit(gridLayoutWidget);
        lineEdit_ulica->setObjectName("lineEdit_ulica");

        gridLayout->addWidget(lineEdit_ulica, 7, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_nazwisko = new QLineEdit(gridLayoutWidget);
        lineEdit_nazwisko->setObjectName("lineEdit_nazwisko");

        gridLayout->addWidget(lineEdit_nazwisko, 3, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName("label_7");
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 7, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName("label_8");
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 6, 0, 1, 1);

        lineEdit_login_2 = new QLineEdit(gridLayoutWidget);
        lineEdit_login_2->setObjectName("lineEdit_login_2");

        gridLayout->addWidget(lineEdit_login_2, 0, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName("label_6");
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        lineEdit_imie = new QLineEdit(gridLayoutWidget);
        lineEdit_imie->setObjectName("lineEdit_imie");

        gridLayout->addWidget(lineEdit_imie, 2, 1, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName("label_10");
        label_10->setFont(font);

        gridLayout->addWidget(label_10, 0, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        lineEdit_numer_telefonu = new QLineEdit(gridLayoutWidget);
        lineEdit_numer_telefonu->setObjectName("lineEdit_numer_telefonu");

        gridLayout->addWidget(lineEdit_numer_telefonu, 5, 1, 1, 1);

        lineEdit_adres_email = new QLineEdit(gridLayoutWidget);
        lineEdit_adres_email->setObjectName("lineEdit_adres_email");

        gridLayout->addWidget(lineEdit_adres_email, 4, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName("label_11");
        label_11->setFont(font);

        gridLayout->addWidget(label_11, 1, 0, 1, 1);

        lineEdit_haslo_2 = new QLineEdit(gridLayoutWidget);
        lineEdit_haslo_2->setObjectName("lineEdit_haslo_2");

        gridLayout->addWidget(lineEdit_haslo_2, 1, 1, 1, 1);

        label_9 = new QLabel(page_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(310, 20, 161, 31));
        label_9->setFont(font);
        pushButton_zarejestruj_sie_2 = new QPushButton(page_2);
        pushButton_zarejestruj_sie_2->setObjectName("pushButton_zarejestruj_sie_2");
        pushButton_zarejestruj_sie_2->setGeometry(QRect(430, 500, 231, 41));
        pushButton_zarejestruj_sie_2->setFont(font);
        pushButton_anuluj = new QPushButton(page_2);
        pushButton_anuluj->setObjectName("pushButton_anuluj");
        pushButton_anuluj->setGeometry(QRect(120, 500, 231, 41));
        pushButton_anuluj->setFont(font);
        stackedWidget->addWidget(page_2);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        pushButton_anuluj_3 = new QPushButton(page_4);
        pushButton_anuluj_3->setObjectName("pushButton_anuluj_3");
        pushButton_anuluj_3->setGeometry(QRect(0, 490, 121, 51));
        pushButton_anuluj_3->setFont(font);
        gridLayoutWidget_2 = new QWidget(page_4);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(210, 110, 361, 121));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(gridLayoutWidget_2);
        label_12->setObjectName("label_12");

        gridLayout_2->addWidget(label_12, 1, 0, 1, 1);

        label_13 = new QLabel(gridLayoutWidget_2);
        label_13->setObjectName("label_13");

        gridLayout_2->addWidget(label_13, 2, 0, 1, 1);

        lineEdit_numer_konta_id_bankomat = new QLineEdit(gridLayoutWidget_2);
        lineEdit_numer_konta_id_bankomat->setObjectName("lineEdit_numer_konta_id_bankomat");

        gridLayout_2->addWidget(lineEdit_numer_konta_id_bankomat, 1, 1, 1, 1);

        lineEdit_kwota_bankomat = new QLineEdit(gridLayoutWidget_2);
        lineEdit_kwota_bankomat->setObjectName("lineEdit_kwota_bankomat");

        gridLayout_2->addWidget(lineEdit_kwota_bankomat, 2, 1, 1, 1);

        pushButton_wplata = new QPushButton(page_4);
        pushButton_wplata->setObjectName("pushButton_wplata");
        pushButton_wplata->setGeometry(QRect(210, 250, 141, 41));
        pushButton_wplata->setFont(font);
        pushButton_wyplata = new QPushButton(page_4);
        pushButton_wyplata->setObjectName("pushButton_wyplata");
        pushButton_wyplata->setGeometry(QRect(420, 250, 151, 41));
        pushButton_wyplata->setFont(font);
        stackedWidget->addWidget(page_4);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 820, 25));
        menuBank_muj = new QMenu(menubar);
        menuBank_muj->setObjectName("menuBank_muj");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuBank_muj->menuAction());

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_logowanie_do_banku->setText(QCoreApplication::translate("MainWindow", "Logowanie do Banku", nullptr));
        pushButton_bankomat->setText(QCoreApplication::translate("MainWindow", "Bankomat", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Login: ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Has\305\202o:", nullptr));
        pushButton_login->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        pushButton_zarejestruj_sie->setText(QCoreApplication::translate("MainWindow", "Zarejestruj si\304\231", nullptr));
        pushButton_anuluj_2->setText(QCoreApplication::translate("MainWindow", "Anuluj", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Imie:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Ulica i numer domu:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Miasto:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Numer Telefonu:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Login:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Adres email:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Nazwisko:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Has\305\202o:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Rejestracja", nullptr));
        pushButton_zarejestruj_sie_2->setText(QCoreApplication::translate("MainWindow", "Zarejestruj si\304\231", nullptr));
        pushButton_anuluj->setText(QCoreApplication::translate("MainWindow", "Anuluj", nullptr));
        pushButton_anuluj_3->setText(QCoreApplication::translate("MainWindow", "Anuluj", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Numer konta(id):", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Kwota:", nullptr));
        pushButton_wplata->setText(QCoreApplication::translate("MainWindow", "Wp\305\202ata", nullptr));
        pushButton_wyplata->setText(QCoreApplication::translate("MainWindow", "Wyp\305\202ata", nullptr));
        menuBank_muj->setTitle(QCoreApplication::translate("MainWindow", "muj Bank", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
