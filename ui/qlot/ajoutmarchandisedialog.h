#ifndef AJOUTMARCHANDISEDIALOG_H
#define AJOUTMARCHANDISEDIALOG_H

#include <QDialog>

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
};

#endif // AJOUTMARCHANDISEDIALOG_H
