#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"

int idzbazy;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui -> przycisk_anuluj ->setProperty("id_przycisku",1);


    QString sciezka = QDir::toNativeSeparators("../baza1.db"); //tu trzeba wrzucic baze do folderu w ktorym znajduje sie projekt
    qDebug() << "Ścieżka do bazy:" << sciezka;

    DB_Connection = QSqlDatabase::addDatabase("QSQLITE");
    DB_Connection.setDatabaseName(sciezka);

    if(DB_Connection.open()){
        qDebug() << "Polaczenie gut";
    } else {
        qDebug() << "Polaczenie not gut: " << DB_Connection.lastError().text();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    DB_Connection.open();
    QSqlDatabase::database().transaction();

    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_2_password->text();
    QSqlQuery query;
    query.prepare("SELECT id FROM login WHERE login = :login AND haslo = :haslo LIMIT 1"); //trzeba zrobic mechanizm sprawdzania w bazie, nie limitujac w sql
    query.bindValue(":login", login);
    query.bindValue(":haslo", password);
        if (query.exec()) {
        if (query.exec() && query.next()) { //czemu tu nie ma tylko query.next(), przeciez query.exec musi byc 1
            idzbazy = query.value(0).toInt();
            qDebug() << "Zalogowano. ID uzytkownika:" << idzbazy;
            secondwindow *second = new secondwindow(idzbazy);
            second->show();
            this->close();
        } else {
            qDebug() << "Błędny login lub hasło";
            QMessageBox::warning(this, "Błąd logowania", "Błędny login lub hasło.");
        }
    } else {
        qDebug() << "Błąd zapytania: " << query.lastError().text();
    }

    QSqlDatabase::database().commit(); //to powinno byc w ifie, po co commit jak sie wywalilo zapytanie
    DB_Connection.close();
}


void MainWindow::on_pushButton_zarejestruj_sie_clicked() // przejscie do strony z rejestracja
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_anuluj_clicked() // cofanie do logowania
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_zarejestruj_sie_2_clicked() // rejestracja, ze wysylanie danych do bazy.
{
    QString login = ui->lineEdit_login_2->text(); //tego sie nie da w liscie zrobic? Np ze login to element o id 0 i etc
    QString haslo = ui->lineEdit_haslo_2->text(); //robisz wtedy uzupelnianie w petli a nie taki makaron
    QString imie = ui->lineEdit_imie->text();
    QString nazwisko = ui->lineEdit_nazwisko->text();
    QString email = ui->lineEdit_adres_email->text();
    QString numer_tel = ui->lineEdit_numer_telefonu->text();
    QString Ulica_i_nr = ui->lineEdit_ulica->text();
    QString Miasto = ui->lineEdit_miasto->text();
    QSqlQuery query;
    query.prepare("INSERT INTO login (login, haslo, imie, nazwisko, email, numer_tel, Miasto, Ulica_i_nr) VALUES (:login, :haslo, :imie, :nazwisko, :email, :numer_tel, :Miasto, :Ulica_i_nr)");
    query.bindValue(":login",login); //wtedy po petli przelatujesz i bindujesz, masz 2 listy - stringow i wartosci i po tym iterujesz
    query.bindValue(":haslo",haslo); //przejrzystsze to i wielokrotne uzycie kodu
    query.bindValue(":imie",imie);
    query.bindValue(":nazwisko",nazwisko);
    query.bindValue(":email",email);
    query.bindValue(":numer_tel",numer_tel);
    query.bindValue(":Ulica_i_nr",Ulica_i_nr);
    query.bindValue(":Miasto",Miasto);
    if (query.exec()) {
        QMessageBox::information(this, "Sukces", "Dziala");

    } else {
        QMessageBox::critical(this, "Błąd", "nie dziala");
    }
}

void MainWindow::nacisniecie_przycisku(int wartosc)
{
    switch(wartosc)
    {
    case 0: //logowanie do banku
        ui->stackedWidget->setCurrentIndex(1);
        break;
    case 1: //anuluj 2
         ui->stackedWidget->setCurrentIndex(1);
        break;
    case 3:
        ui->stackedWidget->setCurrentIndex(3);
        break;
    default:
        break;
    }
}

void MainWindow::on_pushButton_logowanie_do_banku_clicked() // przejscie do strony z logowanniem
{
    ui->stackedWidget->setCurrentIndex(1); //te wszystkie pojedyne funkcje powinny miec parametr liczbowy i wtedy masz 1 funkcje zamiast 4
}


void MainWindow::on_pushButton_bankomat_clicked() // przejscie do strony bankomatu wplaty/wypaty
{
    ui->stackedWidget->setCurrentIndex(3);
}



void MainWindow::on_pushButton_anuluj_2_clicked() // przejscie do wyboru startowego z panelu logowania
{
    ui->stackedWidget->setCurrentIndex(0);

}


void MainWindow::on_pushButton_anuluj_3_clicked() // przejscie do wyboru startowego z bankomatu
{
    ui->stackedWidget->setCurrentIndex(0);

}














void MainWindow::on_pushButton_wplata_clicked()
{
    bool okKwota, okId;
    double kwota = ui->lineEdit_kwota_bankomat->text().toDouble(&okKwota);
    int id = ui->lineEdit_numer_konta_id_bankomat->text().toInt(&okId);
    if (!okKwota || !okId || kwota <= 0) {
        QMessageBox::warning(this, "Błąd", "Wprowadź poprawne dane.");
        return; //void returnuje???
    }
    QSqlDatabase db = QSqlDatabase::database();
    if(!db.isOpen()) db.open();

    db.transaction();
    QSqlQuery q;
    q.prepare("UPDATE login SET balans = balans +:kwota WHERE id = :id");
    q.bindValue(":kwota",kwota);
    q.bindValue(":id",id);

    if (q.exec()) {
        db.commit();
        QMessageBox::information(this, "Sukces", "Wpłata wykonana pomyślnie.");

    } else {
        db.rollback();
        QMessageBox::critical(this, "Błąd", "Nie udało się wykonać wpłaty. Sprawdź kwote i numer konta(id).");
    }

}








void MainWindow::on_pushButton_wyplata_clicked() //podumam czy nie da sie tego zorbic w 1 funkcji i ifa czy wplata czy wyplata
{
    bool okKwota, okId;
    double kwota = ui->lineEdit_kwota_bankomat->text().toDouble(&okKwota);
    int id = ui->lineEdit_numer_konta_id_bankomat->text().toInt(&okId);
    double bilans1,bilans2; // sprawdzanie czy wgl sie cos wyplacilo
    if (!okKwota || !okId || kwota <= 0) {
        QMessageBox::warning(this, "Błąd", "Wprowadź poprawne dane.");
        return; //znowu void returnuje
    }
    QSqlDatabase db = QSqlDatabase::database();
    if(!db.isOpen()) db.open();

    db.transaction();
    QSqlQuery q,q2,q3;

    q2.prepare("SELECT balans FROM login where id = :id");
    q2.bindValue(":id",id);
    q2.exec();
    q2.next();

    bilans1 = q2.value("balans").toDouble();

    q.prepare("UPDATE login SET balans = balans -:kwota WHERE id = :id AND balans >= :kwota");
    q.bindValue(":kwota",kwota);
    q.bindValue(":id",id);

    q3.prepare("SELECT balans FROM login where id = :id");
    q3.bindValue(":id",id);
    q3.exec();
    q3.next();

    bilans2 = q3.value("balans").toDouble();

    if (q.exec() && bilans1!=bilans2){ //Gdzie wartosc bilans2? W tym kodzie jest nieprzypisany chyba ze jest w SQL taki parametr {
        db.commit();
        qDebug() << bilans1;
        qDebug() << bilans2;
        QMessageBox::information(this, "Sukces", "Wypłata wykonana pomyślnie.");

    } else {
        db.rollback();
        QMessageBox::critical(this, "Błąd", "Nie udało się wykonać wypłaty. Sprawdź kwote i numer konta(id).");
    }
}

