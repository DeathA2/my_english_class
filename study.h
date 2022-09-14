#ifndef STUDY_H
#define STUDY_H

#include <QDialog>
#include <mainscreen.h>

namespace Ui {
class Study;
}

class Study : public QDialog
{
    Q_OBJECT

public:
    explicit Study(QWidget *parent = nullptr);
    ~Study();
    int count = 0;

private slots:
    void on_psimple_clicked();

    void on_pCont_clicked();

    void on_tabWidget_tabCloseRequested(int index);

    void on_home_clicked();

    void on_pPer_clicked();

    void on_pPerCon_clicked();

    void on_paSimp_clicked();

    void on_paCont_clicked();

    void on_paPer_clicked();

    void on_paPerCont_clicked();

    void on_fSimp_clicked();

    void on_fCont_clicked();

    void on_fPer_clicked();

    void on_fPerCont_clicked();

    void on_passive_clicked();

    void on_passivedb_clicked();

    void on_wish1_clicked();

    void on_wish2_clicked();

    void on_wish3_clicked();

    void on_tagQue_clicked();

    void on_tagQueSpe_clicked();

    void on_con1_clicked();

    void on_con2_clicked();

    void on_con3_clicked();

    void on_condn_clicked();

    void on_conSpe_clicked();

    void on_comBang_clicked();

    void on_comHon_clicked();

    void on_comNhat_clicked();

    void on_comKep_clicked();

    void on_comMul_clicked();

    void on_comTab_clicked();

    void on_comDang_clicked();

    void on_relaCla_clicked();

    void on_relaRutgon_clicked();

private:
    Ui::Study *ui;
    MainScreen *mainscreen;
};

#endif // STUDY_H
