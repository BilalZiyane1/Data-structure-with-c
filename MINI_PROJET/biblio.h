typedef struct livre {
int ISBN;
char Titre[50];
int Stock;
struct livre *suivant;
} LIVRE;
typedef struct client {
   char nom[50];
}client ;
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
void vendre(LSC *liste, int ISBN,client *clt);
void supprimerSiVide(LSC *liste, LIVRE *livre) ;
void supprimerToutVide(LSC * liste);