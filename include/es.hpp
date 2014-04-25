/**
 * \file es.hpp
 * \brief Entrées / Sorties.
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
#ifndef __ES_HPP__
#define __ES_HPP__

#include <fstream>
#include <string>

#include "magasin.hpp"

/**
 * \brief Entrées / Sorties.
 * \sa magasin
 */
class es
{
public:
    /**
     * \brief Charger un magasin depuis un fichier.
     * \param chemin Chemin du fichier.
     * \param m Magasin.
     * \retval true Pas d'erreur.
     * \retval false Erreur.
     */
    static bool charger_magasin (const char * chemin, magasin & m);

    /**
     * \brief Charger un magasin depuis un fichier.
     * \param chemin Chemin du fichier.
     * \param m Magasin.
     * \retval true Pas d'erreur.
     * \retval false Erreur.
     */
    static bool charger_magasin (std::string chemin, magasin & m);

    /**
     * \brief Charger un magasin depuis un fichier.
     * \param fichier Fichier.
     * \param m Magasin.
     * \retval true Pas d'erreur.
     * \retval false Erreur.
     */
    static bool charger_magasin (std::ifstream & fichier, magasin & m);

    /**
     * \brief Sauvegarder un magasin dans un fichier.
     * \param chemin Chemin.
     * \param m Magasin.
     * \retval true Pas d'erreur.
     * \retval false Erreur.
     */
    static bool sauvegarder_magasin (const char * chemin, const magasin & m);

    /**
     * \brief Sauvegarder un magasin dans un fichier.
     * \param chemin Chemin.
     * \param m Magasin.
     * \retval true Pas d'erreur.
     * \retval false Erreur.
     */
    static bool sauvegarder_magasin (std::string chemin, const magasin & m);

    /**
     * \brief Sauvegarder un magasin dans un fichier.
     * \param fichier Fichier.
     * \param m Magasin.
     * \retval true Pas d'erreur.
     * \retval false Erreur.
     */
    static bool sauvegarder_magasin (std::ofstream & fichier, const magasin & m);
};

#endif /* __ES_HPP__ */
