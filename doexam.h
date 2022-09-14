#ifndef DOEXAM_H
#define DOEXAM_H

#include <QDialog>
#include <QDebug>
#include <QtSql>
#include <QTimer>
#include <QMessageBox>

namespace Ui {
class DoExam;
}

class DoExam : public QDialog
{
    Q_OBJECT

public:
    explicit DoExam(QWidget *parent = nullptr);
    ~DoExam();
    QString Name,rightAnswer;
    int score = 0, uScore;
    int STT;
    int time=0;
    int minutes=0, second = 0;


    void rightmeme();
    void wrongmeme();

private slots:
    void Timer();

    void displayBtnNumber(int i, bool answer);

    void displayQuesWhenClickBtn(int i);

    void displayBtnState(int i, bool b);

    void on_answerA_clicked();

    void on_answerB_clicked();

    void on_answerC_clicked();

    void on_answerD_clicked();

    void on_next_clicked();

    void on_cau1_clicked();

    void on_cau2_clicked();

    void on_cau3_clicked();

    void on_cau4_clicked();

    void on_cau5_clicked();

    void on_cau6_clicked();

    void on_cau7_clicked();

    void on_cau8_clicked();

    void on_cau9_clicked();

    void on_cau10_clicked();

    void on_cau11_clicked();

    void on_cau12_clicked();

    void on_cau13_clicked();

    void on_cau14_clicked();

    void on_cau15_clicked();

    void on_cau16_clicked();

    void on_cau17_clicked();

    void on_cau18_clicked();

    void on_cau19_clicked();

    void on_cau20_clicked();

    void on_cau21_clicked();

    void on_cau22_clicked();

    void on_cau23_clicked();

    void on_cau24_clicked();

    void on_cau25_clicked();

    void on_cau26_clicked();

    void on_cau27_clicked();

    void on_cau28_clicked();

    void on_cau29_clicked();

    void on_cau30_clicked();

    void on_cau31_clicked();

    void on_cau32_clicked();

    void on_cau33_clicked();

    void on_cau34_clicked();

    void on_cau35_clicked();

    void on_cau36_clicked();

    void on_cau37_clicked();

    void on_cau38_clicked();

    void on_cau39_clicked();

    void on_cau40_clicked();

    void SaveScore();

    void on_pushButton_clicked();

private:
    Ui::DoExam *ui;
    QTimer *timer;
    QDateTime date;

};

#endif // DOEXAM_H
