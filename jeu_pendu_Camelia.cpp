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
  //                                                                                                                               //     Ligne 00
  const char *cst_BarreSupEtInfTitre       = "                               ******************\n";                                //18 * Ligne 01
  const char *cst_Titre                    = "                               |  JEU DU PENDU  |\n";                                //     Ligne 02
  //                                                                         ******************                                    //     Ligne 03
  //                                                                                                                               //     Ligne 04
  //                                                                                                                               //     Ligne 05
  const char *cst_DessusPendu              = "                                     _____\n";                                       //     Ligne 06
  const char *cst_PoteauPremiereLigne      = "                                     |/\n";                                          //     Ligne 07
  const char *cst_PoteauVertical           = "                                     |\n";                                           //     Ligne 08
  //                                                                               |                                               //     Ligne 09
  //                                                                               |                                               //     Ligne 10
  const char *cst_PoteauBase               = "                                   __|_______\n";                                    //     Ligne 11
  //                                                                                                                               //     Ligne 12
  //                                                                                                                               //     Ligne 13
  //                                                                                                                               //     Ligne 14 Devra contenir les lignes vides
  //                                                                                                                               //     Ligne 15
  //                                                                                                                               //     Ligne 16
  //                                                                                                                               //     Ligne 17
  const char *cst_BarreHorizontalePleine   = "-------------------------------------------------------------------------------\n";  //80 - Ligne 18
  const char *cst_MauvaisCaracInitial      = " Caracteres demandes, mais absents du mot: \n";                                      //     Ligne 19 Devra se voir ajouter les caractères essayés
  //                                          --------------------------------------------------------------------------------     //     Ligne 20
  const char *cst_Indication               = " Entrez un caractere (ou '#' suivi du mot que vous voulez essayer):            \n";  //     Ligne 21
  const char *cst_Curseur                  = " >";                                                                                 //     Ligne 22

/*===========================================================================================================================================================================*/
  void pAfficheEcran ( char affichage[23][81] )
/*===========================================================================================================================================================================*/
/* Utilisé par: main                                                                                                                                                         */
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
  void pAffichageInitial ( char affichage[23][81] )
/*===========================================================================================================================================================================*/
/* Utilisé par: main                                                                                                                                                         */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Cette procédure sert à afficher le jeu sur l'écran                                                                                                                        */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Utilise: N\A                                                                                                                                                              */
/*===========================================================================================================================================================================*/
  {
    strcpy(affichage[ 0], "\n");                       //Ligne 00
    strcpy(affichage[ 1], cst_BarreSupEtInfTitre);     //Ligne 01
    strcpy(affichage[ 2], cst_Titre);                  //Ligne 02
    strcpy(affichage[ 3], cst_BarreSupEtInfTitre);     //Ligne 03
    strcpy(affichage[ 4], "\n");                       //Ligne 04
    strcpy(affichage[ 5], "\n");                       //Ligne 05
    strcpy(affichage[ 6], cst_DessusPendu);            //Ligne 06
    strcpy(affichage[ 7], cst_PoteauPremiereLigne);    //Ligne 07
    strcpy(affichage[ 8], cst_PoteauVertical);         //Ligne 08
    strcpy(affichage[ 9], cst_PoteauVertical);         //Ligne 09
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
