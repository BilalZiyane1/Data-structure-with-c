#include <stdio.h>
#include <stdlib.h>


#define MAX 5

typedef struct liste {
    int donnees[MAX];
    int debut;
    int fin;
} QUEUE;

void initialiser_file(QUEUE *f);
int est_pleinne(QUEUE *f);
int est_vide(QUEUE *f);
void ajout_file(QUEUE *f, int x);
int supp_file(QUEUE *f);
void afficher_file(QUEUE *f);

int main() {
    QUEUE *f;
    f = malloc(sizeof(QUEUE));
    initialiser_file(f);
    ajout_file(f, 1);
    ajout_file(f, 2);
    ajout_file(f, 3);
    ajout_file(f, 4);
    ajout_file(f, 5);
    ajout_file(f, 6);
    afficher_file(f);
    printf("Element supprime: %d\n", supp_file(f));
    printf("Element supprime: %d\n", supp_file(f));
    printf("Element supprime: %d\n", supp_file(f));
    afficher_file(f);
    return 0;
    
}

void initialiser_file(QUEUE  *f) {
    f->debut = -1;
    f->fin = -1;
  
}

int est_pleinne(QUEUE *f) {
    if (f->fin == MAX - 1)
        return 1;
    else
        return 0;
}

int est_vide(QUEUE *f) {
    if (f->debut == -1)
        return 1;
    else
        return 0;
}

void ajout_file(QUEUE *f, int x) {
    if (est_pleinne(f)) {
        printf("La file est pleine !\n");
    } else if (est_vide(f)) {
        f->debut = f->fin = 0;
        f->donnees[f->fin] = x;
    } else {
        f->fin++;
        f->donnees[f->fin] = x;
    }
}

int supp_file(QUEUE *f) {
    if (est_vide(f)) {
        printf("La file est vide !\n");
        return -1;
    } else {
        int x = f->donnees[f->debut];
        if (f->debut == f->fin) {
            f->debut = f->fin = -1;
        } else {
            int i;
            for (i = f->debut; i < f->fin; i++) {
                f->donnees[i] = f->donnees[i + 1];
            }
            f->fin--;
        }
        return x;
    }
}

void afficher_file(QUEUE *f)
{
    if(f -> fin ==-1)
       printf("la file est vide !");
    else 
    {
        int i;
        printf("\n les elements de la file sont :\n ");
        for(i=f->debut;i<=f->fin;i++)
            printf("%d  ",f->donnees[i]);
    }

    printf("\n");
}