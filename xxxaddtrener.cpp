#include "xxxaddtrener.h"
#include "ui_xxxaddtrener.h"

xxxAddTrener::xxxAddTrener(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::xxxAddTrener)
{
    ui->setupUi(this);

    QSqlQuery query4(QSqlDatabase::database("1"));
    query4.exec("SELECT MAX(\"id\") FROM \"Соревнование\"");
    query4.first();
    int Comp_id = query4.value(0).toInt();

    model = new QSqlTableModel(this, QSqlDatabase::database("1"));
    model->setTable("Тренер");
    model->setFilter(QString("\"Соревн_id\" = %1").arg(Comp_id));
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(4, true);
    ui->tableView->resizeColumnsToContents();
    ui->lineEdit_3->setInputMask("99");
}

xxxAddTrener::~xxxAddTrener()
{
    delete ui;
}


void xxxAddTrener::on_AddTrener_clicked()
{
    if (!ui->lineEdit->text().isEmpty() && !ui->lineEdit_2->text().isEmpty())
    {
        QString FIO = ui->lineEdit->text(),
                Org = ui->lineEdit_2->text();
        int Exp = ui->lineEdit_3->text().toInt();

        QSqlQuery query(QSqlDatabase::database("1")), query2(QSqlDatabase::database("1"));
        query.exec("SELECT MAX(\"id\") FROM \"Соревнование\"");
        query.first();
        int Comp_id = query.value(0).toInt();

        query2.prepare(QString("INSERT INTO \"Тренер\" (\"ФИО\", \"Организация\", \"Стаж\", \"Соревн_id\")" "VALUES (:FIO, :Org, :Exp, :Comp_id)"));
        query2.bindValue(":FIO", FIO);
        query2.bindValue(":Org", Org);
        query2.bindValue(":Exp", Exp);
        query2.bindValue(":Comp_id", Comp_id);
        if (!query2.exec())
        {
            QMessageBox::warning(this, "Error", "Что-то пошло не так, введите данные заново");
        }
        else
        {
            model->select();
        }
    }
    else
    {
        QMessageBox::warning(this, "Error", "Заполните все необходимые поля");
    }
}


void xxxAddTrener::on_Next_clicked()
{
    xxxadduch = new xxxAddUch;
    xxxadduch->setModal(true);
    xxxadduch->setAttribute(Qt::WA_DeleteOnClose);
    this->close();
    xxxadduch->show();
}


void xxxAddTrener::on_Cancel_clicked()
{
    QSqlQuery query3(QSqlDatabase::database("1"));
    query3.exec(QString("DELETE FROM \"Место\" WHERE \"id\" = (SELECT MAX(\"id\") FROM \"Место\")"));
    this->close();
}
