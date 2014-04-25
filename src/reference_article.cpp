/**
 * \file reference_article.cpp
 * \brief Référence d'un article.
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
#include "reference_article.hpp"

////////////////////////////////////////////////////////////////////////////////
// Initialisateurs.
////////////////////////////////////////////////////////////////////////////////

void reference_article::_initialiser (unsigned int modele, unsigned int couleur, unsigned int taille)
{
    _reference = _fabriquer_reference (modele, couleur, taille);
}

void reference_article::_initialiser (unsigned int reference)
{
    unsigned int modele = reference_article::_extraire_modele (reference);
    unsigned int couleur = reference_article::_extraire_couleur (reference);
    unsigned int taille = reference_article::_extraire_taille (reference);

    _initialiser (modele, couleur, taille);
}

////////////////////////////////////////////////////////////////////////////////
// Constructeurs.
////////////////////////////////////////////////////////////////////////////////

reference_article::reference_article (const reference_article & reference)
{
    operator= (reference);
}

reference_article::reference_article (unsigned int reference)
{
    _initialiser (reference);
}

reference_article::reference_article (unsigned int modele, unsigned int couleur, unsigned int taille)
{
    _initialiser (modele, couleur, taille);
}

////////////////////////////////////////////////////////////////////////////////
// Destructeur.
////////////////////////////////////////////////////////////////////////////////
reference_article::~reference_article (void)
{
}

////////////////////////////////////////////////////////////////////////////////
// Sélecteurs.
////////////////////////////////////////////////////////////////////////////////

unsigned int reference_article::vers_entier (void) const
{
    return _reference;
}

unsigned int reference_article::modele (void) const
{
    return _extraire_modele (_reference);
}

unsigned int reference_article::couleur (void) const
{
    return _extraire_couleur (_reference);
}

unsigned int reference_article::taille (void) const
{
    return _extraire_taille (_reference);
}

////////////////////////////////////////////////////////////////////////////////
// Modificateurs.
////////////////////////////////////////////////////////////////////////////////

void reference_article::modifier_modele (unsigned int modele)
{
    _reference = _fabriquer_reference (modele, couleur (), taille ());
}

void reference_article::modifier_couleur (unsigned int couleur)
{
    _reference = _fabriquer_reference (modele (), couleur, taille ());
}

void reference_article::modifier_taille (unsigned int taille)
{
    _reference = _fabriquer_reference (modele (), couleur (), taille);
}

////////////////////////////////////////////////////////////////////////////////
// Comparaisons.
////////////////////////////////////////////////////////////////////////////////

bool reference_article::egal (const reference_article & r) const
{
    return _reference == r._reference;
}

bool reference_article::inferieur_a (const reference_article & r) const
{
    return _reference < r._reference;
}

////////////////////////////////////////////////////////////////////////////////
// Divers.
////////////////////////////////////////////////////////////////////////////////

void reference_article::swap (reference_article & r)
{
    std::swap (_reference, r._reference);
}

reference_article & reference_article::operator= (reference_article r)
{
    this->swap (r);
    return * this;
}

////////////////////////////////////////////////////////////////////////////////
// Fonctions non membres.
////////////////////////////////////////////////////////////////////////////////

std::ostream & operator<< (std::ostream & os, const reference_article & r)
{
    os << r.vers_entier ();
    return os;
}

std::istream & operator>> (std::istream & is, reference_article & r)
{
    unsigned int reference;

    is >> reference;

    if (is.good ())
    {
        reference_article nouvelle_reference (reference);
        r = nouvelle_reference;
    }

    return is;
}
