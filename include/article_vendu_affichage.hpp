/**
 * \file article_vendu_affichage.hpp
 * \brief Article vendu affichage.
 * \author RAZANAJATO RANAIVOARIVONY Harenome
 * \author MEYER Jérémy
 * \date 2014
 * \copyright WTFPL version 2 */
/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://www.wtfpl.net/ for more details.
 */
#ifndef __ARTICLE_VENDU_AFFICHAGE__
#define __ARTICLE_VENDU_AFFICHAGE__

#include <ostream>
#include <algorithm>

#include "reference_article.hpp"
#include "article_vendu.hpp"

/**
 * \brief Article vendu affichage.
 * \sa article_vendu, reference_article
 */
class article_vendu_affichage : public article_vendu
{
public:
    /**
     * \brief Constructeur.
     */
    article_vendu_affichage (void);

    /**
     * \brief Constructeur.
     * \param id ID.
     * \param reference Référence.
     * \param quantite Quantité
     * \param prix Prix.
     */
    article_vendu_affichage (unsigned int id, const reference_article & reference, unsigned int quantite, double prix);

    /**
     * \brief Constructeur.
     * \param ID.
     * \param a Article vendu.
     */
    article_vendu_affichage (unsigned int id, const article_vendu & a);
    /**
     * \brief Destructeur.
     */
    ~article_vendu_affichage (void);

    /**
     * \brief ID de la vente où l'article a été vendu.
     */
    unsigned int id_vente (void) const;

    /**
     * \brief Échanger.
     * \param a Article vendu affichage.
     */
    void swap (article_vendu_affichage & a);

    /**
     * \brief Opérateur \c =.
     * \param a Article vendu affichage.
     */
    article_vendu_affichage & operator= (article_vendu_affichage a);

private:
    unsigned int _id_vente;     /**<- ID vente. */
};

/**
 * \brief Opérateur \c <<.
 * \param[in,out] os Stream de sortie.
 * \param[in] a Article vendu affichage
 * \return \c os.
 * \relates article_vendu_affichage
 */
std::ostream & operator<< (std::ostream & os, const article_vendu_affichage & a);

/**
 * \brief Échanger.
 * \param a 1.
 * \param b 2.
 */
static inline void swap (article_vendu_affichage & a, article_vendu_affichage & b)
{
    a.swap (b);
}

#endif /* __ARTICLE_VENDU_AFFICHAGE__ */
