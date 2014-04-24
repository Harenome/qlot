/**
 * \file condition_article.hpp
 * \brief Magasin.
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
#ifndef __CONDITION_ARTICLE_HPP__
#define __CONDITION_ARTICLE_HPP__

#include <functional>
#include "article.hpp"

struct condition_article : public std::unary_function<const article &, bool>
{
    virtual bool operator() (const article & a)
    {
        return true;
    }
};

struct condition_int : virtual condition_article
{
    unsigned int _valeur;
    virtual unsigned int _valeur_article (const article & a) = 0;
    bool operator() (const article & a)
    {
        return _valeur_article (a) == _valeur;
    }
};

struct condition_modele : virtual condition_int
{
    condition_modele (unsigned int modele)
    {
        _valeur = modele;
    }
    unsigned int _valeur_article (const article & a)
    {
        return a.modele ();
    }
};

struct condition_taille : virtual condition_int
{
    condition_taille (unsigned int taille)
    {
        _valeur = taille;
    }
    unsigned int _valeur_article (const article & a)
    {
        return a.taille ();
    }
};

struct condition_couleur : virtual condition_int
{
    condition_couleur (unsigned int couleur)
    {
        _valeur = couleur;
    }
    unsigned int _valeur_article (const article & a)
    {
        return a.couleur ();
    }
};

struct condition_bornes_float : virtual condition_article
{
    float _minimum;
    float _maximum;
    virtual float _valeur_article (const article & a) = 0;
    bool operator() (const article & a)
    {
        float valeur = _valeur_article (a);
        return valeur >= _minimum && valeur <= _maximum;
    }
};

struct condition_prix_achat : virtual condition_bornes_float
{
    condition_prix_achat (float minimum, float maximum)
    {
        _minimum = minimum;
        _maximum = maximum;
    }
    float _valeur_article (const article & a)
    {
        return a.prix_achat ();
    }
};

struct condition_prix_vente : virtual condition_bornes_float
{
    condition_prix_vente (float minimum, float maximum)
    {
        _minimum = minimum;
        _maximum = maximum;
    }
    float _valeur_article (const article & a)
    {
        return a.prix_vente ();
    }
};

struct condition_date : virtual condition_article
{
    date _date;
    condition_date (const date & d)
    {
        _date = d;
    }
    bool operator() (const article & a)
    {
        return a.date_livraison () == _date;
    }
};

#endif /* __CONDITION_ARTICLE_HPP__ */
