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
#include "jeu_pendu_Camelia.cpp"
/*************************************/
  using namespace std;

/*************************************/
/* Constantes                        */
/*************************************/
const char vec_Mot [50] ="A";



char* fEnlever(char vec_MotEntrer [], char vec_temp [])
{
    for(unsigned int i=0; i<strlen(vec_MotEntrer) ;i++)
    {
      if(vec_MotEntrer[i] != '\0')
      {
        vec_temp [i] = vec_MotEntrer [i+1];
      }
    }
    return vec_temp;
}




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

  int main ()
  {
    
  char vec_MotEntrer [50] = "\0";  
  char vec_temp [50] ="\0";


  
  cin >> vec_MotEntrer;
  //fMotComplet(vec_MotEntrer, vec_Mot);
    fEnlever(vec_MotEntrer,vec_temp);
    
    if(strlen(vec_MotEntrer) == 1)
    {
      cout << "5";
    }
    else{ cout << "erreur"; }
    
    
    
    
    cout << vec_temp;
  
    /*if (vec_temp == vec_Mot)
    {
      cout << "Bonne Reponse";
    }
    else
    {
      cout << "erreur2";
    }*/
    
    return 0;
  }

    
    
    
    
    
