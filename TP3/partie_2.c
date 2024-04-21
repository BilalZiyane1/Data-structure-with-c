#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct liste {
    int* donnees;
    int debut;
    int fin;
    int taille;
} QUEUE;

void initialiser_file(QUEUE* f, int taille);
void ajout_file(QUEUE* f, int x);
int supp_file(QUEUE* f);
void afficher_file(QUEUE* f);
int est_vide(QUEUE* f);
int est_pleine(QUEUE* f);

int main() {
    QUEUE* f = malloc(sizeof(QUEUE));
    initialiser_file(f, 5);
    supp_file(f);
    ajout_file(f, 1);
    ajout_file(f, 2);
    ajout_file(f, 3);
    ajout_file(f, 4);
    ajout_file(f, 5);
    ajout_file(f, 6);
    afficher_file(f);
    free(f->donnees);
    free(f);
    return 0;
}

int est_pleine(QUEUE* f) {
    if (f->fin == MAX - 1)
        return 1;
    else
        return 0;
}

int est_vide(QUEUE* f) {
    if (f->debut == -1)
        return 1;
    else
        return 0;
}

void initialiser_file(QUEUE* f, int taille) {
    f->donnees = malloc(taille * sizeof(int));
    f->debut = -1;
    f->fin = -1;
    f->taille = taille;
}

void ajout_file(QUEUE* f, int x) {
     if (est_pleine(f))
    {
        printf("\nla file est pleine!");
    }
    else if (est_vide(f)) {
        f->debut = f->fin = 0;
       *(f->donnees+f->fin) = x;
    }
     else {
        f->fin++;
        *(f->donnees+f->fin) = x;
    }
}

void afficher_file(QUEUE* f) {
    if (f->fin == -1)
        printf("la file est vide !");
    else {
        int i;
        printf("\n les elements de la file sont :\n ");
        for (i = f->debut; i <= f->fin; i++)
            printf("%d  ", *(f->donnees+(i)));
    }
    printf("\n");
}

int supp_file(QUEUE* f) {
    if (est_vide(f)) {
        printf("RIEN A SUPPRIMER !!");
        return -1;
    } else {
        int element = *(f->donnees+f->debut);
        f->debut++;
        if (f->debut > f->fin) {
            f->debut = -1;
            f->fin = -1;
        } 
        
        else {
            int i;
            for (i = f->debut; i <= f->fin; i++) {
                *(f->donnees+(i - f->debut)) = *(f->donnees+(i));
            }
            f->fin -= f->debut;
            f->debut = 0;
        }
        return element;
    }
}
