#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"

int idzbazy;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //tablica nazw przyciskow z glownego okna do automatycznego przypisania
    QStringList tablicaNazwPrzyciskow = {"pushButton_logowanie_do_banku","pushButton_bankomat",
        "pushButton_anuluj_2","pushButton_anuluj_3","pushButton_zarejestruj_sie","pushButton_anuluj"};

    //petla przypisujaca nazwy przyciskow do akcji w UI
    for (int i = 0; i < tablicaNazwPrzyciskow.size(); ++i) {
        QString nazwa = tablicaNazwPrzyciskow[i];
        QPushButton *przycisk = findChild<QPushButton*>(nazwa);
        if (przycisk) {
            connect(przycisk, &QPushButton::clicked, this, [=]() {
                obsluzPrzycisk(i);
            });
            qDebug() << "Połaczono przycisk:" << nazwa << "z wartościa:" << i;
        } else {
            qDebug() << "Nie znaleziono przycisku:" << nazwa;
        }
    }

    QString sciezka = "baza1.db";
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
//funkcja obslugujaca poszczegolne przyciski
void MainWindow::obsluzPrzycisk(int wartosc)
{
    switch(wartosc)
    {
    case 0: //przycisk logowanie do banki clicked // przejscie do strony z logowanniem //
        ui->stackedWidget->setCurrentIndex(1);
        break;
    case 1: //bankomat clicked // przejscie do strony bankomatu wplaty/wypaty //
        ui->stackedWidget->setCurrentIndex(3);
        break;
    case 2: //anuluj_2 clicked // przejscie do wyboru startowego z panelu logowania //
        ui->stackedWidget->setCurrentIndex(0);
        break;
    case 3: //anuluj w bankmacie clicked // przejscie do wyboru startowego z bankomatu //
        ui->stackedWidget->setCurrentIndex(0);
        break;
    case 4: // zarejestruj clicked // przejscie do strony z rejestracja //
        ui->stackedWidget->setCurrentIndex(2);
        break;
    case 5: //anuluj_clicked // cofanie do logowania //
        ui->stackedWidget->setCurrentIndex(1);
        break;
    default:
        qDebug() << "Nieobsługiwany indeks:" << wartosc;
        break;
    }
}


void MainWindow::on_pushButton_wplata_clicked() //
{
    bool okKwota, okId;
    double kwota = ui->lineEdit_kwota_bankomat->text().toDouble(&okKwota);
    kwota = round(kwota*100)/100;
    int id = ui->lineEdit_numer_konta_id_bankomat->text().toInt(&okId);
    if (!okKwota || !okId || kwota <= 0) {
        QMessageBox::warning(this, "Błąd", "Wprowadź poprawne dane.");
        return;
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


void MainWindow::on_pushButton_wyplata_clicked()// //podumam czy nie da sie tego zorbic w 1 funkcji i ifa czy wplata czy wyplata
{
    bool okKwota, okId;
    double kwota = ui->lineEdit_kwota_bankomat->text().toDouble(&okKwota);
    kwota = round(kwota*100)/100;
    int id = ui->lineEdit_numer_konta_id_bankomat->text().toInt(&okId);
    double bilans1,bilans2; // sprawdzanie czy wgl sie cos wyplacilo
    if (!okKwota || !okId || kwota <= 0) {
        QMessageBox::warning(this, "Błąd", "Wprowadź poprawne dane.");
        return;
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
    q.exec();

    q3.prepare("SELECT balans FROM login where id = :id");
    q3.bindValue(":id",id);
    q3.exec();
    q3.next();

    bilans2 = q3.value("balans").toDouble();

    if (bilans1!=bilans2)
    {
        db.commit();
        qDebug() << bilans1;
        qDebug() << bilans2;
        QMessageBox::information(this, "Sukces", "Wypłata wykonana pomyślnie.");

    } else {
        db.rollback();
        QMessageBox::critical(this, "Błąd", "Nie udało się wykonać wypłaty. Sprawdź kwote i numer konta(id).");
    }
}


void MainWindow::on_pushButton_login_clicked() //
{
    //otwieranie bazy i deklaracja podstawowych zmiennych
    DB_Connection.open();
    QSqlDatabase::database().transaction();

    QString login = ui->lineEdit_login->text();

    QString password = ui->lineEdit_2_password->text();
    QSqlQuery query;

    //zapytanie do bazy w celu zalogowania
    query.prepare("SELECT id FROM login WHERE login = :login AND haslo = :haslo LIMIT 1");
    query.bindValue(":login", login);
    query.bindValue(":haslo", password);

    //wykonanie zapytania i weryfikacja
    if (query.exec()) {
        if ( query.exec()&& query.next()) {
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
        qDebug() << "Blad zapytania: " << query.lastError().text();
    }

    QSqlDatabase::database().commit();
    DB_Connection.close();
}

//rejestracja nowego uzytkownika
void MainWindow::on_pushButton_zarejestruj_sie_2_clicked() // rejestracja, ze wysylanie danych do bazy.
{
    //lista nazw atrybutow potrzebna do rejestracji
    QStringList atrybuty = {
        "login", "haslo", "imie", "nazwisko", "email",
        "numer_tel", "Ulica_i_nr", "Miasto"
    };

    // lista nazw atrybutow w UI
    QStringList atrybutyUi = {
        "lineEdit_login_2", "lineEdit_haslo_2", "lineEdit_imie", "lineEdit_nazwisko",
        "lineEdit_adres_email", "lineEdit_numer_telefonu", "lineEdit_ulica", "lineEdit_miasto"
    };

    //przygotowanie zapytania
    QSqlQuery query;
    query.prepare("INSERT INTO login (login, haslo, imie, nazwisko, email, numer_tel, Miasto, Ulica_i_nr) VALUES (:login, :haslo, :imie, :nazwisko, :email, :numer_tel, :Miasto, :Ulica_i_nr)");


    //przypisanie wartosci atrybutu -> atrybut w bazie
    QMap<QString, QString> dane;
    for (int i = 0; i < atrybuty.size(); ++i)
    {
        QLineEdit* lineEdit = this->findChild<QLineEdit*>(atrybutyUi[i]);
        if (lineEdit)
        {
            dane[atrybuty[i]] = lineEdit->text();
        }
    }

    //sprawdzanie czy wszystkie dane sa wpisane
    for(int i = 0; i< atrybuty.size();i++)
    {
        QString wprowadzonaWartosc = dane[atrybuty[i]];
        if(wprowadzonaWartosc.isEmpty())
        {
            QMessageBox::warning(this, "Błąd", "Wypełnij wszystkie wymagane pola!");
            return;
        }
        for (const QChar &ch : wprowadzonaWartosc)
        {
            if (!ch.isLetter() && ch != ' ')
            {
                    if(i==2)
                    {
                        QMessageBox::warning(this, "Błąd", "Wprowadz poprawne imie!");
                        ui->lineEdit_imie->setFocus();
                        return;
                    }
                    else if(i==3)
                    {
                        QMessageBox::warning(this, "Błąd", "Wprowadz poprawne nazwisko!");
                        ui->lineEdit_nazwisko->setFocus();
                        return;
                    }
                    else if(i==4)
                    {
                        if (!wprowadzonaWartosc.contains("@") || !wprowadzonaWartosc.contains(".") || wprowadzonaWartosc.length() < 5)
                        {
                            QMessageBox::warning(this, "Błąd", "Podaj poprawny adres email!");
                            ui->lineEdit_adres_email->setFocus();
                            return;
                        }
                    }
                }
        }
        if(i == 5) // Numer telefonu
        {
            if(wprowadzonaWartosc.length() < 9)
            {
                QMessageBox::warning(this, "Błąd", "Numer telefonu musi mieć co najmniej 9 cyfr!");
                ui->lineEdit_numer_telefonu->setFocus();
                return;
            }
            for (const QChar &ch : wprowadzonaWartosc)
            {
                if (!ch.isDigit() && ch != ' ' && ch != '-')
                {
                    QMessageBox::warning(this, "Błąd", "Numer telefonu może zawierać tylko cyfry, spacje i myślniki!");
                    ui->lineEdit_numer_telefonu->setFocus();
                    return;
                }
            }
        }

    }

    //przypisanie wartosci do zapytania
    for (auto it = dane.begin(); it != dane.end(); ++it)
    {
        query.bindValue(":" + it.key(), it.value());
    }

    //sprawdzenie zapytania
    if (query.exec())
    {QMessageBox::information(this, "Sukces", "Utworzono konto");}
    else
    {QMessageBox::critical(this, "Błąd", "Rejestracja nieudana");}

    obsluzPrzycisk(0);
    QSqlDatabase::database().commit();
    DB_Connection.close();

}
