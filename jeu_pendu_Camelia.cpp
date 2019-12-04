/****************************************************************************/
/*                                                                          */
/* Projet.................: Projet pendu                                    */
/* Programme..............: jeu_pendu_Camelia.cpp                           */
/* Effectué pour..........: 420-135-SH_Introduction_à_la_programmation      */
/*                                                                          */
/* Auteur.................: Camélia Groleau                                 */
/*                                                                          */
/* Date de conception.....: 20 novembre 2019                                */
/* Date de mise en service: -- -------- ----                                */
/*                                                                          */
/* Modifications                                                            */
/* Date:             Par:                Justification:                     */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

/*************************************/
/* Espace de nom                     */
/*************************************/
  #include <cstring>                  //
  #include <fstream>                  //
  #include <iostream>                 //

/*************************************/
/* Notes personnelles                */
/*************************************/

/*
 * - Pour faire une animation avec des séquences basées sur le temps, la fonction "Sleep(milliseconds)" va s'avérer utile
 * 
 */
 
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
  const char *cst_PoteauVertical           = "                                     |\n";                                           //      Ligne  8
  //                                                                               |                                               //      Ligne  9
  //                                                                               |                                               //      Ligne 10
  const char *cst_PoteauBase               = "                                   __|_______\n";                                    //      Ligne 11
  //                                                                                                                               //      Ligne 12
  //                                                                                                                               //      Ligne 13
  //                                                                                                                               //      Ligne 14 Devra contenir les lignes vides
  //                                                                                                                               //      Ligne 15
  //                                                                                                                               //      Ligne 16
  //                                                                                                                               //      Ligne 17
  const char *cst_BarreHorizontalePleine   = "-------------------------------------------------------------------------------\n";  //80 -  Ligne 18
  const char *cst_MauvaisCaracInitial      = " Caracteres demandes, mais absents du mot: \n";                                      //      Ligne 19 Devra se voir ajouter les caractères essayés
  //                                          --------------------------------------------------------------------------------     //      Ligne 20
  const char *cst_Indication               = " Entrez un caractere (ou '#' suivi du mot que vous voulez essayer):            \n";  //      Ligne 21
  const char *cst_Curseur                  = " >";                                                                                 //      Ligne 22
  
  /////////////////////////
  //Lignes additionnelles//
  /////////////////////////
  const char *cst_MauvaisCarac             = " Caracteres demandes, mais absents du mot: ";                                        //Copie Ligne 19 mais sans le retour à la ligne pour permettre l'ajout des autres lettres

/*===========================================================================================================================================================================*/
  void pAfficheEcran ( char affichage [23][81])
/*===========================================================================================================================================================================*/
/* Utilisé par: main                                                                                                                                                         */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Cette procédure sert à afficher le jeu sur l'écran                                                                                                                        */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Utilise: N\A                                                                                                                                                              */
/*===========================================================================================================================================================================*/
  {
    //system("cls");
    for (int row = 0; row < 23; row++)
    {
      printf("%s", affichage[row]);
    }
  }

/*===========================================================================================================================================================================*/
  void pAffichageInitial (char affichage [23][81])
/*===========================================================================================================================================================================*/
/* Utilisé par: main                                                                                                                                                         */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Cette procédure sert à définir le vecteur à sa valeur initiale                                                                                                            */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Utilise: N\A                                                                                                                                                              */
/*===========================================================================================================================================================================*/
  {
    strcpy(affichage[ 0], "\n");                       //Ligne  0
    strcpy(affichage[ 1], cst_BarreSupEtInfTitre);     //Ligne  1
    strcpy(affichage[ 2], cst_Titre);                  //Ligne  2
    strcpy(affichage[ 3], cst_BarreSupEtInfTitre);     //Ligne  3
    strcpy(affichage[ 4], "\n");                       //Ligne  4
    strcpy(affichage[ 5], "\n");                       //Ligne  5
    strcpy(affichage[ 6], cst_DessusPendu);            //Ligne  6
    strcpy(affichage[ 7], cst_PoteauPremiereLigne);    //Ligne  7
    strcpy(affichage[ 8], cst_PoteauVertical);         //Ligne  8
    strcpy(affichage[ 9], cst_PoteauVertical);         //Ligne  9
    strcpy(affichage[10], cst_PoteauVertical);         //Ligne 10
    strcpy(affichage[11], cst_PoteauBase);             //Ligne 11
    strcpy(affichage[12], "\n");                       //Ligne 12
    strcpy(affichage[13], "\n");                       //Ligne 13
    strcpy(affichage[14], "\n");                       //Ligne 14
    strcpy(affichage[15], "\n");                       //Ligne 15
    strcpy(affichage[16], "\n");                       //Ligne 16
    strcpy(affichage[17], "\n");                       //Ligne 17
    strcpy(affichage[18], cst_BarreHorizontalePleine); //Ligne 18
    strcpy(affichage[19], cst_MauvaisCaracInitial);    //Ligne 19
    strcpy(affichage[20], cst_BarreHorizontalePleine); //Ligne 20
    strcpy(affichage[21], cst_Indication);             //Ligne 21
    strcpy(affichage[22], cst_Curseur);                //Ligne 22
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
      destination[x] = source[x];
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
    
    for(unsigned int i = 0; i < strlen(mot); i++)
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
    pStringReplace(affichage[14], ligne);
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
    char ligne[83];
    int posDansLigne = 43;
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
    ligne[posDansLigne] = '\n';
    pStringReplace(affichage[19], ligne);
  }
