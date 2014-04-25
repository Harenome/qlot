#ifndef AJOUTVENTEDIALOG_H
#define AJOUTVENTEDIALOG_H

#include <QDialog>

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
};

#endif // AJOUTVENTEDIALOG_H
