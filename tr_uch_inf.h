#ifndef TR_UCH_INF_H
#define TR_UCH_INF_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>

namespace Ui {
class Tr_Uch_Inf;
}

class Tr_Uch_Inf : public QDialog
{
    Q_OBJECT

public:
    explicit Tr_Uch_Inf(QWidget *parent = nullptr);
    ~Tr_Uch_Inf();
public slots:
    void Tr_Uch_slot(int id);

private slots:
    void on_tableView_clicked();

    void on_close_clicked();

private:
    Ui::Tr_Uch_Inf *ui;
    QSqlTableModel *model, *model2;
};

#endif // TR_UCH_INF_H
