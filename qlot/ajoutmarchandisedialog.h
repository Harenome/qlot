#ifndef AJOUTMARCHANDISEDIALOG_H
#define AJOUTMARCHANDISEDIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class AjoutMarchandiseDialog;
}

class AjoutMarchandiseDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AjoutMarchandiseDialog(QWidget *parent = 0);
    ~AjoutMarchandiseDialog();
    
private:
    Ui::AjoutMarchandiseDialog *ui;

private slots:
    void validation();
};

#endif // AJOUTMARCHANDISEDIALOG_H
