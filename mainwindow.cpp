#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL", "1");
    db.setHostName("localhost");
    db.setDatabaseName("postgres");
    db.setUserName("postgres");
    db.setPassword("SyncMaster940n");
    db.open();

    model = new QSqlTableModel(this, db);
    model->setTable("Соревнование");
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(5, true);
    ui->tableView->resizeColumnsToContents();
    connect(this, &MainWindow::Pl_sg, &place_inf, &Place_Inf::Pl_slot);
    connect(this, &MainWindow::Tr_Uch_sg, &tr_uch_inf, &Tr_Uch_Inf::Tr_Uch_slot);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Place_Inf_clicked()
{
    place_inf.show();
    int Pl_id = ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(), 5).data().toInt();
    emit Pl_sg(Pl_id);
}


void MainWindow::on_Tr_Uch_Inf_clicked()
{
    tr_uch_inf.show();
    int Comp_id = ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(), 0).data().toInt();
    emit Tr_Uch_sg(Comp_id);
}


void MainWindow::on_AddInf_clicked()
{
    xxxaddplace = new xxxAddPlace;
    xxxaddplace->setWindowModality(Qt::ApplicationModal);
    xxxaddplace->setAttribute(Qt::WA_DeleteOnClose);
    xxxaddplace->show();
}


void MainWindow::on_DelInf_clicked()
{
    int Place_id = ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(), 5).data().toInt();
    QSqlQuery query3(QSqlDatabase::database("1"));
    query3.exec(QString("DELETE FROM \"Место\" WHERE \"id\" = %1").arg(Place_id));
    model->select();
}


void MainWindow::on_Close_clicked()
{
    this->close();
}



void MainWindow::on_Refresh_clicked()
{
    model->select();
}

