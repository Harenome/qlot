#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "versiondialog.h"
#include "ajoutmarchandisedialog.h"
#include "ajoutventedialog.h"
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
    
private:
    Ui::MainWindow *ui;

private slots:
    void version();
    void ajoutMarchandise();
    void ajoutVente();
    void nouvellebdd();
    void enregistrer();
    void ouvrir();
};

#endif // MAINWINDOW_H
