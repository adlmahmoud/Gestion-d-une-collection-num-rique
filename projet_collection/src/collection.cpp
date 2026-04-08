#include "../inc/collection.hpp"
#include <limits>

namespace Collection {

    void MaCollection::ajouterProduit(Produit* p) {
        produits.push_back(p);
        std::cout << "Produit ajoute avec succes.\n";
    }

    void MaCollection::afficherProduits() const {
        if (produits.empty()) {
            std::cout << "La collection est vide.\n";
            return;
        }
        for (size_t i = 0; i < produits.size(); i++) {
            // Utilisation de la surcharge de l'opérateur <<
            std::cout << i + 1 << ". " << *(produits[i]) << "\n";
        }
    }

    void MaCollection::rechercherProduit(const std::string& nomRecherche) const {
        for (const auto& p : produits) {
            if (p->getNom() == nomRecherche) {
                std::cout << "Trouve : " << *p << "\n";
                return;
            }
        }
        // EXERCICE 4 : Exception si introuvable
        throw std::runtime_error("Erreur : Produit introuvable dans la collection.");
    }

    void MaCollection::calculerPrixTotal() const {
        double total = 0.0;
        for (const auto& p : produits) {
            total += p->getPrix();
        }
        std::cout << "Le prix total de la collection est : " << total << " euros.\n";
    }

    // --- EXERCICE 4 : Tris ---
    void MaCollection::trierParPrix() {
        std::sort(produits.begin(), produits.end(), [](Produit* a, Produit* b) {
            return a->getPrix() < b->getPrix();
        });
        std::cout << "Tri par prix effectue.\n";
    }

    void MaCollection::trierParNom() {
        std::sort(produits.begin(), produits.end(), [](Produit* a, Produit* b) {
            return a->getNom() < b->getNom();
        });
        std::cout << "Tri par nom effectue.\n";
    }

    // --- MENU PRINCIPAL ---
    void lancerMenu() {
        MaCollection maCollection;
        int choix = 0;

        do {
            std::cout << "\n--- Menu Collection POO ---\n"
                      << "1. Afficher les produits\n"
                      << "2. Ajouter un Livre\n"
                      << "3. Ajouter un Jeu\n"
                      << "4. Ajouter un Film\n"
                      << "5. Rechercher un produit\n"
                      << "6. Trier les produits (1: Nom, 2: Prix)\n"
                      << "7. Quitter\n"
                      << "Choix : ";
            
            if (!(std::cin >> choix)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                choix = 0;
            }

            switch (choix) {
                case 1: 
                    maCollection.afficherProduits(); 
                    break;
                case 2: case 3: case 4: {
                    std::string nom;
                    double prix;
                    std::cout << "Nom : ";
                    std::getline(std::cin >> std::ws, nom);
                    std::cout << "Prix : ";
                    std::cin >> prix;
                    
                    if (prix < 0) {
                        std::cout << "Erreur : le prix ne peut pas etre negatif.\n";
                        break;
                    }

                    if (choix == 2) maCollection.ajouterProduit(new Livre(nom, prix));
                    else if (choix == 3) maCollection.ajouterProduit(new Jeu(nom, prix));
                    else maCollection.ajouterProduit(new Film(nom, prix));
                    break;
                }
                case 5: {
                    std::string recherche;
                    std::cout << "Nom a rechercher : ";
                    std::getline(std::cin >> std::ws, recherche);
                    try {
                        maCollection.rechercherProduit(recherche);
                    } catch (const std::exception& e) {
                        std::cout << e.what() << "\n";
                    }
                    break;
                }
                case 6: {
                    int choixTri;
                    std::cout << "1. Par nom | 2. Par prix : ";
                    std::cin >> choixTri;
                    if (choixTri == 1) maCollection.trierParNom();
                    else if (choixTri == 2) maCollection.trierParPrix();
                    else std::cout << "Choix invalide.\n";
                    break;
                }
                case 7: 
                    std::cout << "Au revoir.\n"; 
                    break;
                default: 
                    std::cout << "Choix invalide.\n";
            }
        } while (choix != 7);
    }
}