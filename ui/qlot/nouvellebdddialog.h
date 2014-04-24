#ifndef NOUVELLEBDDDIALOG_H
#define NOUVELLEBDDDIALOG_H

#include <QDialog>

namespace Ui {
class NouvelleBDDDialog;
}

class NouvelleBDDDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit NouvelleBDDDialog(QWidget *parent = 0);
    ~NouvelleBDDDialog();
    
private:
    Ui::NouvelleBDDDialog *ui;
};

#endif // NOUVELLEBDDDIALOG_H
