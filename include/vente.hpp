/**
 * \file vente.hpp
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
#ifndef __VENTE_HPP__
#define __VENTE_HPP__

#include <map>

#include "date.hpp"
#include "reference_article.hpp"
#include "article.hpp"
#include "article_vendu.hpp"

////////////////////////////////////////////////////////////////////////////////
// Typedefs.
////////////////////////////////////////////////////////////////////////////////

typedef std::pair<unsigned int, article_vendu> vente_element;
typedef std::map<unsigned int, article_vendu> vente_map;
typedef vente_map::iterator vente_iterator;
typedef vente_map::const_iterator vente_const_iterator;

////////////////////////////////////////////////////////////////////////////////
// Classe.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Vente.
 *
 * \sa date, article_vendu
 */
class vente
{
public:
    /**
     * \brief Constructeur.
     */
    vente (void);

    /**
     * \brief Constructeur.
     * \param date_vente Date de vente.
     */
    vente (const date & date_vente);

    /**
     * \brief Constructeur.
     * \param id ID.
     * \param date_vente Date de vente.
     */
    vente (unsigned int id, const date & date_vente);
    /**
     * \brief Constructeur.
     * \param v Vente à copier.
     */
    vente (const vente & v);

    /**
     * \brief Destructeur.
     */
    ~vente (void);

    /**
     * \brief Obtenir la date.
     */
    date date_vente (void) const;

    /**
     * \brief Obtenir le nombre d'articles vendus.
     */
    unsigned int quantite_articles_vendus (void) const;

    /**
     * \brief Déterminer si un article a été vendu lors de cette vente.
     * \param reference Référence.
     * \retval true Si l'article a été vendu.
     * \retval false Sinon.
     */
    bool vendu_article (unsigned int reference) const;

    /**
     * \brief Déterminer si un article a été vendu lors de cette vente.
     * \param reference Référence.
     * \retval true Si l'article a été vendu.
     * \retval false Sinon.
     */
    bool vendu_article (const reference_article & reference) const;

    /**
     * \brief Déterminer si un modèle a été vendu lors de cette vente.
     * \param modele Modèle.
     * \retval true Si un article de ce modèle a été vendu.
     * \retval false Sinon.
     */
    bool vendu_modele (unsigned int modele) const;

    /**
     * \brief Déterminer si une taille a été vendu lors de cette vente.
     * \param taille Taille.
     * \retval true Si un article de cette taille a été vendu.
     * \retval false Sinon.
     */
    bool vendu_taille (unsigned int taille) const;

    /**
     * \brief Déterminer si un modèle a été vendu lors de cette vente.
     * \param couleur Couleur.
     * \retval true Si un article de ce modèle a été vendu.
     * \retval false Sinon.
     */
    bool vendu_couleur (unsigned int couleur) const;

    /**
     * \brief Opérateur \c [].
     * \param reference Référence.
     */
    article_vendu & operator[] (unsigned int reference);

    /**
     * \brief Opérateur \c [].
     * \param reference Référence.
     */
    article_vendu & operator[] (const reference_article & reference);

    /**
     * \brief Opérateur \c [] (version \c const).
     * \param reference Référence.
     */
    const article_vendu & operator[] (unsigned int reference) const;

    /**
     * \brief Opérateur \c [] (version \c const).
     * \param reference Référence.
     */
    const article_vendu & operator[] (const reference_article & reference) const;

    /**
     * \brief Obtenir un itérateur vers le début.
     * \return Itérateur.
     */
    vente_const_iterator begin (void) const;

    /**
     * \brief Obtenir un itérateur vers la fin.
     * \return Itérateur.
     */
    vente_const_iterator end (void) const;

    /**
     * \brief Obtenir l'ID de la vente.
     * \return ID.
     */
    unsigned int id (void) const;

    /**
     * \brief Obtenir le prix total payé lors de la vente.
     * \return Total.
     */
    double total (void) const;

    /**
     * \brief Ajouter un article vendu à la vent.
     * \param a Article vendu.
     */
    void ajouter_article_vendu (const article_vendu & a);

    /**
     * \brief Retirer un article vendu de la vente.
     * \param reference Référence.
     */
    void retirer_article_vendu (unsigned int reference);

    /**
     * \brief Retirer un article vendu de la vente.
     * \param reference Référence.
     */
    void retirer_article_vendu (const reference_article & reference);

    /**
     * \brief Modifier la date de vente.
     * \param date_vente Date de vente.
     */
    void modifier_date_vente (const date & date_vente);

    /**
     * \brief Utiliser la nouvelle référence d'un article dont la référence a changé.
     * \param ancienne Ancienne référence
     * \param nouvelle Nouvelle référence.
     */
    void remplacer_reference (unsigned int ancienne, unsigned int nouvelle);

    /**
     * \brief Utiliser la nouvelle référence d'un article dont la référence a changé.
     * \param ancienne Ancienne référence
     * \param nouvelle Nouvelle référence.
     */
    void remplacer_reference (const reference_article & ancienne, const reference_article & nouvelle);

    /**
     * \brief Opérateur d'affectation.
     * \param v Vente à affecter
     * \return Vente
     */
    vente & operator= (vente v);

    /**
     * \brief Échanger.
     * \param v Vente à échanger.
     */
    void swap (vente & v);

    /**
     * \brief Écrire sur un flux de sortie.
     * \param os Stream de sortie.
     */
    std::ostream & sortie (std::ostream & os) const;

private:
    unsigned int _id;               /**<- ID. */
    date _date_vente;               /**<- Date de vente. */
    vente_map _articles_vendus;     /**<- Articles vendus. */

    static unsigned int _id_suivant;
};

////////////////////////////////////////////////////////////////////////////////
// Fonctions non membres.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Opérateur \c <<.
 * \param[in,out] os Stream de sortie.
 * \param[in] v Vente.
 * \return \c os.
 * \relates vente
 * \relatesalso std::ostream
 */
std::ostream & operator<< (std::ostream & os, const vente & v);

/**
 * \brief Opérateur \c >>.
 * \param[in,out] is Stream d'entrée.
 * \param[in] v Vente.
 * \return \c os.
 * \relates vente
 * \relatesalso std::istream
 */
std::istream & operator>> (std::istream & is, vente & v);

/**
 * \brief Échanger les contenus de deux ventes.
 * \param[in,out] v1 Vente 1.
 * \param[in,out] v2 Vente 2.
 * \relates vente
 */
static inline void swap (vente & v1, vente & v2)
{
    v1.swap (v2);
}

#endif /* __VENTE_HPP__ */
