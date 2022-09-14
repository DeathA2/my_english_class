#include "addexam.h"
#include "ui_addexam.h"
#include "exam.h"
#include "mainwindow.h"

AddExam::AddExam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddExam)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/new/icon/img/dictionary.png"));
    ui->error->setHidden(true);
    ui->back->setHidden(true);
    ui->next->setHidden(true);
    ui->finish->setHidden(true);
    ui->delete_2->setHidden(true);
    ui->plainTextEdit->setHidden(true);
    ui->scrollArea->setHidden(true);
    ui->answerA_2->setHidden(true);
    ui->answerB_2->setHidden(true);
    ui->answerC_2->setHidden(true);
    ui->answerD_2->setHidden(true);
    ui->rightA->setHidden(true);
    ui->rightB->setHidden(true);
    ui->rightC->setHidden(true);
    ui->rightD->setHidden(true);

    ui->verticalLayoutWidget_2->setStyleSheet("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(0, 0, 0, 0));border-width : 0px;");
    ui->verticalLayoutWidget->setStyleSheet("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(0, 0, 0, 0));border-width : 0px;");

    QString CODE[36]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","0","1","2","3","4","5","6","7","8","9"};
    int chuthu1 = QRandomGenerator::global()->bounded(0,25);
    int chuthu2 = QRandomGenerator::global()->bounded(0,35);
    int chuthu3 = QRandomGenerator::global()->bounded(0,35);
    int chuthu4 = QRandomGenerator::global()->bounded(0,35);
    ui->code->setText(CODE[chuthu1]+CODE[chuthu2]+CODE[chuthu3]+CODE[chuthu4]);

    MainWindow main;
    main.opend();

    QSqlQuery qry;
    qry.prepare("select UserAccount from Account1 where State = '1'");
    if (qry.exec())
        while(qry.next())
        {
            ui->userAccoung->setText(qry.value(0).toString());
        }
    main.closed();

    QDateTime date;
    date = QDateTime::currentDateTime();
    ui->dateTimeEdit->setDateTime(date);

    ui->cau1->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
}

AddExam::~AddExam()
{
    delete ui;
}

void AddExam::question(int stt, int stt_next)
{
    switch (stt) {
    case 1:
        ui->cau1->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 2:
        ui->cau2->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 3:
        ui->cau3->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 4:
        ui->cau4->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 5:
        ui->cau5->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 6:
        ui->cau6->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 7:
        ui->cau7->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 8:
        ui->cau8->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 9:
        ui->cau9->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 10:
        ui->cau10->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 11:
        ui->cau11->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 12:
        ui->cau12->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 13:
        ui->cau13->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 14:
        ui->cau14->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 15:
        ui->cau15->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 16:
        ui->cau16->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 17:
        ui->cau17->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 18:
        ui->cau18->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 19:
        ui->cau19->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 20:
        ui->cau20->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 21:
        ui->cau21->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 22:
        ui->cau22->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 23:
        ui->cau23->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 24:
        ui->cau24->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 25:
        ui->cau25->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 26:
        ui->cau26->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 27:
        ui->cau27->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 28:
        ui->cau28->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 29:
        ui->cau29->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 30:
        ui->cau30->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 31:
        ui->cau31->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 32:
        ui->cau32->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 33:
        ui->cau33->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 34:
        ui->cau34->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 35:
        ui->cau35->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 36:
        ui->cau36->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 37:
        ui->cau37->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 38:
        ui->cau38->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 39:
        ui->cau39->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    case 40:
        ui->cau40->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
        break;
    }
    switch (stt_next) {
    case 1:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau1->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 2:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau2->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 3:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau3->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 4:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau4->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 5:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau5->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 6:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau6->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 7:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau7->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 8:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau8->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 9:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau9->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 10:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau10->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 11:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau11->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 12:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau12->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 13:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau13->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 14:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau14->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 15:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau15->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 16:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau16->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 17:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau17->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 18:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau18->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 19:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau19->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 20:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau20->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 21:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau21->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 22:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau22->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 23:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau23->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 24:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau24->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 25:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau25->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 26:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau26->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 27:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau27->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 28:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau28->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 29:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau29->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 30:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau30->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 31:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau31->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 32:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau32->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 33:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau33->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 34:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau34->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 35:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau35->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 36:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau36->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 37:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau37->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 38:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau38->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 39:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau39->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    case 40:
        if (ui->plainTextEdit->toPlainText() != "" &&
                ui->answerA_2->text() != "" &&
                ui->answerB_2->text() != "" &&
                ui->answerC_2->text() != "" &&
                ui->answerD_2->text() != "" )
            if (ui->rightA->isChecked() || ui->rightB->isChecked() || ui->rightC->isChecked() || ui->rightD->isChecked())
                ui->cau40->setStyleSheet("font: bold; color: rgb(0, 255, 0);");
        break;
    }


}

void AddExam::on_next_clicked()
{
    Exam exam;
    exam.openexam();
    QSqlQuery qry;

    QString Question, AnswerA, AnswerB, AnswerC, AnswerD, RightAnswer="";
    Question = ui->plainTextEdit->toPlainText();
    AnswerA = ui->answerA_2->text();
    AnswerB = ui->answerB_2->text();
    AnswerC = ui->answerC_2->text();
    AnswerD = ui->answerD_2->text();

        if (ui->rightA->isChecked())
            RightAnswer = "A";
        else if (ui->rightB->isChecked())
            RightAnswer = "B";
        else if (ui->rightC->isChecked())
            RightAnswer = "C";
        else if (ui->rightD->isChecked())
            RightAnswer = "D";

    qry.prepare("update "+ui->code->text()+" set Question ='"+Question+"', A = '"+AnswerA+"', B = '"+AnswerB+"', C = '"+AnswerC+"', D = '"+AnswerD+"', RightAnswer = '"+RightAnswer+"' where STT = '"+QString::number(STT)+"' ");
    qry.exec();

    STT++;
    int tam =STT -1;
    question(STT, tam);

    if (STT ==40)
        ui->next->setHidden(true);
    else
        ui->next->setHidden(false);

    if (STT ==1)
        ui->back->setHidden(true);
    else
        ui->back->setHidden(false);

    qry.prepare("select * from "+ui->code->text()+" where STT = '"+QString::number(STT)+"' ");
    if (qry.exec())
    {
        while(qry.next())
        {
            ui->plainTextEdit->setPlainText(qry.value(1).toString());
            ui->answerA_2->setText(qry.value(2).toString());
            ui->answerB_2->setText(qry.value(3).toString());
            ui->answerC_2->setText(qry.value(4).toString());
            ui->answerD_2->setText(qry.value(5).toString());
            if (qry.value(6).toString() == "A")
                ui->rightA->setChecked(true);
            else if (qry.value(6).toString() == "B")
                ui->rightB->setChecked(true);
            else if (qry.value(6).toString() == "C")
                ui->rightC->setChecked(true);
            else if (qry.value(6).toString() == "D")
                ui->rightD->setChecked(true);

        }
    }
}


void AddExam::on_back_clicked()
{

    Exam exam;

    exam.openexam();
    QSqlQuery qry;

    QString Question, AnswerA, AnswerB, AnswerC, AnswerD, RightAnswer="";
    Question = ui->plainTextEdit->toPlainText();
    AnswerA = ui->answerA_2->text();
    AnswerB = ui->answerB_2->text();
    AnswerC = ui->answerC_2->text();
    AnswerD = ui->answerD_2->text();

        if (ui->rightA->isChecked())
            RightAnswer = "A";
        else if (ui->rightB->isChecked())
            RightAnswer = "B";
        else if (ui->rightC->isChecked())
            RightAnswer = "C";
        else if (ui->rightD->isChecked())
            RightAnswer = "D";
    qry.prepare("update "+ui->code->text()+" set Question ='"+Question+"', A = '"+AnswerA+"', B = '"+AnswerB+"', C = '"+AnswerC+"', D = '"+AnswerD+"', RightAnswer = '"+RightAnswer+"' where STT = '"+QString::number(STT)+"' ");
    qry.exec();

    STT--;
    int tam =STT +1;
    question(STT, tam);
    if (STT ==1)
        ui->back->setHidden(true);
    else
        ui->back->setHidden(false);
    if (STT ==40)
        ui->next->setHidden(true);
    else
        ui->next->setHidden(false);


    qry.prepare("select * from "+ui->code->text()+" where STT = '"+QString::number(STT)+"' ");
    if (qry.exec())
    {
        while(qry.next())
        {
            ui->plainTextEdit->setPlainText(qry.value(1).toString());
            ui->answerA_2->setText(qry.value(2).toString());
            ui->answerB_2->setText(qry.value(3).toString());
            ui->answerC_2->setText(qry.value(4).toString());
            ui->answerD_2->setText(qry.value(5).toString());
            if (qry.value(6).toString() == "A")
                ui->rightA->setChecked(true);
            else if (qry.value(6).toString() == "B")
                ui->rightB->setChecked(true);
            else if (qry.value(6).toString() == "C")
                ui->rightC->setChecked(true);
            else if (qry.value(6).toString() == "D")
                ui->rightD->setChecked(true);
        }
    }

}


void AddExam::on_save_clicked()
{
    if (ui->examName->text() == "")
    {
        ui->error->setHidden(false);
    }
    else
    {
    ui->back->setHidden(false);
    ui->next->setHidden(false);
    ui->finish->setHidden(false);
    ui->delete_2->setHidden(false);
    ui->plainTextEdit->setHidden(false);
    ui->scrollArea->setHidden(false);
    ui->answerA_2->setHidden(false);
    ui->answerB_2->setHidden(false);
    ui->answerC_2->setHidden(false);
    ui->answerD_2->setHidden(false);
    ui->rightA->setHidden(false);
    ui->rightB->setHidden(false);
    ui->rightC->setHidden(false);
    ui->rightD->setHidden(false);

    ui->save->setHidden(true);
    ui->close->setHidden(true);
    ui->groupBox_2->setHidden(true);

    ui->answerA_2->setPlaceholderText("A.");
    ui->answerB_2->setPlaceholderText("B.");
    ui->answerC_2->setPlaceholderText("C.");
    ui->answerD_2->setPlaceholderText("D.");

        Exam exam;
        exam.openexam();
        QString query= "CREATE TABLE "+ui->code->text()+" ("
                       "STT integer PRIMARY KEY,"
                       "Question VARCHAR(1000),"
                       "A VARCHAR(1000),"
                       "B VARCHAR(1000),"
                       "C VARCHAR(1000),"
                       "D VARCHAR(1000),"
                       "RightAnswer VARCHAR(1));";
        QSqlQuery qry,qry1;
        if (!qry.exec(query))
        {
            qDebug() << "error";
        }
        for (int j =1; j<=40; j++){
            qry1.prepare("insert into "+ui->code->text()+" (STT,Question,A,B,C,D,RightAnswer) values ('"+QString::number(j)+"','""', '""','""','""','""','""')");
            qry1.exec();
        }

        if (STT == 1)
            ui->back->setHidden(true);
        else if (STT == 40)
            ui->next->setHidden(true);
    }
}


void AddExam::on_close_clicked()
{
    this->close();
}


void AddExam::on_finish_clicked()
{
    Exam exam;

    exam.openexam();
    QSqlQuery qry,qryList;

    QString Question, AnswerA, AnswerB, AnswerC, AnswerD, RightAnswer="";
    Question = ui->plainTextEdit->toPlainText();
    AnswerA = ui->answerA_2->text();
    AnswerB = ui->answerB_2->text();
    AnswerC = ui->answerC_2->text();
    AnswerD = ui->answerD_2->text();

        if (ui->rightA->isChecked())
            RightAnswer = "A";
        else if (ui->rightB->isChecked())
            RightAnswer = "B";
        else if (ui->rightC->isChecked())
            RightAnswer = "C";
        else if (ui->rightD->isChecked())
            RightAnswer = "D";
    qry.prepare("update "+ui->code->text()+" set Question ='"+Question+"', A = '"+AnswerA+"', B = '"+AnswerB+"', C = '"+AnswerC+"', D = '"+AnswerD+"', RightAnswer = '"+RightAnswer+"' where STT = '"+QString::number(STT)+"' ");
    qry.exec();

    QMessageBox::StandardButton reply = QMessageBox::question(this,"Save","Are you ready to save this exam!!!",QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {

        if(ui->hideName->isChecked())
            ui->userAccoung->setText("Anonymous");
        qryList.prepare("insert into ListExam (CODE,NameExam,UserName,Date) values ('"+ui->code->text()+"','"+ui->examName->text()+"','"+ui->userAccoung->text()+"','"+ui->dateTimeEdit->text()+"')");
        qryList.exec();
        QMessageBox::about(this,"Save","Saved");
        exam.closedexam();
        this->close();
    }

}


void AddExam::on_delete_2_clicked()
{
    Exam exam;

    exam.openexam();
    QSqlQuery qry;

    QMessageBox::StandardButton reply = QMessageBox::question(this,"Leave","You are leaving this!!!",QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        qry.prepare("DROP TABLE IF EXISTS "+ui->code->text()+"");
        qry.exec();
        QMessageBox::about(this,"Close","Closed");
        exam.closedexam();
        this->close();
    }
}


void AddExam::on_changecode_clicked()
{
    QString CODE[36]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","0","1","2","3","4","5","6","7","8","9"};
    int chuthu1 = QRandomGenerator::global()->bounded(0,25);
    int chuthu2 = QRandomGenerator::global()->bounded(0,35);
    int chuthu3 = QRandomGenerator::global()->bounded(0,35);
    int chuthu4 = QRandomGenerator::global()->bounded(0,35);
    ui->code->setText(CODE[chuthu1]+CODE[chuthu2]+CODE[chuthu3]+CODE[chuthu4]);
}

