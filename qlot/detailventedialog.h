#ifndef DETAILVENTEDIALOG_H
#define DETAILVENTEDIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include "vente.hpp"

namespace Ui {
class DetailVenteDialog;
}

class DetailVenteDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit DetailVenteDialog(QWidget *parent = 0);
    ~DetailVenteDialog();
    
private:
    Ui::DetailVenteDialog *ui;
    void charge_detail(const vente &v);
};

#endif // DETAILVENTEDIALOG_H
