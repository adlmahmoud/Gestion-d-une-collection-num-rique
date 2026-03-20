#include <algorithm>
#include "tri.hpp"

namespace Collection {

    // Trier les produits par nom
    void trierParNom(std::vector<Produit>& produits) {
        std::sort(produits.begin(), produits.end(), [](const Produit& a, const Produit& b) {
            return a.nom < b.nom;
        });
    }

    // Trier les produits par prix
    void trierParPrix(std::vector<Produit>& produits) {
        std::sort(produits.begin(), produits.end(), [](const Produit& a, const Produit& b) {
            return a.prix < b.prix;
        });
    }

}