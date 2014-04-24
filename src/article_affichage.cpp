/**
 * \file article_affichage.cpp
 * \brief Article affichage.
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
#include "article_affichage.hpp"

////////////////////////////////////////////////////////////////////////////////
// Constructeurs.
////////////////////////////////////////////////////////////////////////////////

article_affichage::article_affichage (void)
{
}

article_affichage::article_affichage (const article_affichage & a)
{
    operator= (a);
}

article_affichage::article_affichage (const article & a, const article_stock & s)
{
    _article = a;
    _article_stock = s;
}

////////////////////////////////////////////////////////////////////////////////
// Destructeur.
////////////////////////////////////////////////////////////////////////////////

article_affichage::~article_affichage (void)
{
}


////////////////////////////////////////////////////////////////////////////////
// Sélecteurs.
////////////////////////////////////////////////////////////////////////////////

reference_article article_affichage::reference (void) const
{
    return _article.reference ();
}

date article_affichage::date_livraison (void) const
{
    return _article.date_livraison ();
}

float article_affichage::prix_achat (void) const
{
    return _article.prix_achat ();
}

float article_affichage::prix_vente (void) const
{
    return _article.prix_vente ();
}

float article_affichage::prix_vente_effectif (void) const
{
    return rabais ().appliquer_a (prix_vente ());
}

unsigned int article_affichage::quantite_stock (void) const
{
    return _article_stock.quantite_stock ();
}

pourcentage article_affichage::rabais (void) const
{
    return _article_stock.rabais ();
}

////////////////////////////////////////////////////////////////////////////////
// Divers.
////////////////////////////////////////////////////////////////////////////////

void article_affichage::swap (article_affichage & a)
{
    _article.swap (a._article);
    _article_stock.swap (a._article_stock);
}

article_affichage & article_affichage::operator= (article_affichage a)
{
    this->swap (a);
    return * this;
}
