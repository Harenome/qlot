/**
 * \file article_vendu_affichage.hpp
 * \brief Article vendu affichage.
 * \author RAZANAJATO RANAIVOARIVONY Harenome
 * \author MEYER Jérémy
 * \date 2014
 * \copyright WTFPL version 2 */
/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://www.wtfpl.net/ for more details.
 */
#include "article_vendu_affichage.hpp"

article_vendu_affichage::article_vendu_affichage (void)
: _article_vendu ()
{
}

article_vendu_affichage::article_vendu_affichage (unsigned int id_vente, const reference_article & reference, unsigned int quantite, double prix)
: _article_vendu (reference, quantite, prix)
{
    _id_vente = id_vente;
}

article_vendu_affichage::article_vendu_affichage (unsigned int id_vente, const article_vendu & a)
: _article_vendu (a)
{
    _id_vente = id_vente;
}

article_vendu_affichage::~article_vendu_affichage (void)
{
}

unsigned int article_vendu_affichage::id_vente (void) const
{
    return _id_vente;
}

reference_article article_vendu_affichage::reference (void) const
{
    return _article_vendu.reference ();
}

unsigned int article_vendu_affichage::quantite_vendue (void) const
{
    return _article_vendu.quantite_vendue ();
}

double article_vendu_affichage::prix (void) const
{
    return _article_vendu.prix ();
}

double article_vendu_affichage::total (void) const
{
    return _article_vendu.total ();
}

void article_vendu_affichage::swap (article_vendu_affichage & a)
{
    _article_vendu.swap (a);
    std::swap (_id_vente, a._id_vente);
}

article_vendu_affichage & article_vendu_affichage::operator= (article_vendu_affichage a)
{
    this->swap (a);
    return * this;
}

std::ostream & operator<< (std::ostream & os, const article_vendu_affichage & a)
{
    os << a.id_vente () << " " << a.reference () << " " << a.quantite_vendue () << " " << a.prix ();
    return os;
}
