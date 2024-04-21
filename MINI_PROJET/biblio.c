#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct livre {
int ISBN;
char Titre[50];
int Stock;
struct livre *suivant;
} LIVRE;

typedef struct {
LIVRE *tete;
} LSC;

void initialise(LSC *liste);
void remplir(LIVRE * newLivre ,int ISBN, char Titre[], int Stock ) ;
void afficher(LIVRE * livre);
void afficherListe(LSC * liste);
LIVRE * chercher(LSC * liste , int ISBN);
int position(LSC * liste , int ISBN);
int	quantite(LSC * liste , int ISBN);
void ajouterLivre(LSC * liste, LIVRE * newLivre);
void vendre(LSC *liste, int ISBN);
void supprimerSiVide(LSC *liste, LIVRE *livre) ;
void supprimerToutVide(LSC * liste);
void initialise(LSC *liste)
{
    liste->tete=NULL;
}
void remplir(LIVRE * newLivre ,int ISBN, char Titre[], int Stock )
{
    newLivre->ISBN=ISBN;
    strcpy(newLivre->Titre, Titre);
    newLivre->Stock=Stock;
    newLivre->suivant=NULL ;
}
void afficher(LIVRE * livre)
{
    printf("ISBN : %d\n", livre->ISBN);
    printf("Titre : %s\n", livre->Titre);
    printf("Stock : %d\n", livre->Stock);
}
void afficherListe(LSC * liste)
{
    LIVRE *courant = liste->tete ;
    while(courant != NULL)
    {
        afficher(courant);
        courant=courant->suivant;
    }
}
LIVRE *chercher(LSC *liste, int ISBN) {
    LIVRE *courant = liste->tete;
    while (courant != NULL) {
        if (courant->ISBN == ISBN)
            return courant;
        courant = courant->suivant;
    }
    return NULL;
}
int position(LSC *liste, int ISBN) {
    LIVRE *courant = liste->tete;
    int pos = 0;
    while (courant != NULL) {
        if (courant->ISBN == ISBN)
            return pos;
        courant = courant->suivant;
        pos++;
    }
    return -1;
}
int quantite(LSC *liste, int ISBN) {
    LIVRE *courant = chercher(liste, ISBN);
    if (courant == NULL)
        return -1;
    else
        return courant->Stock;
}
void ajouterLivre(LSC *liste, LIVRE *newLivre) {
    LIVRE *courant = chercher(liste, newLivre->ISBN);
    if (courant == NULL) {
        if (newLivre->Stock <= 0)
            return;
        else if (liste->tete == NULL)
            liste->tete = newLivre;
        else {
            LIVRE *dernier = liste->tete;
            while (dernier->suivant != NULL)
                dernier = dernier->suivant;
            dernier->suivant = newLivre;
        }
    } else {
        courant->Stock += newLivre->Stock;
        free(newLivre);
    }
}
void vendre(LSC *liste, int ISBN)
{
    LIVRE *courant = chercher(liste, ISBN);
    if (courant != NULL)
        if (courant->Stock > 0)
            courant->Stock--;
}
void supprimerSiVide(LSC *liste, LIVRE *livre) {
    if (livre != NULL && livre->Stock == 0)
    {
        if (livre == liste->tete) {
            liste->tete = livre->suivant;
        }
        else {
            LIVRE *precedent = liste->tete;
            while (precedent != NULL && precedent->suivant != livre)
                precedent = precedent->suivant;
            if (precedent != NULL)
                precedent->suivant = livre->suivant;
        }
        free(livre);
    }
}
void supprimerToutVide(LSC *liste) {
    LIVRE *courant = liste->tete;
    LIVRE *precedent = NULL;
    while (courant != NULL)
    {
        if (courant->Stock == 0)
        {
            if (courant == liste->tete)
            {
                liste->tete = courant->suivant;
                free(courant);
                courant = liste->tete;
            }
            else
            {
                precedent->suivant = courant->suivant;
                free(courant);
                courant = precedent->suivant;
            }
        }
        else
        {
            precedent = courant;
            courant = courant->suivant;
        }
    }
}
int main(void)
{
    LSC liste;
    initialise(&liste);

    LIVRE livre1;
    remplir(&livre1, 2005, "rich dad poor dad", 0);
    ajouterLivre(&liste, &livre1);

    LIVRE livre2;
    remplir(&livre2, 2004, "think and grow rich", 3);
    ajouterLivre(&liste, &livre2);

    LIVRE livre3 ;
    remplir(&livre3, 2006, "mindset", 2);
    ajouterLivre(&liste, &livre3);


    printf("Affichage de la liste des livres:\n");
    afficherListe(&liste);

    printf("\nRecherche d'un livre:\n");
    LIVRE *livre4 = chercher(&liste, 2004);
    if (livre4 != NULL) {
        printf("Le livre avec l'ISBN 2004 existe.\n");
    } else {
        printf("Le livre avec l'ISBN 2004 n'existe pas.\n");
    }

    printf("\nVente d'un livre:\n");
    vendre(&liste, 2004);
    printf("Apres la vente, le stock de livre avec l'ISBN 2004 est %d.\n", quantite(&liste, 2004));

    printf("\nSuppression d'un livre:\n");
    supprimerSiVide(&liste,&livre2);
    printf("Apres la suppression, la liste des livres est:\n");
    afficherListe(&liste);

    printf("\nSuppression de tous les livres vides:\n");
    vendre(&liste, 2004);
    vendre(&liste, 2004);
    vendre(&liste, 2005);
    supprimerToutVide(&liste);
    printf("Apres la suppression, la liste des livres est:\n");
    afficherListe(&liste);

    return 0;
}
