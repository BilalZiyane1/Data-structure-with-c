#include <stdio.h>
#include <stdlib.h>
#define max 100
struct liste
{
    int donnees[max];
    int sommet;
};
typedef struct liste pile;
void initialiser_pile(pile *p)
{
    p->sommet=-1;
}
int est_pleine(pile *p)
{
    return(p->sommet==max-1);
}
int est_vid(pile *p)
{
    return(p->sommet==-1);

}
void empiler(pile *p,int nouv_donne)
{
    p->sommet++;
    p->donnees[p->sommet]=nouv_donne;
}
int  depiler(pile *p)
{
    p->sommet--;
    return(p->donnees[p->sommet+1]);
}
void afficher_pile(pile *p)
{
    for (int i = p->sommet; i >= 0; i--)
    {
        printf("%d\n", p->donnees[i]);
    }
}
int pqw(int a,int b)
{
    return (a==b);
}
pile* innverse(pile *p)
{
    pile *inv;
    inv=malloc(sizeof(pile));
    initialiser_pile(inv);
    for(int i=p->sommet;i>=0;i--)
    {
        empiler(inv,p->donnees[i]);
    }
    return(inv);
}
int main ()
{
    pile *p;
    p = malloc(sizeof(pile));
    initialiser_pile(p);
    empiler(p, 1);
    empiler(p, 2);
    empiler(p, 3);
    empiler(p, 4);
    printf("Pile initiale:\n");
    afficher_pile(p);
    printf("pile apres inverse \n");
    afficher_pile(innverse(p));

}