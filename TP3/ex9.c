#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int valeur;
    struct element* suivant;
} Noeud;

typedef struct pile {
    Noeud* sommet;
} Pile;

void initialiser_pile(Pile* pile) {
    pile->sommet = NULL;
}

int est_vide(Pile* pile) {
    return pile->sommet == NULL;
}

// Empile une valeur dans la pile
void empiler(Pile* pile, int valeur) {
    Noeud* nouveau_noeud = (Noeud*) malloc(sizeof(Noeud));
    nouveau_noeud->valeur = valeur;
    nouveau_noeud->suivant = pile->sommet;
    pile->sommet = nouveau_noeud;
}

// Dépile une valeur de la pile et la retourne
int depiler(Pile* pile) {
    if (est_vide(pile)) {
        printf("Erreur : la pile est vide\n");
        exit(EXIT_FAILURE);
    }
    int valeur = pile->sommet->valeur;
    Noeud* noeud_a_supprimer = pile->sommet;
    pile->sommet = pile->sommet->suivant;
    free(noeud_a_supprimer);
    return valeur;
}

// Affiche les valeurs de la pile
void afficher_pile(Pile* pile) {
    Noeud* noeud_courant = pile->sommet;
    while (noeud_courant != NULL) {
        printf("%d ", noeud_courant->valeur);
        noeud_courant = noeud_courant->suivant;
    }
    printf("\n");
}

int main() {
    Pile pile;
    initialiser_pile(&pile);

    empiler(&pile, 1);
    empiler(&pile, 2);
    empiler(&pile, 3);
    empiler(&pile, 4);

    afficher_pile(&pile);

    printf("%d\n", depiler(&pile));
    printf("%d\n", depiler(&pile));

    afficher_pile(&pile);

    return 0;
}
