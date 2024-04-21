#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct LISTE 
{
    int donnees[MAX];
    int sommet;
}PILE;

void initialiser_PILE(PILE *P)
{
    P->sommet = -1;
}

int Est_Pleinne(PILE *P)
{
    return P->sommet == MAX - 1;
}

int Est_Vide(PILE *P)
{
    return P->sommet == -1;
}

void Empiler(PILE *P, int nouv_donnee)
{
    if (Est_Pleinne(P))
    {
        printf("La pile est pleine, impossible d'empiler.\n");
        return;
    }

    P->sommet++;
    P->donnees[P->sommet] = nouv_donnee;
}

void Depiler(PILE *P)
{
    if (Est_Vide(P))
    {
        printf("La pile est vide, impossible de depiler.\n");
        return;
    }

    P->sommet--;
}

void Afficher_Pile(PILE *P)
{
    if (Est_Vide(P))
    {
        printf("La pile est vide.\n");
        return;
    }

    printf("Contenu de la pile:\n");
    for (int i = P->sommet; i >= 0; i--)
    {
        printf("%d\n", P->donnees[i]);
    }
}

int main()
{
    PILE P;
    initialiser_PILE(&P);
    Empiler(&P, 8);
    Empiler(&P, 41);
    Afficher_Pile(&P);
    Depiler(&P);
    Empiler(&P, 2);
    Empiler(&P, 15);
    Depiler(&P);
    Afficher_Pile(&P);
    return 0;
}