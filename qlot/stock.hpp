/**
 * \file stock.hpp
 * \brief Stock.
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
#ifndef __STOCK_HPP__
#define __STOCK_HPP__

#include <map>
#include <ostream>
#include <istream>
#include <algorithm>

#include "date.hpp"
#include "pourcentage.hpp"
#include "reference_article.hpp"
#include "article.hpp"
#include "article_stock.hpp"

////////////////////////////////////////////////////////////////////////////////
// Typedefs.
////////////////////////////////////////////////////////////////////////////////

typedef std::pair<unsigned int, article_stock> stock_element;
typedef std::map<unsigned int, article_stock> stock_map;
typedef stock_map::iterator stock_iterator;
typedef stock_map::const_iterator stock_const_iterator;

////////////////////////////////////////////////////////////////////////////////
// Classe.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Stock.
 */
class stock
{
public:
    /**
     * \brief Constructeur.
     */
    stock (void);

    /**
     * \brief Destructeur.
     */
    ~stock (void);

    /**
     * \brief Constructeur.
     * \param s Stock.
     * \return Stock.
     */
    stock (const stock & s);

    /**
     * \brief Ajouter un article.
     * \param a Article à ajouter.
     */
    void ajouter_article (const article_stock & a);

    /**
     * \brief Ajouter un article.
     * \param reference Référence.
     * \param quantite Quantité.
     * \param rabais Rabais.
     */
    void ajouter_article (const reference_article & reference, unsigned int quantite = 0, const pourcentage & rabais = pourcentage::ZERO);

    /**
     * \brief Retirer un article.
     * \param a Article à retirer.
     */
    void retirer_article (const article_stock & a);

    /**
     * \brief Retirer un article.
     * \param reference Référence de l'article à retirer.
     */
    void retirer_article (unsigned int reference);

    /**
     * \brief Retirer un article.
     * \param reference Référence de l'article à retirer.
     */
    void retirer_article (const reference_article & reference);

    /**
     * \brief Vérifier si un article existe en stock.
     * \param reference Référence.
     * \return \c true si l'article existe, \c false sinon.
     */
    bool article_en_stock (unsigned int reference) const;

    /**
     * \brief Vérifier si un article existe en stock.
     * \param reference Référence.
     * \return \c true si l'article existe, \c false sinon.
     */
    bool article_en_stock (const reference_article & reference) const;

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
     * \brief Opérateur \c =.
     * \param s Stock à assigner.
     */
    stock & operator= (stock s);

    /**
     * \brief Vérifier si le stock est vide.
     * \return Vacuité du stock.
     */
    bool vide (void) const;

    /**
     * \brief Itérateur vers le début du stock.
     * \return Itérateur.
     */
    stock_const_iterator begin (void) const;

    /**
     * \brief Itérateur vers la fin du stock.
     * \return Itérateur.
     */
    stock_const_iterator end (void) const;

    /**
     * \brief Obtenir le nombre d'articles distincts dans le stock.
     * \return Nombre d'articles.
     */
    unsigned int nombre_articles_stock (void) const;

    /**
     * \brief Opérateur \c [].
     * \param reference Référence de l'article recherché.
     * \return Article.
     */
    article_stock & operator[] (unsigned int reference);

    /**
     * \brief Opérateur \c [].
     * \param reference Référence de l'article recherché.
     * \return Article.
     */
    article_stock & operator[] (const reference_article & reference);

    /**
     * \brief Opérateur \c [] (version \c const).
     * \param reference Référence de l'article recherché.
     * \return Article.
     */
    const article_stock & operator[] (unsigned int reference) const;

    /**
     * \brief Opérateur \c [] (version \c const).
     * \param reference Référence de l'article recherché.
     * \return Article.
     */
    const article_stock & operator[] (const reference_article & reference) const;

    /**
     * \brief Échanger les contenus de deux stocks.
     * \param s Stock à échanger.
     */
    void swap (stock & s);

    /**
     * \brief Écrire sur un flux de sortie.
     * \param os Stream de sortie.
     */
    std::ostream & ecrire_vers (std::ostream & os) const;

private:
    stock_map _stock;   /**<- Stock. */
};

////////////////////////////////////////////////////////////////////////////////
// Fonctions non membres.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Opérateur \c <<.
 * \param[in,out] os Stream de sortie.
 * \param[in] s Stock.
 * \return \c os.
 * \relates stock
 */
std::ostream & operator<< (std::ostream & os, const stock & s);

/**
 * \brief Opérateur \c >>.
 * \param[in,out] is Stream d'entrée
 * \param[in] s Stock.
 * \return \c is.
 * \relates stock
 */
std::istream & operator>> (std::istream & is, stock & s);

/**
 * \brief Échanger les contenus de deux stocks.
 * \param[in,out] s1 Stock 1.
 * \param[in,out] s2 Stock 2.
 * \relates stock
 */
static inline void swap (stock & s1, stock & s2)
{
    s1.swap (s2);
}

#endif /* __STOCK_HPP__ */
