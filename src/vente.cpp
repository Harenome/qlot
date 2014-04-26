/**
 * \file vente.cpp
 * \brief Vente.
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
#include "vente.hpp"

////////////////////////////////////////////////////////////////////////////////
// Variable.
////////////////////////////////////////////////////////////////////////////////

unsigned int vente::_id_suivant = 0;

////////////////////////////////////////////////////////////////////////////////
// Constructeur.
////////////////////////////////////////////////////////////////////////////////

vente::vente (void)
{
}

vente::vente (const date & date_vente)
{
    _id = _id_suivant;
    _date_vente = date_vente;
    _id_suivant++;
}

vente::vente (unsigned int id, const date & date_vente)
{
    _id = id;
    _date_vente = date_vente;
}

vente::vente (const vente & v)
{
    _id = v._id;
    _date_vente = v._date_vente;
    _articles_vendus = v._articles_vendus;
}

////////////////////////////////////////////////////////////////////////////////
// Destructeur.
////////////////////////////////////////////////////////////////////////////////

vente::~vente (void)
{
}

////////////////////////////////////////////////////////////////////////////////
// Sélecteurs.
////////////////////////////////////////////////////////////////////////////////

unsigned int vente::id (void) const
{
    return _id;
}

double vente::total (void) const
{
    double somme = 0.0;
    for (vente_map::const_iterator it = _articles_vendus.begin (); it != _articles_vendus.end (); ++it)
        somme += it->second.total ();
    return somme;
}

date vente::date_vente (void) const
{
    return _date_vente;
}

unsigned int vente::quantite_articles_vendus (void) const
{
    return _articles_vendus.size ();
}

bool vente::vendu_article (unsigned int reference) const
{
    return _articles_vendus.count (reference) == 1;
}

bool vente::vendu_article (const reference_article & reference) const
{
    return vendu_article (reference.vers_entier ());
}

bool vente::vendu_modele (unsigned int modele) const
{
    bool trouve = false;
    for (vente_const_iterator it = _articles_vendus.begin (); ! trouve && it != _articles_vendus.end (); ++it)
    {
        article_vendu a = it->second;
        trouve = a.reference ().modele () == modele;
    }
    return trouve;
}

bool vente::vendu_taille (unsigned int taille) const
{
    bool trouve = false;
    for (vente_const_iterator it = _articles_vendus.begin (); ! trouve && it != _articles_vendus.end (); ++it)
    {
        article_vendu a = it->second;
        trouve = a.reference ().taille () == taille;
    }
    return trouve;
}

bool vente::vendu_couleur (unsigned int couleur) const
{
    bool trouve = false;
    for (vente_const_iterator it = _articles_vendus.begin (); ! trouve && it != _articles_vendus.end (); ++it)
    {
        article_vendu a = it->second;
        trouve = a.reference ().couleur () == couleur;
    }
    return trouve;
}

article_vendu & vente::operator[] (unsigned int reference)
{
    return _articles_vendus[reference];
}

article_vendu & vente::operator[] (const reference_article & reference)
{
    return operator[] (reference.vers_entier ());
}

const article_vendu & vente::operator[] (unsigned int reference) const
{
    return _articles_vendus.find (reference)->second;
}

const article_vendu & vente::operator[] (const reference_article & reference) const
{
    return operator[] (reference.vers_entier ());
}

////////////////////////////////////////////////////////////////////////////////
// Modificateurs.
////////////////////////////////////////////////////////////////////////////////

void vente::ajouter_article_vendu (const article_vendu & a)
{
    vente_element p (a.reference ().vers_entier (), a);
    _articles_vendus.insert (p);
}

void vente::modifier_date_vente (const date & date_vente)
{
    _date_vente = date_vente;
}

void vente::retirer_article_vendu (unsigned int reference)
{
    if (vendu_article (reference))
        _articles_vendus.erase (reference);
}

void vente::retirer_article_vendu (const reference_article & reference)
{
    retirer_article_vendu (reference.vers_entier ());
}

void vente::remplacer_reference (unsigned int ancienne_reference, unsigned int nouvelle_reference)
{
    if (vendu_article (ancienne_reference))
    {
        article_vendu nouvel_article (operator[] (ancienne_reference));
        nouvel_article.modifier_reference (nouvelle_reference);
        retirer_article_vendu (ancienne_reference);
        ajouter_article_vendu (nouvel_article);
    }
}

void vente::remplacer_reference (const reference_article & ancienne_reference, const reference_article & nouvelle_reference)
{
    remplacer_reference (ancienne_reference.vers_entier (), nouvelle_reference.vers_entier ());
}

////////////////////////////////////////////////////////////////////////////////
// Divers.
////////////////////////////////////////////////////////////////////////////////

vente & vente::operator= (vente v)
{
    this->swap (v);
    return * this;
}

void vente::swap (vente & v)
{
    std::swap (_id, v._id);
    std::swap (_date_vente, v._date_vente);
    _articles_vendus.swap (v._articles_vendus);
}

std::ostream & vente::sortie (std::ostream & os) const
{
    os << id () << " " << date_vente () << " " << quantite_articles_vendus () << std::endl;
    for (vente_map::const_iterator it = _articles_vendus.begin (); it != _articles_vendus.end (); ++it)
        os << it->second << std::endl;

    return os;
}

////////////////////////////////////////////////////////////////////////////////
// Fonctions non membres.
////////////////////////////////////////////////////////////////////////////////

std::ostream & operator<< (std::ostream & os, const vente & v)
{
    return v.sortie (os);
}

std::istream & operator>> (std::istream & is, vente & v)
{
    bool succes;
    date d;
    unsigned int id;
    unsigned int quantite;

    is >> id >> d >> quantite;
    succes = is.good ();

    if (succes)
    {
        vente nouvelle_vente (id, d);
        for (unsigned int i = 0; succes && i < quantite; ++i)
        {
            article_vendu nouvel_article;
            is >> nouvel_article;
            succes = is.good ();
            if (succes)
                nouvelle_vente.ajouter_article_vendu (nouvel_article);
        }

        if (succes)
            v = nouvelle_vente;
    }

    return is;
}
