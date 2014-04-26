/**
 * \file article.cpp
 * \brief Article.
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
#include "article.hpp"

////////////////////////////////////////////////////////////////////////////////
// Initialisateurs.
////////////////////////////////////////////////////////////////////////////////

void article::_initialiser (const reference_article & reference, double prix_achat, double prix_vente)
{
    _reference = reference;
    _prix_achat = prix_achat;
    _prix_vente = prix_vente;
}

void article::_initialiser (unsigned int modele, unsigned int couleur, unsigned int taille, double prix_achat, double prix_vente)
{
    reference_article r (modele, couleur, taille);
    _initialiser (r, prix_achat, prix_vente);
}

////////////////////////////////////////////////////////////////////////////////
// Constructeurs.
////////////////////////////////////////////////////////////////////////////////

article::article (void)
{
}

article::article (const article & a)
{
    _initialiser (a.reference (), a.prix_achat (), a.prix_vente ());
    _date_livraison = a.date_livraison ();
}

article::article (const reference_article & reference, double prix_achat, double prix_vente)
{
    _initialiser (reference, prix_achat, prix_vente);
}

article::article (const reference_article & reference, double prix_achat, double prix_vente, const date & date_livraison)
{
    _initialiser (reference, prix_achat, prix_vente);
    _date_livraison = date_livraison;
}

article::article (unsigned int modele, unsigned int couleur, unsigned int taille, double prix_achat, double prix_vente)
{
    _initialiser (modele, couleur, taille, prix_achat, prix_vente);
}

article::article (unsigned int modele, unsigned int couleur, unsigned int taille, double prix_achat, double prix_vente, const date & date_livraison)
{
    _initialiser (modele, couleur, taille, prix_achat, prix_vente);
    _date_livraison = date_livraison;
}

////////////////////////////////////////////////////////////////////////////////
// Destructeur.
////////////////////////////////////////////////////////////////////////////////

article::~article (void)
{
}

////////////////////////////////////////////////////////////////////////////////
// Sélecteurs.
////////////////////////////////////////////////////////////////////////////////

reference_article article::reference (void) const
{
    return _reference;
}

unsigned int article::modele (void) const
{
    return _reference.modele ();
}

unsigned int article::couleur (void) const
{
    return _reference.couleur ();
}

unsigned int article::taille (void) const
{
    return _reference.taille ();
}

double article::prix_achat (void) const
{
    return _prix_achat;
}

double article::prix_vente (void) const
{
    return _prix_vente;
}

date article::date_livraison (void) const
{
    return _date_livraison;
}

////////////////////////////////////////////////////////////////////////////////
// Modificateurs.
////////////////////////////////////////////////////////////////////////////////

void article::modifier_modele (unsigned int modele)
{
    _reference.modifier_modele (modele);
}

void article::modifier_taille (unsigned int taille)
{
    _reference.modifier_taille (taille);
}

void article::modifier_couleur (unsigned int couleur)
{
    _reference.modifier_couleur (couleur);
}

void article::modifier_prix_achat (double prix_achat)
{
    _prix_achat = prix_achat;
}

void article::modifier_prix_vente (double prix_vente)
{
    _prix_vente = prix_vente;
}

void article::modifier_date_livraison (const date & date_livraison)
{
    _date_livraison = date_livraison;
}

void article::modifier_date_livraison (unsigned int jour, unsigned int mois, unsigned int annee)
{
    _date_livraison.modifier (jour, mois, annee);
}

////////////////////////////////////////////////////////////////////////////////
// Divers.
////////////////////////////////////////////////////////////////////////////////

void article::swap (article & a)
{
    _reference.swap (a._reference);
    _date_livraison.swap (a._date_livraison);
    std::swap (_prix_achat, a._prix_achat);
    std::swap (_prix_vente, a._prix_vente);
}

article & article::operator= (article a)
{
    this->swap (a);
    return * this;
}

////////////////////////////////////////////////////////////////////////////////
// Fonctions non membres.
////////////////////////////////////////////////////////////////////////////////

std::ostream & operator<< (std::ostream & os, const article & a)
{
    os << a.reference () << " " << a.date_livraison () << " ";
    os << a.prix_achat () << " " << a.prix_vente ();
    return os;
}

std::istream & operator>> (std::istream & is, article & a)
{
    reference_article reference;
    date date_livraison;
    double prix_achat, prix_vente;

    is >> reference >> date_livraison >> prix_achat >> prix_vente;

    if (! is.good () || prix_achat < 0. || prix_vente < 0.)
    {
        is.setstate (std::ios_base::failbit);
    }
    else
    {
        article nouvel_article (reference, prix_achat, prix_vente, date_livraison);
        a = nouvel_article;
    }

    return is;
}
