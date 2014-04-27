#include "statdialog.h"
#include "ui_statdialog.h"

StatDialog::StatDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatDialog)
{
    ui->setupUi(this);
    MainWindow * daron = (MainWindow *)parentWidget();

    double chiffre_affaire = daron->m.chiffre_d_affaires();
    double bene = daron->m.benefices();

    ui->doubleSpinBox_benefice->setValue(bene);
    ui->doubleSpinBox_chiffre_affaire->setValue(chiffre_affaire);
}

StatDialog::~StatDialog()
{
    delete ui;
}
