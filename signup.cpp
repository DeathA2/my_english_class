#include "signup.h"
#include "ui_signup.h"

SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{

    ui->setupUi(this);
    setWindowIcon(QIcon(":/new/icon/img/signup.png"));
    ui->errorUserName->setHidden(true);
    ui->errorUserAcc->setHidden(true);
    ui->userAccount->setPlaceholderText("Ex: abc, Abc1232, A1x_3 ..... NOT: 1abc, _abc");
    ui->errorPass->setHidden(true);
    ui->errorRePas->setHidden(true);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_checkBoxPass_clicked()
{
    if (ui->checkBoxPass->isChecked()){
        ui->pass->setEchoMode(ui->pass->Normal);

        ui->checkBoxPass->setIcon(QIcon(":/new/icon/img/unhide.png"));
    }
    else
    {
        ui->checkBoxPass->setIcon(QIcon(":/new/icon/img/hide.png"));
        ui->pass->setEchoMode(ui->pass->Password);
    }

}
void SignUp::on_checkBoxRePass_clicked()
{
    if (ui->checkBoxRePass->isChecked())
        ui->rePass->setEchoMode(ui->pass->Normal);
    else
        ui->rePass->setEchoMode(ui->pass->Password);

}

void SignUp::on_Save_clicked()
{
    ui->errorUserName->setHidden(true);
    ui->errorUserAcc->setHidden(true);
    ui->errorPass->setHidden(true);
    ui->errorRePas->setHidden(true);
    MainWindow main;
    QString password, repassword, userName, userAccount;
    password = ui->pass->text();
    repassword = ui->rePass->text();
    userAccount = ui->userAccount->text();
    userName = ui->username->text();


    main.opend();
    QSqlQuery qrysignUp;
    QSqlQuery qryCheckAcc, qryCheckName;

    qrysignUp.prepare("insert into Account1 (UserAccount,UserName,Password) values ('"+userAccount+"','"+userName+"', '"+password+"')");
    qryCheckAcc.prepare("select * from Account1 where UserAccount = '"+userAccount+"'");
    qryCheckName.prepare("select * from Account1 where UserName = '"+userName+"'");


    int count = 0;
    int count1 = 0;

    if (qryCheckName.exec())
    {
        while(qryCheckName.next())
        {
            count++;
        }
        if (count == 1){
            ui->errorUserName->setHidden(false);
            return;
        }
        else
        {
            if (qryCheckAcc.exec())
            {
                while(qryCheckAcc.next())
                {
                    count1++;
                }
                if (count1 == 1){
                    ui->errorUserAcc->setHidden(false);
                }
                else
                {
                    if (password.length() < 8)
                        ui->errorPass->setHidden(false);
                    else
                        if (password!=repassword)
                            ui->errorRePas->setHidden(false);
                        else
                        {
                            QSqlQuery qryAccount;
                            QString query = "CREATE TABLE "+ui->userAccount->text()+" ("
                                                                                    "CODE VARCHAR(4),"
                                                                                    "Score INTEGER,"
                                                                                    "Date DATE,"
                                                                                    "Time TIME)";

                            qryAccount.exec(query);
                            QMessageBox::StandardButton reply = QMessageBox::question(this,"Save","Do you want create new account!",QMessageBox::Yes | QMessageBox::No);
                            if (reply == QMessageBox::Yes)
                            {

                                qrysignUp.exec();
                                QMessageBox::about(this,"Save","Saved");
                                this->close();
                            }
                            else{
                                QSqlQuery qryDeleteAcc;
                                qryDeleteAcc.prepare("DROP TABLE IF EXISTS "+ui->userAccount->text()+"");
                                qryDeleteAcc.exec();
                            }

                        }

                }
             }
        }
    }
    main.closed();

}


void SignUp::on_Close_clicked()
{
    this->close();
}




