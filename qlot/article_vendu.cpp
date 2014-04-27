/**
 * \file article_vendu.cpp
 * \brief Article vendu.
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
#include "article_vendu.hpp"

////////////////////////////////////////////////////////////////////////////////
// Initialisateur.
////////////////////////////////////////////////////////////////////////////////

void article_vendu::_initialiser (const reference_article & reference, unsigned int quantite, double prix)
{
    _reference = reference;
    _quantite = quantite;
    _prix = prix;
}

////////////////////////////////////////////////////////////////////////////////
// Constructeurs.
////////////////////////////////////////////////////////////////////////////////

article_vendu::article_vendu (void)
{
    reference_article r (0);
    _initialiser (r, 0, 0);
}

article_vendu::article_vendu (const reference_article & reference, unsigned int quantite, double prix)
{
    _initialiser (reference, quantite, prix);
}

article_vendu::article_vendu (const article_vendu & a)
{
    _initialiser (a.reference (), a.quantite_vendue (), a.prix ());
}

////////////////////////////////////////////////////////////////////////////////
// Destructeur.
////////////////////////////////////////////////////////////////////////////////

article_vendu::~article_vendu (void)
{
}

////////////////////////////////////////////////////////////////////////////////
// Sélecteurs.
////////////////////////////////////////////////////////////////////////////////

unsigned int article_vendu::quantite_vendue (void) const
{
    return _quantite;
}

double article_vendu::prix (void) const
{
    return _prix;
}

double article_vendu::total (void) const
{
    return quantite_vendue () * prix ();
}

reference_article article_vendu::reference (void) const
{
    return _reference;
}

////////////////////////////////////////////////////////////////////////////////
// Modificateurs.
////////////////////////////////////////////////////////////////////////////////

void article_vendu::modifier_reference (unsigned int reference)
{
    reference_article r (reference);
    modifier_reference (r);
}

void article_vendu::modifier_reference (const reference_article & reference)
{
    _reference = reference;
}

void article_vendu::modifier_quantite_vendue (unsigned int quantite)
{
    _quantite = quantite;
}

void article_vendu::modifier_prix (double prix)
{
    _prix = prix;
}

////////////////////////////////////////////////////////////////////////////////
// Divers.
////////////////////////////////////////////////////////////////////////////////

void article_vendu::swap (article_vendu & a)
{
    _reference.swap (a._reference);
    std::swap (_quantite, a._quantite);
    std::swap (_prix, a._prix);
}

article_vendu & article_vendu::operator= (article_vendu a)
{
    this->swap (a);
    return * this;
}

////////////////////////////////////////////////////////////////////////////////
// Fonctions non membres.
////////////////////////////////////////////////////////////////////////////////

std::ostream & operator<< (std::ostream & os, const article_vendu & a)
{
    os << a.reference () << " " << a.quantite_vendue () << " " << a.prix ();

    return os;
}

std::istream & operator>> (std::istream & is, article_vendu & a)
{
    reference_article reference;
    unsigned int quantite;
    double prix;

    is >> reference >> quantite >> prix;

    if (! is.good () || prix < 0.)
    {
        is.setstate (std::ios_base::failbit);
    }
    else
    {
        article_vendu nouvel_article_vendu (reference, quantite, prix);
        a = nouvel_article_vendu;
    }

    return is;
}
