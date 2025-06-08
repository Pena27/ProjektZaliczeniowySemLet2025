#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void obsluzPrzycisk(int d);
    void on_pushButton_login_clicked();

    void on_pushButton_zarejestruj_sie_clicked();

    void on_pushButton_anuluj_clicked();

    void on_pushButton_zarejestruj_sie_2_clicked(); //musimy to inaczej podpisac

    void on_pushButton_logowanie_do_banku_clicked();

    void on_pushButton_bankomat_clicked();

    void on_pushButton_anuluj_2_clicked(); //to tez

    void on_pushButton_anuluj_3_clicked(); //to tez

    void on_pushButton_wplata_clicked();

    void on_pushButton_wyplata_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase DB_Connection;
};
#endif // MAINWINDOW_H
