/**
 * \file article_affichage.hpp
 * \brief Article affichage.
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
#ifndef __ARTICLE_AFFICHAGE_HPP__
#define __ARTICLE_AFFICHAGE_HPP__

#include "article.hpp"
#include "article_stock.hpp"
#include "reference_article.hpp"
#include "date.hpp"
#include "pourcentage.hpp"

////////////////////////////////////////////////////////////////////////////////
// Classe.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Classe pour faciliter l'affichage d'un article en stock.
 * \sa article, article_stock, reference_article, date, pourcentage
 *
 * Cette classe réunit un article_stock et un article : toutes les
 * informations se trouvent au même endroit.
 * Des objets article_affichage sont donc destinés à...l'affichage, et
 * non à l'édition des informations.
 */
class article_affichage
{
public:
    /**
     * \brief Constructeur.
     */
    article_affichage (void);

    /**
     * \brief Constructeur.
     * \param a Article affichage.
     */
    article_affichage (const article_affichage & a);

    /**
     * \brief Constructeur.
     * \param a Article.
     * \param s Article en stock.
     */
    article_affichage (const article & a, const article_stock & s);

    /**
     * \brief Destructeur.
     */
    ~article_affichage (void);

    /**
     * \brief Obtenir la référence.
     * \return Référence.
     */
    reference_article reference (void) const;

    /**
     * \brief Obtenir la date de livraison.
     * \return Date de livraison.
     */
    date date_livraison (void) const;

    /**
     * \brief Obtenir le prix d'achat.
     * \return Prix d'achat.
     */
    float prix_achat (void) const;

    /**
     * \brief Obtenir le prix de vente.
     * \return Prix de vente.
     */
    float prix_vente (void) const;

    /**
     * \brief Obtenir le prix de vente effectif (après application du rabais).
     * \return Prix de vente effectif.
     */
    float prix_vente_effectif (void) const;

    /**
     * \brief Obtenir la quantité en stock.
     * \return Quantité en stock.
     */
    unsigned int quantite_stock (void) const;

    /**
     * \brief Obtenir le rabais.
     * \return Rabais.
     */
    pourcentage rabais (void) const;

    /**
     * \brief Échanger deux articles affichage.
     * \param[in,out] a Article affichage.
     */
    void swap (article_affichage & a);

    /**
     * \brief Opérateur \c =.
     * \param a Article affichage.
     */
    article_affichage & operator= (article_affichage a);

private:
    article _article;               /**<- Article. */
    article_stock _article_stock;   /**<- Infos sur le stock de l'article. */
};

////////////////////////////////////////////////////////////////////////////////
// Fonctions non membres.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Échanger deux articles affichage.
 * \param a Article affichage.
 * \param b Article affichage.
 * \relates article_affichage
 */
static inline void swap (article_affichage & a, article_affichage & b)
{
    a.swap (b);
}

#endif /* __ARTICLE_AFFICHAGE_HPP__ */
