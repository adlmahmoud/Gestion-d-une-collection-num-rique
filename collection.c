#include <stdio.h>
#include <string.h>
#include "collection.h"

// Affiche la liste des produits (Ex 1)
void afficherProduits(char produits[][MAX_TAILLE_TITRE], int nbProduits) {
    if (nbProduits == 0) {
        printf("La collection est vide.\n");
        return;
    }
    for (int i = 0; i < nbProduits; i++) {
        printf("%d. %s\n", i + 1, produits[i]);
    }
}

// Demande et ajoute un produit si le tableau n'est pas plein (Ex 2)
void ajouterProduit(char produits[][MAX_TAILLE_TITRE], int *nbProduits) {
    if (*nbProduits >= MAX_PRODUITS) {
        printf("Erreur : le tableau a atteint sa taille maximale.\n");
        return;
    }
    printf("Entrez le titre du produit : ");
    scanf(" %[^\n]", produits[*nbProduits]); 
    (*nbProduits)++;
    printf("Produit ajoute.\n");
}

// Parcourt le tableau pour trouver le produit (Ex 3)
int rechercherProduit(char produits[][MAX_TAILLE_TITRE], int nbProduits, char *titreRecherche) {
    for (int i = 0; i < nbProduits; i++) {
        if (strcmp(produits[i], titreRecherche) == 0) {
            return i; // Produit trouvé
        }
    }
    return -1; // Produit non trouvé
}

// Gère l'interaction avec l'utilisateur et appelle les fonctions (Ex 4)
void lancerMenu() {
    char produits[MAX_PRODUITS][MAX_TAILLE_TITRE];
    int nbProduits = 0;
    int choix;
    char recherche[MAX_TAILLE_TITRE];

    do {
        printf("\n--- Menu ---\n");
        printf("1. Afficher les produits\n");
        printf("2. Ajouter un produit\n");
        printf("3. Rechercher un produit\n");
        printf("4. Quitter\n");
        printf("Choix : ");
        
        if (scanf("%d", &choix) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF); 
            choix = 0; 
        }

        switch (choix) {
            case 1:
                afficherProduits(produits, nbProduits);
                break;
            case 2:
                ajouterProduit(produits, &nbProduits);
                break;
            case 3:
                printf("Titre a rechercher : ");
                scanf(" %[^\n]", recherche);
                int index = rechercherProduit(produits, nbProduits, recherche);
                if (index != -1) {
                    printf("Produit trouve a l'index %d.\n", index);
                } else {
                    printf("Produit introuvable.\n");
                }
                break;
            case 4:
                printf("Au revoir.\n");
                break;
            default:
                printf("Choix invalide. Veuillez entrer un nombre.\n");
        }
    } while (choix != 4);
}