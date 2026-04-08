#ifndef COLLECTION_HPP
#define COLLECTION_HPP

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>

namespace Collection {

    // --- EXERCICE 1 : Classe Produit (Base) ---
    class Produit {
    protected: // Accessible par les classes dérivées (Livre, Jeu, Film)
        std::string nom;
        double prix;
        std::string type;

    public:
        // Constructeur
        Produit(std::string n, double p, std::string t) : nom(n), prix(p), type(t) {}
        
        // Destructeur virtuel indispensable pour le polymorphisme
        virtual ~Produit() = default;

        // Getters
        std::string getNom() const { return nom; }
        double getPrix() const { return prix; }

        void modifierPrix(double nouveauPrix) {
            if (nouveauPrix < 0) throw std::invalid_argument("Le prix ne peut pas etre negatif.");
            prix = nouveauPrix;
        }

        virtual void afficher() const {
            std::cout << nom << " - Prix : " << prix << " euros";
        }

        // --- EXERCICE 3 : Méthode virtuelle ---
        virtual void afficherType() const {
            std::cout << "[" << type << "]";
        }

        // --- EXERCICE 4 : Surcharge d'opérateur ---
        friend std::ostream& operator<<(std::ostream& os, const Produit& p) {
            p.afficherType();
            os << " " << p.nom << " - " << p.prix << " euros";
            return os;
        }
    };

    // --- EXERCICE 3 : Classes dérivées ---
    class Livre : public Produit {
    public:
        Livre(std::string n, double p) : Produit(n, p, "Livre") {}
        void afficherType() const override { std::cout << "[Livre]"; }
    };

    class Jeu : public Produit {
    public:
        Jeu(std::string n, double p) : Produit(n, p, "Jeu") {}
        void afficherType() const override { std::cout << "[Jeu]"; }
    };

    class Film : public Produit {
    public:
        Film(std::string n, double p) : Produit(n, p, "Film") {}
        void afficherType() const override { std::cout << "[Film]"; }
    };

    // --- EXERCICE 2 : Classe Collection ---
    class MaCollection {
    private:
        // On utilise des pointeurs (Produit*) pour que le polymorphisme fonctionne !
        std::vector<Produit*> produits;

    public:
        ~MaCollection() {
            // Nettoyage de la mémoire allouée dynamiquement
            for (auto p : produits) {
                delete p;
            }
        }

        void ajouterProduit(Produit* p);
        void afficherProduits() const;
        void rechercherProduit(const std::string& nomRecherche) const;
        void trierParPrix();
        void trierParNom();
        void calculerPrixTotal() const;
    };

    void lancerMenu();
}

#endif