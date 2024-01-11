#include "xxxaddplace.h"
#include "ui_xxxaddplace.h"

xxxAddPlace::xxxAddPlace(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::xxxAddPlace)
{
    ui->setupUi(this);
}

xxxAddPlace::~xxxAddPlace()
{
    delete ui;
}

void xxxAddPlace::on_Next_clicked()
{

        if (!ui->lineEdit->text().isEmpty() && !ui->lineEdit_2->text().isEmpty())
        {
            QString Name = ui->lineEdit->text(),
                    Address = ui->lineEdit_2->text(),
                    Room = ui->comboBox->currentText();

            QSqlQuery query(QSqlDatabase::database("1"));
            query.prepare(QString("INSERT INTO \"Место\" (\"Название\", \"Адрес\", \"Наличие жилья участникам\")" "VALUES (:Name, :Address, :Room)"));
            query.bindValue(":Name", Name);
            query.bindValue(":Address", Address);
            query.bindValue(":Room", Room);
            if (!query.exec())
                {
                    QMessageBox::warning(this, "Error", query.lastError().text());
                }
            else
                {
                    xxxaddcomp = new xxxAddComp;
                    xxxaddcomp->setModal(true);
                    xxxaddcomp->setAttribute(Qt::WA_DeleteOnClose);
                    this->close();
                    xxxaddcomp->show();
                }
        }
        else
        {
                QMessageBox::warning(this, "Error", "Заполните все необходимые поля");
        }
}


void xxxAddPlace::on_Cancel_clicked()
{
    this->close();
}

