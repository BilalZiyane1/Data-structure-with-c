#include <stdio.h>
void afficher_tableau(int tab[],int taille);
int pos_min(int tab[],int taille );
void permuter(int *a,int *b);
void tri_selection(int tab[],int taille );
int main(){
   int ab[] = {5,2,126,9,51,7,1,6,12,24};
   int x=10;
   //afficher_tableau(ab,x);
   //int e=pos_min(ab,x);
   //printf("the min is %d",e);
   //permuter(&ab[0],&ab[5]);
   //afficher_tableau(ab,x);
   tri_selection(ab,x);
}
void afficher_tableau(int tab[],int taille){
   for (int i=0;i<taille;i++){
      printf("%d\t",tab[i]);
   }
}
int pos_min(int tab[],int taille){
    int pos_min = 0;  
    
    for (int i = 1; i < taille-1; i++) {
        if (tab[i] < tab[pos_min]) {
            tab[pos_min] = tab[i];
            pos_min = i;
        }
    }

    return pos_min;
}
void permuter(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void tri_selection(int tab[],int taille){
    int i,pos_min,temp;
    printf("avant le tri:\n");
    afficher_tableau(tab,taille);
    printf("\n");
    printf("\n");
     for(int i=0;i<taille-1;i++){
        pos_min=i;
        int j=0;
        printf("[%d]",tab[i]);
        printf("{");
        for ( j=i+1;j<taille;j++){
            if (tab[j]<tab[pos_min])
               pos_min=j;
               printf("%d ",tab[j]);

        }
        printf("}");
               printf("\n");
        if(i!=pos_min){
           permuter(&tab[i],&tab[pos_min]);
        }
        for (int k=0;k<i+1;k++){
            printf("%d ",tab[k]);
        }
    }
    printf("apres le tri:\n");
    afficher_tableau(tab,taille);
}