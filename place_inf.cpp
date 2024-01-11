#include "place_inf.h"
#include "ui_place_inf.h"

Place_Inf::Place_Inf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Place_Inf)
{
    ui->setupUi(this);
}


Place_Inf::~Place_Inf()
{
    delete ui;
}


void Place_Inf::Pl_slot(int id)
{
    model = new QSqlTableModel(this, QSqlDatabase::database("1"));
    model->setTable("Место");
    model->setFilter(QString("\"id\" = %1").arg(id));
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->resizeColumnsToContents();
}


void Place_Inf::on_close_clicked()
{
    this->close();
}

