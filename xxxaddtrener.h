#ifndef XXXADDTRENER_H
#define XXXADDTRENER_H


#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlTableModel>
#include <xxxadduch.h>

namespace Ui {
class xxxAddTrener;
}

class xxxAddTrener : public QDialog
{
    Q_OBJECT

public:
    explicit xxxAddTrener(QWidget *parent = nullptr);
    ~xxxAddTrener();

private slots:
    void on_Cancel_clicked();

    void on_AddTrener_clicked();

    void on_Next_clicked();

private:
    Ui::xxxAddTrener *ui;
    xxxAddUch *xxxadduch;
    QSqlTableModel *model;
};

#endif // XXXADDTRENER_H
