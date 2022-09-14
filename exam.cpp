#include "exam.h"
#include "ui_exam.h"
#include "mainwindow.h"
#include <QHBoxLayout>
#include "addexam.h"
#include "mainscreen.h"
#include "doexam.h"

Exam::Exam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Exam)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/new/icon/img/dictionary.png"));

    ui->infor->setHidden(true);
    ui->label_3->setHidden(true);
    elist = new QSqlQueryModel();
    openexam();

    QSqlQuery *qry = new QSqlQuery(dbexam);

    qry->prepare("Select CODE,NameExam,UserName,Date from ListExam");
    qry->exec();

    elist->setQuery(*qry);
    ui->tableView->setModel(elist);

    int width = ui->tableView->width();
    for (int i = 0; i<=elist->columnCount() ; i++ ) {
        ui->tableView->setColumnWidth(i, width/elist->columnCount());
    }

    closedexam();

}

Exam::~Exam()
{
    delete ui;
}

void Exam::on_pushButton_8_clicked()
{
    AddExam add;
    add.setModal(true);
    add.exec();
}


void Exam::on_home_clicked()
{

    MainScreen *mainscreen = new MainScreen ();
    mainscreen->show();
    close();
}


void Exam::on_tableView_activated(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString();
    openexam();
    QSqlQuery qry;
    qry.prepare("select CODE,NameExam,UserName,Date from ListExam where NameExam = '"+val+"' or CODE='"+val+"'");
    if (qry.exec()){
        while (qry.next()){
            ui->infor->setHidden(false);
            ui->label_3->setHidden(false);
            ui->code->setText(qry.value(0).toString());
            ui->examName->setText(qry.value(1).toString());
            ui->userAccoung->setText(qry.value(2).toString());
            ui->dateTime->setText(qry.value(3).toString());
        }
    }
    QSqlQuery qrycheckable;

    qrycheckable.prepare("update ListExam set Doing = '1' where CODE = '"+ui->code->text()+"' ");
    qrycheckable.exec();
}


void Exam::on_no_clicked()
{
    openexam();
    ui->infor->setHidden(true);
    ui->label_3->setHidden(true);
    QSqlQuery qrycheckable;

    qrycheckable.prepare("update ListExam set Doing = '0' where Doing= '1' ");
    qrycheckable.exec();
}


void Exam::on_yes_clicked()
{

    DoExam doing;
    ui->infor->setHidden(true);
    ui->label_3->setHidden(true);
    doing.setModal(true);
    doing.exec();
    closedexam();
}


void Exam::on_lineEdit_returnPressed()
{
    openexam();
    slist = new QSqlQueryModel();

    QSqlQuery *qry = new QSqlQuery(dbexam);

    qry->prepare("Select CODE,NameExam,UserName,Date from ListExam where CODE = '"+ui->lineEdit->text()+"' or NameExam = '"+ui->lineEdit->text()+"' or UserName = '"+ui->lineEdit->text()+"'");
    qry->exec();


    slist->setQuery(*qry);
    ui->tableView->setModel(slist);

    int width = ui->tableView->width();
    for (int i = 0; i<=slist->columnCount() ; i++ ) {
        ui->tableView->setColumnWidth(i, width/slist->columnCount());
    }
    closedexam();
}

