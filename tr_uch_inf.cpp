#include "tr_uch_inf.h"
#include "ui_tr_uch_inf.h"

Tr_Uch_Inf::Tr_Uch_Inf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tr_Uch_Inf)
{
    ui->setupUi(this);
}


Tr_Uch_Inf::~Tr_Uch_Inf()
{
    delete ui;
}


void Tr_Uch_Inf::Tr_Uch_slot(int id)
{
    model = new QSqlTableModel(this, QSqlDatabase::database("1"));
    model->setTable("Тренер");
    model->setFilter(QString("\"Соревн_id\" = %1").arg(id));
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(4, true);
    ui->tableView->resizeColumnsToContents();

    model2 = new QSqlTableModel(this, QSqlDatabase::database("1"));
    ui->tableView_2->setModel(model2);
}


void Tr_Uch_Inf::on_tableView_clicked()
{
    int Tr_id = ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(), 0).data().toInt();

    model2->setTable("Участник");
    model2->setFilter(QString("\"Тренер_id\" = %1").arg(Tr_id));
    model2->select();
    ui->tableView_2->setColumnHidden(0, true);
    ui->tableView_2->setColumnHidden(5, true);
    ui->tableView_2->resizeColumnsToContents();
}


void Tr_Uch_Inf::on_close_clicked()
{
    this->close();
}

