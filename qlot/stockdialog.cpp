#include "stockdialog.h"
#include "ui_stockdialog.h"

StockDialog::StockDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StockDialog)
{
    ui->setupUi(this);

    MainWindow * pere = (MainWindow *)parentWidget();
    ui->spinBox_stock->setValue(pere->m.nombre_articles());

    QObject::connect(ui->dateEdit_article,SIGNAL(dateChanged(QDate)),this,SLOT(refresh_nb()),Qt::AutoConnection);

    date d(ui->dateEdit_article->date().day(),ui->dateEdit_article->date().month(),ui->dateEdit_article->date().year());
    ui->spinBox_livre->setValue(pere->m.articles_par_date(d).size());
}

StockDialog::~StockDialog()
{
    delete ui;
}

void StockDialog::refresh_nb()
{
    MainWindow * pere = (MainWindow *)parentWidget();

    date d(ui->dateEdit_article->date().day(),ui->dateEdit_article->date().month(),ui->dateEdit_article->date().year());
    ui->spinBox_livre->setValue(pere->m.articles_par_date(d).size());
}
