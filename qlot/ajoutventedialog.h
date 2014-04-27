#ifndef AJOUTVENTEDIALOG_H
#define AJOUTVENTEDIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include "magasin.hpp"

namespace Ui {
class AjoutVenteDialog;
}

class AjoutVenteDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AjoutVenteDialog(QWidget *parent = 0);
    ~AjoutVenteDialog();
    
private:
    Ui::AjoutVenteDialog *ui;
    vente v;

    void init_vd();

private slots:
    void ajouter_une_vente();
    void changer_max();
    void vendre();
};

#endif // AJOUTVENTEDIALOG_H
