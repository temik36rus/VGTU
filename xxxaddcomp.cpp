#include "xxxaddcomp.h"
#include "ui_xxxaddcomp.h"

xxxAddComp::xxxAddComp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::xxxAddComp)
{
    ui->setupUi(this);
}

xxxAddComp::~xxxAddComp()
{
    delete ui;
}

void xxxAddComp::on_Next_clicked()
{
    if (!ui->lineEdit->text().isEmpty() && !ui->lineEdit_2->text().isEmpty() && !ui->lineEdit_3->text().isEmpty() && !ui->lineEdit_4->text().isEmpty())
    {
        QString Name = ui->lineEdit->text(),
                Level = ui->lineEdit_2->text(),
                Org = ui->lineEdit_3->text();
        QDate Date = QDate::fromString(ui->lineEdit_4->text(), "dd.MM.yyyy");

        QSqlQuery query(QSqlDatabase::database("1")), query2(QSqlDatabase::database("1"));
        query.exec(QString("SELECT MAX(\"id\") FROM \"Место\""));
        query.first();
        int Pl_id = query.value(0).toInt();

        query2.prepare(QString("INSERT INTO \"Соревнование\" (\"Дисциплина\", \"Уровень\", \"Организатор\", \"Дата проведения\", \"Место_id\")" "VALUES (:Name, :Level, :Org, :Date, :Pl_id)"));
        query2.bindValue(":Name", Name);
        query2.bindValue(":Level", Level);
        query2.bindValue(":Org", Org);
        query2.bindValue(":Date", Date);
        query2.bindValue(":Pl_id", Pl_id);
        if (!query2.exec())
            {
                QMessageBox::warning(this, "Error", "Ошибка в типе заполняемых данных");
            }
        else
            {
                xxxaddtrener = new xxxAddTrener;
                xxxaddtrener->setModal(true);
                xxxaddtrener->setAttribute(Qt::WA_DeleteOnClose);
                this->close();
                xxxaddtrener->show();
            }
    }
    else
    {
            QMessageBox::warning(this, "Error", "Заполните все поля");
    }
}


void xxxAddComp::on_Cancel_clicked()
{
    QSqlQuery query3(QSqlDatabase::database("1"));
    query3.exec(QString("DELETE FROM \"Место\" WHERE \"id\" = (SELECT MAX(\"id\") FROM \"Место\")"));
    this->close();
}

