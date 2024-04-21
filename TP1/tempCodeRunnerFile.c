#include<stdio.h>
void afficher_tableau(int tab[],int taille);
void insert(int tab[],int taille);
int main (){
   int ab[] = {5,2,126,9,51,7,1,6,12,24};
   int x=10;
   insert(ab,x);
   
}
void insert(int tab[],int taille){
   int key,i,j;
   printf("*********Tri par insertion***********\n");
   printf("avant le tri:\n");
   afficher_tableau(tab,taille);
   printf("\n");
   printf("[%d] --> {%d}\n",tab[0],tab[0]);
      for (i=1;i<taille;i++){
         
         printf("{");
         for (int k=0;k<i;k++){
            printf("%d  ",tab[k]);
         }
         printf("}");
        printf("[%d]",tab[i]);

      printf("-->");
      
      
      key=tab[i];
      j=i-1;
      while (key<tab[j]&&j>=0)
     {
      tab[j+1]=tab[j];
      j--;
     }
     
     tab[j+1]=key;
      printf("{");
         for (int k=0;k<i+1;k++){
            printf("%d  ",tab[k]);
         }
         printf("}\n");

   }
  
   printf("apres le tri :\n");
   afficher_tableau(tab,taille);
   
}
void afficher_tableau(int tab[],int taille){
   for (int i=0;i<taille;i++){
      printf("%d\t",tab[i]);
   }
}