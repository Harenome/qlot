/**
 * \file pourcentage.cpp
 * \brief Pourcentage.
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
#include "pourcentage.hpp"

////////////////////////////////////////////////////////////////////////////////
// Variables.
////////////////////////////////////////////////////////////////////////////////

const pourcentage ZERO (0);
const pourcentage CENT (100);

////////////////////////////////////////////////////////////////////////////////
// Constructeurs.
////////////////////////////////////////////////////////////////////////////////

pourcentage::pourcentage (unsigned int valeur)
{
    modifier_valeur (valeur);
}

pourcentage::pourcentage (const pourcentage & p)
{
    operator= (p);
}

////////////////////////////////////////////////////////////////////////////////
// Destructeur.
////////////////////////////////////////////////////////////////////////////////

pourcentage::~pourcentage (void)
{
}

////////////////////////////////////////////////////////////////////////////////
// Modificateurs.
////////////////////////////////////////////////////////////////////////////////

void pourcentage::modifier_valeur (unsigned int valeur)
{
    _valeur = pourcentage::_seuil_valeur (valeur);
}

void pourcentage::modifier_valeur (const pourcentage & p)
{
    modifier_valeur (p.valeur ());
}

////////////////////////////////////////////////////////////////////////////////
// Sélecteur.
////////////////////////////////////////////////////////////////////////////////

unsigned int pourcentage::valeur (void) const
{
    return _valeur;
}

////////////////////////////////////////////////////////////////////////////////
// Comparaisons.
////////////////////////////////////////////////////////////////////////////////

bool pourcentage::egal (const pourcentage & p) const
{
    return valeur () == p.valeur ();
}

bool pourcentage::inferieur_a (const pourcentage & p) const
{
    return valeur () < p.valeur ();
}

////////////////////////////////////////////////////////////////////////////////
// Divers.
////////////////////////////////////////////////////////////////////////////////

#define _appliquer_a(x) (x) * _valeur / 100.

float pourcentage::appliquer_a (float f) const
{
    return _appliquer_a (f);
}

double pourcentage::appliquer_a (double d) const
{
    return _appliquer_a (d);
}

#undef _appliquer_a

void pourcentage::swap (pourcentage & p)
{
    std::swap (_valeur, p._valeur);
}

pourcentage & pourcentage::operator= (pourcentage p)
{
    this->swap (p);
    return * this;
}

////////////////////////////////////////////////////////////////////////////////
// Fonctions non membres.
////////////////////////////////////////////////////////////////////////////////

std::ostream & operator<< (std::ostream & os, const pourcentage & p)
{
    os << p.valeur () << '%';
    return os;
}

std::istream & operator>> (std::istream & is, pourcentage & p)
{
    unsigned int valeur;
    unsigned int caractere;

    is >> valeur >> caractere;

    if ((! is.good ()) || caractere != '%' || valeur > pourcentage::MAXIMUM || valeur < pourcentage::MINIMUM)
    {
        is.setstate (std::ios_base::failbit);
    }
    else
    {
        pourcentage nouveau_pourcentage (valeur);
        p = nouveau_pourcentage;
    }

    return is;
}
