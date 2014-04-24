/**
 * \file pourcentage.hpp
 * \brief Pourcentage.
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
#ifndef __POURCENTAGE_HPP__
#define __POURCENTAGE_HPP__

#include <algorithm>
#include <istream>
#include <ostream>

////////////////////////////////////////////////////////////////////////////////
// Classe.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Pourcentage.
 */
class pourcentage
{
public:
    static const unsigned int MINIMUM = 0;      /**<- Pourcentage minimal. */
    static const unsigned int MAXIMUM = 100;    /**<- Pourcentage maximal. */
    static const pourcentage ZERO;
    static const pourcentage CENT;

    /**
     * \brief Constructeur.
     * \pre valeur <= pourcentage::MAXIMUM && valeur >= pourcentage::MINIMUM
     *
     * En cas de valeur invalide, le pourcentage est initialisé à la valeur
     * minimum (pourcentage::MINIMUM).
     */
    pourcentage (unsigned int valeur = pourcentage::MINIMUM);

    /**
     * \brief Constructeur.
     * \param p Pourcentage.
     */
    pourcentage (const pourcentage & p);

    /**
     * \brief Destructeur.
     */
    ~pourcentage (void);

    /**
     * \brief Obtenir la valeur du pourcentage.
     * \return Valeur.
     */
    unsigned int valeur (void) const;

    /**
     * \brief Modifier le pourcentage.
     * \param valeur Nouvelle valeur.
     * \pre valeur <= pourcentage::MAXIMUM && valeur >= pourcentage::MINIMUM
     */
    void modifier_valeur (unsigned int valeur);

    /**
     * \brief Modifier le pourcentage.
     * \param p Nouveau pourcentage.
     */
    void modifier_valeur (const pourcentage & p);

    /**
     * \brief Appliquer le pourcentage.
     * \param f Valeur sur laquelle appliquer le pourcentage.
     * \return f * pourcentage.
     */
    float appliquer_a (float f) const;

    /**
     * \brief Appliquer le pourcentage.
     * \param d Valeur sur laquelle appliquer le pourcentage.
     * \return d * pourcentage.
     */
    double appliquer_a (double d) const;

    /**
     * \brief Déterminer si deux pourcentages sont égaux.
     * \param p Pourcentage à comparer.
     * \return Égalité des deux pourcentages.
     */
    bool egal (const pourcentage & p) const;

    /**
     * \brief Déterminer si le pourcentage est inférieur à un autre pourcentage.
     * \param p Pourcentage à comparer.
     * \return Comparaison des deux pourcentages.
     */
    bool inferieur_a (const pourcentage & p) const;

    /**
     * \brief Échanger deux pourcentages.
     * \param p Pourcentage.
     */
    void swap (pourcentage & p);

    /**
     * \brief Opérateur \c =.
     * \param p Pourcentage.
     */
    pourcentage & operator= (pourcentage p);


private:
    unsigned int _valeur;   /**<- Valeur. */
    static inline unsigned int _seuil_valeur (unsigned int valeur)
    {
        return valeur > pourcentage::MAXIMUM ? pourcentage::MINIMUM : valeur;
    }
};

////////////////////////////////////////////////////////////////////////////////
// Fonctions non membres.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Opérateur \c ==.
 * \param gauche Gauche.
 * \param droite Droite.
 * \retval true si \c gauche est égal à \c droite.
 * \retval false sinon.
 * \relates pourcentage
 */
static inline bool operator== (const pourcentage & gauche, const pourcentage & droite)
{
    return gauche.egal (droite);
}

/**
 * \brief Opérateur \c !=.
 * \param gauche Gauche.
 * \param droite Droite.
 * \retval true si \c gauche est différent de \c droite.
 * \retval false sinon.
 * \relates pourcentage
 */
static inline bool operator!= (const pourcentage & gauche, const pourcentage & droite)
{
    return ! operator== (gauche, droite);
}

/**
 * \brief Opérateur \c <
 * \param gauche Gauche.
 * \param droite Droite.
 * \retval true si \c gauche est inférieur à \c droite.
 * \retval false sinon.
 * \relates pourcentage
 */
static inline bool operator< (const pourcentage & gauche, const pourcentage & droite)
{
    return gauche.inferieur_a (droite);
}

/**
 * \brief Opérateur \c >
 * \param gauche Gauche.
 * \param droite Droite.
 * \retval true si \c gauche est supérieur à \c droite.
 * \retval false sinon.
 * \relates pourcentage
 */
static inline bool operator> (const pourcentage & gauche, const pourcentage & droite)
{
    return operator< (droite, gauche);
}

/**
 * \brief Opérateur \c <=.
 * \param gauche Gauche.
 * \param droite Droite.
 * \retval true si \c gauche est inférieur ou égal à \c droite.
 * \retval false sinon.
 * \relates pourcentage
 */
static inline bool operator<= (const pourcentage & gauche, const pourcentage & droite)
{
    return ! operator> (gauche, droite);
}

/**
 * \brief Opérateur \c >=.
 * \param gauche Gauche.
 * \param droite Droite.
 * \retval true si \c gauche est supérieur ou égal à \c droite.
 * \retval false sinon.
 * \relates pourcentage
 */
static inline bool operator>= (const pourcentage & gauche, const pourcentage & droite)
{
    return ! operator< (gauche, droite);
}

/**
 * \brief Opérateur \c <<.
 * \param[in,out] os Stream de sortie.
 * \param[in] p Pourcentage.
 * \return \c os.
 * \relates pourcentage
 * \relatesalso std::ostream
 */
std::ostream & operator<< (std::ostream & os, const pourcentage & p);

/**
 * \brief Opérateur \c <<.
 * \param[in,out] is Stream d'entrée.
 * \param[in] p Pourcentage.
 * \return \c is.
 * \relates pourcentage
 * \relatesalso std::istream
 */
std::istream & operator>> (std::istream & is, pourcentage & p);

/**
 * \brief Échanger deux pourcentages.
 * \param[in,out] a Premier pourcentage.
 * \param[in,out] b Deuxième pourcentage.
 * \relates pourcentage
 */
static inline void swap (pourcentage & a, pourcentage & b)
{
    a.swap (b);
}

#endif /* __POURCENTAGE_HPP__ */
