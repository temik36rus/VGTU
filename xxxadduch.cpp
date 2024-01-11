#include "xxxadduch.h"
#include "ui_xxxadduch.h"

xxxAddUch::xxxAddUch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::xxxAddUch)
{
    ui->setupUi(this);

    QSqlQuery query(QSqlDatabase::database("1"));
    query.exec(QString("SELECT MAX(\"id\") FROM \"Соревнование\""));
    query.first();
    int Comp_id = query.value(0).toInt();

    model = new QSqlTableModel(this, QSqlDatabase::database("1"));
    model->setTable("Тренер");
    model->setFilter(QString("\"Соревн_id\" = %1").arg(Comp_id));
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(4, true);
    ui->tableView->resizeColumnsToContents();
}

xxxAddUch::~xxxAddUch()
{
    delete ui;
}


void xxxAddUch::on_tableView_clicked()
{
    int Tr_id = ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(), 0).data().toInt();

    model2 = new QSqlTableModel(this, QSqlDatabase::database("1"));
    model2->setTable("Участник");
    model2->setFilter(QString("\"Тренер_id\" = %1").arg(Tr_id));
    model2->select();
    ui->tableView_2->setModel(model2);
    ui->tableView_2->setColumnHidden(0, true);
    ui->tableView_2->setColumnHidden(5, true);
    ui->tableView_2->resizeColumnsToContents();
}


void xxxAddUch::on_AddUch_clicked()
{
    if (!ui->lineEdit->text().isEmpty() && !ui->comboBox->currentText().isEmpty() && !ui->lineEdit_3->text().isEmpty())
    {
        QString FIO = ui->lineEdit->text(),
                Gender = ui->comboBox->currentText(),
                Skill = ui->lineEdit_4->text();
        int Age = ui->lineEdit_3->text().toInt();
        int Tr_id = ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(), 0).data().toInt();

        QSqlQuery query2(QSqlDatabase::database("1"));
        query2.prepare(QString("INSERT INTO \"Участник\" (\"ФИО\", \"Пол\", \"Возраст\", \"Разряд\", \"Тренер_id\")" "VALUES (:FIO, :Gender, :Age, :Skill, :Tr_id)"));
        query2.bindValue(":FIO", FIO);
        query2.bindValue(":Gender", Gender);
        query2.bindValue(":Age", Age);
        query2.bindValue(":Skill", Skill);
        query2.bindValue(":Tr_id", Tr_id);
        if (!query2.exec())
        {
            QMessageBox::warning(this, "Error", "Что-то пошло не так, введите данные заново");
        }
        else
        {
            model2->select();
        }
    }
    else
    {
        QMessageBox::warning(this, "Error", "Заполните все необходимые поля");
    }
}


void xxxAddUch::on_Save_clicked()
{
    this->close();
}


void xxxAddUch::on_Cancel_clicked()
{
    QSqlQuery query3(QSqlDatabase::database("1"));
    query3.exec(QString("DELETE FROM \"Место\" WHERE \"id\" = (SELECT MAX(\"id\") FROM \"Место\")"));
    this->close();
}





