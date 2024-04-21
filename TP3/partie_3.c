#include <stdio.h>
#include <stdlib.h>
typedef struct element
{
    int donnee;
    struct element *suivant;
} noeud;
typedef struct liste
{
    noeud *debut;
} LSC;
void initialiser_liste(LSC *liste)
{
    liste->debut = NULL;
}
void remplir_noeud(noeud *noeud, int information)
{
    noeud->donnee = information;
}
void insert_debut(LSC *liste, noeud *newnoeud)
{
    newnoeud->suivant = liste->debut;
    liste->debut = newnoeud;
}
void insert_fin(LSC *liste, noeud *newnoeud)
{
    noeud *courant;
    courant = liste->debut;
    while (courant->suivant != NULL)
    {
        courant = courant->suivant;
    }
    newnoeud->suivant = NULL;
    courant->suivant = newnoeud;
}

void insert_milieu(LSC *liste, int position, noeud *newnoeud)
{
    noeud *courant;
    int i;
    courant = liste->debut;

    if (position >= 2)
    {
        for (i = 1; i < position - 1; i++)
        {
            if (courant != NULL)
            {
                courant = courant->suivant;
            }
            else
            {
                printf("Position non trouvée!\n");
                return;
            }
        }
        newnoeud->suivant = courant->suivant;
        courant->suivant = newnoeud;
    }
    else if (position == 1)
    {
        newnoeud->suivant = liste->debut;
        liste->debut = newnoeud;
    }
    else
    {
        printf("Position non conforme!\n");
    }
}

void afficher_liste(LSC *liste)
{
    noeud *courant;
    courant = liste->debut;
    while (courant != NULL)
    {
        printf("%d --> ", courant->donnee);
        courant = courant->suivant;
    }
    printf("fin (NULL). \n");
}
int comparer_noeud(noeud *noeud1, noeud *noeud2)
{
    if (noeud1->donnee == noeud2->donnee)
        return 1;
    else
        return 0;
}
int chercher_position(LSC *liste, noeud *cible)
{
    noeud *courant;
    int position;

    courant = liste->debut;

    position = 0;
    while (comparer_noeud(courant, cible) != 1 && courant != NULL)
    {
        position++;
        courant = courant->suivant;
    }
    position++;
    return position;
}
void supprimer_debut(LSC *liste)
{
    noeud *a_liberer;
    a_liberer = liste->debut;
    liste->debut = liste->debut->suivant;
    free(a_liberer);
}
void supprimer_fin(LSC *liste)
{
    noeud *courant;
    noeud *a_liberer;
    courant = liste->debut;
    while (courant->suivant->suivant != NULL)
    {
        courant = courant->suivant;
    }
    a_liberer = courant->suivant;
    courant->suivant = NULL;
    free(a_liberer);
}
void supprimer_milieu(LSC *liste, int position)
{
    noeud *courant;
    noeud *a_liberer;
    int i;
    courant = liste->debut;
    if (position >= 2)
    {
        for (i = 1; i < position - 1; i++)
        {
            if (courant != NULL)
                courant = courant->suivant;
            else
                printf("position non trouve!\n");
        }
        a_liberer = courant->suivant;
        courant->suivant = courant->suivant->suivant;
        free(a_liberer);
    }
    else
        printf("position non conforme ! \n");
}
int egual_noeud(noeud *noeud1, noeud *noeud2)
{
    if (noeud1 == NULL || noeud2 == NULL)
    {
        // Si l'un des nœuds est NULL, les nœuds ne sont pas égaux
        return 0;
    }
    if (noeud1->donnee == noeud2->donnee && noeud1->suivant == noeud2->suivant)
    {
        // Si les valeurs et les suivants des nœuds sont égaux, les nœuds sont égaux
        return 1;
    }
    else
    {
        // Sinon, les nœuds ne sont pas égaux
        return 0;
    }
}
int Chercher_Position(LSC *liste, noeud *Cible)
{
    noeud *Courant = liste->debut;
    int Position = 1;
    while (Courant != NULL)
    {
        if (egual_noeud(Courant, Cible))
        {
            return Position;
        }
        Courant = Courant->suivant;
        Position++;
    }
    return -1;
}
int chercher_position2(LSC *liste, noeud *Cible)
{
    noeud *courant = liste->debut;
    int position = 1;
    int i;
    while (courant != NULL)
    {
        if (egual_noeud(courant, Cible))
        {
            i = position;
        }
        courant = courant->suivant;
        i++;
    }
    return i;
}
void supprimer_double(LSC *liste, noeud *cible)
{
    if (chercher_position(liste, cible) != chercher_position2(liste, cible))
    {
        supprimer_milieu(liste, chercher_position2(liste, cible));
    }
    else
        printf("pas d'element doublant ");
}
int main()
{
    LSC *liste;
    int rien;
    noeud *noeud1;
    noeud *noeud2;
    noeud *noeud3;
    noeud *noeud4;

    liste = malloc(sizeof(LSC));
    initialiser_liste(liste);
    afficher_liste(liste);

    noeud1 = malloc(sizeof(noeud));
    noeud2 = malloc(sizeof(noeud));
    noeud3 = malloc(sizeof(noeud));
    noeud4 = malloc(sizeof(noeud));
    insert_debut(liste, noeud1);
    insert_fin(liste, noeud3);
    insert_fin(liste, noeud4);
    insert_milieu(liste, 2, noeud2);
    remplir_noeud(noeud1, 1);
    remplir_noeud(noeud2, 2);
    remplir_noeud(noeud3, 3);
    remplir_noeud(noeud4, 2);
    afficher_liste(liste);
    printf("\n%d\n", chercher_position2(liste, noeud2));
    supprimer_milieu(liste, 4);
    afficher_liste(liste);
    free(noeud1);
    free(noeud2);
    free(noeud3);
    free(noeud4);
}
