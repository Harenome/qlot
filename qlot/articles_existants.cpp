/**
 * \file articles_existants.cpp
 * \brief Articles existants.
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
#include "articles_existants.hpp"

////////////////////////////////////////////////////////////////////////////////
// Constructeurs.
////////////////////////////////////////////////////////////////////////////////

articles_existants::articles_existants (void)
{
}

articles_existants::articles_existants (const articles_existants & a)
{
    _articles = a._articles;
}

////////////////////////////////////////////////////////////////////////////////
// Destructeurs.
////////////////////////////////////////////////////////////////////////////////

articles_existants::~articles_existants (void)
{
}

////////////////////////////////////////////////////////////////////////////////
// Sélecteurs.
////////////////////////////////////////////////////////////////////////////////

bool articles_existants::existe (const reference_article & reference) const
{
    return existe (reference.vers_entier ());
}

bool articles_existants::existe (unsigned int reference) const
{
    return _articles.count (reference) == 1;
}

unsigned int articles_existants::nombre_articles (void) const
{
    return _articles.size ();
}

article & articles_existants::operator[] (unsigned int reference)
{
    return _articles[reference];
}

article & articles_existants::operator[] (const reference_article & reference)
{
    return operator[] (reference.vers_entier ());
}

const article & articles_existants::operator[] (unsigned int reference) const
{
    return _articles.find (reference)->second;
}

const article & articles_existants::operator[] (const reference_article & reference) const
{
    return operator[] (reference.vers_entier ());
}

articles_existants_const_iterator articles_existants::begin (void) const
{
    return _articles.begin ();
}

articles_existants_const_iterator articles_existants::end (void) const
{
    return _articles.end ();
}

////////////////////////////////////////////////////////////////////////////////
// Modificateurs.
////////////////////////////////////////////////////////////////////////////////

void articles_existants::ajouter_article (const article & a)
{
    _articles.insert (articles_existants_element (a.reference ().vers_entier (), a));
}

void articles_existants::retirer_article (const article & a)
{
    retirer_article (a.reference ());
}

void articles_existants::retirer_article (const reference_article & reference)
{
    retirer_article (reference.vers_entier ());
}

void articles_existants::retirer_article (unsigned int reference)
{
    _articles.erase (reference);
}

////////////////////////////////////////////////////////////////////////////////
// Divers.
////////////////////////////////////////////////////////////////////////////////

articles_existants & articles_existants::operator= (articles_existants a)
{
    this->swap (a);
    return * this;
}

void articles_existants::swap (articles_existants & a)
{
    _articles.swap (a._articles);
}

std::ostream & articles_existants::ecrire_vers (std::ostream & os) const
{
    os << nombre_articles () << std::endl;
    for (articles_existants_const_iterator it = _articles.begin (); it != _articles.end (); ++it)
        os << it->second << std::endl;

    return os;
}

////////////////////////////////////////////////////////////////////////////////
// Fonctions non membres.
////////////////////////////////////////////////////////////////////////////////

std::ostream & operator<< (std::ostream & os, const articles_existants & a)
{
    return a.ecrire_vers (os);
}

std::istream & operator>> (std::istream & is, articles_existants & a)
{
    bool succes;
    unsigned int quantite;
    articles_existants nouveaux_articles;

    is >> quantite;
    succes = is.good ();

    for (unsigned int i = 0; succes && i < quantite; ++i)
    {
        article nouvel_article;
        is >> nouvel_article;
        succes = is.good ();
        if (succes)
            nouveaux_articles.ajouter_article (nouvel_article);
    }

    if (succes)
        a = nouveaux_articles;

    return is;
}
