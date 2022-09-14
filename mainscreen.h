#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QDebug>
#include <QFileDialog>
#include <QSqlQueryModel>

namespace Ui {
class MainScreen;
}

class MainScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScreen(QWidget *parent = nullptr);
    ~MainScreen();
    QString userAccount;

private slots:
    void closeEdit();

    void on_study_clicked();

    void on_exam_clicked();

    void on_store_clicked();

    void on_edit_clicked();

    void on_save_clicked();

    void on_close_clicked();

    void on_addPic_clicked();

    void on_history_clicked();

    void on_close_2_clicked();

    void on_logout_clicked();

private:
    Ui::MainScreen *ui;
    QString Account;
    QString avatar_direction;
    QSqlQueryModel *hlist;
};

#endif // MAINSCREEN_H
