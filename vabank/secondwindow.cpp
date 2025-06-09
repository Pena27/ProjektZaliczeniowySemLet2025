#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "mainwindow.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

secondwindow::secondwindow(int idzbazy,QWidget *parent)
    : QDialog(parent),
    ui(new Ui::secondwindow),
    m_idzbazy(idzbazy)
{
    ui->setupUi(this);
    qDebug() << "id przekazane to: " << m_idzbazy;

    ui->tableWidget_historia->setColumnCount(4);
    ui->tableWidget_historia->setHorizontalHeaderLabels(QStringList() << "Nadawca ID" << "Odbiorca ID" << "Kwota" << "Data");

    daneuzytkownika();
    danedoprzelewu();
    wyswietlHistorie();
}

secondwindow::~secondwindow()
{
    delete ui;
}

// void err()
// {
//     qDebug() << "Błąd SELECT:" << q.lastError().text();
//     ui->label_balans->setText("---");
//     return;
// }

void secondwindow::daneuzytkownika(){
    QSqlQuery q;
    q.prepare("SELECT imie, balans FROM login where id = :id");
    q.bindValue(":id", m_idzbazy);

    if (!q.exec()) {
        qDebug() << "Błąd SELECT:" << q.lastError().text();
        ui->label_imie ->setText("Błąd bazy");
        ui->label_balans->setText("---");
        return; //return na voidzie
    }

    if (q.next()) {
        const QString imie  = q.value("imie").toString();
        const double  balans = q.value("balans").toDouble();

        ui->label_imie ->setText(QString("%1").arg(imie));
        ui->label_balans->setText(QString("%1 zł").arg(balans, 0, 'f', 2));
        ui->label_id->setText(QString("%1").arg(m_idzbazy));
    } else {
        ui->label_imie ->setText("Nie znaleziono");
        ui->label_balans->setText("---");
    }


}

void secondwindow::danedoprzelewu(){
    QSqlQuery q;
    q.prepare("SELECT balans FROM login where id = :id"); // ja bym zebral te kwerendy do pliku zasobow, zaimportowal go i
    q.bindValue(":id", m_idzbazy); //bral gotowe bo one sie powtarzaja

    if (!q.exec()) { //to moze byc osobna funkcja wywolujaca blad bo jest 2 razy zdefiniowana, jest wyzej jako voidEerr
        qDebug() << "Błąd SELECT:" << q.lastError().text();
        ui->label_balans->setText("---");
        return;
    }

    if (q.next()) {
        const double  balans = q.value("balans").toDouble();

        ui->label_balans_2->setText(QString("%1 zł").arg(balans, 0, 'f', 2));
        ui->label_id_2->setText(QString("%1").arg(m_idzbazy));
    } else {
        ui->label_balans->setText("---");
    }
}

void secondwindow::on_pushButton_powrot_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void secondwindow::on_pushButton_przelew_clicked() // przycisk by przejsc do strony przelewow
{
    ui->stackedWidget->setCurrentIndex(1);
}

void secondwindow::on_pushButton_wykonaj_przelew_clicked() // przelew na inne konto
{
    bool okKwota, okId;
    double kwota = ui->lineEdit_przelew_kwota->text().toDouble(&okKwota); //to tez juz widzialem, mozna by to zebrac w
    int odbiorcaId = ui->lineEdit_przelew_nr__konta->text().toInt(&okId); //jakis header zeby 2 razy nie opisywac tylko
    if (!okKwota || !okId || kwota <= 0) {  //latac parametrami, mamy to opisane w 2 plikach
        QMessageBox::warning(this, "Błąd", "Wprowadź poprawne dane.");
        return;
    }
    QSqlDatabase db = QSqlDatabase::database();
    if(!db.isOpen()) db.open();

    db.transaction();
    QSqlQuery q1,q2,q3;
    q1.prepare("UPDATE login SET balans = balans - :kwota WHERE id = :nadawca_id AND balans >= :kwota"); //tu tez jest mechanizm wyplaty,
    q1.bindValue(":kwota",kwota); //podowjne opisanie tylko sie parametry roznia
    q1.bindValue(":nadawca_id", m_idzbazy);

    q2.prepare("UPDATE login SET balans = balans + :kwota WHERE id = :odbiorca_id");
    q2.bindValue(":kwota",kwota);
    q2.bindValue(":odbiorca_id",odbiorcaId);

    q3.prepare("INSERT INTO historia (nadawca_id, odbiorca_id, kwota) VALUES (:nadawca_id, :odbiorca_id, :kwota)");
    q3.bindValue(":nadawca_id",m_idzbazy);
    q3.bindValue(":odbiorca_id",odbiorcaId);
    q3.bindValue(":kwota",kwota);
    if (q1.exec() && q1.numRowsAffected() == 1 && q2.exec() && q2.numRowsAffected() == 1 && q3.exec()) {
        db.commit();
        QMessageBox::information(this, "Sukces", "Przelew wykonano pomyślnie.");
        daneuzytkownika();
        danedoprzelewu();
        wyswietlHistorie();
    } else {
        db.rollback();
        QMessageBox::critical(this, "Błąd", "Nie udało się wykonać przelewu. Sprawdź środki i ID odbiorcy.");
    }
}

void secondwindow::wyswietlHistorie(){
    QSqlQuery q;
    q.prepare("SELECT odbiorca_id, nadawca_id, kwota, data FROM historia WHERE odbiorca_id = :id OR nadawca_id = :id ORDER BY data DESC");
    q.bindValue(":id",m_idzbazy);

    if (!q.exec()) {
        qDebug() << "Błąd historii:" << q.lastError().text();
        return;
    }

    ui->tableWidget_historia->setRowCount(0);
    int row = 0;

    while (q.next()) {
        int nadawca = q.value("nadawca_id").toInt();
        int odbiorca = q.value("odbiorca_id").toInt();
        double kwota = q.value("kwota").toDouble();
        QString data = q.value("data").toString();

        QColor kolor = (nadawca == m_idzbazy) ? QColor(220, 0, 0) : QColor(0, 150, 0);  // czerwony lub zielony
        QString kwotaStr = QString("%1 zł").arg(kwota, 0, 'f', 2);

        QTableWidgetItem *itemNadawca = new QTableWidgetItem(QString::number(nadawca));
        QTableWidgetItem *itemOdbiorca = new QTableWidgetItem(QString::number(odbiorca));
        QTableWidgetItem *itemKwota = new QTableWidgetItem(kwotaStr);
        QTableWidgetItem *itemData = new QTableWidgetItem(data);

        itemKwota->setForeground(QBrush(kolor));

        ui->tableWidget_historia->insertRow(row);
        ui->tableWidget_historia->setItem(row, 0, itemNadawca);
        ui->tableWidget_historia->setItem(row, 1, itemOdbiorca);
        ui->tableWidget_historia->setItem(row, 2, itemKwota);
        ui->tableWidget_historia->setItem(row, 3, itemData);

        row++;
    }
}


void secondwindow::on_pushButton_wyloguj_clicked()
{
    MainWindow *main = new MainWindow();
    main->show();
    this->close();
}

