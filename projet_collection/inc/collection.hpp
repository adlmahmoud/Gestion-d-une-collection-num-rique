#ifndef COLLECTION_HPP
#define COLLECTION_HPP

#include <vector>
#include <string>
#include <stdexcept>

namespace Collection {

    struct Produit {
        std::string nom;
        double prix;
    };

    // Afficher les produits
    void afficherProduits(const std::vector<Produit>& produits);

    // Ajouter un produit
    void ajouterProduit(std::vector<Produit>& produits);

    // Calculer le prix total
    void calculerPrixTotal(const std::vector<Produit>& produits);

    // Trouver le prix d'un produit
    double trouverPrixProduit(const std::vector<Produit>& produits, const std::string& nomRecherche);

    // Lancer le menu principal
    void lancerMenu();

}

#endif