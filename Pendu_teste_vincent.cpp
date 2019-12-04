#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

const char* cst_cheminFich           ="C:\\prog1\\25.81_liste_mots.txt" ;
const unsigned int cst_longeurMaxMot =40;

/*==========================================================================*/
void pMotAleatoire (char vec_motAleatoire[cst_longeurMaxMot])
/*==========================================================================*/
/* Utilisé par : le fichier main du jeu pendu                               */
/*--------------------------------------------------------------------------*/
/* Cette procédure va chercher un mot dans le fichier externe de façon      */
/* le plus random possible                                                  */
/*--------------------------------------------------------------------------*/
{
  FILE *ptr_FichierMot  = NULL;
  int var_longeurFich =0;
  unsigned int var_choixMot =0;
  unsigned int var_randomisation=0;
  srand (time(NULL));
  
  ptr_FichierMot = fopen(cst_cheminFich,"rt");
  while (!feof(ptr_FichierMot))
  {
    fgets(vec_motAleatoire,cst_longeurMaxMot,ptr_FichierMot);
    var_longeurFich++;
  }
  var_randomisation = rand()%(var_longeurFich/4);
  var_choixMot = (((rand()%4) - 1)*(var_longeurFich/4)+var_randomisation);
  rewind(ptr_FichierMot);
  for(unsigned int var_chercheLigne=0; var_chercheLigne < var_choixMot; var_chercheLigne++)
  {
    fgets(vec_motAleatoire,cst_longeurMaxMot,ptr_FichierMot);
    if (feof(ptr_FichierMot))
    {
      break;
    }
  }
  
  for(unsigned int var_position=0;var_position < cst_longeurMaxMot;var_position++)
  {
    vec_motAleatoire[var_position] = toupper(vec_motAleatoire[var_position]);
  }
}

bool fVeutContinuer ()
/*==========================================================================*/
/* Utilisé par : le fichier main du jeu pendu                               */
/*--------------------------------------------------------------------------*/
/* Cette Fonction sert uniquement à savoir si l'utilisateur veux continuer  */
/* de jouer au jeu du pendu                                                 */
/*--------------------------------------------------------------------------*/
{
  char var_continuer ='0';
  cin>>var_continuer;
  return toupper(var_continuer) == 'O';
}
