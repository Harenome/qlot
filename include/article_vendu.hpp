/**
 * \file article_vendu.hpp
 * \brief Article vendu.
 * \author RAZANAJATO RANAIVOARIVONY Harenome
 * \author MEYER Jérémy
 * \date 2014
 * \copyright WTFPL version 2 */ /* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://www.wtfpl.net/ for more details.
 */
#ifndef __ARTICLE_VENDU_HPP__
#define __ARTICLE_VENDU_HPP__

#include <algorithm>

#include "reference_article.hpp"
#include "article.hpp"

////////////////////////////////////////////////////////////////////////////////
// Classe.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Article vendu.
 * \sa article
 */
class article_vendu
{
public:
    /**
     * \brief Constructeur.
     */
    article_vendu (void);

    /**
     * \brief Destructeur.
     */
    ~article_vendu (void);

    /**
     * \brief Constructeur.
     * \param a Article vendu.
     */
    article_vendu (const article_vendu & a);

    /**
     * \brief Constructeur.
     * \param reference Référence.
     * \param quantite Quantité vendue.
     * \param prix Prix de vente effectif.
     */
    article_vendu (const reference_article & reference, unsigned int quantite, float prix);

    /**
     * \brief Obtenir la quantité vendue.
     * \return Quantité vendue.
     */
    unsigned int quantite_vendue (void) const;

    /**
     * \brief Obtenir le prix de vente.
     * \return Prix de vente.
     */
    float prix (void) const;

    /**
     * \brief Obtenir le total payé pour cet article.
     * \return Total.
     */
    float total (void) const;

    /**
     * \brief Modifier la référence.
     * \param reference Référence
     */
    void modifier_reference (unsigned int reference);

    /**
     * \brief Modifier la référence.
     * \param reference Référence
     */
    void modifier_reference (const reference_article & reference);

    /**
     * \brief Modifier la quantité vendue.
     * \param quantite Quantité.
     */
    void modifier_quantite_vendue (unsigned int quantite);

    /**
     * \brief Modifier le prix de vente effectif.
     * \param prix Prix de vente effectif.
     */
    void modifier_prix (float prix);

    /**
     * \brief Obtenir la référence de l'article qui a été vendu.
     * \return Référence de l'article qui a été vendu.
     */
    reference_article reference (void) const;

    /**
     * \brief Échanger deux articles vendus.
     * \param[in,out] a Article vendu.
     */
    void swap (article_vendu & a);

    /**
     * \brief Opérateur \c =.
     * \param a Article vendu.
     */
    article_vendu & operator= (article_vendu a);

private:
    reference_article _reference;   /**<- Référence article. */
    float _prix;                    /**<- Prix de vente effectif. */
    unsigned int _quantite;         /**<- Quantité vendue. */

    void _initialiser (const reference_article & reference, unsigned int quantite, float prix);
};

////////////////////////////////////////////////////////////////////////////////
// Fonctions non membres.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Opérateur \c <<.
 * \param[in,out] os Stream de sortie.
 * \param[in] a Article vendu.
 * \return \c os.
 * \relates article_vendu
 */
std::ostream & operator<< (std::ostream & os, const article_vendu & a);

/**
 * \brief Opérateur \c >>.
 * \param[in,out] is Stream d'entrée.
 * \param[in] a Article vendu.
 * \return \c is.
 * \relates article_vendu
 */
std::istream & operator>> (std::istream & is, article_vendu & a);


/**
 * \brief Échanger deux articles vendus.
 * \param[in,out] a Premier article vendu.
 * \param[in,out] b Deuxième article vendu.
 * \relates article_vendu
 */
static inline void swap (article_vendu & a, article_vendu & b)
{
    a.swap (b);
}

#endif /* __ARTICLE_VENDU_HPP__ */
