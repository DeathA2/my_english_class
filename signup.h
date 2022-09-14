#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "mainwindow.h"


namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

private slots:

    void on_checkBoxPass_clicked();

    void on_Save_clicked();

    void on_Close_clicked();

    void on_checkBoxRePass_clicked();

private:
    Ui::SignUp *ui;

};

#endif // SIGNUP_H
