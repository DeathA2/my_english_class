#ifndef ADDEXAM_H
#define ADDEXAM_H

#include <QDialog>
#include <QDebug>
#include <QRandomGenerator>
#include <QDateTime>
#include <QMessageBox>

namespace Ui {
class AddExam;
}

class AddExam : public QDialog
{
    Q_OBJECT

public:
    int STT = 1;
    explicit AddExam(QWidget *parent = nullptr);
    ~AddExam();
    void question(int stt, int stt_next);

private slots:
    void on_next_clicked();

    void on_back_clicked();

    void on_save_clicked();

    void on_close_clicked();

    void on_finish_clicked();

    void on_delete_2_clicked();

    void on_changecode_clicked();

private:
    Ui::AddExam *ui;
};

#endif // ADDEXAM_H
