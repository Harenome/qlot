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

#include "date.hpp"
#include "pourcentage.hpp"
#include "reference_article.hpp"
#include "article.hpp"
#include "article_affichage.hpp"
#include "article_stock.hpp"
#include "article_vendu.hpp"
#include "vente.hpp"
#include "stock.hpp"
#include "historique_ventes.hpp"
#include "articles_existants.hpp"
#include "condition_article.hpp"
#include "condition_vente.hpp"

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
     * \brief Obtenir le nombre d'articles en stock.
     * \return Nombre d'articles en stock.
     *
     * Les articles en stock sont les articles dont la quantité est supérieure
     * ou égale à 1. Donc magasin::nombre_articles_en_stock retourne une
     * valeur inférieure ou égale à magasin::nombre_articles.
     */
    unsigned int nombre_articles_en_stock (void) const;

    /**
     * \brief Déterminer les frais.
     * \return Frais.
     */
    double frais (void) const;

    /**
     * \brief Déterminer les bénéfices.
     * \return Bénéfices.
     * \note Équivalent à magasin::chiffre_d_affaires () - magasin::frais ().
     */
    double benefices (void) const;

    /**
     * \brief Obtenir le nombre de ventes.
     * \return Nombre de ventes.
     */
    unsigned int nombre_ventes (void) const;

    /**
     * \brief Déterminer le prix total payé pour toutes les ventes.
     * \return Total.
     */
    double chiffre_d_affaires (void) const;

    /**
     * \brief Déterminer si un article existe.
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
     * \brief Vérifier qu'une vente existe.
     * \param id ID.
     * \retval true Si la vente existe.
     * \retval false Sinon.
     */
    bool vente_existe (unsigned int id) const;

    /**
     * \brief Obtenir une vente.
     * \param id ID.
     * \return vente.
     */
    vente vente_id (unsigned int id) const;

    /**
     * \brief Obtenir tous les articles.
     * \return Articles.
     */
    std::vector<article_affichage> articles (void) const;

    /**
     * \brief Obtenir tous les articles en stock.
     * \return Articles.
     */
    std::vector<article_affichage> articles_en_stock (void) const;

    /**
     * \brief Obtenir toutes les references.
     * \return Références.
     */
    std::vector<reference_article> references (void) const;

    /**
     * \brief Obtenir toutes les references des articles en stock.
     * \return Références.
     */
    std::vector<reference_article> references_en_stock (void) const;

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
    std::vector<article_affichage> articles_par_prix_achat (double minimum, double maximum) const;

    /**
     * \brief Obtenir les articles dont le prix de vente correspond.
     * \param minimum Prix minimum.
     * \param maximum Prix maximum.
     * \return Articles qui correspondent.
     */
    std::vector<article_affichage> articles_par_prix_vente (double minimum, double maximum) const;

    /**
     * \brief Obtenir les articles dont le prix de vente effectif correspond.
     * \param minimum Prix minimum.
     * \param maximum Prix maximum.
     * \return Articles qui correspondent.
     */
    std::vector<article_affichage> articles_par_prix_effectif (double minimum, double maximum) const;

    /**
     * \brief Obtenir les ventes.
     * \return Ventes qui correspondent.
     */
    std::vector<vente> ventes (void) const;

    /**
     * \brief Obtenir les ventes dont la date correspond.
     * \param d Date.
     * \return Ventes qui correspondent.
     */
    std::vector<vente> ventes_par_date (const date & d) const;

    /**
     * \brief Obtenir les ventes contenant un article qui correspond.
     * \param reference Référence recherchée.
     * \return Ventes qui correspondent.
     */
    std::vector<vente> ventes_par_reference (const reference_article & reference) const;

    /**
     * \brief Obtenir les ventes contenant un article qui correspond.
     * \param reference Référence recherchée.
     * \return Ventes qui correspondent.
     */
    std::vector<vente> ventes_par_reference (unsigned int reference) const;

    /**
     * \brief Obtenir les ventes contenant un article qui correspond.
     * \param modele Modèle recherché.
     * \return Ventes qui correspondent.
     */
    std::vector<vente> ventes_par_modele (unsigned int modele) const;

    /**
     * \brief Obtenir les ventes contenant un article qui correspond.
     * \param taille Taille recherchée.
     * \return Ventes qui correspondent.
     */
    std::vector<vente> ventes_par_taille (unsigned int taille) const;

    /**
     * \brief Obtenir les ventes contenant un article qui correspond.
     * \param couleur Couleur recherchée.
     * \return Ventes qui correspondent.
     */
    std::vector<vente> ventes_par_couleur (unsigned int couleur) const;

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
     * Lors de l'ajout d'une vente, le stock est automatiquement modifié en conséquence.
     * C'est-à-dire que le stock des articles vendus lors de cette vente sera diminué.
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
    void modifier_prix_achat_article (unsigned int reference, double prix);

    /**
     * \brief Modifier le prix d'achat d'un article.
     * \param reference Référence de l'article à modifier.
     * \param prix Nouveau prix d'achat.
     */
    void modifier_prix_achat_article (const reference_article & reference, double prix);

    /**
     * \brief Modifier le prix d'vente d'un article.
     * \param reference Référence de l'article à modifier.
     * \param prix Nouveau prix d'vente.
     */
    void modifier_prix_vente_article (unsigned int reference, double prix);

    /**
     * \brief Modifier le prix d'vente d'un article.
     * \param reference Référence de l'article à modifier.
     * \param prix Nouveau prix d'vente.
     */
    void modifier_prix_vente_article (const reference_article & reference, double prix);

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
     * L'annulation d'une vente restaure en stock les articles précédemment vendus.
     */
    void annuler_vente (const vente & v);

    /**
     * \brief Annuler une vente.
     * \param id Id.
     * L'annulation d'une vente restaure en stock les articles précédemment vendus.
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
     * L'annulation d'une vente restaure le stock.
     */
    void annuler_vente_article (unsigned int id_vente, const reference_article & reference);

    /**
     * \brief Modifier la quantité vendue lors d'une vente d'un article.
     * \param id ID de la vente.
     * \param reference Référence de l'article.
     * \param quantite Quantité.
     * Le stock sera modifié en conséquence.
     */
    void modifier_vente_article_quantite (unsigned int id, unsigned int reference, unsigned int quantite);

    /**
     * \brief Modifier la quantité vendue lors d'une vente d'un article.
     * \param id ID de la vente.
     * \param reference Référence de l'article.
     * \param quantite Quantité.
     * Le stock sera modifié en conséquence.
     */
    void modifier_vente_article_quantite (unsigned int id, const reference_article & reference, unsigned int quantite);

    /**
     * \brief Modifier le prix de vente d'un article dans une vente.
     * \param id ID de la vente.
     * \param reference Référence de l'article.
     * \param prix Prix.
     */
    void modifier_vente_article_prix (unsigned int id, unsigned int reference, double prix);

    /**
     * \brief Modifier le prix de vente d'un article dans une vente.
     * \param id ID de la vente.
     * \param reference Référence de l'article.
     * \param prix Prix.
     */
    void modifier_vente_article_prix (unsigned int id, const reference_article & reference, double prix);

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
    std::vector<article_affichage> _articles_par_condition (const condition_article & condition) const;

    std::vector<vente> _ventes_par_condition (const condition_vente & condition) const;
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
std::istream & operator>> (std::istream & is, magasin & m);

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
