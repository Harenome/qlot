/**
 * \file articles_existants.hpp
 * \brief Articles existants.
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
#ifndef __ARTICLES_EXISTANTS_HPP__
#define __ARTICLES_EXISTANTS_HPP__

#include <map>
#include <ostream>
#include <istream>
#include <algorithm>

#include "article.hpp"
#include "reference_article.hpp"

////////////////////////////////////////////////////////////////////////////////
// Typedefs.
////////////////////////////////////////////////////////////////////////////////

typedef std::pair<unsigned int, article> articles_existants_element;
typedef std::map<unsigned int, article> articles_existants_map;
typedef articles_existants_map::iterator articles_existants_iterator;
typedef articles_existants_map::const_iterator articles_existants_const_iterator;

////////////////////////////////////////////////////////////////////////////////
// Classe.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Articles existants.
 * \sa article, reference_article
 */
class articles_existants
{
public:
    /**
     * \brief Constructeur.
     */
    articles_existants (void);

    /**
     * \brief Constructeur.
     * \param a Articles existants.
     */
    articles_existants (const articles_existants & a);

    /**
     * \brief Destructeur.
     */
    ~articles_existants (void);

    /**
     * \brief Ajouter un article.
     * \param a Article.
     */
    void ajouter_article (const article & a);

    /**
     * \brief Retirer un article.
     * \param a Article.
     */
    void retirer_article (const article & a);

    /**
     * \brief Retirer un article.
     * \param reference Référence.
     */
    void retirer_article (const reference_article & reference);

    /**
     * \brief Retrier un article.
     * \param reference Référence.
     */
    void retirer_article (unsigned int reference);

    /**
     * \brief Obtenir un itérateur sur le début des articles.
     * \return itérateur.
     */
    articles_existants_const_iterator begin (void) const;

    /**
     * \brief Obtenir un itérateur sur la fin des articles.
     * \return itérateur.
     */
    articles_existants_const_iterator end (void) const;

    /**
     * \brief Déterminer si un article existe.
     * \param reference Référence.
     * \retval true Si un article portant cette référence existe.
     * \retval false Sinon.
     */
    bool existe (const reference_article & reference) const;

    /**
     * \brief Déterminer si un article existe.
     * \param reference Référence.
     * \retval true Si un article portant cette référence existe.
     * \retval false Sinon.
     */
    bool existe (unsigned int reference) const;

    /**
     * \brief Obtenir le nombre d'articles existants.
     * \return Nombre d'articles.
     */
    unsigned int nombre_articles (void) const;

    /**
     * \brief Opérateur \c [].
     * \param reference Référence.
     * \return Article.
     */
    article & operator[] (unsigned int reference);

    /**
     * \brief Opérateur \c [].
     * \param reference Référence
     * \return Article.
     */
    article & operator[] (const reference_article & reference);

    /**
     * \brief Opérateur \c [] (version \c const).
     * \param reference Référence.
     * \return Article.
     */
    const article & operator[] (unsigned int reference) const;

    /**
     * \brief Opérateur \c [] (version \c const).
     * \param reference Référence.
     * \return Article.
     */
    const article & operator[] (const reference_article & reference) const;

    /**
     * \brief Opérateur \c =.
     * \param a Articles existants.
     */
    articles_existants & operator= (articles_existants a);

    /**
     * \brief Échanger des articles_existants.
     * \param a Articles existants.
     */
    void swap (articles_existants & a);

    /**
     * \brief Écrire vers un flux de sortie.
     * \param os Stream de sortie.
     * \return \c os.
     */
    std::ostream & ecrire_vers (std::ostream & os) const;

private:
    articles_existants_map _articles;
};

////////////////////////////////////////////////////////////////////////////////
// Fonctions non membres.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Opérateur \c <<.
 * \param[in,out] os Stream de sortie.
 * \param[in] a Articles existants.
 * \return \c os.
 * \relates articles_existants
 */
std::ostream & operator<< (std::ostream & os, const articles_existants & a);

/**
 * \brief Opérateur \c >>.
 * \param[in,out] is Stream d'entrée.
 * \param[in] a Articles existants.
 * \return \c is.
 * \relates articles_existants
 */
std::istream & operator>> (std::istream & is, articles_existants & a);

/**
 * \brief Échanger des articles_existants.
 * \param[in,out] a Articles existants.
 * \param[in,out] b Articles existants.
 * \relates articles_existants
 */
static inline void swap (articles_existants & a, articles_existants & b)
{
    a.swap (b);
}

#endif /* __ARTICLES_EXISTANTS_HPP__ */
