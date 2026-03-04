#ifndef COLLECTION_H
#define COLLECTION_H

#define MAX_PRODUITS 100
#define MAX_TAILLE_TITRE 50

// Affiche la liste des produits
void afficherProduits(char produits[][MAX_TAILLE_TITRE], int nbProduits);

// Ajoute un produit en vérifiant la taille maximale
void ajouterProduit(char produits[][MAX_TAILLE_TITRE], int *nbProduits);

// Recherche un produit et retourne son index ou -1
int rechercherProduit(char produits[][MAX_TAILLE_TITRE], int nbProduits, char *titreRecherche);

// Lance le menu interactif principal
void lancerMenu();

#endif