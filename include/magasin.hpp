/**
 * \file magasin.hpp
 * \brief Magasin.
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
#ifndef __MAGASIN_HPP__
#define __MAGASIN_HPP__

#include <map>
#include <istream>
#include <ostream>
#include <vector>
#include <algorithm>

#include "article.hpp"
#include "reference_article.hpp"
#include "pourcentage.hpp"
#include "date.hpp"
#include "stock.hpp"
#include "historique_ventes.hpp"
#include "articles_existants.hpp"
#include "article_affichage.hpp"
#include "condition_article.hpp"

////////////////////////////////////////////////////////////////////////////////
// Classe.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Magasin.
 * \sa articles_existants, stock, historique_ventes
 *
 * Le magasin se charge d'enregistrer les articles et les ventes.
 * Lors de la modification d'un article, d'une vente, etc., c'est le magasin
 * qui se charge de conserver l'intégrité (notamment lors de modifications qui
 * affectent la référence d'un article.)
 */
class magasin
{
public:
    /**
     * \brief Constructeur.
     */
    magasin (void);

    /**
     * \brief Constructeur.
     * \param m Magasin.
     */
    magasin (const magasin & m);

    /**
     * \brief Constructeur.
     * \param a Articles existants.
     * \param s Stock.
     * \param h Historique des ventes.
     */
    magasin (const articles_existants & a, const stock & s, const historique_ventes & h);

    /**
     * \brief Destructeur.
     */
    ~magasin (void);

    /**
     * \brief Obtenir le nombre d'articles.
     * \return Nombre d'articles.
     */
    unsigned int nombre_articles (void) const;

    /**
     * \brief Obtenir le nombre de ventes.
     * \return Nombre de ventes.
     */
    unsigned int nombre_ventes (void) const;

    /**
     * \brief Déterminer le prix total payé pour toutes les ventes.
     * \return Total.
     */
    float total_ventes (void) const;

    /**
     * \brief Déterminier si un article existe.
     * \param reference Référence.
     * \retval true Si l'article existe.
     * \retval false Sinon.
     */
    bool article_existe (unsigned int reference) const;

    /**
     * \brief Déterminer si un article existe.
     * \param reference Référence.
     * \retval true Si l'article existe.
     * \retval false Sinon.
     */
    bool article_existe (const reference_article & reference) const;

    /**
     * \brief Obtenir un article.
     * \param reference Référence.
     * \return Article affichage.
     */
    article_affichage operator[] (unsigned int reference) const;

    /**
     * \brief Obtenir un article.
     * \param reference Référence.
     * \return Article affichage.
     */
    article_affichage operator[] (const reference_article & reference) const;

    /**
     * \brief Obtenir les articles dont le modèle correspond.
     * \param modele Modèle.
     * \return Articles qui correspondent.
     */
    std::vector<article_affichage> articles_par_modele (unsigned int modele) const;

    /**
     * \brief Obtenir les articles dont la taille correspond.
     * \param taille Taille.
     * \return Articles qui correspondent.
     */
    std::vector<article_affichage> articles_par_taille (unsigned int taille) const;

    /**
     * \brief Obtenir les articles dont la couleur correspond.
     * \param couleur Couleur.
     * \return Articles qui correspondent.
     */
    std::vector<article_affichage> articles_par_couleur (unsigned int couleur) const;

    /**
     * \brief Obtenir les articles dont la date correspond.
     * \param date_livraison Date.
     * \return Articles qui correspondent.
     */
    std::vector<article_affichage> articles_par_date (const date & date_livraison) const;

    /**
     * \brief Obtenir les articles dont le prix d'achat correspond.
     * \param minimum Prix minimum.
     * \param maximum Prix maximum.
     * \return Articles qui correspondent.
     */
    std::vector<article_affichage> articles_par_prix_achat (float minimum, float maximum) const;

    /**
     * \brief Obtenir les articles dont le prix de vente correspond.
     * \param minimum Prix minimum.
     * \param maximum Prix maximum.
     * \return Articles qui correspondent.
     */
    std::vector<article_affichage> articles_par_prix_vente (float minimum, float maximum) const;

    /**
     * \brief Obtenir les articles dont le prix de vente effectif correspond.
     * \param minimum Prix minimum.
     * \param maximum Prix maximum.
     * \return Articles qui correspondent.
     */
    std::vector<article_affichage> articles_par_prix_effectif (float minimum, float maximum) const;

    /**
     * \brief Ajouter un article.
     * \param a Article.
     * \param quantite Quantité.
     * \param rabais Rabais.
     */
    void ajouter_article (const article & a, unsigned int quantite = 0, const pourcentage & rabais = pourcentage::ZERO);

    /**
     * \brief Ajouter une vente.
     * \param v Vente.
     */
    void ajouter_vente (const vente & v);

    /**
     * \brief Modifier le modèle d'un article.
     * \param reference Référence de l'article à modifier.
     * \param modele Nouveau modèle.
     * \return Nouvelle référence.
     * \warning La référence de l'article sera changée !
     */
    void modifier_modele_article (unsigned int reference, unsigned int modele);

    /**
     * \brief Modifier le modèle d'un article.
     * \param reference Référence de l'article à modifier.
     * \param modele Nouveau modèle.
     * \return Nouvelle référence.
     * \warning La référence de l'article sera changée !
     */
    void modifier_modele_article (const reference_article & reference, unsigned int modele);

    /**
     * \brief Modifier le modèle d'un article.
     * \param reference Référence de l'article à modifier.
     * \param couleur Nouvelle couleur.
     * \return Nouvelle référence.
     * \warning La référence de l'article sera changée !
     */
    void modifier_couleur_article (unsigned int reference, unsigned int couleur);

    /**
     * \brief Modifier le modèle d'un article.
     * \param reference Référence de l'article à modifier.
     * \param couleur Nouvelle couleur.
     * \return Nouvelle référence.
     * \warning La référence de l'article sera changée !
     */
    void modifier_couleur_article (const reference_article & reference, unsigned int couleur);

    /**
     * \brief Modifier le modèle d'un article.
     * \param reference Référence de l'article à modifier.
     * \param taille Nouvelle taille.
     * \return Nouvelle référence.
     * \warning La référence de l'article sera changée !
     */
    void modifier_taille_article (unsigned int reference, unsigned int taille);

    /**
     * \brief Modifier le modèle d'un article.
     * \param reference Référence de l'article à modifier.
     * \param taille Nouvelle taille.
     * \return Nouvelle référence.
     * \warning La référence de l'article sera changée !
     */
    void modifier_taille_article (const reference_article & reference, unsigned int taille);

    /**
     * \brief Modifier la quantité d'un article.
     * \param reference Référence de l'article à modifier.
     * \param quantite Nouvelle quantité.
     */
    void modifier_quantite_article (unsigned int reference, unsigned int quantite);

    /**
     * \brief Modifier la quantité d'un article.
     * \param reference Référence de l'article à modifier.
     * \param quantite Nouvelle quantité.
     */
    void modifier_quantite_article (const reference_article & reference, unsigned int quantite);

    /**
     * \brief Modifier le rabais d'un article.
     * \param reference référence de l'article à modifier.
     * \param rabais Nouveau rabais.
     */
    void modifier_rabais_article (unsigned int reference, unsigned int rabais);

    /**
     * \brief Modifier le rabais d'un article.
     * \param reference référence de l'article à modifier.
     * \param rabais Nouveau rabais.
     */
    void modifier_rabais_article (const reference_article & reference, unsigned int rabais);

    /**
     * \brief Modifier le rabais d'un article.
     * \param reference référence de l'article à modifier.
     * \param rabais Nouveau rabais.
     */
    void modifier_rabais_article (unsigned int reference, const pourcentage & rabais);

    /**
     * \brief Modifier le rabais d'un article.
     * \param reference référence de l'article à modifier.
     * \param rabais Nouveau rabais.
     */
    void modifier_rabais_article (const reference_article & reference, const pourcentage & rabais);

    /**
     * \brief Modifier le prix d'achat d'un article.
     * \param reference Référence de l'article à modifier.
     * \param prix Nouveau prix d'achat.
     */
    void modifier_prix_achat_article (unsigned int reference, float prix);

    /**
     * \brief Modifier le prix d'achat d'un article.
     * \param reference Référence de l'article à modifier.
     * \param prix Nouveau prix d'achat.
     */
    void modifier_prix_achat_article (const reference_article & reference, float prix);

    /**
     * \brief Modifier le prix d'vente d'un article.
     * \param reference Référence de l'article à modifier.
     * \param prix Nouveau prix d'vente.
     */
    void modifier_prix_vente_article (unsigned int reference, float prix);

    /**
     * \brief Modifier le prix d'vente d'un article.
     * \param reference Référence de l'article à modifier.
     * \param prix Nouveau prix d'vente.
     */
    void modifier_prix_vente_article (const reference_article & reference, float prix);

    /**
     * \brief Modifier la date de livraison d'un article.
     * \param reference Référence de l'article à modifier.
     * \param date_livraison Nouvelle date de livraison.
     */
    void modifier_date_livraison_article (unsigned int reference, const date & date_livraison);

    /**
     * \brief Modifier la date de livraison d'un article.
     * \param reference Référence de l'article à modifier.
     * \param date_livraison Nouvelle date de livraison.
     */
    void modifier_date_livraison_article (const reference_article & reference, const date & date_livraison);

    /**
     * \brief Modifier la date de livraison d'un article.
     * \param reference Référence de l'article à modifier.
     * \param jour Jour.
     * \param mois Mois.
     * \param annee Année.
     */
    void modifier_date_livraison_article (unsigned int reference, unsigned int jour, unsigned int mois, unsigned int annee);

    /**
     * \brief Modifier la date de livraison d'un article.
     * \param reference Référence de l'article à modifier.
     * \param jour Jour.
     * \param mois Mois.
     * \param annee Année.
     */
    void modifier_date_livraison_article (const reference_article & reference, unsigned int jour, unsigned int mois, unsigned int annee);

    /**
     * \brief Annuler une vente.
     * \param v Vente.
     */
    void annuler_vente (const vente & v);

    /**
     * \brief Annuler une vente.
     * \param id Id.
     */
    void annuler_vente (unsigned int id);

    /**
     * \brief Modifier la date d'une vente.
     * \param id ID.
     * \param d Date.
     */
    void modifier_date_vente (unsigned int id, const date & d);

    /**
     * \brief Modifier la date d'une vente.
     * \param id ID.
     * \param jour Jour.
     * \param mois Mois.
     * \param annee Année.
     */
    void modifier_date_vente (unsigned int id, unsigned int jour, unsigned int mois, unsigned int annee);

    /**
     * \brief Annuler la vente d'un article.
     * \param id_vente ID de la vente.
     * \param reference Référence de l'article.
     */
    void annuler_vente_article (unsigned int id_vente, unsigned int reference);

    /**
     * \brief Annuler la vente d'un article.
     * \param id_vente ID de la vente.
     * \param reference Référence de l'article.
     */
    void annuler_vente_article (unsigned int id_vente, const reference_article & reference);

    /**
     * \brief Modifier la quantité vendue lors d'une vente d'un article.
     * \param id ID de la vente.
     * \param reference Référence de l'article.
     * \param quantite Quantité.
     */
    void modifier_vente_article_quantite (unsigned int id, unsigned int reference, unsigned int quantite);

    /**
     * \brief Modifier la quantité vendue lors d'une vente d'un article.
     * \param id ID de la vente.
     * \param reference Référence de l'article.
     * \param quantite Quantité.
     */
    void modifier_vente_article_quantite (unsigned int id, const reference_article & reference, unsigned int quantite);

    /**
     * \brief Modifier le prix de vente d'un article dans une vente.
     * \param id ID de la vente.
     * \param reference Référence de l'article.
     * \param prix Prix.
     */
    void modifier_vente_article_prix (unsigned int id, unsigned int reference, float prix);

    /**
     * \brief Modifier le prix de vente d'un article dans une vente.
     * \param id ID de la vente.
     * \param reference Référence de l'article.
     * \param prix Prix.
     */
    void modifier_vente_article_prix (unsigned int id, const reference_article & reference, float prix);

    /**
     * \brief Échanger deux magasins.
     * \param m Magasin.
     */
    void swap (magasin & m);

    /**
     * \brief Opérateur \c =.
     * \param m Magasin.
     */
    magasin & operator= (magasin m);

    /**
     * \brief Écrire les articles dans un flux de sortie.
     * \param os Stream de sortie.
     * \return \c os.
     */
    std::ostream & ecrire_articles_vers (std::ostream & os) const;

    /**
     * \brief Écrire le stock dans un flux de sortie.
     * \param os Stream de sortie.
     * \return \c os.
     */
    std::ostream & ecrire_stock_vers (std::ostream & os) const;

    /**
     * \brief Écrire l'historique dans un flux de sortie.
     * \param os Stream de sortie.
     * \return \c os.
     */
    std::ostream & ecrire_historique_vers (std::ostream & os) const;

    /**
     * \brief Écrire vers un flux de sortie.
     * \param os Stream de sortie.
     * \return \c os.
     */
    std::ostream & ecrire_vers (std::ostream & os) const;

private:
    stock _stock;                       /**<- Stock. */
    articles_existants _articles;       /**<- Articles. */
    historique_ventes _historique;      /**<- Historique. */

    /**
     * \brief Obtenir un vector contenant tous les articles respectant une condition.
     * \param condition Condition.
     * \return std::vector.
     */
    std::vector<article_affichage> _articles_par_condition (condition_article condition) const;

    /**
     * \brief Modifier le modèle d'un article.
     * \param a Article
     * \param modele Nouveau modèle.
     * \sa magasin::_modificateur_reference
     */
    static inline void _modificateur_modele (article & a, unsigned int modele)
    {
        a.modifier_modele (modele);
    }

    /**
     * \brief Modifier la taille d'un article.
     * \param a Article
     * \param taille Nouvelle taille.
     * \sa magasin::_modificateur_reference
     */
    static inline void _modificateur_taille (article & a, unsigned int taille)
    {
        a.modifier_taille (taille);
    }

    /**
     * \brief Modifier la couleur d'un article.
     * \param a Article
     * \param couleur Nouvelle couleur.
     * \sa magasin::_modificateur_reference
     */
    static inline void _modificateur_couleur (article & a, unsigned int couleur)
    {
        a.modifier_couleur (couleur);
    }

    /**
     * \brief Fonction générique pour les modificateurs modifiant la référence d'un article.
     * \param reference Référence de l'article à modifier.
     * \param valeur Nouvelle valeur.
     * \param modificateur Modificateur.
     * \sa magasin::_modificateur_modele, magasin::_modificateur_taille, magasin::_modificateur_couleur
     *
     * Les fonctions à utiliser en paramètre sont :
     * - magasin::_modificateur_modele
     * - magasin::_modificateur_taille
     * - magasin::_modificateur_couleur
     */
    void _modificateur_reference (unsigned int reference, unsigned int valeur, void (* modificateur) (article &, unsigned int));
};

////////////////////////////////////////////////////////////////////////////////
// Fonctions non membres.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Opérateur \c <<
 * \param[in,out] os Stream de sortie.
 * \param[in] m Magasin.
 * \return \c os.
 * \relates magasin
 */
std::ostream & operator<< (std::ostream & os, const magasin & m);

/**
 * \brief Operateur \c >>
 * \param[in,out] is Stream d'entrée.
 * \param[in] m Magasin.
 * \return \c is.
 * \relates magasin
 */
std::istream & operator<< (std::istream & is, magasin & m);

/**
 * \brief Échanger deux magasins.
 * \param[in,out] a Magasin.
 * \param[in,out] b Magasin.
 * \relates magasin
 */
static inline void swap (magasin & a, magasin & b)
{
    a.swap (b);
}

#endif /* __MAGASIN_HPP__ */
