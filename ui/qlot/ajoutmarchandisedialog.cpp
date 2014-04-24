#include "ajoutmarchandisedialog.h"
#include "ui_ajoutmarchandisedialog.h"

AjoutMarchandiseDialog::AjoutMarchandiseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutMarchandiseDialog)
{
    ui->setupUi(this);
}

AjoutMarchandiseDialog::~AjoutMarchandiseDialog()
{
    delete ui;
}
