/**
 * \file condition_article.hpp
 * \brief Condition article.
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

/**
 * \brief Simulacre de fonction d'ordre supérieur pour tester une condition sur un article.
 */
struct condition_article : public std::unary_function<const article &, bool>
{
    /**
     * \brief Test d'un article.
     * \param a Article à tester.
     * \return Résultat du test.
     */
    virtual bool operator() (const article & a) const
    {
        return true;
    }
};

/**
 * \brief Tester un article à l'aide d'un entier.
 */
struct condition_article_int : virtual condition_article
{
    unsigned int _valeur;   /**<- Valeur à comparer lors de l'application du test. */

    /**
     * \brief Obtenir l'information pertinente sur l'article.
     * \param a Article.
     * \return Information jugée pertinente.
     */
    virtual unsigned int _valeur_article (const article & a) const = 0;

    bool operator() (const article & a) const
    {
        return _valeur_article (a) == _valeur;
    }
};

/**
 * \brief Tester si le modèle d'un article correspond.
 */
struct condition_article_modele : virtual condition_article_int
{
    /**
     * \brief Constructeur.
     * \param modele Modèle recherché.
     */
    condition_article_modele (unsigned int modele)
    {
        _valeur = modele;
    }

    unsigned int _valeur_article (const article & a) const
    {
        return a.modele ();
    }
};

/**
 * \brief Tester si la taille d'un article correspond.
 */
struct condition_article_taille : virtual condition_article_int
{
    /**
     * \brief Constructeur.
     * \param taille Taille recherchée.
     */
    condition_article_taille (unsigned int taille)
    {
        _valeur = taille;
    }

    unsigned int _valeur_article (const article & a) const
    {
        return a.taille ();
    }
};

/**
 * \brief Tester si la couleur d'un article correspond.
 */
struct condition_article_couleur : virtual condition_article_int
{
    /**
     * \brief Constructeur.
     * \param couleur Couleur recherchée.
     */
    condition_article_couleur (unsigned int couleur)
    {
        _valeur = couleur;
    }
    unsigned int _valeur_article (const article & a) const
    {
        return a.couleur ();
    }
};

/**
 * \brief Tester un article à l'aide de deux bornes.
 */
struct condition_article_bornes_double : virtual condition_article
{
    double _minimum;    /**<- Borne inférieure. */
    double _maximum;    /**<- Borne supérieure. */

    /**
     * \brief Obtenir l'information pertinente sur l'article.
     * \param a Article.
     * \return Information jugée pertinente.
     */
    virtual double _valeur_article (const article & a) const = 0;

    bool operator() (const article & a) const
    {
        double valeur = _valeur_article (a);
        return valeur >= _minimum && valeur <= _maximum;
    }
};

/**
 * \brief Tester si le prix d'achat d'un article est dans le bon intervalle.
 */
struct condition_article_prix_achat : virtual condition_article_bornes_double
{
    /**
     * \brief Constructeur.
     * \param minimum Borne inférieure.
     * \param maximum Borne supérieure.
     */
    condition_article_prix_achat (double minimum, double maximum)
    {
        _minimum = minimum;
        _maximum = maximum;
    }
    double _valeur_article (const article & a) const
    {
        return a.prix_achat ();
    }
};

/**
 * \brief Tester si le prix de vente d'un article est dans le bon intervalle.
 */
struct condition_article_prix_vente : virtual condition_article_bornes_double
{
    /**
     * \brief Constructeur.
     * \param minimum Borne inférieure.
     * \param maximum Borne supérieure.
     */
    condition_article_prix_vente (double minimum, double maximum)
    {
        _minimum = minimum;
        _maximum = maximum;
    }

    double _valeur_article (const article & a) const
    {
        return a.prix_vente ();
    }
};

/**
 * \brief Tester si la date d'un article correspond.
 */
struct condition_article_date : virtual condition_article
{
    date _date;     /**<- Date recherchée. */

    /**
     * \brief Constructeur.
     * \param d Date recherchée.
     */
    condition_article_date (const date & d)
    {
        _date = d;
    }

    bool operator() (const article & a) const
    {
        return a.date_livraison () == _date;
    }
};

#endif /* __CONDITION_ARTICLE_HPP__ */
