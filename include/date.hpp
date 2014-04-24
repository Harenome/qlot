/**
 * \file date.hpp
 * \brief Date.
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
#ifndef __DATE_HPP__
#define __DATE_HPP__

#include <string>
#include <ctime>
#include <istream>
#include <ostream>
#include <algorithm>

////////////////////////////////////////////////////////////////////////////////
// Classe.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Date.
 */
class date
{
public:
    /**
     * \brief Constructeur.
     * La date sera la date actuelle.
     */
    date (void);

    /**
     * \brief Constructeur.
     * \param jour Jour.
     * \param mois Mois.
     * \param annee Annee.
     */
    date (int jour, int mois, int annee);

    /**
     * \brief Constructeur.
     * \param d Date.
     */
    date (const date & d);

    /**
     * \brief Destructeur.
     */
    ~date (void);

    /**
     * \brief Obtenir l'année.
     * \return Année.
     */
    int annee (void) const;

    /**
     * \brief Obtenir le mois.
     * \return Mois.
     */
    int mois (void) const;

    /**
     * \brief Otenir le jour.
     * \return Jour.
     */
    int jour (void) const;

    /**
     * \brief Obtenir le jour de la semaine.
     * \return Jour de la semaine.
     */
    std::string jour_semaine (void) const;

    /**
     * \brief Modifier le jour.
     * \param jour Jour.
     */
    void modifier_jour (int jour);

    /**
     * \brief Modifier le mois.
     * \param mois Mois.
     */
    void modifier_mois (int mois);

    /**
     * \brief Modifier l'année.
     * \param annee Année.
     */
    void modifier_annee (int annee);

    /**
     * \brief Modifier la date.
     * \param jour Jour.
     * \param mois Mois.
     * \param annee Année.
     */
    void modifier (int jour, int mois, int annee);

    /**
     * \brief Modifier la date.
     * \param d Date.
     */
    void modifier (const date & d);

    /**
     * \brief Déterminer si deux dates sont égales.
     * \param d Date à comparer.
     * \retval true si la date est égale à \c d.
     * \retval false sinon.
     */
    bool egal (const date & d) const;

    /**
     * \brief Déterminer si la date est inférieur à une autre date.
     * \param d Date à comparer.
     * \retval true si la date est inférieure à \c d.
     * \retval false sinon.
     */
    bool inferieur_a (const date & d) const;

    /**
     * \brief Échanger deux dates.
     */
    void swap (date & d);

    /**
     * \brief Opérateur \c =.
     * \param d Date
     */
    date & operator= (date d);

private:
    struct tm _date;                            /**<- Date. */
    static const int _DECALAGE_MOIS = 1;        /**<- Décalage mois. (voir struct tm). */
    static const int _DECALAGE_ANNEES = 1990;   /**<- Décalage années. (voir struct tm). */

    /**
     * \brief Accorder un mois fourni par l'utilisateur avec struct tm.
     * \param mois Mois dans [1, 12].
     * \return Mois dans [0, 11].
     */
    static inline int _mois_correct (int mois);

    /**
     * \brief Accorder une année fournie par l'utilisateur avec struct tm.
     * \param annee Année YYYY.
     * \return Nombre d'années depuis 1900.
     */
    static inline int _annee_correcte (int annee);
};

////////////////////////////////////////////////////////////////////////////////
// Fonctions non membres.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Opérateur \c ==
 * \param gauche Gauche.
 * \param droite Droite.
 * \retval true si \c gauche et \c droite sont égales.
 * \retval false sinon.
 * \relates date
 */
static inline bool operator== (const date & gauche, const date & droite)
{
    return gauche.egal (droite);
}

/**
 * \brief Opérateur \c <
 * \param gauche Gauche.
 * \param droite Droite.
 * \retval true si \c gauche est différente de \c droite.
 * \retval false sinon.
 * \relates date
 */
static inline bool operator!= (const date & gauche, const date & droite)
{
    return ! operator== (gauche, droite);
}

/**
 * \brief Opérateur \c <
 * \param gauche Gauche.
 * \param droite Droite.
 * \retval true si \c gauche est inférieure à \c droite.
 * \retval false sinon.
 * \relates date
 */
static inline bool operator< (const date & gauche, const date & droite)
{
    return gauche.inferieur_a (droite);
}

/**
 * \brief Opérateur \c >
 * \param gauche Gauche.
 * \param droite Droite.
 * \retval true si \c gauche est supérieure à \c droite.
 * \retval false sinon.
 * \relates date
 */
static inline bool operator> (const date & gauche, const date & droite)
{
    return operator< (droite, gauche);
}

/**
 * \brief Opérateur \c <=
 * \param gauche Gauche.
 * \param droite Droite.
 * \retval true si \c gauche est inférieure ou égale à \c droite.
 * \retval false sinon.
 * \relates date
 */
static inline bool operator<= (const date & gauche, const date & droite)
{
    return ! operator> (gauche, droite);
}

/**
 * \brief Opérateur \c >=
 * \param gauche Gauche.
 * \param droite Droite.
 * \retval true si \c gauche est supérieure ou égale à \c droite.
 * \retval false sinon.
 * \relates date
 */
static inline bool operator>= (const date & gauche, const date & droite)
{
    return ! operator< (gauche, droite);
}

/**
 * \brief Opérateur \c <<
 * \param[in,out] os Stream de sortie.
 * \param[in] d Date.
 * \return \c os
 * \relates date
 */
std::ostream & operator<< (std::ostream & os, const date & d);

/**
 * \brief Operateur \c >>
 * \param[in,out] is Stream d'entrée.
 * \param[in] d Date.
 * \return \c is
 * \relates date
 */
std::istream & operator>> (std::istream & is, date & d);

/**
 * \brief Échanger deux dates.
 * \param[in,out] a Première date.
 * \param[in,out] b Deuxième date.
 * \relates date
 */
static inline void swap (date & a, date & b)
{
    a.swap (b);
}

#endif /* __DATE_HPP_  */
