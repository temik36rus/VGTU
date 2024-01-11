#ifndef XXXADDPLACE_H
#define XXXADDPLACE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlTableModel>
#include <xxxaddcomp.h>


namespace Ui {
class xxxAddPlace;
}

class xxxAddPlace : public QDialog
{
    Q_OBJECT

public:
    explicit xxxAddPlace(QWidget *parent = nullptr);
    ~xxxAddPlace();

private slots:
    void on_Next_clicked();

    void on_Cancel_clicked();

private:
    Ui::xxxAddPlace *ui;
    xxxAddComp *xxxaddcomp;
    QSqlTableModel *model;
};

#endif // XXXADDPLACE_H
