#ifndef STOCKDIALOG_H
#define STOCKDIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class StockDialog;
}

class StockDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit StockDialog(QWidget *parent = 0);
    ~StockDialog();
    
private:
    Ui::StockDialog *ui;

private slots:
    void refresh_nb();
};

#endif // STOCKDIALOG_H
