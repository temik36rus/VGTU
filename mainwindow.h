#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlTableModel>
#include <place_inf.h>
#include <tr_uch_inf.h>
#include <xxxaddplace.h>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void  Pl_sg(int id);
    void  Tr_Uch_sg(int id);

private slots:
    void on_Place_Inf_clicked();

    void on_Tr_Uch_Inf_clicked();

    void on_AddInf_clicked();

    void on_Close_clicked();

    void on_DelInf_clicked();

    void on_Refresh_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;
    Place_Inf place_inf;
    Tr_Uch_Inf tr_uch_inf;
    xxxAddPlace *xxxaddplace;
};
#endif // MAINWINDOW_H
