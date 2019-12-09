/****************************************************************************/
/*                                                                          */
/* Projet.................: Projet pendu                                    */
/* Programme..............: jeu_pendu.cpp                                   */
/* Effectué pour..........: 420-135-SH_Introduction_à_la_programmation      */
/*                                                                          */
/* Auteur.................: Camélia Groleau                                 */
/*                          Vincent Doucet                                  */
/*                          David Marcoux                                   */
/*                                                                          */
/* Date de conception.....: 20 novembre 2019                                */
/* Date de mise en service: -- -------- ----                                */
/*                                                                          */
/* Modifications                                                            */
/* Date:             Par:                Justification:                     */
/*                                                                          */
/*                                                                          */
/****************************************************************************/
/*                                                                          */
/* En entrée.: -Ce programme va initialement choisir un mot de façon        */
/*              aléatoire dans sa banque de mot qui est un fichier          */
/*              externe. Par la suite, il va interagir avec le client       */
/*              selon les règles du jeu du pendu.                           */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* Traitement: -ce programme verifie si la lettre ou le mot entrer par      */
/*              l'utilisateur sont valide ou ont deja ete entrer.           */
/*                                                                          */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* En sortie.: -Affiche le pendu et le nombre d'erreur fait emplus que      */
/*              tout les chiffre entrer par lutilisateur                    */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

/*************************************/
/* Espace de nom                     */
/*************************************/
  using namespace std;

/*************************************/
/* Espace de nom                     */
/*************************************/
  #include <cstring>                  //
  #include <fstream>                  //
  #include <iostream>                 //
  #include "jeu_pendu_Camelia.cpp"    // pAfficheEcran, pAffichageInitial, pAffichageBarresVides, fCorrespondanceLettreChiffre
//  #include "jeu_penduDavid.cpp"       //
  #include "Pendu_teste_vincent.cpp"  // fVeutContinuer, pMotAleatoire 

/*************************************/
/* Variables globales                */
/*************************************/

/*************************************/
/* Espace de nom                     */
/*************************************/
  using namespace std;                //

/*************************************/
/* Directives au préprocesseur       */
/*************************************/
  #include <cstring>                  //
  #include <fstream>                  //
  #include <iostream>                 //
  #include <chrono>                   //
  #include <thread>                   //

/*************************************/
/* Constantes                        */
/*************************************/
  /////////////////////
  //Affichage initial//
  /////////////////////
  //                                                                                                                               //      Ligne  0
  const char *cst_BarreSupEtInfTitre       = "                               ******************\n";                                //18 *  Ligne  1
  const char *cst_Titre                    = "                               |  JEU DU PENDU  |\n";                                //      Ligne  2
  //                                                                         ******************                                    //      Ligne  3
  //                                                                                                                               //      Ligne  4
  //                                                                                                                               //      Ligne  5
  const char *cst_DessusPendu              = "                                     _____\n";                                       //      Ligne  6
  const char *cst_PoteauPremiereLigne      = "                                     |/\n";                                          //      Ligne  7
  const char *cst_PoteauVerticalBug        = "                                     | \n";                                          //      Ligne  8
  const char *cst_PoteauVertical           = "                                     |\n";                                           //      Ligne  9
  //                                                                               |                                               //      Ligne 10
  const char *cst_PoteauBase               = "                                   __|_______\n";                                    //      Ligne 11
  //                                                                                                                               //      Ligne 12
  //                                                                                                                               //      Ligne 13
  //                                                                                                                               //      Ligne 14 Devra contenir les lignes vides
  //                                                                                                                               //      Ligne 15
  //                                                                                                                               //      Ligne 16
  //                                                                                                                               //      Ligne 17
  const char *cst_BarreHorizontalePleine   = "-------------------------------------------------------------------------------\n";  //79 -  Ligne 18
  //                                           Caracteres demandes, mais absents du mot:                                           //      Ligne 19 Devra se voir ajouter les caractères essayés
  //                                          --------------------------------------------------------------------------------     //      Ligne 20
  const char *cst_Indication               = " Entrez un caractere (ou '#' suivi du mot que vous voulez essayer):            \n";  //      Ligne 21
  const char *cst_Curseur                  = " >";                                                                                 //      Ligne 22
  
  /////////////////////////
  //Lignes additionnelles//
  /////////////////////////
  const char *cst_MauvaisCarac             = " Caracteres demandes, mais absents du mot:                                     \n";  //Copie Ligne 19 mais sans le retour à la ligne pour permettre l'ajout des autres lettres
  
  //////////////////////////
  //Caractère déjà utilisé//
  //////////////////////////
  const char *cst_AnimCaracDejaUtilise1[3] = 
  {                                          "                                                                               \n",  //      Ligne  8 et 12 Frame 1 et 5
                                             "                                                                               \n",  //      Ligne  8 et 12 Frame 2 et 4
                                             "                  ********************************************                 \n"}; //      Ligne  8 et 12 Frame 3
  
  const char *cst_AnimCaracDejaUtilise2[3] = 
  {                                          "                                                                               \n",  //      Ligne  9 et 11 Frame 1 et 5
                                             "                             **********************                            \n",  //      Ligne  9 et 11 Frame 2 et 4
                                             "                  *                                          *                 \n"}; //      Ligne  9 et 11 Frame 3
  const char *cst_AnimCaracDejaUtilise3[3] =
  {                                          "                                     ******                                    \n",  //      Ligne 10       Frame 1 et 5
                                             "                             *                    *                            \n",  //      Ligne 10       Frame 2 et 4
                                             "                  *   Le caractere ' ' a deja ete utilise!   *                 \n"}; //      Ligne 10       Frame 3      Pos 36 = Carac à remplacer
                                             

  
/*===========================================================================================================================================================================*/
  void pStringReplace (char destination [81], char source [81])
/*===========================================================================================================================================================================*/
/* Utilisé par: pAffichageLettresErronees, pAffichageBarresVides                                                                                                             */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Cette procédure sert à remplacer une ligne par une autre                                                                                                                  */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Utilise: N\A                                                                                                                                                              */
/*===========================================================================================================================================================================*/
  {
    for (unsigned int x = 0; x < 81; x++)
    {
      if (source[x] != '\0')
      {
        destination[x] = source[x];
      }
      else
      {
        destination[x] = '\0';
      }
    }
  }
  
/*===========================================================================================================================================================================*/
  void pStringReplace (char destination [81], const char source [81])
/*===========================================================================================================================================================================*/
/* Utilisé par: pAffichageLettresErronees, pAffichageBarresVides                                                                                                             */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Cette procédure sert à remplacer une ligne par une autre                                                                                                                  */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Utilise: N\A                                                                                                                                                              */
/*===========================================================================================================================================================================*/
  {
    for (unsigned int x = 0; x < 81; x++)
    {
      if (source[x] != '\0')
      {
        destination[x] = source[x];
      }
      else
      {
        destination[x] = '\0';
      }
    }
  }

/*===========================================================================================================================================================================*/
  void pAfficheEcran ( char affichage [23][81])
/*===========================================================================================================================================================================*/
/* Utilisé par: main, pCaracDejaEntreeAnimation                                                                                                                              */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Cette procédure sert à afficher le jeu sur l'écran                                                                                                                        */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Utilise: N\A                                                                                                                                                              */
/*===========================================================================================================================================================================*/
  {
    system("cls");
    for (int row = 0; row < 23; row++)
    {
      printf("%s", affichage[row]);
    }
  }

/*===========================================================================================================================================================================*/
  void pAffichageInitial (char affichage [23][81], char mot [])
/*===========================================================================================================================================================================*/
/* Utilisé par: main                                                                                                                                                         */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Cette procédure sert à définir le vecteur à sa valeur initiale                                                                                                            */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Utilise: N\A                                                                                                                                                              */
/*===========================================================================================================================================================================*/
  {
    char affichageMot[30];
    strcpy(affichageMot, mot);
    affichageMot[strlen(affichageMot) + 1] = '\n';
    affichageMot[29] = '\n';
    pStringReplace(affichage[ 0], affichageMot);               //Ligne  0
    pStringReplace(affichage[ 1], cst_BarreSupEtInfTitre);     //Ligne  1
    pStringReplace(affichage[ 2], cst_Titre);                  //Ligne  2
    pStringReplace(affichage[ 3], cst_BarreSupEtInfTitre);     //Ligne  3
    pStringReplace(affichage[ 4], "\n");                       //Ligne  4
    pStringReplace(affichage[ 5], "\n");                       //Ligne  5
    pStringReplace(affichage[ 6], cst_DessusPendu);            //Ligne  6
    pStringReplace(affichage[ 7], cst_PoteauPremiereLigne);    //Ligne  7
    pStringReplace(affichage[ 8], cst_PoteauVerticalBug);      //Ligne  8
    pStringReplace(affichage[ 9], cst_PoteauVertical);         //Ligne  9
    pStringReplace(affichage[10], cst_PoteauVertical);         //Ligne 10
    pStringReplace(affichage[11], cst_PoteauBase);             //Ligne 11
    pStringReplace(affichage[12], "\n");                       //Ligne 12
    pStringReplace(affichage[13], "\n");                       //Ligne 13
    pStringReplace(affichage[14], "\n");                       //Ligne 14
    pStringReplace(affichage[15], "\n");                       //Ligne 15
    pStringReplace(affichage[16], "\n");                       //Ligne 16
    pStringReplace(affichage[17], "\n");                       //Ligne 17
    pStringReplace(affichage[18], cst_BarreHorizontalePleine); //Ligne 18
    pStringReplace(affichage[19], "\n");                       //Ligne 19
    pStringReplace(affichage[20], cst_BarreHorizontalePleine); //Ligne 20
    pStringReplace(affichage[21], cst_Indication);             //Ligne 21
    pStringReplace(affichage[22], cst_Curseur);                //Ligne 22
  }


/*===========================================================================================================================================================================*/
  int fCorrespondanceLettreChiffre (char lettre)
/*===========================================================================================================================================================================*/
/* Utilisé par: pAffichageBarresVides                                                                                                                                        */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Cette procédure sert à afficher les barres vides représentant les caractères à trouver                                                                                    */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Utilise: N\A                                                                                                                                                              */
/*===========================================================================================================================================================================*/
  {
    return (int)toupper(lettre) - 0x41;
  }
  
/*===========================================================================================================================================================================*/
  int fCorrespondanceChiffreLettre (int numero)
/*===========================================================================================================================================================================*/
/* Utilisé par: pAffichageBarresVides                                                                                                                                        */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Cette procédure sert à afficher les barres vides représentant les caractères à trouver                                                                                    */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Utilise: N\A                                                                                                                                                              */
/*===========================================================================================================================================================================*/
  {
    return (char)(numero + 0x41);
  }
  
/*===========================================================================================================================================================================*/
  void pScreenReplace (char destination [23][81], char source [23][81])
/*===========================================================================================================================================================================*/
/* Utilisé par: pAffichageLettresErronees, pAffichageBarresVides                                                                                                             */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Cette procédure sert à remplacer une ligne par une autre                                                                                                                  */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Utilise: N\A                                                                                                                                                              */
/*===========================================================================================================================================================================*/
  {
    for (unsigned int y = 0; y < 23; y++)
    {
      {
        for (unsigned int x = 0; x < 81; x++)
        {
          if (source[y][x] != '\0')
          {
            destination[y][x] = source[y][x];
          }
          else
          {
            destination[y][x] = '\0';
          }
        }
      }
    }
  }
  
/*===========================================================================================================================================================================*/
  void pAffichageBarresVides (char affichage [23][81], char mot [40], bool lettresChoisies[26])
/*===========================================================================================================================================================================*/
/* Utilisé par: main                                                                                                                                                         */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Cette procédure sert à afficher les barres vides représentant les caractères à trouver ainsi que les caractères trouvés                                                   */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Utilise: fCorrespondanceLettreChiffre, pStringReplace                                                                                                                     */
/*===========================================================================================================================================================================*/
  {
    char ligne[81];
    int x = 40 - strlen(mot);
    //int numDeLettre = 0;
    for(int i = 0; i < x; i++)
    {
      ligne[i] = ' ';
    }
    
    for(unsigned int i = 0; i < strlen(mot) - 1; i++)
    {
      if (lettresChoisies[fCorrespondanceLettreChiffre(mot[i])])
      {
        ligne[x] = mot[i];
      }
      else
      {
        ligne[x] = '_';
      }
      x++;
      ligne[x] = ' ';
      x++;
    }
    strcpy(affichage[13], ligne);
  }

/*===========================================================================================================================================================================*/
  void pAffichageLettresErronees (char affichage [23][81], char mot [40], bool lettresChoisies[26])
/*===========================================================================================================================================================================*/
/* Utilisé par: main                                                                                                                                                         */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Cette procédure sert à afficher les lettres erronées entrées par l'utilisateur                                                                                            */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Utilise: fCorrespondanceLettreChiffre, fCorrespondanceChiffreLettre, pStringReplace                                                                                       */
/*===========================================================================================================================================================================*/
  {
    int nbDeLettresErronees = 0;
    char ligne[81]; 
    pStringReplace(ligne, cst_MauvaisCarac);
    int posDansLigne = 42;
    bool lettreErronee = true;
    
    strcpy(ligne, cst_MauvaisCarac);
    for (int nbDeLaLettre = 0; nbDeLaLettre < 26; nbDeLaLettre++)
    {
      lettreErronee = true;
      if (lettresChoisies[nbDeLaLettre])
      {
        for (int posDansMot = 0; posDansMot < 40; posDansMot++)
        {
          if (fCorrespondanceLettreChiffre(mot[posDansMot]) == nbDeLaLettre)
          {
            lettreErronee = false;
            break;
          }
        }
        if (lettreErronee)
        {
          if (!nbDeLettresErronees)
          {
            
            ligne[posDansLigne] = ' ';
            posDansLigne++;
            ligne[posDansLigne] = fCorrespondanceChiffreLettre(nbDeLaLettre);
            posDansLigne++;
            nbDeLettresErronees++;
          }
          else
          {
            ligne[posDansLigne] = ',';
            posDansLigne++;
            ligne[posDansLigne] = ' ';
            posDansLigne++;
            ligne[posDansLigne] = fCorrespondanceChiffreLettre(nbDeLaLettre);
            posDansLigne++;
            nbDeLettresErronees++;
          }
        }
      }
    }
    pStringReplace(affichage[19], ligne);
  }

/*===========================================================================================================================================================================*/
  void pCaracDejaEntreeAnimation (char affichage [23][81], char lettreEntree)
/*===========================================================================================================================================================================*/
/* Utilisé par: main                                                                                                                                                         */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Cette procédure sert à afficher une animation lorsque l'utilisateur entre un caractère qu'il a déjà entré au préalable                                                    */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Utilise: pStringReplace, pAfficheEcran, pScreenReplace                                                                                                                    */
/*===========================================================================================================================================================================*/
  {
    
    using namespace std::this_thread;   // sleep_for
    using namespace std::chrono;        // milliseconds
    
    char affichageTemp [23][81];
    for (int frame = 0; frame < 6; frame++)
    {
      pScreenReplace(affichageTemp, affichage);
      switch (frame)
      {
        case 0:
        pStringReplace(affichageTemp[ 8], affichage[ 8]               );
        pStringReplace(affichageTemp[ 9], affichage[ 9]               );
        pStringReplace(affichageTemp[10], cst_AnimCaracDejaUtilise3[0]);
        pStringReplace(affichageTemp[11], affichage[11]               );
        pStringReplace(affichageTemp[12], affichage[12]               );
        break;
        
        case 1:
        pStringReplace(affichageTemp[ 8], affichage[ 8]               );
        pStringReplace(affichageTemp[ 9], cst_AnimCaracDejaUtilise2[1]);
        pStringReplace(affichageTemp[10], cst_AnimCaracDejaUtilise3[1]);
        pStringReplace(affichageTemp[11], cst_AnimCaracDejaUtilise2[1]);
        pStringReplace(affichageTemp[12], affichage[12]               );
        break;
        
        case 2:
        pStringReplace(affichageTemp[ 8], cst_AnimCaracDejaUtilise1[2]);
        pStringReplace(affichageTemp[ 9], cst_AnimCaracDejaUtilise2[2]);
        pStringReplace(affichageTemp[10], cst_AnimCaracDejaUtilise3[2]);
        pStringReplace(affichageTemp[11], cst_AnimCaracDejaUtilise2[2]);
        pStringReplace(affichageTemp[12], cst_AnimCaracDejaUtilise1[2]);
        affichageTemp[10][36] = toupper(lettreEntree);
        break;
        
        case 3:
        pStringReplace(affichageTemp[ 8], affichage[ 8]               );
        pStringReplace(affichageTemp[ 9], cst_AnimCaracDejaUtilise2[1]);
        pStringReplace(affichageTemp[10], cst_AnimCaracDejaUtilise3[1]);
        pStringReplace(affichageTemp[11], cst_AnimCaracDejaUtilise2[1]);
        pStringReplace(affichageTemp[12], affichage[12]               );
        break;
        
        case 4:
        pStringReplace(affichageTemp[ 8], affichage[ 8]               );
        pStringReplace(affichageTemp[ 9], affichage[ 9]               );
        pStringReplace(affichageTemp[10], cst_AnimCaracDejaUtilise3[0]);
        pStringReplace(affichageTemp[11], affichage[11]               );
        pStringReplace(affichageTemp[12], affichage[12]               );
        break;
        
        case 5:
        
        pStringReplace(affichageTemp[ 8], affichage[ 8]               );
        pStringReplace(affichageTemp[ 9], affichage[ 9]               );
        pStringReplace(affichageTemp[10], affichage[10]               );
        pStringReplace(affichageTemp[11], affichage[11]               );
        pStringReplace(affichageTemp[12], affichage[12]               );
      }
      pAfficheEcran(affichageTemp);
      switch (frame)
      {
        case 0:
        sleep_for(milliseconds(200));
        break;
        
        case 1:
        sleep_for(milliseconds(200));
        break;
        
        case 2:
        sleep_for(milliseconds(1000));
        break;
        
        case 3:
        sleep_for(milliseconds(200));
        break;
        
        case 4:
        sleep_for(milliseconds(200));
        break;
      }
    }
  }

/*===========================================================================================================================================================================*/
  void pAnalyseVictoire (bool lettresChoisies [26], char mot[30], bool &victory)
/*===========================================================================================================================================================================*/
/* Utilisé par: main                                                                                                                                                         */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Cette procédure sert à détecter si l'utilisateur a gagné en rentrant toutes les lettres individuellements                                                                 */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Utilise: fCorrespondanceLettreChiffre                                                                                                                                     */
/*===========================================================================================================================================================================*/
  {
    bool tempVictory = true;
    for (unsigned int x = 0; x < strlen(mot) - 1; x++)
    {
      if (!lettresChoisies[fCorrespondanceLettreChiffre(mot[x])])
      {
        tempVictory = false;
        break;
      }
    }
    if (tempVictory)
    {
      victory = true;
    }
  }


/*===========================================================================================================================================================================*/
  void pReceptionEntree (bool lettresChoisies [26], char mot[30], bool &victory, char affichage[23][81], int &nbErreurs)
/*===========================================================================================================================================================================*/
/* Utilisé par: main                                                                                                                                                         */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Cette procédure sert à recevoir et analyser l'entrée de l'utilisateur                                                                                                     */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Utilise:                                                                                                                                                                  */
/*===========================================================================================================================================================================*/
  {
    char entreeUtilisateur[30];
    bool lettreErronee = false;
    
    cin >> entreeUtilisateur;
    for (unsigned int x = 0; x < strlen(entreeUtilisateur); x++)
    {
      entreeUtilisateur[x] = toupper(entreeUtilisateur[x]);
    }
    if (strlen(entreeUtilisateur) == 1)
    {
      if (lettresChoisies[fCorrespondanceLettreChiffre(entreeUtilisateur[0])])
      {
        pCaracDejaEntreeAnimation(affichage, entreeUtilisateur[0]);
      }
      else
      {
        lettresChoisies[fCorrespondanceLettreChiffre(entreeUtilisateur[0])] = true;
        lettreErronee = true;
        for (unsigned int x = 0; x < strlen(mot); x++)
        {
          if (mot[x] == entreeUtilisateur[0])
          {
            lettreErronee = false;
            break;
          }
        }
        if (lettreErronee)
        {
          nbErreurs += 1;
        }
      }
    }
    else
    {
      bool tempVictory = false;
      if (entreeUtilisateur[0] == '#' && strlen(entreeUtilisateur) == strlen(mot))
      {
        tempVictory = true;
        for (unsigned int x = 0; x < strlen(mot) - 1; x++)
        {
          if (mot[x] != entreeUtilisateur[x+1])
          {
            nbErreurs += 1;
            tempVictory = false;
            break;
          } 
        }
      }
      else
      {
        nbErreurs += 1;
      }
      if (tempVictory)
      {
        victory = true;
      }
    }
  }

/*===========================================================================================================================================================================*/
  void pAffichageErreurs (char affichage [23][81], int nbErreurs)
/*===========================================================================================================================================================================*/
/* Utilisé par: main                                                                                                                                                         */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Cette procédure sert à afficher le pendu                                                                                                                                  */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Utilise:                                                                                                                                                                  */
/*===========================================================================================================================================================================*/
  {
    char var = '0';
    char ligne[81];
    strcpy(ligne, affichage[7]);
    switch (nbErreurs)
    {
      case 1:
      var = '1';
      break;
      
      case 2:
      var = '2';
      break;
      
      case 3:
      var = '3';
      break;
      
      case 4:
      var = '4';
      break;
      
      case 5:
      var = '5';
      break;
      
      case 6:
      var = '6';
      break;
      
      case 7:
      var = 'P';
      break;
    }
    affichage[7][39] = '|';
    affichage[7][40] = '\n';
    affichage[8][39] = var;
    affichage[8][40] = '\n';
  }


/*===========================================================================================================================================================================*/
  void pAffichageVictoire (char affichage[23][81])
/*===========================================================================================================================================================================*/
/* Utilisé par: main                                                                                                                                                         */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Cette procédure sert à dire à l'utilisateur qu'il a gagné                                                                                                                 */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Utilise: N\A                                                                                                                                                              */
/*===========================================================================================================================================================================*/
  {
    pStringReplace(affichage[ 7], "                       **********************************\n");
    pStringReplace(affichage[ 8], "                       *                                *\n");
    pStringReplace(affichage[ 9], "                       *   BRAVO! VOUS L'AVEZ TROUVE!   *\n");
    pStringReplace(affichage[10], "                       *                                *\n");
    pStringReplace(affichage[11], "                       **********************************\n");
  }

#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

const char* cst_cheminFich           ="25.81_liste_mots.txt" ;
const unsigned int cst_longeurMaxMot = 40;

/*==========================================================================*/
void pMotAleatoire (char vec_motAleatoire[cst_longeurMaxMot])
/*==========================================================================*/
/* Utilisé par : le fichier main du jeu pendu                               */
/*--------------------------------------------------------------------------*/
/* Cette procédure va chercher un mot dans le fichier externe de façon      */
/* le plus random possible                                                  */
/*--------------------------------------------------------------------------*/
{
  FILE *ptr_FichierMot;
  int var_longeurFich =0;
  unsigned int var_choixMot =0;
//  unsigned int var_randomisation=0;
  srand (time(NULL));
  
  ptr_FichierMot = fopen(cst_cheminFich,"r");
  while (!feof(ptr_FichierMot))
  {
    fgets(vec_motAleatoire,cst_longeurMaxMot,ptr_FichierMot);
    var_longeurFich++;
  }
  //var_randomisation = rand()%(var_longeurFich/4);
  var_choixMot = rand()%var_longeurFich;
  rewind(ptr_FichierMot);
  for(unsigned int var_chercheLigne=0; var_chercheLigne < var_choixMot; var_chercheLigne++)
  {
    fgets(vec_motAleatoire, cst_longeurMaxMot, ptr_FichierMot);
    if (feof(ptr_FichierMot))
    {
      break;
    }
  }
  
  for(unsigned int var_position = 0; var_position < strlen(vec_motAleatoire); var_position++)
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
  cout << "Voulez-vous jouer a nouveau (o/n)? ";
  cin>>var_continuer;
  return toupper(var_continuer) == 'O';
}


int main()
{
  do
  {
    char vgl_affichage[23][81];
    char vgl_mot[30];
    int  vgl_nbErreurs = 0;
    bool vgl_lettresChoisies[26] =
    {
      false, //a
      false, //b
      false, //c
      false, //d
      false, //e
      false, //f
      false, //g
      false, //h
      false, //i
      false, //j
      false, //k
      false, //l
      false, //m
      false, //n
      false, //o
      false, //p
      false, //q
      false, //r
      false, //s
      false, //t
      false, //u
      false, //v
      false, //w
      false, //x
      false, //y
      false  //z
    };
    bool vgl_victory = false;
    
    pMotAleatoire(vgl_mot);
    //Initial
    pAffichageInitial(vgl_affichage, vgl_mot);
    //Boucle
    while (vgl_nbErreurs < 7 && !vgl_victory)
    {
      pAffichageBarresVides(vgl_affichage, vgl_mot, vgl_lettresChoisies);
      pAffichageLettresErronees(vgl_affichage, vgl_mot, vgl_lettresChoisies);
      pAffichageErreurs(vgl_affichage, vgl_nbErreurs);
      pAfficheEcran(vgl_affichage);
      pReceptionEntree(vgl_lettresChoisies, vgl_mot, vgl_victory, vgl_affichage, vgl_nbErreurs);
      pAnalyseVictoire(vgl_lettresChoisies, vgl_mot, vgl_victory);
    }
    if (vgl_victory)
    {
      for (int i = 0; i < 26; i++)
      {
        vgl_lettresChoisies[i] = true;
      }
    }
    pAffichageBarresVides(vgl_affichage, vgl_mot, vgl_lettresChoisies);
    if (!vgl_victory)
    pAffichageLettresErronees(vgl_affichage, vgl_mot, vgl_lettresChoisies);
    pAffichageErreurs(vgl_affichage, vgl_nbErreurs);
    if (vgl_victory)
    {
      pAffichageVictoire(vgl_affichage);
    }
    pAfficheEcran(vgl_affichage);
  }
  while(fVeutContinuer());
  return 0;
}
