#include "modifarticledialog.h"
#include "ui_modifarticledialog.h"

ModifArticleDialog::ModifArticleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifArticleDialog)
{
    ui->setupUi(this);

    MainWindow * pere = (MainWindow *)parentWidget();

    init_modif(pere->id_vente);

    QObject::connect(ui->ajout_marchandise_button,SIGNAL(clicked()),this,SLOT(modifie_article()),Qt::AutoConnection);
}

ModifArticleDialog::~ModifArticleDialog()
{
    delete ui;
}

void ModifArticleDialog::init_modif(unsigned int ref)
{
    ui->spinBox_modele->setValue(ref);
}

void ModifArticleDialog::modifie_article()
{
    MainWindow * parent = (MainWindow *)parentWidget();
    parent->m.modifier_quantite_article(ui->spinBox_modele->value(),ui->spinBox_quantite->value());

    date d(ui->dateEdit_livraison->date().day(),ui->dateEdit_livraison->date().month(),ui->dateEdit_livraison->date().year());
    parent->m.modifier_date_livraison_article(ui->spinBox_modele->value(),d);

    parent->m.modifier_prix_achat_article(ui->spinBox_modele->value(),ui->doubleSpinBox_achat->value());
    parent->m.modifier_prix_vente_article(ui->spinBox_modele->value(),ui->doubleSpinBox_vente->value());

    parent->m.modifier_rabais_article(ui->spinBox_modele->value(),ui->spinBox_rabais->value());
    emit(accept());
}
