#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "versiondialog.h"
#include "ajoutmarchandisedialog.h"
#include "ajoutventedialog.h"
#include "statdialog.h"
#include "stockdialog.h"
#include "detailventedialog.h"
#include "modifarticledialog.h"
#include "es.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    magasin m;
    unsigned int id_vente;

private:
    Ui::MainWindow *ui;

private slots:
    void annuler_vente();
    void statistiques();
    void version();
    void ajoutMarchandise();
    void ajoutVente();
    void nouvellebdd();
    void enregistrer();
    void ouvrir();
    void affichage_gestion();
    void affichage_vente();
    void changement_affichage_vente();
    void changement_affichage_gestion();
    void stock_total();
    void enablement_detail_vente();
    void enablement_modif();
    void ouvre_detail();
    void modif_article();
};

#endif // MAINWINDOW_H
