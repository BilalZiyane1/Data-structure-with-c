#include<stdio.h>
#include<stdlib.h>

struct Element 
{
	int cle;
	struct Element* gFils;
	struct Element* dFils;
	struct Element* parent;
};
typedef struct Element  NOEUD;

typedef struct 
{
	NOEUD * racine;
} ARBRE;

// signatures
void Remplir_Noeud(NOEUD * noeud, int data);
void Afficher_Noeud(NOEUD * noeud);
void Parcourir_Arbre_RGD(ARBRE * abr);
void Parcourir_Arbre_GRD(ARBRE * abr);
void Parcourir_Arbre_GRD(ARBRE * abr);
void Ajouter_Noeud(ARBRE * abr , NOEUD * new_noeud);




void Remplir_Noeud(NOEUD * noeud, int data)
{
    noeud->cle=data;
    noeud->gFils=NULL;
	noeud->dFils=NULL;
}


void Afficher_Noeud(NOEUD * noeud)
{
	printf("%d - ", noeud->cle);
}
void rgd(ARBRE *abr)
{
    Afficher_Noeud(abr ->racine);
    Afficher_Noeud(abr->racine->gFils);
    Afficher_Noeud(abr->racine-> dFils);
}
void gdr(ARBRE *abr)
{
    Afficher_Noeud(abr->racine->gFils);
    Afficher_Noeud(abr->racine-> dFils);
    Afficher_Noeud(abr ->racine);

}
void grd(ARBRE *abr)
{
    Afficher_Noeud(abr->racine->gFils);
    Afficher_Noeud(abr ->racine);
    Afficher_Noeud(abr->racine-> dFils);
}
void Parcourir_Arbre_RGD(ARBRE * abr)
{
   ARBRE *sousarbre_g;
   ARBRE *sousarbre_d;
   sousarbre_g=malloc(sizeof(ARBRE));
   sousarbre_d=malloc(sizeof(ARBRE));
   sousarbre_d->racine=abr->racine->dFils;
   sousarbre_g->racine=abr->racine->gFils;
   Afficher_Noeud(abr->racine);
   if(abr->racine->dFils != NULL)
   {
    Parcourir_Arbre_RGD(sousarbre_d);
   }
   if(abr->racine->gFils != NULL)
   {
    Parcourir_Arbre_RGD(sousarbre_g);
   }
}

void Parcourir_Arbre_GRD(ARBRE * abr)
{
	/*if(noeud != NULL)
    {
        Parcourir_Arbre_GRD(noeud->gFils);
        Afficher_Noeud(noeud);
        Parcourir_Arbre_GRD(noeud->dFils);
    }*/
}

void Parcourir_Arbre_GDR(ARBRE * abr)
{
    /* if(noeud != NULL)
    {
        Parcourir_Arbre_GDR(noeud->gFils);
        Parcourir_Arbre_GDR(noeud->dFils);
        Afficher_Noeud(noeud);
    }
		*/		
}

void Ajouter_Noeud(ARBRE *abr, NOEUD *new_noeud)
{
    NOEUD * Courant = abr->racine;
    NOEUD * Emplacement;
    while(Courant != NULL)
    {
        Emplacement = Courant;
        if(new_noeud ->cle < Courant ->cle)
            Courant = Courant->gFils;
        else 
            Courant = Courant ->dFils;

    }
    new_noeud ->parent =Emplacement;
    if(Emplacement == NULL)
         abr->racine = new_noeud;
    else if(new_noeud->cle < Emplacement->cle)
        Emplacement->gFils = new_noeud;
    else
        Emplacement->dFils = new_noeud;
}
    

void main()
{
	
	int Liste[12]={11,7,20,9,8,10,17,23,19,3,28,2};
	ARBRE *abr1,*abr2,*abr;
	int i;
    NOEUD * ND[13];
	
	printf("\nOn cherche  implementer l'arbre binaire de rechcreh suivant:'\n");
	printf("                      11              \n");
	printf("                    /   \\             \n");
    printf("                  /      \\            \n");
    printf("                /         \\           \n");
    printf("              /            \\          \n");
    printf("             7             20         \n");
    printf("           /   \\           / \\      \n");
    printf("          3     9        17    23     \n");
    printf("        /     /   \\       \\    \\    \n");
    printf("       2     8    10      19     28");
    printf("\n");

    for (int i =0;i<3;i++)
    {
        ND[i]=malloc(sizeof(NOEUD));
        Remplir_Noeud(ND[i],Liste[i]);
    }
    abr1=malloc(sizeof(ARBRE));
    abr1 -> racine =ND[0];
    ND[0] -> gFils=ND[1];
    ND[0] -> dFils = ND[2];
    ND[1] -> parent = ND [2] -> parent = ND[0];

    rgd(abr1);
    printf("\n");

    for (int i =3;i<6;i++)
    {
        ND[i]=malloc(sizeof(NOEUD));
        Remplir_Noeud(ND[i],Liste[i]);
    }

    abr2=malloc(sizeof(ARBRE));

    //	int Liste[12]={11,7,20,9,8,10,17,23,19,3,28,2};
    ND[9]=malloc(sizeof(NOEUD));
    Remplir_Noeud(ND[9], Liste[9]);
    abr2->racine=ND[3];
    ND[3] -> gFils =ND[4];
    ND[3] ->dFils=ND[5];
    ND[4] -> parent =ND[5] -> parent = ND[3];
    abr = malloc(sizeof(ARBRE));
    abr->racine = ND[0];

    ND[0]->gFils = ND[1];
    ND[0]->dFils = ND[2];
    ND[1]->parent = ND[0];
    ND[2]->parent = ND[0];

    ND[1]->gFils = ND[3];
    ND[3]->parent = ND[1];

    ND[3]->gFils = ND[4];
    ND[3]->dFils = ND[5];
    ND[4]->parent = ND[3];
    ND[5]->parent = ND[3];
    Parcourir_Arbre_RGD(abr1);
    printf("\n");
    Ajouter_Noeud(abr1,ND[9]);
    Parcourir_Arbre_RGD(abr1);
   
  // rgd(abr2);
   /*Parcourir_Arbre_RGD(abr);
   for (i = 6; i < 12; i++)
    {
        ND[i] = malloc(sizeof(NOEUD));
        Remplir_Noeud(ND[i], Liste[i]);
        Ajouter_Noeud(abr,ND[i]);
    }
   Pacourir_Arbre_RGD(abr);*/

}