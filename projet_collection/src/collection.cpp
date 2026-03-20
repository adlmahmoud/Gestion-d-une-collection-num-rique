#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>
#include "collection.hpp"
#include "tri.hpp"

namespace Collection {

    // Afficher les produits
    void afficherProduits(const std::vector<Produit>& produits) {
        if (produits.empty()) {
            std::cout << "La collection est vide.\n";
            return;
        }
        for (size_t i = 0; i < produits.size(); i++) {
            std::cout << i + 1 << ". " << produits[i].nom << " - Prix : " << produits[i].prix << " euros\n";
        }
    }

    // Ajouter un produit
    void ajouterProduit(std::vector<Produit>& produits) {
        Produit nouveauProduit;
        std::cout << "Entrez le titre du produit : ";
        std::getline(std::cin >> std::ws, nouveauProduit.nom); 
        
        while (true) {
            std::cout << "Entrez le prix du produit : ";
            if (std::cin >> nouveauProduit.prix && nouveauProduit.prix >= 0) break;
            std::cout << "Erreur : Saisie invalide.\n";
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        }
        produits.push_back(nouveauProduit);
        std::cout << "Produit ajoute.\n";
    }

    // Calculer le prix total
    void calculerPrixTotal(const std::vector<Produit>& produits) {
        double total = 0.0;
        for (const auto& p : produits) total += p.prix;
        std::cout << "Le prix total de la collection est : " << total << " euros.\n";
    }

    // Trouver le prix d'un produit
    double trouverPrixProduit(const std::vector<Produit>& produits, const std::string& nomRecherche) {
        for (const auto& p : produits) {
            if (p.nom == nomRecherche) return p.prix;
        }
        throw std::runtime_error("Produit introuvable.");
    }

    // Lancer le menu principal
    void lancerMenu() {
        std::vector<Produit> produits;
        int choix = 0;

        do {
            std::cout << "\n--- Menu ---\n"
                      << "1. Afficher les produits\n"
                      << "2. Ajouter un produit\n"
                      << "3. Rechercher un produit\n"
                      << "4. Calculer le prix total\n"
                      << "5. Trier les produits\n"
                      << "6. Quitter\n"
                      << "Choix : ";
            
            if (!(std::cin >> choix)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                choix = 0;
            }

            switch (choix) {
                case 1: afficherProduits(produits); break;
                case 2: ajouterProduit(produits); break;
                case 3: {
                    std::string recherche;
                    std::cout << "Titre a rechercher : ";
                    std::getline(std::cin >> std::ws, recherche);
                    try {
                        std::cout << "Prix : " << trouverPrixProduit(produits, recherche) << " euros.\n";
                    } catch (const std::exception& e) {
                        std::cout << "Erreur : " << e.what() << "\n";
                    }
                    break;
                }
                case 4: calculerPrixTotal(produits); break;
                case 5: {
                    int choixTri;
                    std::cout << "1. Par nom | 2. Par prix : ";
                    std::cin >> choixTri;
                    if (choixTri == 1) {
                        trierParNom(produits);
                        std::cout << "Tri par nom effectue.\n";
                    } else if (choixTri == 2) {
                        trierParPrix(produits);
                        std::cout << "Tri par prix effectue.\n";
                    } else {
                        std::cout << "Choix de tri invalide.\n";
                    }
                    break;
                }
                case 6: std::cout << "Au revoir.\n"; break;
                default: std::cout << "Choix invalide.\n";
            }
        } while (choix != 6);
    }

}