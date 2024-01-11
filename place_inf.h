#ifndef PLACE_INF_H
#define PLACE_INF_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>

namespace Ui {
class Place_Inf;
}

class Place_Inf : public QDialog
{
    Q_OBJECT

public:
    explicit Place_Inf(QWidget *parent = nullptr);
    ~Place_Inf();
public slots:
    void Pl_slot(int id);

private slots:


    void on_close_clicked();

private:
    Ui::Place_Inf *ui;
    QSqlTableModel *model;
};

#endif // PLACE_INF_H
