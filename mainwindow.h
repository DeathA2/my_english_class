#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QMovie>
#include <QTimer>
#include <QRandomGenerator>
#include <QDesktopWidget>
#include <QScreen>
#include <QApplication>
#include <QSettings>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlDatabase mydb;

    bool opend(){
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("D:/Project/QT/EnglishClass/database/Account.db");

        if(!mydb.open()){
            qDebug()<<"Failed to connect the database!!!";
            return false;
        }
        else{
            qDebug()<<"Successful to connect the database!!!";
            return true;}
    };
    void closed(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    };

    void loadSetting();
    void saveSetting();

private slots:
    void on_signUpBtn_clicked();

    void on_signInBtn_clicked();

    void loading();

    void loadinggif();

    void on_pass_returnPressed();

private:
    Ui::MainWindow *ui;
    QTimer *timer;

};
#endif // MAINWINDOW_H
