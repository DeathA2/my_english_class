#include "store.h"
#include "ui_store.h"
#include <QDesktopServices>


Store::Store(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Store)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/new/icon/img/dictionary.png"));
    MainWindow main;
    main.opend();
    QSqlQuery qry;
    qry.prepare("select * from Account1 where State = '1'");
    if (qry.exec())
        while (qry.next()) {
            totalScore = qry.value(11).toInt();
        }
    main.closed();
}

Store::~Store()
{
    MainWindow mainW;
    mainW.opend();
    QSqlQuery qry;
    qry.prepare("update Account1 set Score = '"+QString::number(totalScore)+"' where State='1'");
    qry.exec();
    MainScreen *main = new MainScreen();
    main->show();
    delete ui;
}

bool Store::ThanhToan(QString price)
{
    int pricePic = price.toInt();
    if (totalScore < pricePic){
        QMessageBox::about(this,"Notification!", "You don't have enough money to buy this Picture!!");
        return false;
    }
    else {
        totalScore -= pricePic;
        QMessageBox::about(this,"Notification!", "Thanks");
        return true;
    }
}

void Store::on_home_clicked(){
    close();
}


void Store::on_left1_clicked()
{
    if (ThanhToan(ui->left1->text())){
        QMessageBox::about(this,"Your Picture","https://drive.google.com/drive/u/0/folders/139t_PRbOzpL5mgJMgMccEwpkE1-Ty0b1");
        QDesktopServices::openUrl(QUrl("https://drive.google.com/file/d/1aMyd5si3hph94D6kMrFqtsBUYZMStF0D/view?usp=sharing"));

    }
}


void Store::on_left5_clicked()
{
    if (ThanhToan(ui->left5->text())){
        QDesktopServices::openUrl(QUrl("https://drive.google.com/file/d/1iwcx3giBGiB2Gjogi-qONo07rCrLukLz/view?usp=sharing"));
    }
}


void Store::on_left2_clicked()
{
    if (ThanhToan(ui->left2->text())){
        QDesktopServices::openUrl(QUrl("https://drive.google.com/file/d/1bB6TzFCxWaVogsW466NnrDsRGbieHRo9/view?usp=sharing"));
    }
}


void Store::on_left3_clicked()
{
    if (ThanhToan(ui->left3->text())){
        QDesktopServices::openUrl(QUrl("https://drive.google.com/file/d/1OVu-qskKH4I67xb5Gm6-AIyVqKyXqaMl/view?usp=sharing"));
    }
}


void Store::on_left4_clicked()
{
    if (ThanhToan(ui->left4->text())){
        QDesktopServices::openUrl(QUrl("https://drive.google.com/file/d/1WiRhjTti7swEwgOTQVwBV-KIhz1ETL7A/view?usp=sharing"));
    }
}


void Store::on_right3_clicked()
{
    if (ThanhToan(ui->right3->text())){
        QDesktopServices::openUrl(QUrl("https://drive.google.com/file/d/10RDZ8AwK9c3VWsOf4N94MEIgUKHs_dPL/view?usp=sharing"));
    }
}


void Store::on_right4_clicked()
{
    if (ThanhToan(ui->right4->text())){
        QDesktopServices::openUrl(QUrl("https://drive.google.com/file/d/1cAtyCs_HfF1G5b4H3CTKdQtJ5OBuXY7B/view?usp=sharing"));
    }
}


void Store::on_right2_clicked()
{
    if (ThanhToan(ui->right2->text())){
        QDesktopServices::openUrl(QUrl("https://drive.google.com/file/d/1H4q7nXjAUVGhNBerF9cBS2GJLPbceMmL/view?usp=sharing"));
    }
}


void Store::on_right1_clicked()
{
    if (ThanhToan(ui->right1->text())){
        QDesktopServices::openUrl(QUrl("https://drive.google.com/file/d/19BYBSqTVvusLaGe2ZG8skbSC0fGBT3KH/view?usp=sharing"));
    }
}


void Store::on_mid_clicked()
{
    if (ThanhToan("10000")){
        QDesktopServices::openUrl(QUrl("https://drive.google.com/drive/folders/1WhLB2KWy9OFY0wJziFR98Soaow67rp2y?usp=sharing"));
    }
}


