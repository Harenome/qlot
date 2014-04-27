#include "ajoutventedialog.h"
#include "ui_ajoutventedialog.h"

AjoutVenteDialog::AjoutVenteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutVenteDialog)
{
    ui->setupUi(this);
    init_vd();

    QObject::connect(ui->comboBox_ref_vente,SIGNAL(currentIndexChanged(int)),this,SLOT(changer_max()),Qt::AutoConnection);
    QObject::connect(ui->button_ajout,SIGNAL(clicked()),this,SLOT(ajouter_une_vente()),Qt::AutoConnection);
    QObject::connect(ui->button_vente,SIGNAL(clicked()),this,SLOT(vendre()),Qt::AutoConnection);
}

AjoutVenteDialog::~AjoutVenteDialog()
{
    delete ui;
}

void AjoutVenteDialog::init_vd()
{
    MainWindow * parent = (MainWindow *)parentWidget();

    std::vector<reference_article> vra = parent->m.references_en_stock();
    char buff [vra.size()][11];

    for (int i = 0 ; i<vra.size() ; i++)
    {
        sprintf(buff[i],"%4u %2u% 2u",vra[i].modele(),vra[i].couleur(),vra[i].taille());
        ui->comboBox_ref_vente->addItem(buff[i]);
    }

    if(vra.size() == 0)
        ui->button_ajout->setEnabled(false);
    else
        changer_max();
}

void AjoutVenteDialog::changer_max()
{
    MainWindow * parent = (MainWindow *)parentWidget();
    std::vector<article_affichage> vaa = parent->m.articles_en_stock();
    article_affichage a = vaa[ui->comboBox_ref_vente->currentIndex()];

    ui->spinBox_qtite_vente->setMaximum(a.quantite_stock());
}

void AjoutVenteDialog::ajouter_une_vente()
{
    MainWindow * parent = (MainWindow *)parentWidget();

    QTableWidgetItem * tab[3];
    ui->table_ajout_vente->setRowCount(ui->table_ajout_vente->rowCount()+1);

    for (int j = 0 ; j<3 ; j++)
    {
        tab[j] = new QTableWidgetItem;
        ui->table_ajout_vente->setItem(ui->table_ajout_vente->rowCount()-1,j,tab[j]);
    }

    std::vector<article_affichage> vaa = parent->m.articles_en_stock();
    article_affichage a = vaa[ui->comboBox_ref_vente->currentIndex()];

    char buff[11];

    sprintf(buff,"%4u %2u %2u",a.reference().modele(),a.reference().couleur(),a.reference().taille());
    ui->table_ajout_vente->item(ui->table_ajout_vente->rowCount()-1,0)->setText(buff);

    unsigned int quantite = (unsigned int)ui->spinBox_qtite_vente->value();
    char buff_qte[4];
    sprintf(buff_qte,"%u",quantite);
    ui->table_ajout_vente->item(ui->table_ajout_vente->rowCount()-1,1)->setText(buff_qte);

    double prix_lot = a.prix_vente_effectif()*(double)quantite;
    char buff_pl[8];
    sprintf(buff_pl,"%.2f",prix_lot);
    ui->table_ajout_vente->item(ui->table_ajout_vente->rowCount()-1,2)->setText(buff_pl);

    ui->doubleSpinBox_prix_total->setValue(ui->doubleSpinBox_prix_total->value()+prix_lot);

    ui->button_vente->setEnabled(true);
    article_vendu artv(a.reference(),quantite,a.prix_vente_effectif());

    v.ajouter_article_vendu(artv);
}

void AjoutVenteDialog::vendre()
{
    MainWindow * parent = (MainWindow *)parentWidget();

    parent->m.ajouter_vente(v);
    emit(accept());
}
