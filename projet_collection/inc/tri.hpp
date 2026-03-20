#ifndef TRI_HPP
#define TRI_HPP

#include <vector>
#include "collection.hpp"

namespace Collection {

    // Trier les produits par nom
    void trierParNom(std::vector<Produit>& produits);

    // Trier les produits par prix
    void trierParPrix(std::vector<Produit>& produits);

}

#endif