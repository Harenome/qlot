#include "detailventedialog.h"
#include "ui_detailventedialog.h"

DetailVenteDialog::DetailVenteDialog(QWidget *parent, const vente &v_courante) :
    QDialog(parent),
    ui(new Ui::DetailVenteDialog)
{
    ui->setupUi(this);
    vente v(v_courante);
    charge_detail(v);
}

DetailVenteDialog::~DetailVenteDialog()
{
    delete ui;
}

void DetailVenteDialog::charge_detail(const vente & v)
{
    std::vector<article_vendu_affichage> af = v.articles_vendus();
    QTableWidgetItem * tab[2][af.size()];

    ui->tableWidget->setRowCount(af.size());

    char ref [af.size()][11];
    char qte [af.size()][4];

    for (int i = 0 ; i<af.size() ; i++)
    {
        for (int j = 0 ; j<2 ; j++)
        {
            tab[i][j] = new QTableWidgetItem;
            ui->tableWidget->setItem(i,j,tab[i][j]);
        }

        ui->tableWidget->item(i,0)->setText(ref[i]);

        ui->tableWidget->item(i,1)->setText(qte);
    }
}
