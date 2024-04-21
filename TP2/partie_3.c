#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct PILE 
{
    char donnees[MAX];
    int sommet;
} PILE;

void initialiser_PILE(PILE *P)
{
    P->sommet = -1;
}

int Est_Pleine(PILE *P)
{
    return P->sommet == MAX - 1;
}

int Est_Vide(PILE *P)
{
    return P->sommet == -1;
}

void Empiler(PILE *P, char nouv_donnee)
{
    if (Est_Pleine(P))
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
        printf("%c\n", P->donnees[i]);
    }
}

int Equilibre(char tab[]){
    PILE Pile_Parenthese;
    initialiser_PILE(&Pile_Parenthese);
    int i=0;
    while(tab[i] != '\0'){
        
        if(tab[i]=='{' || tab[i]== '(' || tab[i]== '['){
            Empiler(&Pile_Parenthese,tab[i]);
        }
        else if (tab[i]=='}' || tab[i]== ')' || tab[i]== ']'){
            if (Est_Vide(&Pile_Parenthese)){
                return 0;
            }
            char ouvrante = Pile_Parenthese.donnees[Pile_Parenthese.sommet];
            if ((ouvrante == '(' && tab[i] == ')') ||
                (ouvrante == '[' && tab[i] == ']') ||
                (ouvrante == '{' && tab[i] == '}')){
                Depiler(&Pile_Parenthese);
            }
            else{
                return 0;
            }
        }

        i++;
    }
    return Est_Vide(&Pile_Parenthese);
}

int main()
{
    char tab[MAX];
    printf("Entrez une chaine de caracteres : ");
    fgets(tab, MAX, stdin);

    if(Equilibre(tab) == 1)
        printf("La chaine de caracteres est equilibre !\n");
    else
        printf("La chaine de caracteres n'est pas equilibre !\n");
    
    return 0;
}