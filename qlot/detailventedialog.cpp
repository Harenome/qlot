#include "detailventedialog.h"
#include "ui_detailventedialog.h"

DetailVenteDialog::DetailVenteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailVenteDialog)
{
    ui->setupUi(this);

    MainWindow * pere = (MainWindow *)parentWidget();

    vente v(pere->m.vente_id(pere->id_vente));
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

        sprintf(ref[i],"%u%u%u",af[i].reference().modele(),af[i].reference().couleur(),af[i].reference().taille());
        ui->tableWidget->item(i,0)->setText(ref[i]);

        sprintf(qte[i],"%u",af[i].quantite_vendue());
        ui->tableWidget->item(i,1)->setText(qte[i]);
    }
}
