#ifndef STORE_H
#define STORE_H

#include <QDialog>
#include <QMessageBox>
#include "mainwindow.h"
#include "mainscreen.h"

namespace Ui {
class Store;
}

class Store : public QDialog
{
    Q_OBJECT

public:
    explicit Store(QWidget *parent = nullptr);
    ~Store();
    int totalScore;
    QString Name;

private slots:
    bool ThanhToan(QString price);

    void on_home_clicked();

    void on_left1_clicked();

    void on_left5_clicked();

    void on_left2_clicked();

    void on_left3_clicked();

    void on_left4_clicked();

    void on_right3_clicked();

    void on_right4_clicked();

    void on_right2_clicked();

    void on_right1_clicked();

    void on_mid_clicked();

private:
    Ui::Store *ui;
};

#endif // STORE_H
