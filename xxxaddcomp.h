#ifndef XXXADDCOMP_H
#define XXXADDCOMP_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <xxxaddtrener.h>
#include <QDate>

namespace Ui {
class xxxAddComp;
}

class xxxAddComp : public QDialog
{
    Q_OBJECT

public:
    explicit xxxAddComp(QWidget *parent = nullptr);
    ~xxxAddComp();

private slots:
    void on_Next_clicked();

    void on_Cancel_clicked();

private:
    Ui::xxxAddComp *ui;
    xxxAddTrener *xxxaddtrener;
};

#endif // XXXADDCOMP_H
