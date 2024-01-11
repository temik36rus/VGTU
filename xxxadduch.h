#ifndef XXXADDUCH_H
#define XXXADDUCH_H


#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlTableModel>


namespace Ui {
class xxxAddUch;
}

class xxxAddUch : public QDialog
{
    Q_OBJECT

public:
    explicit xxxAddUch(QWidget *parent = nullptr);
    ~xxxAddUch();

private slots:
    void on_Cancel_clicked();

    void on_tableView_clicked();

    void on_AddUch_clicked();

    void on_Save_clicked();

private:
    Ui::xxxAddUch *ui;
    QSqlTableModel *model, *model2;
};

#endif // XXXADDUCH_H
