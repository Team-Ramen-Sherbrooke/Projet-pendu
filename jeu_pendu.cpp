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
/* Constantes                        */
/*************************************/


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
