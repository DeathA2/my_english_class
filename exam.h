#ifndef EXAM_H
#define EXAM_H

#include <QDialog>
#include <QtSql>



namespace Ui {
class Exam;
}

class Exam : public QDialog
{
    Q_OBJECT

public:
    explicit Exam(QWidget *parent = nullptr);
    ~Exam();
    QSqlDatabase dbexam;

    bool openexam(){
        dbexam = QSqlDatabase::addDatabase("QSQLITE");
        dbexam.setDatabaseName("D:/Project/QT/EnglishClass/database/exam.db");

        if(!dbexam.open()){
            qDebug()<<"False";
            return false;
        }
        else{
            qDebug()<<"Rồi đó";
            return true;}
    };
    void closedexam(){
        dbexam.close();
        dbexam.removeDatabase(QSqlDatabase::defaultConnection);
    };

private slots:
    void on_pushButton_8_clicked();

    void on_home_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_no_clicked();

    void on_yes_clicked();

    void on_lineEdit_returnPressed();

private:
    Ui::Exam *ui;
    QSqlQueryModel *elist, *slist;
};

#endif // EXAM_H
