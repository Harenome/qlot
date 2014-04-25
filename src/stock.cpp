/**
 * \file stock.cpp
 * \brief Stock.
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
#include "stock.hpp"


////////////////////////////////////////////////////////////////////////////////
// Constructeurs.
////////////////////////////////////////////////////////////////////////////////

stock::stock (void)
{
}

stock::stock (const stock & s)
{
    _stock = s._stock;
}

////////////////////////////////////////////////////////////////////////////////
// Destructeurs.
////////////////////////////////////////////////////////////////////////////////

stock::~stock (void)
{
}

////////////////////////////////////////////////////////////////////////////////
// Sélecteurs.
////////////////////////////////////////////////////////////////////////////////

bool stock::article_en_stock (unsigned int reference) const
{
    return _stock.count (reference) == 1;
}

bool stock::article_en_stock (const reference_article & reference) const
{
    return article_en_stock (reference.vers_entier ());
}

bool stock::vide (void) const
{
    return _stock.empty ();
}

unsigned int stock::nombre_articles_stock (void) const
{
    return _stock.size ();
}

article_stock & stock::operator[] (unsigned int reference)
{
    return _stock[reference];
}

article_stock & stock::operator[] (const reference_article & reference)
{
    return operator[] (reference.vers_entier ());
}

const article_stock & stock::operator[] (unsigned int reference) const
{
    return _stock.find (reference)->second;
}

const article_stock & stock::operator[] (const reference_article & reference) const
{
    return operator[] (reference.vers_entier ());
}

stock_const_iterator stock::begin (void) const
{
    return _stock.begin ();
}

stock_const_iterator stock::end (void) const
{
    return _stock.end ();
}

////////////////////////////////////////////////////////////////////////////////
// Modificateurs.
////////////////////////////////////////////////////////////////////////////////

void stock::ajouter_article (const article_stock & a)
{
    _stock.insert (stock_element (a.reference ().vers_entier (), a));
}

void stock::ajouter_article (const reference_article & reference, unsigned int quantite, const pourcentage & rabais)
{
    article_stock a (reference, quantite, rabais);
    ajouter_article (a);
}

void stock::retirer_article (const article_stock & a)
{
    retirer_article (a.reference ());
}

void stock::retirer_article (unsigned int reference)
{
    _stock.erase (reference);
}

void stock::retirer_article (const reference_article & reference)
{
    retirer_article (reference.vers_entier ());
}

void stock::remplacer_reference (unsigned int ancienne_reference, unsigned int nouvelle_reference)
{
    if (article_en_stock (ancienne_reference))
    {
        article_stock nouvel_article (operator[] (ancienne_reference));
        nouvel_article.modifier_reference (nouvelle_reference);
        retirer_article (ancienne_reference);
        ajouter_article (nouvel_article);
    }
}

////////////////////////////////////////////////////////////////////////////////
// Divers.
////////////////////////////////////////////////////////////////////////////////

void stock::swap (stock & s)
{
    _stock.swap (s._stock);
}

stock & stock::operator= (stock s)
{
    this->swap (s);
    return * this;
}

std::ostream & stock::ecrire_vers (std::ostream & os) const
{
    os << nombre_articles_stock () << std::endl;
    for (stock_const_iterator it = _stock.begin (); it != _stock.end (); ++it)
        os << it->second << std::endl;

    return os;
}

////////////////////////////////////////////////////////////////////////////////
// Fonctions non membres.
////////////////////////////////////////////////////////////////////////////////

std::ostream & operator<< (std::ostream & os, const stock & s)
{
    return s.ecrire_vers (os);
}

std::istream & operator>> (std::istream & is, stock & s)
{
    bool succes;
    unsigned int quantite;
    stock nouveau_stock;

    is >> quantite;

    succes = is.good ();

    for (unsigned int i = 0; succes && i < quantite; ++i)
    {
        article_stock nouvel_article;

        is >> nouvel_article;

        succes = is.good ();
        if (succes)
            nouveau_stock.ajouter_article (nouvel_article);
    }

    if (succes)
        s = nouveau_stock;

    return is;
}

