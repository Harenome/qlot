/**
 * \file magasin.cpp
 * \brief Magasin.
 * \author RAZANAJATO RANAIVOARIVONY Harenome
 * \author MEYER Jérémy
 * \date 2014
 * \copyright WTFPL version 2
 */
/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://www.wtfpl.net/ for more details.
 */
#include "magasin.hpp"

////////////////////////////////////////////////////////////////////////////////
// Constructeurs.
////////////////////////////////////////////////////////////////////////////////

magasin::magasin (void)
{
}

magasin::magasin (const magasin & m)
{
    operator= (m);
}

magasin::magasin (const articles_existants & a, const stock & s, const historique_ventes & h)
{
    _articles = a;
    _stock = s;
    _historique = h;
}

////////////////////////////////////////////////////////////////////////////////
// Destructeur.
////////////////////////////////////////////////////////////////////////////////

magasin::~magasin (void)
{
}

////////////////////////////////////////////////////////////////////////////////
// Sélecteurs.
////////////////////////////////////////////////////////////////////////////////

unsigned int magasin::nombre_articles (void) const
{
    return _articles.nombre_articles ();
}

unsigned int magasin::nombre_ventes (void) const
{
    return _historique.nombre_ventes ();
}

float magasin::total_ventes (void) const
{
    float somme = 0.0;
    for (historique_ventes_const_iterator it = _historique.begin (); it != _historique.end (); ++it)
            somme += it->second.total ();
    return somme;
}

article_affichage magasin::operator[] (unsigned int reference) const
{
    article_affichage a (_articles[reference], _stock[reference]);
    return a;
}

article_affichage magasin::operator[] (const reference_article & reference) const
{
    return operator[] (reference.vers_entier ());
}

std::vector<article_affichage> magasin::_articles_par_condition (condition_article condition) const
{
    std::vector<article_affichage> articles;

    for (articles_existants_const_iterator it = _articles.begin (); it != _articles.end (); ++it)
    {
        const article & courant = it->second;
        if (condition (courant))
        {
            unsigned int reference = courant.reference ().vers_entier ();
            article_affichage a (_articles[reference], _stock[reference]);
            articles.push_back (a);
        }
    }

    return articles;
}

std::vector<article_affichage> magasin::articles_par_modele (unsigned int modele) const
{
    condition_modele condition (modele);
    return _articles_par_condition (condition);
}

std::vector<article_affichage> magasin::articles_par_taille (unsigned int taille) const
{
    condition_taille condition (taille);
    return _articles_par_condition (condition);
}

std::vector<article_affichage> magasin::articles_par_couleur (unsigned int couleur) const
{
    condition_couleur condition (couleur);
    return _articles_par_condition (condition);
}

std::vector<article_affichage> magasin::articles_par_date (const date & date_livraison) const
{
    condition_date condition (date_livraison);
    return _articles_par_condition (condition);
}

std::vector<article_affichage> magasin::articles_par_prix_achat (float minimum, float maximum) const
{
    condition_prix_achat condition (minimum, maximum);
    return _articles_par_condition (condition);
}

std::vector<article_affichage> magasin::articles_par_prix_vente (float minimum, float maximum) const
{
    condition_prix_vente condition (minimum, maximum);
    return _articles_par_condition (condition);
}

////////////////////////////////////////////////////////////////////////////////
// Modificateurs.
////////////////////////////////////////////////////////////////////////////////

void magasin::ajouter_article (const article & a, unsigned int quantite, const pourcentage & rabais)
{
    _articles.ajouter_article (a);
    _stock.ajouter_article (a.reference (), quantite, rabais);
}

void magasin::ajouter_vente (const vente & v)
{
    _historique.ajouter_vente (v);
}

void magasin::_modificateur_reference (unsigned int reference, unsigned int valeur,
    void (* modificateur) (article &, unsigned int))
{
    /* Certaines modifications modifient la référence de l'article.
     * Les références des articles étant utilisées pour les indexer,
     * il faut changer les indexes !
     *
     * Copie, modification de la copie, suppression de « l'ancien » article,
     * ajout du « nouvel » article.
     * Remplacement des références dans le stock et l'historique.
     *
     * modificateur :
     * _modificateur_modele | _modificateur_taille | _modificateur_couleur
     */
    if (_articles.existe (reference))
    {
        article a (_articles[reference]);
        modificateur (a, valeur);
        unsigned int nouvelle_reference = a.reference ().vers_entier ();

        _articles.retirer_article (reference);
        _articles.ajouter_article (a);
        _stock.remplacer_reference (reference, nouvelle_reference);
        _historique.remplacer_references (reference, nouvelle_reference);
    }
}

void magasin::modifier_modele_article (unsigned int reference, unsigned int modele)
{
    _modificateur_reference (reference, modele, magasin::_modificateur_modele);
}

void magasin::modifier_modele_article (const reference_article & reference, unsigned int modele)
{
    modifier_modele_article (reference.vers_entier (), modele);
}

void magasin::modifier_couleur_article (unsigned int reference, unsigned int couleur)
{
    _modificateur_reference (reference, couleur, magasin::_modificateur_couleur);
}

void magasin::modifier_couleur_article (const reference_article & reference, unsigned int couleur)
{
    modifier_couleur_article (reference.vers_entier (), couleur);
}

void magasin::modifier_taille_article (unsigned int reference, unsigned int taille)
{
    _modificateur_reference (reference, taille, magasin::_modificateur_taille);
}

void magasin::modifier_taille_article (const reference_article & reference, unsigned int taille)
{
    modifier_taille_article (reference.vers_entier (), taille);
}

void magasin::modifier_quantite_article (unsigned int reference, unsigned int quantite)
{
    if (_stock.article_en_stock (reference))
        _stock[reference].modifier_quantite_stock (quantite);
}

void magasin::modifier_quantite_article (const reference_article & reference, unsigned int quantite)
{
    modifier_quantite_article (reference.vers_entier (), quantite);
}

void magasin::modifier_rabais_article (unsigned int reference, unsigned int rabais)
{
    if (_stock.article_en_stock (reference))
        _stock[reference].modifier_rabais (rabais);
}

void magasin::modifier_rabais_article (unsigned int reference, const pourcentage & rabais)
{
    if (_stock.article_en_stock (reference))
        _stock[reference].modifier_rabais (rabais);
}

void magasin::modifier_rabais_article (const reference_article & reference, unsigned int rabais)
{
    modifier_rabais_article (reference.vers_entier (), rabais);
}

void magasin::modifier_rabais_article (const reference_article & reference, const pourcentage & rabais)
{
    modifier_rabais_article (reference.vers_entier (), rabais);
}

void magasin::modifier_prix_achat_article (unsigned int reference, float prix)
{
    if (_articles.existe (reference))
        _articles[reference].modifier_prix_achat (prix);
}

void magasin::modifier_prix_achat_article (const reference_article & reference, float prix)
{
    modifier_prix_achat_article (reference.vers_entier (), prix);
}

void magasin::modifier_prix_vente_article (unsigned int reference, float prix)
{
    if (_articles.existe (reference))
        _articles[reference].modifier_prix_vente (prix);
}

void magasin::modifier_date_livraison_article (unsigned int reference, const date & date_livraison)
{
    if (_articles.existe (reference))
        _articles[reference].modifier_date_livraison (date_livraison);
}

void magasin::modifier_date_livraison_article (const reference_article & reference, const date & date_livraison)
{
    modifier_date_livraison_article (reference.vers_entier (), date_livraison);
}

void magasin::modifier_date_livraison_article (unsigned int reference, unsigned int jour, unsigned int mois, unsigned int annee)
{
    if (_articles.existe (reference))
        _articles[reference].modifier_date_livraison (jour, mois, annee);
}

void magasin::modifier_date_livraison_article (const reference_article & reference, unsigned int jour, unsigned int mois, unsigned int annee)
{
    modifier_date_livraison_article (reference.vers_entier (), jour, mois, annee);
}

void magasin::annuler_vente (const vente & v)
{
    _historique.retirer_vente (v);
}

void magasin::annuler_vente (unsigned int id)
{
    _historique.retirer_vente (id);
}

void magasin::modifier_date_vente (unsigned int id, const date & d)
{
    if (_historique.existe (id))
        _historique[id].modifier_date_vente (d);
}

void magasin::modifier_date_vente (unsigned int id, unsigned int jour, unsigned int mois, unsigned int annee)
{
    date d (jour, mois, annee);
    modifier_date_vente (id, d);
}

void magasin::annuler_vente_article (unsigned int id, unsigned int reference)
{
    if (_historique.existe (id) && _historique[id].vendu (reference))
            _historique[id].retirer_article_vendu (reference);
}

void magasin::annuler_vente_article (unsigned int id, const reference_article & reference)
{
    annuler_vente_article (id, reference.vers_entier ());
}

void magasin::modifier_vente_article_quantite (unsigned int id, unsigned int reference, unsigned int quantite)
{
    if (quantite == 0)
        annuler_vente_article (id, reference);
    else if (_historique.existe (id) && _historique[id].vendu (reference))
        _historique[id][reference].modifier_quantite_vendue (quantite);
}

void magasin::modifier_vente_article_quantite (unsigned int id, const reference_article & reference, unsigned int quantite)
{
    modifier_vente_article_quantite (id, reference.vers_entier (), quantite);
}

void magasin::modifier_vente_article_prix (unsigned int id, unsigned int reference, float prix)
{
    if (_historique.existe (id) && _historique[id].vendu (reference))
        _historique[id][reference].modifier_prix (prix);
}

void magasin::modifier_vente_article_prix (unsigned int id, const reference_article & reference, float prix)
{
    modifier_vente_article_prix (id, reference.vers_entier (), prix);
}

////////////////////////////////////////////////////////////////////////////////
// Divers.
////////////////////////////////////////////////////////////////////////////////

void magasin::swap (magasin & m)
{
    _articles.swap (m._articles);
    _stock.swap (m._stock);
    _historique.swap (m._historique);
}

magasin & magasin::operator= (magasin m)
{
    this->swap (m);
    return * this;
}

std::ostream & magasin::ecrire_articles_vers (std::ostream & os) const
{
    os << _articles;
    return os;
}

std::ostream & magasin::ecrire_stock_vers (std::ostream & os) const
{
    os << _stock;
    return os;
}

std::ostream & magasin::ecrire_historique_vers (std::ostream & os) const
{
    os << _historique;
    return os;
}

std::ostream & magasin::ecrire_vers (std::ostream & os) const
{
    os << _articles << std::endl << _stock << std::endl << _historique << std::endl;
    return os;
}

////////////////////////////////////////////////////////////////////////////////
// Fonctions non membres.
////////////////////////////////////////////////////////////////////////////////

std::ostream & operator<< (std::ostream & os, const magasin & m)
{
    return m.ecrire_vers (os);
}

std::istream & operator<< (std::istream & is, magasin & m)
{
    stock nouveau_stock;
    articles_existants nouveaux_articles;
    historique_ventes nouvel_historique;

    is >> nouveaux_articles >> nouveau_stock >> nouvel_historique;
    if (is.good ())
    {
        magasin nouveau_magasin (nouveaux_articles, nouveau_stock, nouvel_historique);
        m = nouveau_magasin;
    }

    return is;
}
