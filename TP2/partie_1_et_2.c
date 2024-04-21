#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct litst
{
    int donnees[MAX];
    int sommet;
} PILE;

void initialiser_pile(PILE *p);
int est_pleine(PILE *p);
int est_vide(PILE *p);
int empiler(PILE *p, int nouv_donne);
int depiler(PILE *p);
void afficher_pile(PILE *p);
PILE inverser_pile(PILE *p);
PILE copier_pile(PILE *p);

int main()
{
    PILE *p;
    p = malloc(sizeof(PILE));
    initialiser_pile(p);
    empiler(p, 1);
    empiler(p, 2);
    empiler(p, 3);
    empiler(p, 4);
    printf("Pile initiale:\n");
    afficher_pile(p);

    PILE pile_inverse = inverser_pile(p);
    printf("Pile inverse:\n");
    afficher_pile(&pile_inverse);

    PILE p_copy = copier_pile(p);
    printf("Copie de la pile :\n");
    afficher_pile(&p_copy);

    free(p);
    return 0;
}
void initialiser_pile(PILE *p)
{
    p->sommet = -1;
}

int est_pleine(PILE *p)
{
    if (p->sommet == MAX - 1)
        return 1;
    else
        return 0;
}

int est_vide(PILE *p)
{
    if (p->sommet == -1)
        return 1;
    else
        return 0;
}

int empiler(PILE *p, int nouv_donne)
{
    if (est_pleine(p))
        return 0;
    else
        p->sommet++;
    p->donnees[p->sommet] = nouv_donne;
    return 1;
}

int depiler(PILE *p)
{
    if (est_vide(p))
        return 0;
    else
        p->sommet--;
    return p->donnees[p->sommet + 1];
}

void afficher_pile(PILE *p)
{
    if (est_vide(p))
    {
        printf("La pile est vide.\n");
        return;
    }

    printf("Contenu de la pile:\n");
    for (int i = p->sommet; i >= 0; i--)
    {
        printf("%d\n", p->donnees[i]);
    }
}

PILE inverser_pile(PILE *p)
{
    PILE pile_inverse;
    initialiser_pile(&pile_inverse);

    // copie les éléments de p dans la pile_inverse en les inversant
    for (int i = p->sommet; i >= 0; i--)
    {
        empiler(&pile_inverse, p->donnees[i]);
    }

    return pile_inverse;
}

PILE copier_pile(PILE *p) {
    PILE p_copy;
    initialiser_pile(&p_copy);

    for(int i = 0; i <= p->sommet; i++) {
        empiler(&p_copy, p->donnees[i]);
    }

    return p_copy;
}
