#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->actionVersion,SIGNAL(triggered()),this,SLOT(version()),Qt::AutoConnection);
    QObject::connect(ui->actionAjouter_une_marchandise,SIGNAL(triggered()),this,SLOT(ajoutMarchandise()),Qt::AutoConnection);
    QObject::connect(ui->actionAjouter_une_vente,SIGNAL(triggered()),this,SLOT(ajoutVente()),Qt::AutoConnection);
    QObject::connect(ui->actionNouvelle_BDD,SIGNAL(triggered()),this,SLOT(nouvellebdd()),Qt::AutoConnection);
    QObject::connect(ui->actionEnregistrer,SIGNAL(triggered()),this,SLOT(enregistrer()),Qt::AutoConnection);
    QObject::connect(ui->actionOuvrir_une_BDD,SIGNAL(triggered()),this,SLOT(ouvrir()),Qt::AutoConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::version()
{
    VersionDialog vd(this);
    vd.exec();
}

void MainWindow::ajoutMarchandise()
{
    AjoutMarchandiseDialog amd(this);
    amd.exec();

    QTableWidgetItem * tab[m.nombre_articles()][8];
    std::vector<article_affichage> vacla = m.articles();

    for(int i = 0 ; i<m.nombre_articles() ; i++)
    {
        article_affichage i_eme_article = vacla[i];

        for (int j = 0 ; j<8 ; j++)
        {
            tab[i][j] = new QTableWidgetItem;
            ui->tableau_recherche_gestion->setItem(i,j,tab[i][j]);
        }

        ui->tableau_recherche_gestion->item(i,0)->setText(i_eme_article.reference().modele());
        ui->tableau_recherche_gestion->item(i,1)->setText(i_eme_article.reference().couleur());
        ui->tableau_recherche_gestion->item(i,2)->setText(i_eme_article.reference().taille());
        ui->tableau_recherche_gestion->item(i,3)->setText(i_eme_article.quantite_stock());
        ui->tableau_recherche_gestion->item(i,4)->setText(i_eme_article.date_livraison());
        ui->tableau_recherche_gestion->item(i,5)->setText(i_eme_article.prix_achat());
        ui->tableau_recherche_gestion->item(i,6)->setText(i_eme_article.prix_vente());
        ui->tableau_recherche_gestion->item(i,7)->setText(i_eme_article.rabais());
    }
}

void MainWindow::ajoutVente()
{
    AjoutVenteDialog avd(this);
    avd.exec();
}

void MainWindow::nouvellebdd()
{
    magasin mprime;
    m.swap(mprime);
    ui->tableau_recherche_gestion->setRowCount(0);
    ui->tableWidget_vente->setRowCount(0);
}

void MainWindow::enregistrer()
{
    QString filename;
    filename = QFileDialog::getSaveFileName(this,tr("Enregistrer un fichier de gestion QloT"),QString(),tr("FichierQloT (*.qlot *.culotte)"));
    es::sauvegarder_magasin(filename.toStdString(),m);
}

void MainWindow::ouvrir()
{
    QString filename;
    filename = QFileDialog::getOpenFileName(this,tr("Ouvrir un fichier de gestion QloT"),QString(),tr("FichierQloT (*.qlot *.culotte)"));
    es::charger_magasin(filename.toStdString(),m);
}
