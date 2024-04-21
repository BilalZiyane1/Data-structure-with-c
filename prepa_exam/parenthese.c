#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct pile {
    char tab[MAX];
    int sommet;
} Pile;

void initialiser_pile(Pile *p) {
    p->sommet = -1;
}

int est_pleine(Pile *p) {
    return p->sommet == MAX - 1;
}

int est_vide(Pile *p) {
    return p->sommet == -1;
}

int empiler(Pile *p, char nouv_donne) {
    if (est_pleine(p)) {
        return 0;
    }
    p->sommet++;
    p->tab[p->sommet] = nouv_donne;
    return 1;
}

char depiler(Pile *p) {
    if (est_vide(p)) {
        return '\0';
    }
    char ancienne_donnee = p->tab[p->sommet];
    p->sommet--;
    return ancienne_donnee;
}

void afficher_pile(Pile *p) {
    printf("[ ");
    for (int i = 0; i <= p->sommet; i++) {
        printf("%c ", p->tab[i]);
    }
    printf("]\n");
}

Pile inverser_pile(Pile *p) {
    Pile pile_inverse;
    initialiser_pile(&pile_inverse);

    for (int i = p->sommet; i >= 0; i--) {
        empiler(&pile_inverse, p->tab[i]);
    }

    return pile_inverse;
}

void est_equilibre(Pile *p) {
    Pile pile_inverse = inverser_pile(p);
    printf("Pile inverse :\n");
    afficher_pile(&pile_inverse);

    int est_equilibree = 1;

    for (int i = 0; pile_inverse.tab[i] != '\0'; i++) {
        char caractere = pile_inverse.tab[i];

        if (caractere == '(' || caractere == '[' || caractere == '{') {
            empiler(p, caractere);
        }
        else if (caractere == ')' || caractere == ']' || caractere == '}') {
            if (est_vide(p)) {
                est_equilibree = 0;
                break;
            }
            char sommet = depiler(p);
            if ((sommet == '(' && caractere != ')') ||
                (sommet == '[' && caractere != ']') ||
                (sommet == '{' && caractere != '}')) {
                est_equilibree = 0;
                break;
            }
        }
    }

    if (est_vide(p) && est_equilibree) {
        printf("La chaine de parentheses est equilibree.\n");
    }
    else {
        printf("La chaine de parentheses n'est pas equilibree.\n");
    }
}

int main() {
    char chaine[MAX];
    printf("Entrez votre chaine de caractere : ");
    scanf("%s", chaine);

    int taille = strlen(chaine);

    Pile *p = malloc(sizeof(Pile));
    initialiser_pile(p);

    for (int i = 0; i < taille; i++) {
        empiler(p, chaine[i]);
    }

    printf("Pile initiale :\n");
    afficher_pile(p);
    est_equilibre(p);

    free(p);
    return 0;
}
