#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct list
{

    char tab[MAX];
    int sommet;
} PILE;
void initialiser_pile(PILE *p);
int est_pleine(PILE *p);
int est_vide(PILE *p);
int empiler(PILE *p, char nouv_donne);
char depiler(PILE *p);
void afficher_pile(PILE *p);
PILE inverser_pile(PILE *p);
void est_equilibre(PILE *p)
{
    PILE E = inverser_pile(p);
    printf("Pile inverse :\n");
    afficher_pile(&E);

    int est_equilibree = 1;

    for (int i = 0; E.tab[i] != '\0'; i++) {
        char caractere = E.tab[i];

        if (caractere == '(' || caractere == '[' || caractere == '{') {
            empiler(p, caractere);
        }
        else if (caractere == ')' || caractere == ']' || caractere == '}') {
            if (est_vide(p)) {  // Correction : est_vide() -> est_pile_vide()
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

    if (est_vide(p) && est_equilibree) {  // Correction : est_vide() -> est_pile_vide()
        printf("La chaine de parentheses est equilibree.\n");
    }
    else {
        printf("La chaine de parentheses n'est pas equilibree.\n");
    }
}

//PILE copier_pile(PILE *p);
int main()
{
    char ab[50];
    printf("Entrez votre chaine de caractere : ");
    scanf("%s", ab);

    int a = strlen(ab);

    PILE *p = malloc(sizeof(PILE));
    initialiser_pile(p);

    for (int i = 0; i < a; i++) {
        empiler(p, ab[i]);
    }

    printf("Pile initiale :\n");
    afficher_pile(p);
    est_equilibre(p);
    PILE E = inverser_pile(p);
    printf("Pile inverse :\n");
    afficher_pile(&E);

    int est_equilibree = 1;

    for (int i = 0; E.tab[i] != '\0'; i++) {
        char caractere = E.tab[i];

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

    if (!est_vide(p) && est_equilibree) {
        printf("La chaine de parentheses est equilibre.\n");
    }
    else {
        printf("La chaine de parentheses n'est pas equilibre.\n");
    }

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

int empiler(PILE *p, char nouv_donne)
{
    if (est_pleine(p))
        return 0;
    else
        p->sommet++;
        p->tab[p->sommet] = nouv_donne;
    return 1;
}

char depiler(PILE *p)
{
    if (est_vide(p))
        return '\0';
    else
        p->sommet--;
    return p->tab[p->sommet + 1];
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
        printf("%c\n", p->tab[i]);
    }
}
PILE inverser_pile(PILE *p)
{
    PILE pile_inverse;
    initialiser_pile(&pile_inverse);

    // copie les éléments de p dans la pile_inverse en les inversant
    for (int i = p->sommet; i >= 0; i--)
    {
        empiler(&pile_inverse, p->tab[i]);
    }

    return pile_inverse;
}


/*PILE copier_pile(PILE *p) {
    PILE p_copy;
    initialiser_pile(&p_copy);

    for(int i = 0; i <= p->sommet; i++) {
        empiler(&p_copy, p->donnees[i]);
    }

    return p_copy;
}*/
