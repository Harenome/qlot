#include "ajoutmarchandisedialog.h"
#include "ui_ajoutmarchandisedialog.h"

AjoutMarchandiseDialog::AjoutMarchandiseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutMarchandiseDialog)
{
    ui->setupUi(this);
    QObject::connect(ui->ajout_marchandise_button,SIGNAL(clicked()),this,SLOT(validation()),Qt::AutoConnection);
}

AjoutMarchandiseDialog::~AjoutMarchandiseDialog()
{
    delete ui;
}

void AjoutMarchandiseDialog::validation()
{
    MainWindow * parent = (MainWindow *)parentWidget();

    // Référence
    unsigned int modele = (unsigned int)ui->spinBox_modele->value();
    unsigned int couleur = (unsigned int)ui->comboBox_couleur->currentIndex();
    unsigned int taille = (unsigned int)ui->spinBox_taille->value();
    reference_article ra(modele,couleur,taille);

    // Prix achat/vente
    double achat = ui->doubleSpinBox_achat->value();
    double vente = ui->doubleSpinBox_vente->value();

    // Date
    int jour = ui->dateEdit_livraison->date().day();
    int mois = ui->dateEdit_livraison->date().month();
    int annee = ui->dateEdit_livraison->date().year();
    date d(jour,mois,annee);

    // Quantité + rabais
    unsigned int quantite = (unsigned int)ui->spinBox_quantite->value();
    pourcentage pcg((unsigned int)ui->spinBox_rabais->value());

    unsigned int rabais = pcg.valeur();

    fprintf(stderr,"Pas de bug à l'assignement du poucentage\nRa = (%u,%u,%u), Achat = %f, Vente %f, Date = %d/%d/%d\n",ra.modele(),ra.couleur(),ra.taille(),achat,vente,d.jour(),d.mois(),d.annee());

    // Ajout de l'article dans les articles existants
    article art(ra,achat,vente,d);

    fprintf(stderr,"Pas de bug à la création de l'article\n");

    // Finalisation
    parent->m.ajouter_article(art,quantite,rabais);

    // Ajoute une ligne au tableau de recherche
    parent->ui->tableau_recherche_gestion->setRowCount(parent->ui->tableau_recherche_gestion->rowCount() + 1);

    emit(accept());
}
