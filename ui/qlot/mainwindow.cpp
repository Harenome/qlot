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
}

void MainWindow::ajoutVente()
{
    AjoutVenteDialog avd(this);
    avd.exec();
}

void MainWindow::nouvellebdd()
{
    //Remet tout à 0;
}

void MainWindow::enregistrer()
{
    QString filename;
    filename = QFileDialog::getSaveFileName(this,tr("Enregistrer un fichier de gestion QloT"),QString(),tr("FichierQloT (*.qlot *.culotte)"));
}

void MainWindow::ouvrir()
{
    QString filename;
    filename = QFileDialog::getOpenFileName(this,tr("Ouvrir un fichier de gestion QloT"),QString(),tr("FichierQloT (*.qlot *.culotte)"));
}
