/**
 * \file article.hpp
 * \brief Article.
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
#ifndef __ARTICLE_HPP__
#define __ARTICLE_HPP__

#include <istream>
#include <ostream>
#include <algorithm>

#include "date.hpp"
#include "reference_article.hpp"

////////////////////////////////////////////////////////////////////////////////
// Classe.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Article.
 *
 * \sa reference_article, date, pourcentage
 */
class article
{
public:
    /**
     * \brief Constructeur.
     */
    article (void);

    /**
     * \brief Constructeur.
     * \param a Article.
     */
    article (const article & a);

    /**
     * \brief Constructeur.
     * \param reference Référence.
     * \param prix_achat Prix d'achat.
     * \param prix_vente Prix de vente.
     * La date est initialisée à la date courante.
     */
    article (const reference_article & reference, double prix_achat, double prix_vente);

    /**
     * \brief Constructeur.
     * \param reference Référence.
     * \param prix_achat Prix d'achat.
     * \param prix_vente Prix de vente.
     * \param date_livraison Date de livraison.
     */
    article (const reference_article & reference, double prix_achat, double prix_vente, const date & date_livraison);

    /**
     * \brief Constructeur.
     * \param modele Modèle.
     * \param couleur Couleur.
     * \param taille Taille.
     * \param prix_achat Prix d'achat.
     * \param prix_vente Prix de vente.
     * La date est initialisée à la date courante.
     */
    article (unsigned int modele, unsigned int couleur, unsigned int taille, double prix_achat, double prix_vente);

    /**
     * \brief Constructeur.
     * \param modele Modèle.
     * \param couleur Couleur.
     * \param taille Taille.
     * \param prix_achat Prix d'achat.
     * \param prix_vente Prix de vente.
     * \param date_livraison Date de livraison.
     */
    article (unsigned int modele, unsigned int couleur, unsigned int taille, double prix_achat, double prix_vente, const date & date_livraison);

    /**
     * \brief Destructeur.
     */
    ~article (void);

    /**
     * \brief Obtenir la référence.
     * \return Référence.
     */
    reference_article reference (void) const;

    /**
     * \brief Obtenir le modèle.
     * \return Modèle.
     */
    unsigned int modele (void) const;

    /**
     * \brief Obtenir la couleur.
     * \return Couleur.
     */
    unsigned int couleur (void) const;

    /**
     * \brief Obtenir la taille.
     * \return Taille.
     */
    unsigned int taille (void) const;

    /**
     * \brief Obtenir le prix d'achat.
     * \return Prix d'achat.
     */
    double prix_achat (void) const;

    /**
     * \brief Obtenir le prix de vente.
     * \return Prix de vente.
     */
    double prix_vente (void) const;

    /**
     * \brief Obtenir le prix de vente effectif (après application du rabais).
     * \return Prix de vente effectif.
     */
    double prix_vente_effectif (void) const;

    /**
     * \brief Obtenir la date de livraison.
     * \return Date de livraison.
     */
    date date_livraison (void) const;

    /**
     * \brief Modifier le modèle.
     * \param modele Nouveau modèle.
     */
    void modifier_modele (unsigned int modele);

    /**
     * \brief Modifier la taille.
     * \param taille Nouvelle taille.
     */
    void modifier_taille (unsigned int taille);

    /**
     * \brief Modifier la couleur.
     * \param couleur Nouvelle couleur.
     */
    void modifier_couleur (unsigned int couleur);

    /**
     * \brief Modifier le prix d'achat.
     * \param prix_achat Nouveau prix d'achat.
     */
    void modifier_prix_achat (double prix_achat);

    /**
     * \brief Modifier le prix de vente
     * \param prix_vente Nouveau prix de vente.
     */
    void modifier_prix_vente (double prix_vente);

    /**
     * \brief Modifier la date de livraison.
     * \param date_livraison Nouvelle date de livraison.
     */
    void modifier_date_livraison (const date & date_livraison);

    /**
     * \brief Modifier la date de livraison.
     * \param jour Nouveau jour.
     * \param mois Nouveau mois.
     * \param annee Nouvelle annee.
     */
    void modifier_date_livraison (unsigned int jour, unsigned int mois, unsigned int annee);

    /**
     * \brief Échanger deux articles.
     * \param[in,out] a Article.
     */
    void swap (article & a);

    /**
     * \brief Opérateur \c =.
     * \param a Article.
     */
    article & operator= (article a);

private:
    reference_article _reference;   /**<- Référence. */
    date _date_livraison;           /**<- Date de livraison. */
    double _prix_achat;              /**<- Prix d'achat. */
    double _prix_vente;              /**<- Prix de vente. */

    /**
     * \brief Initialiser.
     * \param reference Référence.
     * \param prix_achat Prix d'achat.
     * \param prix_vente Prix de vente.
     */
    void _initialiser (const reference_article & reference, double prix_achat, double prix_vente);

    /**
     * \brief Initialiser.
     * \param modele Modèle.
     * \param couleur Couleur.
     * \param taille Taille.
     * \param prix_achat Prix d'achat.
     * \param prix_vente Prix de vente.
     */
    void _initialiser (unsigned int modele, unsigned int couleur, unsigned int taille, double prix_achat, double prix_vente);
};

////////////////////////////////////////////////////////////////////////////////
// Fonctions non membres.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Opérateur \c <<.
 * \param[in,out] os Stream de sortie.
 * \param[in] a Article.
 * \return \c os.
 * \relates article
 */
std::ostream & operator<< (std::ostream & os, const article & a);

/**
 * \brief Opérateur \c >>.
 * \param[in,out] is Stream d'entrée.
 * \param[in] a Article.
 * \return \c is.
 * \relates article
 */
std::istream & operator>> (std::istream & is, article & a);

/**
 * \brief Échanger deux articles.
 * \param[in,out] a Premier article.
 * \param[in,out] b Deuxième article.
 * \relates article
 */
static inline void swap (article & a, article & b)
{
    a.swap (b);
}

#endif /* __ARTICLE_HPP__ */
