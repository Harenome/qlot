#include "nouvellebdddialog.h"
#include "ui_nouvellebdddialog.h"

NouvelleBDDDialog::NouvelleBDDDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NouvelleBDDDialog)
{
    ui->setupUi(this);
}

NouvelleBDDDialog::~NouvelleBDDDialog()
{
    delete ui;
}
