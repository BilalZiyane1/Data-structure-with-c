#include <stdio.h>
#include <stdlib.h>
void affiche(int *tab,int taille);
void insert(int *tab,int taille );
void permuter(int *a,int *b);
void selection(int *tab,int taille);
int main()
{
   int ab[] = {5,2,126,9,51,7,1,6,12,24};
   int taille =10; 
   insert(ab,taille);
   printf("\n");
   selection(ab,taille);
}
void affiche(int *tab,int taille )
{
    for(int i=0;i<taille;i++)
      printf("%d\t",*(tab+i));

}
void insert(int *tab,int taille)
{
    int key,i,j;
    for (int i=1;i<taille;i++)
    {
        j=i-1;
        key=tab[i];
        while(key<tab[j]&&j>=0)
        {
            tab[j+1]=tab[j];
            j--;
        }
        tab[j+1]=key;
    }
    affiche(tab,taille);
}
void permuter(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void selection(int *tab,int taille)
{
    int i,j,posmin;
    for(i=0;i<taille;i++)
    {
        posmin=i;
        for(j=i+1;j<taille;j++)
        {
            if(tab[j]<tab[posmin])
            {
                posmin=j;
                permuter(&tab[j],&tab[posmin]);
            }
        }
    }
    affiche(tab,taille);
}