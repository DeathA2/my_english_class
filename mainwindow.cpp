#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signup.h"
#include "mainscreen.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/new/icon/img/signin.png"));

    opend();
    ui->progressBar->setValue(0);
    ui->error->setHidden(true);
    ui->progressBar->setHidden(true);
    ui->loading->setHidden(true);
    ui->logo->setHidden(true);
    loadSetting();

}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::saveSetting(){
    QSettings setting("MyName", "MyApp");
    setting.beginGroup("SaveText");
    setting.setValue("MyAccount", ui->account->text());
    setting.setValue("MyPass", ui->pass->text());
    setting.endGroup();
}

void MainWindow::loadSetting(){
    QSettings setting("MyName", "MyApp");
    setting.beginGroup("SaveText");
    ui->account->setText(setting.value("MyAccount").toString());
    ui->pass->setText(setting.value("MyPass").toString());
    setting.endGroup();
}

void MainWindow::loading()
{
    int ld = ui->progressBar->value();
    ld = ld + 1;
    ui->progressBar->setValue(ld);
    ui->loading->setGeometry(ld*6+80,400,50,50);
    if (ld == 100){

        hide();
        MainScreen *mainscreen = new MainScreen ();
        int screenWidth;
        int screenHeight;

        int x, y;


        QDesktopWidget *desktop = QApplication::desktop();

        screenWidth = desktop->width();
        screenHeight = desktop->height();
        x = (screenWidth - 1280) / 2;
        y = (screenHeight - 720) / 2;
        mainscreen->resize(1280, 720);
        mainscreen->move( x, y );
        mainscreen->show();
    }
}

void MainWindow::loadinggif()
{
    QMovie *movie;
    int n = QRandomGenerator::global()->bounded(1,10);
    switch (n) {
    case 1:{
        movie = new QMovie("D:/Project/QT/EnglishClass/img/loading.gif");
        break;
    }
    case 2:{
        movie = new QMovie("D:/Project/QT/EnglishClass/img/loading1.gif");
        break;
    }
    case 3:{
        movie = new QMovie("D:/Project/QT/EnglishClass/img/loading2.gif");
        break;
    }
    case 4:{
        movie = new QMovie("D:/Project/QT/EnglishClass/img/loading3.gif");
        break;
    }
    case 5:{
        movie = new QMovie("D:/Project/QT/EnglishClass/img/loading4.gif");
        break;
    }
    case 6:{
        movie = new QMovie("D:/Project/QT/EnglishClass/img/loading5.gif");
        break;
    }
    case 7:{
        movie = new QMovie("D:/Project/QT/EnglishClass/img/loading6.gif");
        break;
    }
    case 8:{
        movie = new QMovie("D:/Project/QT/EnglishClass/img/loading7.gif");
        break;
    }
    case 9:{
        movie = new QMovie("D:/Project/QT/EnglishClass/img/loading8.gif");
        break;
    }
    default:{
        movie = new QMovie("D:/Project/QT/EnglishClass/img/loading9.gif");
        break;
    }
    }

    ui->loading->setMovie(movie);
    movie->start();
}

void MainWindow::on_signUpBtn_clicked()
{
    SignUp signup(this);
    signup.setModal(true);
    signup.exec();

}


void MainWindow::on_signInBtn_clicked()
{
    QSqlQuery qrycheck;
    qrycheck.prepare("update Account1 set State = '0' where State = '1' ");
    qrycheck.exec();

    QString useraccount, password;
    useraccount = ui->account->text();
    password = ui->pass->text();

    saveSetting();
    opend();
    QSqlQuery qry, qrycheckable;

    qrycheckable.prepare("update Account1 set State = '1' where UserAccount = '"+ui->account->text()+"' ");
    qrycheckable.exec();

    qry.prepare("select * from Account1 where UserAccount = '"+useraccount+"' and Password = '"+password+"'");
    if (qry.exec())
    {
        int count = 0;
        while(qry.next())
        {
            count++;
        }
        if (count == 1){

            ui->error->setText("correct!");
            closed();
            ui->error->setHidden(false);
            ui->groupBox->setHidden(true);
            ui->label->setHidden(true);
            ui->label_2->setPixmap(QPixmap(":/new/image/img/2785219.jpg"));
            ui->progressBar->setHidden(false);
            ui->loading->setHidden(false);
            ui->logo->setHidden(false);
            ui->admin->setHidden(true);
            loadinggif();
            ui->signUpBtn->setHidden(true);
            timer = new QTimer(this);
            connect(timer, SIGNAL(timeout()),this,SLOT(loading()));
            timer->start(40);
        }
        else
        {
            ui->error->setText("Incorrect!");
            ui->error->setHidden(false);
        }
    }
}

void MainWindow::on_pass_returnPressed()
{
    on_signInBtn_clicked();
}

