/**
 * \file date.cpp
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
#include "date.hpp"

////////////////////////////////////////////////////////////////////////////////
// Variables.
////////////////////////////////////////////////////////////////////////////////

static std::string _SEMAINE[] =
{
    "Dimanche",
    "Lundi",
    "Mardi",
    "Mercredi",
    "Jeudi",
    "Vendredi",
    "Samedi",
};

////////////////////////////////////////////////////////////////////////////////
// Méthodes statiques.
////////////////////////////////////////////////////////////////////////////////

inline int date::_mois_correct (int mois)
{
    /* Les valeurs valides du champ "tm_mon" de "struct tm" sont [0, 11]. */
    return mois - date::_DECALAGE_MOIS;
}

inline int date::_annee_correcte (int annee)
{
    /* "tm_year" : Nombre d'années depuis 1900. */
    return annee - date::_DECALAGE_ANNEES;
}


////////////////////////////////////////////////////////////////////////////////
// Constructeurs.
////////////////////////////////////////////////////////////////////////////////

date::date (void)
{
    time_t maintenant = time (NULL);
    struct tm * local = localtime (& maintenant); // que vais-je faire ?
    _date = * local;
}

date::date (const date & d)
{
    _date = d._date;
}

date::date (int jour, int mois, int annee)
{
    time_t maintenant = time (NULL);
    struct tm * local = localtime (& maintenant);

    /* On veut une précision au jour, pas besoin des heures, minutes,
     * secondes.
     * tm_hour = 3 car struct_tm peut prendre en compte les heures
     * d'été/hiver.
     */
    local->tm_sec = 0;
    local->tm_min = 0;
    local->tm_hour = 3;

    local->tm_year = _annee_correcte (annee);
    local->tm_mon = _mois_correct (mois);
    local->tm_mday = jour;
    mktime (local);
    _date = * local;
}

////////////////////////////////////////////////////////////////////////////////
// Destructeur.
////////////////////////////////////////////////////////////////////////////////

date::~date (void)
{
}

////////////////////////////////////////////////////////////////////////////////
// Sélecteurs.
////////////////////////////////////////////////////////////////////////////////

int date::annee (void) const
{
    return _date.tm_year + date::_DECALAGE_ANNEES;
}

int date::mois (void) const
{
    return _date.tm_mon + date::_DECALAGE_MOIS;
}

int date::jour (void) const
{
    return _date.tm_mday;
}

std::string date::jour_semaine (void) const
{
    return _SEMAINE[_date.tm_wday];
}

////////////////////////////////////////////////////////////////////////////////
// Modificateurs.
////////////////////////////////////////////////////////////////////////////////

void date::modifier_jour (int jour)
{
    _date.tm_mday = jour;
    mktime (& _date);
}

void date::modifier_mois (int mois)
{
    _date.tm_mon = _mois_correct (mois);
    mktime (& _date);
}

void date::modifier_annee (int annee)
{
    _date.tm_year = _annee_correcte (annee);
    mktime (& _date);
}

void date::modifier (int jour, int mois, int annee)
{
    _date.tm_year = _annee_correcte (annee);
    _date.tm_mon = _mois_correct (mois);
    _date.tm_mday = jour;
    mktime (& _date);
}

void date::modifier (const date & d)
{
    _date = d._date;
}

////////////////////////////////////////////////////////////////////////////////
// Comparaisons.
////////////////////////////////////////////////////////////////////////////////

bool date::egal (const date & d) const
{
    return  annee () == d.annee () && mois () == d.mois () && jour () == d.jour ();
}

bool date::inferieur_a (const date & d) const
{
    bool resultat = true;

    if (annee () > d.annee ())
        resultat = false;
    else if (annee () == d.annee ())
    {
        if (mois () > d.mois ())
            resultat = false;
        else if (mois () == d.mois ())
            resultat = jour () < d.jour ();
    }

    return resultat;
}

////////////////////////////////////////////////////////////////////////////////
// Divers.
////////////////////////////////////////////////////////////////////////////////

void date::swap (date & d)
{
    std::swap (_date, d._date);
}

date & date::operator= (date d)
{
    this->swap (d);
    return * this;
}

////////////////////////////////////////////////////////////////////////////////
// Fonctions non membres.
////////////////////////////////////////////////////////////////////////////////

std::ostream & operator<< (std::ostream & os, const date & d)
{
    os << d.jour () << "/" << d.mois () << "/" << d.annee ();
    return os;
}

std::istream & operator>> (std::istream & is, date & d)
{
    unsigned int jour, mois, annee;
    char separateur[2];

    is >> jour >> separateur[0] >> mois >> separateur[1] >> annee;

    if ((! is.good ()) || separateur[0] != '/' || separateur[1] != '/')
    {
        is.setstate (std::ios_base::failbit);
    }
    else
    {
        date nouvelle_date (jour, mois, annee);
        d = nouvelle_date;
    }

    return is;
}
