/**
 * \file article_stock.cpp
 * \brief Article stock.
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
#include "article_stock.hpp"

////////////////////////////////////////////////////////////////////////////////
// Constructeurs.
////////////////////////////////////////////////////////////////////////////////

article_stock::article_stock (void)
{
}

article_stock::article_stock (const article_stock & a)
{
    _reference = a.reference ();
    _quantite_stock = a.quantite_stock ();
    _rabais = a.rabais ();
}

article_stock::article_stock (const reference_article & reference, unsigned int quantite, const pourcentage & rabais)
{
    _reference = reference;
    _quantite_stock = quantite;
    _rabais = rabais;
}

////////////////////////////////////////////////////////////////////////////////
// Destructeur.
////////////////////////////////////////////////////////////////////////////////

article_stock::~article_stock (void)
{
}

////////////////////////////////////////////////////////////////////////////////
// Sélecteurs.
////////////////////////////////////////////////////////////////////////////////

pourcentage article_stock::rabais (void) const
{
    return _rabais;
}

unsigned int article_stock::quantite_stock (void) const
{
    return _quantite_stock;
}

reference_article article_stock::reference (void) const
{
    return _reference;
}

////////////////////////////////////////////////////////////////////////////////
// Modificateurs.
////////////////////////////////////////////////////////////////////////////////

void article_stock::modifier_reference (unsigned int reference)
{
    reference_article r (reference);
    modifier_reference (r);
}

void article_stock::modifier_reference (const reference_article & reference)
{
    _reference = reference;
}

void article_stock::modifier_rabais (const pourcentage & rabais)
{
    _rabais = rabais;
}

void article_stock::modifier_rabais (unsigned int rabais)
{
    pourcentage r (rabais);
    modifier_rabais (r);
}

void article_stock::modifier_quantite_stock (unsigned int quantite)
{
    _quantite_stock = quantite;
}

////////////////////////////////////////////////////////////////////////////////
// Divers.
////////////////////////////////////////////////////////////////////////////////

void article_stock::swap (article_stock & a)
{
    std::swap (_quantite_stock, a._quantite_stock);
    _rabais.swap (a._rabais);
    _rabais.swap (a._rabais);
}

article_stock & article_stock::operator= (article_stock a)
{
    this->swap (a);
    return * this;
}

////////////////////////////////////////////////////////////////////////////////
// Fonctions non membres.
////////////////////////////////////////////////////////////////////////////////

std::ostream & operator<< (std::ostream & os, const article_stock & a)
{
    os << a.reference () << " " << a.quantite_stock () << " " << a.rabais ();

    return os;
}

std::istream & operator>> (std::istream & is, article_stock & a)
{
    reference_article reference;
    unsigned int quantite;
    pourcentage rabais;

    is >> reference >> quantite >> rabais;

    if (is.good ())
    {
        article_stock nouvel_article (reference, quantite, rabais);
        a = nouvel_article;
    }

    return is;
}
