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

/*************************************/
/* Espace de nom                     */
/*************************************/
  using namespace std;

/*************************************/
/* Constantes                        */
/*************************************/










/*char fMotComplet(char* vec_MotEntrer, char* vec_Mot)
{
  char* vec_Mot = "unmot";
  
  cin >> vec_MotEntrer;
  if (vec_MotEntrer [0] == "#" && vec_MotEntrer == vec_Mot)
  {
    cout << "Bonne Reponse";
    
    
    
  }
  
    
    
  return 0; 
}*/
    
    
    
    
/*==========================================================================*/
  int main ()
/*==========================================================================*/
/* Programme principal                                                      */
/*==========================================================================*/
  {
    
  char vec_MotEntrer [] = "\0";  
  char vec_Mot [] ="unmot";
  
  cin >> vec_MotEntrer;
  if (vec_MotEntrer [0] == "#" )//&& vec_MotEntrer == vec_Mot)
  {
    cout << "Bonne Reponse";
  }
  else
  {
    cout <<"Mauvaise reponse";
  }
    
    
    return 0;
  }

    
    
    
    
    