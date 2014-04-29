#ifndef MODIFARTICLEDIALOG_H
#define MODIFARTICLEDIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class ModifArticleDialog;
}

class ModifArticleDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ModifArticleDialog(QWidget *parent = 0);
    ~ModifArticleDialog();
    
private:
    Ui::ModifArticleDialog *ui;
    void init_modif(unsigned int ref);

private slots:
    void modifie_article();
};

#endif // MODIFARTICLEDIALOG_H
