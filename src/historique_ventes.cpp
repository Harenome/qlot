/**
 * \file historique_ventes.cpp
 * \brief Historique ventes.
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
#include "historique_ventes.hpp"

////////////////////////////////////////////////////////////////////////////////
// Constructeurs.
////////////////////////////////////////////////////////////////////////////////

historique_ventes::historique_ventes (void)
{
}

historique_ventes::historique_ventes (const historique_ventes & h)
{
    _ventes = h._ventes;
}

////////////////////////////////////////////////////////////////////////////////
// Destructeurs.
////////////////////////////////////////////////////////////////////////////////

historique_ventes::~historique_ventes (void)
{
}

////////////////////////////////////////////////////////////////////////////////
// Sélecteurs.
////////////////////////////////////////////////////////////////////////////////

bool historique_ventes::existe (unsigned int id)
{
    return _ventes.count (id) == 1;
}

vente & historique_ventes::operator[] (unsigned int id)
{
    return _ventes[id];
}

const vente & historique_ventes::operator[] (unsigned int id) const
{
    return _ventes.find (id)->second;
}

unsigned int historique_ventes::nombre_ventes (void) const
{
    return _ventes.size ();
}

double historique_ventes::total (void) const
{
    double somme = 0.0;
    for (historique_ventes_const_iterator it = _ventes.begin (); it != _ventes.end (); ++it)
        somme += it->second.total ();
    return somme;
}

historique_ventes_const_iterator historique_ventes::begin (void) const
{
    return _ventes.begin ();
}

historique_ventes_const_iterator historique_ventes::end (void) const
{
    return _ventes.end ();
}

////////////////////////////////////////////////////////////////////////////////
// Modificateurs.
////////////////////////////////////////////////////////////////////////////////

void historique_ventes::ajouter_vente (const vente & v)
{
    _ventes.insert (historique_ventes_element (v.id (), v));
}

void historique_ventes::retirer_vente (const vente & v)
{
    retirer_vente (v.id ());
}

void historique_ventes::retirer_vente (unsigned int id)
{
    _ventes.erase (id);
}

void historique_ventes::remplacer_references (unsigned int ancienne, unsigned int nouvelle)
{
    for (historique_ventes_iterator it = _ventes.begin (); it != _ventes.end (); ++it)
        it->second.remplacer_reference (ancienne, nouvelle);
}

void historique_ventes::remplacer_references (const reference_article & ancienne, const reference_article & nouvelle)
{
    remplacer_references (ancienne.vers_entier (), nouvelle.vers_entier ());
}

////////////////////////////////////////////////////////////////////////////////
// Divers.
////////////////////////////////////////////////////////////////////////////////

void historique_ventes::swap (historique_ventes & h)
{
    _ventes.swap (h._ventes);
}

historique_ventes & historique_ventes::operator= (historique_ventes h)
{
    this->swap (h);
    return * this;
}

std::ostream & historique_ventes::ecrire_vers (std::ostream & os) const
{
    os << nombre_ventes () << std::endl;

    for (historique_ventes_map::const_iterator it = _ventes.begin (); it != _ventes.end (); ++it)
        os << it->second << std::endl;

    return os;
}

////////////////////////////////////////////////////////////////////////////////
// Fonctions non membres.
////////////////////////////////////////////////////////////////////////////////

std::ostream & operator<< (std::ostream & os, const historique_ventes & h)
{
    return h.ecrire_vers (os);
}

std::istream & operator>> (std::istream & is, historique_ventes & h)
{
    bool succes;
    unsigned int quantite;
    historique_ventes nouvel_historique;

    is >> quantite;
    succes = is.good ();

    for (unsigned int i = 0; succes && i < quantite; ++i)
    {
        vente nouvelle_vente;
        is >> nouvelle_vente;
        succes = is.good ();
        if (succes)
            nouvel_historique.ajouter_vente (nouvelle_vente);
    }

    if (succes)
        h = nouvel_historique;

    return is;
}
