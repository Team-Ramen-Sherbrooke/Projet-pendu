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
  #include "jeu_pendu_Camelia.cpp"    //
  #include "jeu_penduDavid.cpp"       //

/*************************************/
/* Variables globales                */
/*************************************/
  char vgl_affichage[23][81];
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
  } ;
  char vgl_mot[40];

/*************************************/
/* Constantes                        */
/*************************************/
