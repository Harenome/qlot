#include "ajoutventedialog.h"
#include "ui_ajoutventedialog.h"

AjoutVenteDialog::AjoutVenteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutVenteDialog)
{
    ui->setupUi(this);
}

AjoutVenteDialog::~AjoutVenteDialog()
{
    delete ui;
}
