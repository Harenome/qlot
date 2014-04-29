/**
 * \file condition_vente.hpp
 * \brief Condition vente.
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
#ifndef __CONDITION_VENTE_HPP__
#define __CONDITION_VENTE_HPP__

#include <functional>

#include "vente.hpp"

/**
 * \brief Simulacre de fonction d'ordre supérieur pour tester une condition sur une vente.
 */
struct condition_vente : public std::unary_function<const vente &, bool>
{
    /**
     * \brief Test d'une vente.
     * \param v Vente à tester.
     * \return Résultat du test.
     */
    virtual bool operator() (const vente & v) const
    {
        /* La non utilisation de v est intentionnelle ! */
        (void) v;
        return true;
    }
};

/**
 * \brief Tester si la date d'une vente correspond.
 */
struct condition_vente_date : virtual condition_vente
{
    date _date;     /**<- Date recherchée. */

    /**
     * \brief Constructeur.
     * \param d Date recherchée.
     */
    condition_vente_date (const date & d)
    {
        _date = d;
    }

    bool operator() (const vente & v) const
    {
        return v.date_vente () == _date;
    }
};

/**
 * \brief Tester si un article a été vendu lors de cette vente.
 */
struct condition_vente_reference : virtual condition_vente
{
    unsigned int _reference;    /**<- Référence de l'article recherché. */

    /**
     * \brief Constructeur.
     * \param r Référence de l'article recherché.
     */
    condition_vente_reference (const reference_article & r)
    {
        _reference = r.vers_entier ();
    }

    /**
     * \brief Constructeur.
     * \param r Référence de l'article recherché.
     */
    condition_vente_reference (unsigned int r)
    {
        _reference = r;
    }

    bool operator() (const vente & v) const
    {
        return v.vendu_article (_reference);
    }
};

/**
 * \brief Tester si un modèle a été vendu lors de cette vente.
 */
struct condition_vente_modele : virtual condition_vente
{
    unsigned int _modele;   /**<_ Modèle recherché. */

    /**
     * \brief Constructeur.
     * \param modele Modèle recherché.
     */
    condition_vente_modele (unsigned int modele)
    {
        _modele = modele;
    }

    bool operator() (const vente & v) const
    {
        return v.vendu_modele (_modele);
    }
};

/**
 * \brief Tester si une taille a été vendue lors de cette vente.
 */
struct condition_vente_taille : virtual condition_vente
{
    unsigned int _taille;   /**<- Taille recherchée. */

    /**
     * \brief Constructeur.
     * \param modele Modèle recherché.
     */
    condition_vente_taille (unsigned int taille)
    {
        _taille = taille;
    }

    bool operator() (const vente & v) const
    {
        return v.vendu_taille (_taille);
    }
};

/**
 * \brief Tester si une couleur a été vendue lors de cette vente.
 */
struct condition_vente_couleur : virtual condition_vente
{
    unsigned int _couleur; /**<- Couleur recherchée. */

    /**
     * \brief Constructeur.
     * \param couleur Couleur recherchée.
     */
    condition_vente_couleur (unsigned int couleur)
    {
        _couleur = couleur;
    }

    bool operator() (const vente & v) const
    {
        return v.vendu_couleur (_couleur);
    }
};

/**
 * \brief Tester si le nombre d'articles vendus correspond.
 */
struct condition_vente_quantite : virtual condition_vente
{
    unsigned int _quantite; /**<- Couleur recherchée. */

    /**
     * \brief Constructeur.
     * \param couleur Couleur recherchée.
     */
    condition_vente_quantite (unsigned int quantite)
    {
        _quantite = quantite;
    }

    bool operator() (const vente & v) const
    {
        return v.quantite_articles_vendus () == _quantite;
    }
};

/**
 * \brief Tester si la vente est comprise dans une fourchette.
 */
struct condition_vente_prix_total : virtual condition_vente
{
    double _minimum;    /**<- Borne inférieure. */
    double _maximum;    /**<- Borne supérieure. */

    /**
     * \brief Constructeur.
     * \param minimum Minimum.
     * \param maximum Maximum.
     */
    condition_vente_prix_total (double minimum, double maximum)
    {
        _minimum = minimum;
        _maximum = maximum;
    }

    bool operator() (const vente & v) const
    {
        double prix_total = v.total ();
        return _minimum <= prix_total && prix_total <= _maximum;
    }
};

#endif /* __CONDITION_VENTE_HPP__ */
