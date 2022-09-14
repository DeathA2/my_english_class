#include "mainscreen.h"
#include "ui_mainscreen.h"
#include "mainwindow.h"
#include "study.h"
#include "store.h"
#include "exam.h"


MainScreen::MainScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScreen)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/new/icon/img/dictionary.png"));
    ui->exam->setGeometry(590, 500, 150, 100);
    ui->study->setGeometry(290, 500, 150, 100);
    ui->store->setGeometry(890, 500, 150, 100);
    closeEdit();

}

MainScreen::~MainScreen()
{
    delete ui;
}

void MainScreen::closeEdit()
{
    ui->fullName->setEnabled(false);
    ui->birthday->setHidden(true);
    ui->setBirth->setHidden(false);
    ui->setBirth->setEnabled(false);
    ui->sex->setEnabled(false);
    ui->grade->setEnabled(false);
    ui->school->setEnabled(false);
    ui->phone->setEnabled(false);
    ui->mail->setEnabled(false);
    ui->score->setEnabled(false);
    ui->uAccount->setEnabled(false);
    ui->uname->setEnabled(false);
    ui->save->setHidden(true);
    ui->close->setHidden(true);
    ui->addPic->setEnabled(false);
    ui->edit->setHidden(false);
    ui->history->setHidden(false);
    ui->logout->setHidden(false);
    ui->uhistory->setHidden(true);
    MainWindow main;
    main.opend();
    QSqlQuery qry;
    qry.prepare("select * from Account1 where State ='1'");
    if (qry.exec())
        while (qry.next()) {
            ui->uAccount->setText(qry.value(0).toString());
            ui->uname->setText(qry.value(1).toString());
            ui->fullName->setText(qry.value(4).toString());
            ui->setBirth->setText(qry.value(5).toString());
            ui->sex->setCurrentIndex(qry.value(6).toInt());
            ui->grade->setCurrentIndex(qry.value(7).toInt());
            ui->school->setText(qry.value(8).toString());
            ui->phone->setText(qry.value(9).toString());
            ui->mail->setText(qry.value(10).toString());
            ui->score->setText(qry.value(11).toString());
            ui->avatar->setPixmap(QPixmap(qry.value(12).toString()));
        }
    main.closed();
}

void MainScreen::on_study_clicked()
{
    this->setHidden(true);
    Study study;
    study.setModal(true);
    study.exec();
}


void MainScreen::on_exam_clicked()
{
    this->setHidden(true);
    Exam exam;
    exam.exec();
}


void MainScreen::on_store_clicked()
{
    this->setHidden(true);
    Store store;
    store.exec();
}


void MainScreen::on_edit_clicked()
{
    ui->fullName->setEnabled(true);
    ui->birthday->setHidden(false);
    ui->setBirth->setHidden(true);
    ui->sex->setEnabled(true);
    ui->grade->setEnabled(true);
    ui->school->setEnabled(true);
    ui->phone->setEnabled(true);
    ui->mail->setEnabled(true);
    ui->uname->setEnabled(true);
    ui->save->setHidden(false);
    ui->close->setHidden(false);
    ui->edit->setHidden(true);
    ui->addPic->setEnabled(true);
    ui->history->setHidden(true);
    ui->logout->setHidden(true);
}


void MainScreen::on_save_clicked()
{

    MainWindow main;
    main.opend();
    QSqlQuery qry;
    qry.prepare("update Account1 set UserName ='"+ui->uname->text()+"',"
                                    "FullName = '"+ui->fullName->text()+"',"
                                    "BirthDay = '"+ui->birthday->text()+"',"
                                    "Sex = '"+QString::number(ui->sex->currentIndex())+"',"
                                    "Grade = '"+QString::number(ui->grade->currentIndex())+"',"
                                    "School = '"+ui->school->text()+"',"
                                    "Phone = '"+ui->phone->text()+"',"
                                    "Mail = '"+ui->mail->text()+"',"
                                    "Avatar = '"+avatar_direction+"' "
                                    "where State = '1' ");
    qry.exec();
    main.closed();
    closeEdit();
}


void MainScreen::on_close_clicked()
{
    closeEdit();
}


void MainScreen::on_addPic_clicked()
{
    QString filter = "PNG File (*.png) ;; JPG File (*.jpg) ;; All Files (*.*)";
    avatar_direction = QFileDialog::getOpenFileName(this,"Choose your Avatar!","C://",filter);
    ui->avatar->setPixmap(QPixmap(avatar_direction));
}


void MainScreen::on_history_clicked()
{
    ui->uhistory->setHidden(false);
    MainWindow main;
    main.opend();
    QString uAcc;
    hlist = new QSqlQueryModel();
    QSqlQuery qry;

    qry.prepare("select * from Account1 where State ='1'");
    if (qry.exec())
        while (qry.next()) {
                uAcc = qry.value(0).toString();
            }

    QSqlQuery *qryAcc = new QSqlQuery(main.mydb);
    qryAcc->prepare("select * from "+uAcc+"");
    qryAcc->exec();

    hlist->setQuery(*qryAcc);
    ui->tableView->setModel(hlist);

    int width = ui->tableView->width();
    for (int i = 0; i<=hlist->columnCount() ; i++ ) {
        ui->tableView->setColumnWidth(i, width/hlist->columnCount());
        }

    main.closed();
}


void MainScreen::on_close_2_clicked()
{
    ui->uhistory->setHidden(true);
}


void MainScreen::on_logout_clicked()
{
    MainWindow *main = new MainWindow();
    main->show();
    close();
}

