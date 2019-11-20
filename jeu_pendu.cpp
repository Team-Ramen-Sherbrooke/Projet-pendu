/****************************************************************************/
/*                                                                          */
/* Projet.................: Manipulation de fichiers                        */
/* Programme..............: fichier_multilingue.cpp                         */
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
/* Traitement: -##MUST BE DONE##                                            */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* En sortie.: -##MUST BE DONE##                                            */
/*                                                                          */
/****************************************************************************/

/*************************************/
/* Espace de nom                     */
/*************************************/
#include <cstring>
#include <fstream>
#include <iostream>

char vgl_affichage[23][80];

void pAfficheEcran ()
{
  system("cls");
  for (int row = 0; row < 23; row++)
  {
    printf("%s", vgl_affichage[row]);
  }
}
