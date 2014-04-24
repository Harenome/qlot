/**
 * \file reference_article.hpp
 * \brief Référence d'un article.
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
#ifndef __REFERENCE_ARTICLE_HPP__
#define __REFERENCE_ARTICLE_HPP__

#include <algorithm>
#include <istream>
#include <ostream>

////////////////////////////////////////////////////////////////////////////////
// Classe.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Référence d'un article.
 *
 * Une référence pour un article est un nombre de la forme \a mmmmcctt tel que
 * - \a mmmm correspond au modèle de l'article.
 * - \a cc correspond à la couleur de l'article.
 * - \a tt correspond à la taille de l'article.
 */
class reference_article
{
public:
    /**
     * \brief Constructeur.
     * \param reference Référence.
     */
    reference_article (unsigned int reference = 0);

    /**
     * \brief Constructeur.
     * \param reference Référence.
     */
    reference_article (const reference_article & reference);

    /**
     * \brief Constructeur.
     * \param modele Modèle.
     * \param couleur Couleur.
     * \param taille Taille.
     */
    reference_article (unsigned int modele, unsigned int couleur, unsigned int taille);

    /**
     * \brief Destructeur.
     */
    ~reference_article (void);

    /**
     * \brief Obtenir la référence sous forme d'un entier.
     * \return Référence.
     */
    unsigned int vers_entier (void) const;

    /**
     * \brief Extraire le modèle de la référence.
     * \return Modèle.
     */
    unsigned int modele (void) const;

    /**
     * \brief Extraire la couleur de la référence.
     * \return Couleur.
     */
    unsigned int couleur (void) const;

    /**
     * \brief Extraire la taille de la référence.
     * \return Taille.
     */
    unsigned int taille (void) const;

    /**
     * \brief Modifier le modèle.
     */
    void modifier_modele (unsigned int modele);

    /**
     * \brief Modifier la couleur.
     */
    void modifier_couleur (unsigned int couleur);

    /**
     * \brief Modifier la taille.
     */
    void modifier_taille (unsigned int taille);

    /**
     * \brief Déterminer si deux références sont égales.
     * \param r Référence à comparer.
     * \retval true si la référence est égale à \c r.
     * \retval false sinon.
     */
    bool egal (const reference_article & r) const;

    /**
     * \brief Déterminer si la référence est inférieure à une autre référence.
     * \param r Référence à comparer.
     * \retval true si la référence est inférieure à \c r.
     * \retval false sinon.
     */
    bool inferieur_a (const reference_article & r) const;

    /**
     * \brief Échanger les contenus.
     * \param r Référence.
     */
    void swap (reference_article & r);

    /**
     * \brief Opérateur \c =
     * \param r Référence.
     * \return Référence.
     */
    reference_article & operator= (reference_article r);

private:
    unsigned int _reference;    /**<- Référence. */

    /**
     * \brief Initialiser la référence.
     * \param reference Référence.
     */
    void _initialiser (unsigned int reference);

    /**
     * \brief Initialiser la référence.
     * \param modele Modèle.
     * \param couleur Couleur.
     * \param taille Taille.
     */
    void _initialiser (unsigned int modele, unsigned int couleur, unsigned int taille);

    /**
     * \brief Fabriquer une référence.
     * \param modele Modèle.
     * \param couleur Couleur.
     * \param taille Taille.
     * \return Référence.
     */
    static inline unsigned int _fabriquer_reference (unsigned int modele, unsigned int couleur, unsigned int taille)
    {
        modele = (modele % 10000) * 10000;
        couleur = (couleur % 100) * 100;
        taille = taille % 100;

        return  modele + taille + couleur;
    }

    /**
     * \brief Extraire le modèle d'une référence.
     * \return Modèle.
     */
    static inline unsigned int _extraire_modele (unsigned int reference)
    {
        return (reference / 10000) % 10000;
    }

    /**
     * \brief Extraire la couleur d'une référence.
     * \return Couleur.
     */
    static inline unsigned int _extraire_couleur (unsigned int reference)
    {
        return (reference / 100) % 100;
    }

    /**
     * \brief Extraire la taille d'une référence.
     * \return Taille.
     */
    static inline unsigned int _extraire_taille (unsigned int reference)
    {
        return reference % 100;
    }
};

////////////////////////////////////////////////////////////////////////////////
// Fonctions non membres.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Opérateur \c ==
 * \param gauche Gauche.
 * \param droite Droite.
 * \retval true si \c gauche est égale à \c droite.
 * \retval false sinon.
 * \relates reference_article
 */
static inline bool operator== (const reference_article & gauche, const reference_article & droite)
{
    return gauche.egal (droite);
}

/**
 * \brief Opérateur \c !=
 * \param gauche Gauche.
 * \param droite Droite.
 * \retval true si \c gauche est différente de \c droite.
 * \retval false sinon.
 * \relates reference_article
 */
static inline bool operator!= (const reference_article & gauche, const reference_article & droite)
{
    return ! operator== (gauche, droite);
}

/**
 * \brief Opérateur \c <
 * \param gauche Gauche.
 * \param droite Droite.
 * \retval true si \c gauche est inférieure à \c droite.
 * \retval false sinon.
 * \relates reference_article
 */
static inline bool operator< (const reference_article & gauche, const reference_article & droite)
{
    return gauche.inferieur_a (droite);
}

/**
 * \brief Opérateur \c >
 * \param gauche Gauche.
 * \param droite Droite.
 * \retval true si \c gauche est supérieure à \c droite.
 * \retval false sinon.
 * \relates reference_article
 */
static inline bool operator> (const reference_article & gauche, const reference_article & droite)
{
    return operator< (droite, gauche);
}

/**
 * \brief Opérateur \c <=
 * \param gauche Gauche.
 * \param droite Droite.
 * \retval true si \c gauche est inférieure ou égale à \c droite.
 * \retval false sinon.
 * \relates reference_article
 */
static inline bool operator<= (const reference_article & gauche, const reference_article & droite)
{
    return ! operator> (droite, gauche);
}

/**
 * \brief Opérateur \c >=
 * \param gauche Gauche.
 * \param droite Droite.
 * \retval true si \c gauche est supérieure ou égale à \c droite.
 * \retval false sinon.
 * \relates reference_article
 */
static inline bool operator>= (const reference_article & gauche, const reference_article & droite)
{
    return ! operator< (droite, gauche);
}

/**
 * \brief Opérateur \c <<
 * \param[in,out] os Stream de sortie.
 * \param[in] r Référence.
 * \return \c os
 * \relates reference_article
 */
std::ostream & operator<< (std::ostream & os, const reference_article & r);

/**
 * \brief Opérateur \c >>
 * \param[in,out] is Stream d'entrée
 * \param[in] r Référence.
 * \return \c is
 * \relates reference_article
 */
std::istream & operator>> (std::istream & is, reference_article & r);

/**
 * \brief Échanger deux références.
 * \param[in,out] a Première référence.
 * \param[in,out] b Deuxième référence.
 * \relates reference_article
 */
static inline void swap (reference_article & a, reference_article & b)
{
    a.swap (b);
}

#endif /* __REFERENCE_ARTICLE_HPP__ */
