/**
 * \file article_stock.hpp
 * \brief Article stock.
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
#ifndef __ARTICLE_STOCK_HPP__
#define __ARTICLE_STOCK_HPP__

#include <istream>
#include <ostream>
#include <algorithm>

#include "reference_article.hpp"
#include "pourcentage.hpp"
#include "article.hpp"

////////////////////////////////////////////////////////////////////////////////
// Classe.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Article en stock.
 *
 * \sa reference_article, pourcentage, article
 */
class article_stock
{
public:
    /**
     * \brief Constructeur.
     */
    article_stock (void);

    /**
     * \brief Constructeur.
     * \param a Article.
     */
    article_stock (const article_stock & a);

    /**
     * \brief Constructeur.
     * \param reference Référence de l'article.
     * \param quantite Quantité en stock.
     * \param rabais Rabais.
     */
    article_stock (const reference_article & reference, unsigned int quantite, const pourcentage & rabais = pourcentage::ZERO);

    /**
     * \brief Destructeur.
     */
    ~article_stock (void);
    /**
     * \brief Obtenir le rabais.
     * \return Rabais.
     */
    pourcentage rabais (void) const;

    /**
     * \brief Obtenir la quantité en stock.
     * \return Quantité en stock.
     */
    unsigned int quantite_stock (void) const;

    /**
     * \brief Obtenir la référence.
     * \return Référence.
     */
    reference_article reference (void) const;

    /**
     * \brief Modifier la référence.
     * \param reference Référence.
     */
    void modifier_reference (unsigned int reference);

    /**
     * \brief Modifier la référence.
     * \param reference Référence.
     */
    void modifier_reference (const reference_article & reference);

    /**
     * \brief Modifier le rabais.
     * \param rabais Rabais.
     */
    void modifier_rabais (unsigned int rabais);

    /**
     * \brief Modifier le rabais.
     * \param rabais Rabais.
     */
    void modifier_rabais (const pourcentage & rabais);

    /**
     * \brief Modifier la quantité en stock.
     * \param quantite Quantité en stock.
     */
    void modifier_quantite_stock (unsigned int quantite);

    /**
     * \brief Échanger deux articles_stock.
     * \param a Article en stock.
     */
    void swap (article_stock & a);

    /**
     * \brief Opérateur \c =.
     * \param a Article en stock.
     */
    article_stock & operator= (article_stock a);
private:
    pourcentage _rabais;            /**<- Rabais. */
    unsigned int _quantite_stock;   /**<- Quantité en stock. */
    reference_article _reference;   /**<- Référence. */
};

////////////////////////////////////////////////////////////////////////////////
// Fonctions non membres.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Opérateur \c <<.
 * \param[in,out] os Stream de sortie.
 * \param[in] a Article en stock.
 * \return \c os.
 * \relates article_stock
 */
std::ostream & operator<< (std::ostream & os, const article_stock & a);

/**
 * \brief Opérateur \c >>.
 * \param[in,out] is Stream d'entrée.
 * \param[in] a Article en stock.
 * \return \c is.
 * \relates article_stock
 */
std::istream & operator>> (std::istream & is, article_stock & a);

/**
 * \brief Échanger deux articles stock.
 * \param[in,out] a Premier article en stock.
 * \param[in,out] b Deuxième article en stock.
 * \relates article_stock
 */
static inline void swap (article_stock & a, article_stock & b)
{
    a.swap (b);
}

#endif /* __ARTICLE_STOCK_HPP__ */
