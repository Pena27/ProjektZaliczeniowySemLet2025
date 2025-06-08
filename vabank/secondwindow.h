#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>

namespace Ui {
class secondwindow;
}

class secondwindow : public QDialog
{
    Q_OBJECT

public:
    explicit secondwindow(int idzbazy, QWidget *parent = nullptr);
    ~secondwindow();

private slots:
    void on_pushButton_przelew_clicked();

    void on_pushButton_powrot_clicked();

    void on_pushButton_wykonaj_przelew_clicked();

private:
    Ui::secondwindow *ui;
    int m_idzbazy { -1 };
    void daneuzytkownika();
    void danedoprzelewu();
    void wyswietlHistorie();
};

#endif
