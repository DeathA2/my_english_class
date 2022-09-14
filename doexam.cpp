#include "doexam.h"
#include "ui_doexam.h"
#include "exam.h"
#include "mainwindow.h"

DoExam::DoExam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DoExam)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/new/icon/img/dictionary.png"));
    ui->textA->setEnabled(false);
    ui->textB->setEnabled(false);
    ui->textC->setEnabled(false);
    ui->textD->setEnabled(false);
    STT=1;
    MainWindow main;
    main.opend();
    QSqlQuery qry;
    qry.prepare("select * from Account1 where State = '1'");
    if (qry.exec())
        while(qry.next())
        {
            ui->name->setText(qry.value(1).toString());
            uScore = qry.value(11).toInt();
        }

    main.closed();
    ui->score->setText("0");
    ui->frame->setHidden(true);
    ui->question->setEnabled(false);
    Exam exam;
    exam.openexam();
    QSqlQuery qryExam,qryName;

    qryName.prepare("select * from ListExam where Doing = '1' ");
    if (qryName.exec()){
        while (qryName.next()){
            Name = qryName.value(0).toString();
            date = QDateTime::currentDateTime();
        }
    }
    qryExam.prepare("select * from "+Name+" where STT='"+QString::number(STT)+"'");
    if (qryExam.exec())
        while (qryExam.next()){
            ui->question->setPlainText(qryExam.value(1).toString());
            ui->textA->setPlainText(qryExam.value(2).toString());
            ui->textB->setPlainText(qryExam.value(3).toString());
            ui->textC->setPlainText(qryExam.value(4).toString());
            ui->textD->setPlainText(qryExam.value(5).toString());
            rightAnswer = qryExam.value(6).toString();
    }
    ui->cau1->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
    ui->time->setValue(time);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(Timer()));
    timer->start(1000);

}

DoExam::~DoExam()
{
    SaveScore();
    Exam exam;
    exam.openexam();
    QSqlQuery qrycheckable;
    qrycheckable.prepare("update ListExam set Doing = '0' where Doing = '1' ");
    qrycheckable.exec();
    exam.closedexam();
    delete ui;
}

void DoExam::rightmeme()
{
    QPixmap pix1;
    int n = QRandomGenerator::global()->bounded(1,6);
    switch (n) {
    case 1:{
        QPixmap pix1(":/new/image/img/ohgodyoureright.jpg");
        ui->label_3->setPixmap(pix1);
        break;
    }
    case 2:{
        QPixmap pix1(":/new/image/img/ohshityouare.jpg");
        ui->label_3->setPixmap(pix1);
        break;
    }
    case 3:{
        QPixmap pix1(":/new/image/img/thatsright5c378e.jpg");
        ui->label_3->setPixmap(pix1);
        break;
    }
    case 4:{
        QPixmap pix1(":/new/image/img/correctt.jpg");
        ui->label_3->setPixmap(pix1);
        break;
    }
    case 5:{
        QPixmap pix1(":/new/image/img/correct.jpg");
        ui->label_3->setPixmap(pix1);
        break;
    }
    case 6:
        QPixmap pix6(":/new/image/img/correct5aced0.jpg");
        ui->label_3->setPixmap(pix1);
        break;
    }

}

void DoExam::wrongmeme()
{
    QPixmap pix2;
    int n = QRandomGenerator::global()->bounded(1,3);
    switch (n) {
    case 1:{
        QPixmap pix2(":/new/image/img/wrong.jpg");
        ui->label_3->setPixmap(pix2);
        break;
    }
    case 2:{
        QPixmap pix2(":/new/image/img/wrong_2.jpg");
        ui->label_3->setPixmap(pix2);
        break;
    }
    case 3:{
        QPixmap pix2(":/new/image/img/wrongg.jpg");
        ui->label_3->setPixmap(pix2);
        break;
    }
    }
}

void DoExam::Timer()
{

    second++;
    time++;
    if (second == 60){
        second = 0;
        minutes++;
    }
    ui->time->setValue(time);

}

void DoExam::displayBtnNumber(int i, bool answer)
{
    if (answer)
        switch (i) {
        case 1:
            ui->cau1->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau1->setEnabled(false);
            break;
        case 2:
            ui->cau2->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau2->setEnabled(false);
            break;
        case 3:
            ui->cau3->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau3->setEnabled(false);
            break;
        case 4:
            ui->cau4->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau4->setEnabled(false);
            break;
        case 5:
            ui->cau5->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau5->setEnabled(false);
            break;
        case 6:
            ui->cau6->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau6->setEnabled(false);
            break;
        case 7:
            ui->cau7->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau7->setEnabled(false);
            break;
        case 8:
            ui->cau8->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau8->setEnabled(false);
            break;
        case 9:
            ui->cau9->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau9->setEnabled(false);
            break;
        case 10:
            ui->cau10->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau10->setEnabled(false);
            break;
        case 11:
            ui->cau11->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau11->setEnabled(false);
            break;
        case 12:
            ui->cau12->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau12->setEnabled(false);
            break;
        case 13:
            ui->cau13->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau13->setEnabled(false);
            break;
        case 14:
            ui->cau14->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau14->setEnabled(false);
            break;
        case 15:
            ui->cau15->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau15->setEnabled(false);
            break;
        case 16:
            ui->cau16->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau16->setEnabled(false);
            break;
        case 17:
            ui->cau17->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau17->setEnabled(false);
            break;
        case 18:
            ui->cau18->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau18->setEnabled(false);
            break;
        case 19:
            ui->cau19->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau19->setEnabled(false);
            break;
        case 20:
            ui->cau20->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau20->setEnabled(false);
            break;
        case 21:
            ui->cau21->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau21->setEnabled(false);
            break;
        case 22:
            ui->cau22->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau22->setEnabled(false);
            break;
        case 23:
            ui->cau23->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau23->setEnabled(false);
            break;
        case 24:
            ui->cau24->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau24->setEnabled(false);
            break;
        case 25:
            ui->cau25->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau25->setEnabled(false);
            break;
        case 26:
            ui->cau26->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau26->setEnabled(false);
            break;
        case 27:
            ui->cau27->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau27->setEnabled(false);
            break;
        case 28:
            ui->cau28->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau28->setEnabled(false);
            break;
        case 29:
            ui->cau29->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau29->setEnabled(false);
            break;
        case 30:
            ui->cau30->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau30->setEnabled(false);
            break;
        case 31:
            ui->cau31->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau31->setEnabled(false);
            break;
        case 32:
            ui->cau32->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau32->setEnabled(false);
            break;
        case 33:
            ui->cau33->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau33->setEnabled(false);
            break;
        case 34:
            ui->cau34->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau34->setEnabled(false);
            break;
        case 35:
            ui->cau35->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau35->setEnabled(false);
            break;
        case 36:
            ui->cau36->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau36->setEnabled(false);
            break;
        case 37:
            ui->cau37->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau37->setEnabled(false);
            break;
        case 38:
            ui->cau38->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau38->setEnabled(false);
            break;
        case 39:
            ui->cau39->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau39->setEnabled(false);
            break;
        case 40:
            ui->cau40->setStyleSheet("font: bold; color: rgb(0, 168, 0);");
            ui->cau40->setEnabled(false);
            break;
        }
    else
        switch (i){
        case 1:
            ui->cau1->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau1->setEnabled(false);
            break;
        case 2:
            ui->cau2->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau2->setEnabled(false);
            break;
        case 3:
            ui->cau3->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau3->setEnabled(false);
            break;
        case 4:
            ui->cau4->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau4->setEnabled(false);
            break;
        case 5:
            ui->cau5->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau5->setEnabled(false);
            break;
        case 6:
            ui->cau6->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau6->setEnabled(false);
            break;
        case 7:
            ui->cau7->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau7->setEnabled(false);
            break;
        case 8:
            ui->cau8->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau8->setEnabled(false);
            break;
        case 9:
            ui->cau9->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau9->setEnabled(false);
            break;
        case 10:
            ui->cau10->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau10->setEnabled(false);
            break;
        case 11:
            ui->cau11->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau11->setEnabled(false);
            break;
        case 12:
            ui->cau12->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau12->setEnabled(false);
            break;
        case 13:
            ui->cau13->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau13->setEnabled(false);
            break;
        case 14:
            ui->cau14->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau14->setEnabled(false);
            break;
        case 15:
            ui->cau15->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau15->setEnabled(false);
            break;
        case 16:
            ui->cau16->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau16->setEnabled(false);
            break;
        case 17:
            ui->cau17->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau17->setEnabled(false);
            break;
        case 18:
            ui->cau18->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau18->setEnabled(false);
            break;
        case 19:
            ui->cau19->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau19->setEnabled(false);
            break;
        case 20:
            ui->cau20->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau20->setEnabled(false);
            break;
        case 21:
            ui->cau21->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau21->setEnabled(false);
            break;
        case 22:
            ui->cau22->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau22->setEnabled(false);
            break;
        case 23:
            ui->cau23->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau23->setEnabled(false);
            break;
        case 24:
            ui->cau24->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau24->setEnabled(false);
            break;
        case 25:
            ui->cau25->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau25->setEnabled(false);
            break;
        case 26:
            ui->cau26->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau26->setEnabled(false);
            break;
        case 27:
            ui->cau27->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau27->setEnabled(false);
            break;
        case 28:
            ui->cau28->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau28->setEnabled(false);
            break;
        case 29:
            ui->cau29->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau29->setEnabled(false);
            break;
        case 30:
            ui->cau30->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau30->setEnabled(false);
            break;
        case 31:
            ui->cau31->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau31->setEnabled(false);
            break;
        case 32:
            ui->cau32->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau32->setEnabled(false);
            break;
        case 33:
            ui->cau33->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau33->setEnabled(false);
            break;
        case 34:
            ui->cau34->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau34->setEnabled(false);
            break;
        case 35:
            ui->cau35->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau35->setEnabled(false);
            break;
        case 36:
            ui->cau36->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau36->setEnabled(false);
            break;
        case 37:
            ui->cau37->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau37->setEnabled(false);
            break;
        case 38:
            ui->cau38->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau38->setEnabled(false);
            break;
        case 39:
            ui->cau39->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau39->setEnabled(false);
            break;
        case 40:
            ui->cau40->setStyleSheet("font: bold; color: rgb(255, 0, 0);");
            ui->cau40->setEnabled(false);
            break;
        }
}

void DoExam::displayQuesWhenClickBtn(int i)
{
    STT = i;
    ui->frame->setHidden(true);
    ui->answerA->setEnabled(true);
    ui->answerB->setEnabled(true);
    ui->answerC->setEnabled(true);
    ui->answerD->setEnabled(true);
    ui->textD->setStyleSheet("border : solid;border-width: 1px;border-radius: 10px;border-color: rgb(0, 0, 0);background-color: rgb(239, 239, 239);");
    ui->textA->setStyleSheet("border : solid;border-width: 1px;border-radius: 10px;border-color: rgb(0, 0, 0);background-color: rgb(239, 239, 239);");
    ui->textB->setStyleSheet("border : solid;border-width: 1px;border-radius: 10px;border-color: rgb(0, 0, 0);background-color: rgb(239, 239, 239);");
    ui->textC->setStyleSheet("border : solid;border-width: 1px;border-radius: 10px;border-color: rgb(0, 0, 0);background-color: rgb(239, 239, 239);");
    ui->scrollArea->setEnabled(true);

    Exam exam;
    exam.openexam();
    QSqlQuery qryExam;

    qryExam.prepare("select * from "+Name+" where STT='"+QString::number(STT)+"'");
    if (qryExam.exec())
        while (qryExam.next()){
            ui->question->setPlainText(qryExam.value(1).toString());
            ui->textA->setPlainText(qryExam.value(2).toString());
            ui->textB->setPlainText(qryExam.value(3).toString());
            ui->textC->setPlainText(qryExam.value(4).toString());
            ui->textD->setPlainText(qryExam.value(5).toString());
            rightAnswer = qryExam.value(6).toString();
    }
    displayBtnState(STT, 1);
}

void DoExam::displayBtnState(int i, bool b)
{
    if (b){
    switch (i) {
    case 1:
        ui->cau1->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 2:
        ui->cau2->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 3:
        ui->cau3->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 4:
        ui->cau4->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 5:
        ui->cau5->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 6:
        ui->cau6->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 7:
        ui->cau7->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 8:
        ui->cau8->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 9:
        ui->cau9->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 10:
        ui->cau10->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 11:
        ui->cau11->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 12:
        ui->cau12->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 13:
        ui->cau13->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 14:
        ui->cau14->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 15:
        ui->cau15->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 16:
        ui->cau16->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 17:
        ui->cau17->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 18:
        ui->cau18->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 19:
        ui->cau19->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 20:
        ui->cau20->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 21:
        ui->cau21->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 22:
        ui->cau22->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 23:
        ui->cau23->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 24:
        ui->cau24->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 25:
        ui->cau25->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 26:
        ui->cau26->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 27:
        ui->cau27->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 28:
        ui->cau28->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 29:
        ui->cau29->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 30:
        ui->cau30->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 31:
        ui->cau31->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 32:
        ui->cau32->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 33:
        ui->cau33->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 34:
        ui->cau34->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 35:
        ui->cau35->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 36:
        ui->cau36->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 37:
        ui->cau37->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 38:
        ui->cau38->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 39:
        ui->cau39->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    case 40:
        ui->cau40->setStyleSheet("font: bold; color: rgb(0, 0, 255);");
        break;
    }
    }
    else {
        switch (i)
        {
        case 1:
            ui->cau1->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 2:
            ui->cau2->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 3:
            ui->cau3->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 4:
            ui->cau4->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 5:
            ui->cau5->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 6:
            ui->cau6->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 7:
            ui->cau7->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 8:
            ui->cau8->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 9:
            ui->cau9->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 10:
            ui->cau10->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 11:
            ui->cau11->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 12:
            ui->cau12->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 13:
            ui->cau13->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 14:
            ui->cau14->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 15:
            ui->cau15->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 16:
            ui->cau16->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 17:
            ui->cau17->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 18:
            ui->cau18->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 19:
            ui->cau19->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 20:
            ui->cau20->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 21:
            ui->cau21->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 22:
            ui->cau22->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 23:
            ui->cau23->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 24:
            ui->cau24->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 25:
            ui->cau25->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 26:
            ui->cau26->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 27:
            ui->cau27->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 28:
            ui->cau28->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 29:
            ui->cau29->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 30:
            ui->cau30->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 31:
            ui->cau31->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 32:
            ui->cau32->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 33:
            ui->cau33->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 34:
            ui->cau34->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 35:
            ui->cau35->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 36:
            ui->cau36->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 37:
            ui->cau37->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 38:
            ui->cau38->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 39:
            ui->cau39->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
        case 40:
            ui->cau40->setStyleSheet("font: bold; color: rgb(0, 0, 0);");
            break;
    }
}
}

void DoExam::on_answerA_clicked()
{
    QString yourAnswer = "A";
    ui->frame->setHidden(false);
    ui->answerA->setEnabled(false);
    ui->answerB->setEnabled(false);
    ui->answerC->setEnabled(false);
    ui->answerD->setEnabled(false);
    ui->textA->setStyleSheet("background-color: rgb(200, 170, 255);");
    ui->scrollArea->setEnabled(false);
    if (yourAnswer == rightAnswer)
    {
        rightmeme();
        score += 10;
        ui->score->setText(QString::number(score));
        displayBtnNumber(STT, true);
    }
    else
    {
        displayBtnNumber(STT, false);
        wrongmeme();
    }
}


void DoExam::on_answerB_clicked()
{
    QString yourAnswer = "B";
    ui->frame->setHidden(false);
    ui->answerA->setEnabled(false);
    ui->answerB->setEnabled(false);
    ui->answerC->setEnabled(false);
    ui->answerD->setEnabled(false);
    ui->textB->setStyleSheet("background-color: rgb(200, 170, 255);");
    ui->scrollArea->setEnabled(false);
    if (yourAnswer == rightAnswer)
    {
        rightmeme();
        score += 10;
        ui->score->setText(QString::number(score));
        displayBtnNumber(STT, true);
    }
    else
    {
        displayBtnNumber(STT, false);
        wrongmeme();
    }
}


void DoExam::on_answerC_clicked()
{
    QString yourAnswer = "C";
    ui->frame->setHidden(false);
    ui->answerA->setEnabled(false);
    ui->answerB->setEnabled(false);
    ui->answerC->setEnabled(false);
    ui->answerD->setEnabled(false);
    ui->textC->setStyleSheet("background-color: rgb(200, 170, 255);");
    ui->scrollArea->setEnabled(false);
    if (yourAnswer == rightAnswer)
    {
        rightmeme();
        score += 10;
        ui->score->setText(QString::number(score));
        displayBtnNumber(STT, true);
    }
    else
    {
        displayBtnNumber(STT, false);
        wrongmeme();
    }
}


void DoExam::on_answerD_clicked()
{
    QString yourAnswer = "D";
    ui->frame->setHidden(false);
    ui->answerA->setEnabled(false);
    ui->answerB->setEnabled(false);
    ui->answerC->setEnabled(false);
    ui->answerD->setEnabled(false);
    ui->textD->setStyleSheet("background-color: rgb(200, 170, 255);");
    ui->scrollArea->setEnabled(false);
    if (yourAnswer == rightAnswer)
    {
        rightmeme();
        score += 10;
        ui->score->setText(QString::number(score));
        displayBtnNumber(STT, true);
    }
    else
    {
        displayBtnNumber(STT, false);
        wrongmeme();
    }
}


void DoExam::on_next_clicked()
{
    STT++;
    ui->frame->setHidden(true);
    ui->answerA->setEnabled(true);
    ui->answerB->setEnabled(true);
    ui->answerC->setEnabled(true);
    ui->answerD->setEnabled(true);
    ui->textD->setStyleSheet("border : solid;border-width: 1px;border-radius: 10px;border-color: rgb(0, 0, 0);background-color: rgb(239, 239, 239);");
    ui->textA->setStyleSheet("border : solid;border-width: 1px;border-radius: 10px;border-color: rgb(0, 0, 0);background-color: rgb(239, 239, 239);");
    ui->textB->setStyleSheet("border : solid;border-width: 1px;border-radius: 10px;border-color: rgb(0, 0, 0);background-color: rgb(239, 239, 239);");
    ui->textC->setStyleSheet("border : solid;border-width: 1px;border-radius: 10px;border-color: rgb(0, 0, 0);background-color: rgb(239, 239, 239);");
    ui->scrollArea->setEnabled(true);
    Exam exam;
    exam.openexam();
    QSqlQuery qryExam;

    qryExam.prepare("select * from "+Name+" where STT='"+QString::number(STT)+"'");
    if (qryExam.exec())
        while (qryExam.next()){
            ui->question->setPlainText(qryExam.value(1).toString());
            ui->textA->setPlainText(qryExam.value(2).toString());
            ui->textB->setPlainText(qryExam.value(3).toString());
            ui->textC->setPlainText(qryExam.value(4).toString());
            ui->textD->setPlainText(qryExam.value(5).toString());
            rightAnswer = qryExam.value(6).toString();
    }
    displayBtnState(STT,1);
}
//click Question Number Button

void DoExam::on_cau1_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(1);
}

void DoExam::on_cau2_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(2);
}

void DoExam::on_cau3_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(3);
}

void DoExam::on_cau4_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(4);
}

void DoExam::on_cau5_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(5);
}

void DoExam::on_cau6_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(6);
}

void DoExam::on_cau7_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(7);
}

void DoExam::on_cau8_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(8);
}


void DoExam::on_cau9_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(9);
}


void DoExam::on_cau10_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(10);
}

void DoExam::on_cau11_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(11);
}

void DoExam::on_cau12_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(12);
}

void DoExam::on_cau13_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(13);
}

void DoExam::on_cau14_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(14);
}

void DoExam::on_cau15_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(15);
}

void DoExam::on_cau16_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(16);
}

void DoExam::on_cau17_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(17);
}

void DoExam::on_cau18_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(18);
}


void DoExam::on_cau19_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(19);
}


void DoExam::on_cau20_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(20);
}

void DoExam::on_cau21_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(21);
}

void DoExam::on_cau22_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(22);
}

void DoExam::on_cau23_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(23);
}

void DoExam::on_cau24_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(24);
}

void DoExam::on_cau25_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(25);
}

void DoExam::on_cau26_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(26);
}

void DoExam::on_cau27_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(27);
}

void DoExam::on_cau28_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(28);
}


void DoExam::on_cau29_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(29);
}


void DoExam::on_cau30_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(30);
}

void DoExam::on_cau31_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(31);
}

void DoExam::on_cau32_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(32);
}

void DoExam::on_cau33_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(33);
}

void DoExam::on_cau34_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(34);
}

void DoExam::on_cau35_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(35);
}

void DoExam::on_cau36_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(36);
}

void DoExam::on_cau37_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(37);
}

void DoExam::on_cau38_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(38);
}


void DoExam::on_cau39_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(39);
}


void DoExam::on_cau40_clicked()
{
    displayBtnState(STT,0);
    displayQuesWhenClickBtn(40);
}


void DoExam::SaveScore()
{
    MainWindow main;
    main.opend();
    QString YourName, ExamCode, ExamScore, TimeDoing;
    QSqlQuery qry;
    qry.prepare("Select * from Account1 where State='1'");
    if (qry.exec())
        while (qry.next())
        {
            YourName = qry.value(0).toString();
        }
    main.closed();

    Exam exam;
    exam.openexam();

    QSqlQuery qryExam;
    qryExam.prepare("select * from ListExam where Doing = '1'");
    if (qryExam.exec())
        while (qryExam.next())
        {
            ExamCode = qryExam.value(0).toString();
            ExamScore = ui->score->text();     
        }
    exam.closedexam();
    uScore = uScore + ExamScore.toInt();
    main.opend();
    QSqlQuery qryHistory;
    TimeDoing = QString::number(minutes) + " : " + QString::number(second);
    qryHistory.prepare("insert into "+YourName+" (CODE, Score, Date, Time) values ('"+ExamCode+"', '"+ExamScore+"', '"+date.toString()+"', '"+TimeDoing+"')");
    qryHistory.exec();

    QSqlQuery qryScore;
    qryScore.prepare("update Account1 set Score = '"+QString::number(uScore)+"' where State='1'");
    qryScore.exec();

    main.closed();
}

void DoExam::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Finish","Do you want to exit this exam!!!",QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        QMessageBox::about(this,"Close","Closed");
        this->close();
    }
}

