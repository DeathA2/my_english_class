#include "study.h"
#include "ui_study.h"
#include "mainscreen.h"
#include "QDebug"

Study::Study(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Study)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/new/icon/img/dictionary.png"));
    for (int i=0; i < ui->tabWidget->count() ; i++ ) {
        ui->tabWidget->setTabVisible(i,false);
    }

    for (int i=0; i < ui->tabWidget->count() ; i++ ) {
        if (ui->tabWidget->isTabVisible(i) == false)
            count++;
    }
    if (count == ui->tabWidget->count())
        ui->tabWidget->setHidden(true);
    else
        ui->tabWidget->setHidden(false);
}

Study::~Study()
{
    delete ui;
}


void Study::on_psimple_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(0, true);
}


void Study::on_pCont_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(1, true);
}


void Study::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->setTabVisible(index,false);
    count = 0;
    for (int i=0; i < ui->tabWidget->count() ; i++ ) {
        if (ui->tabWidget->isTabVisible(i) == false)
            count++;
    }
    if (count == ui->tabWidget->count())
        ui->tabWidget->setHidden(true);
    else
        ui->tabWidget->setHidden(false);
}


void Study::on_home_clicked()
{
    //hide();
    mainscreen = new MainScreen ();
    mainscreen->show();
    close();

}


void Study::on_pPer_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(2, true);
}


void Study::on_pPerCon_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(3, true);
}


void Study::on_paSimp_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(4, true);
}


void Study::on_paCont_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(5, true);
}


void Study::on_paPer_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(6, true);
}


void Study::on_paPerCont_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(7, true);
}


void Study::on_fSimp_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(8, true);
}


void Study::on_fCont_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(9, true);
}


void Study::on_fPer_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(10, true);
}


void Study::on_fPerCont_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(11, true);
}


void Study::on_passive_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(12, true);
}


void Study::on_passivedb_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(13, true);
}


void Study::on_wish1_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(14, true);
}


void Study::on_wish2_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(15, true);
}


void Study::on_wish3_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(16, true);
}


void Study::on_tagQue_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(17, true);
}


void Study::on_tagQueSpe_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(18, true);
}


void Study::on_con1_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(19, true);
}


void Study::on_con2_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(20, true);
}


void Study::on_con3_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(21, true);
}


void Study::on_condn_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(22, true);
}


void Study::on_conSpe_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(23, true);
}


void Study::on_comBang_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(24, true);
}


void Study::on_comHon_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(25, true);
}


void Study::on_comNhat_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(26, true);
}


void Study::on_comKep_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(27, true);
}


void Study::on_comMul_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(28, true);
}


void Study::on_comTab_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(29, true);
}


void Study::on_comDang_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(30, true);
}


void Study::on_relaCla_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(31, true);
}


void Study::on_relaRutgon_clicked()
{
    ui->tabWidget->setHidden(false);
    ui->tabWidget->setTabVisible(32, true);
}

