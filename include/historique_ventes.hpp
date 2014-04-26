/**
 * \file historique_ventes.hpp
 * \brief Historique ventes.
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
#ifndef __HISTORIQUE_VENTES_HPP__
#define __HISTORIQUE_VENTES_HPP__

#include <map>
#include <istream>
#include <ostream>

#include "reference_article.hpp"
#include "vente.hpp"

////////////////////////////////////////////////////////////////////////////////
// Typedefs.
////////////////////////////////////////////////////////////////////////////////

typedef std::pair<unsigned int, vente> historique_ventes_element;
typedef std::map<unsigned int, vente> historique_ventes_map;
typedef historique_ventes_map::iterator historique_ventes_iterator;
typedef historique_ventes_map::const_iterator historique_ventes_const_iterator;

////////////////////////////////////////////////////////////////////////////////
// Classe.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Historique des ventes.
 * \sa vente, reference_article
 */
class historique_ventes
{
public:
    /**
     * \brief Constructeur.
     */
    historique_ventes (void);

    /**
     * \brief Constructeur.
     * \param h Historique.
     */
    historique_ventes (const historique_ventes & h);

    /**
     * \brief Destructeur.
     */
    ~historique_ventes (void);

    /**
     * \brief Ajouter une vente.
     * \param v Vente.
     */
    void ajouter_vente (const vente & v);

    /**
     * \brief Retirer une vente.
     * \param v Vente.
     */
    void retirer_vente (const vente & v);

    /**
     * \brief Retirer une vente.
     * \param id ID.
     */
    void retirer_vente (unsigned int id);

    /**
     * \brief Utiliser la nouvelle référence d'un article dont la référence a changé.
     * \param ancienne Ancienne référence
     * \param nouvelle Nouvelle référence.
     */
    void remplacer_references (unsigned int ancienne, unsigned int nouvelle);

    /**
     * \brief Utiliser la nouvelle référence d'un article dont la référence a changé.
     * \param ancienne Ancienne référence
     * \param nouvelle Nouvelle référence.
     */
    void remplacer_references (const reference_article & ancienne, const reference_article & nouvelle);

    /**
     * \brief Obtenir un itérateur sur le début des ventes.
     * \return itérateur.
     */
    historique_ventes_const_iterator begin (void) const;

    /**
     * \brief Obtenir un itérateur sur la fin des ventes.
     * \return itérateur.
     */
    historique_ventes_const_iterator end (void) const;

    /**
     * \brief Déterminer si une vente existe.
     * \param id ID.
     */
    bool existe (unsigned int id) const;

    /**
     * \brief Opérateur \c [].
     * \param id ID.
     * \return Vente.
     */
    vente & operator[] (unsigned int id);

    /**
     * \brief Opérateur \c [] (version \c const).
     * \param id ID.
     * \return Vente.
     */
    const vente & operator[] (unsigned int id) const;

    /**
     * \brief Obtenir le total payé pour toutes les ventes.
     * \return Total.
     */
    double total (void) const;

    /**
     * \brief Obtenir le nombre de ventes.
     * \return Nombre de ventes.
     */
    unsigned int nombre_ventes (void) const;

    /**
     * \brief Échanger deux historiques.
     * \param h Historique.
     */
    void swap (historique_ventes & h);

    /**
     * \brief Opérateur \c =.
     * \param h Historique.
     */
    historique_ventes & operator= (historique_ventes h);

    /**
     * \brief Écrire vers un flux de sortie.
     * \param os Stream de sortie.
     * \return \c os.
     */
    std::ostream & ecrire_vers (std::ostream & os) const;

private:
    historique_ventes_map _ventes;  /**<- Ventes. */
};

////////////////////////////////////////////////////////////////////////////////
// Fonctions non membres.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Opérateur \c <<.
 * \param[in,out] os Stream de sortie.
 * \param[in] h Historique.
 * \return \c os.
 * \relates historique_ventes
 */
std::ostream & operator<< (std::ostream & os, const historique_ventes & h);

/**
 * \brief Opérateur \c >>.
 * \param[in,out] is Stream d'entrée.
 * \param[in] h Historique.
 * \return \c is.
 * \relates historique_ventes
 */std::istream & operator>> (std::istream & is, historique_ventes & h);

/**
 * \brief Échanger les contenus de deux historiques.
 * \param[in,out] a Historique.
 * \param[in,out] b Historique.
 * \relates historique_ventes
 */
static inline void swap (historique_ventes & a, historique_ventes & b)
{
    a.swap (b);
}

#endif /* __HISTORIQUE_VENTES_HPP__ */
