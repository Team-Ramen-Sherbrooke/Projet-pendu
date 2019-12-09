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
  //#include "jeu_pendu_Camelia.cpp"

/*************************************/
  using namespace std;

/*************************************/
/* Constantes                        */
/*************************************/
  char vec_Mot [30] ="UNMOT";
  int vgl_nbErreurs =0;
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

/*===========================================================================================================================================================================*/
  void pEnlever(char vec_MotEntrer [], char vec_temp [])
/*===========================================================================================================================================================================*/
/* Utilisé par: pVerificationMotComplet                                                                                                                                      */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Cette procédure sert à enlever le # du mot entré                                                                                                                          */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Utilise: n/a                                                                                                                                                              */
/*===========================================================================================================================================================================*/
  {
      for(unsigned int i=0; i<strlen(vec_MotEntrer) ;i++)
      {
        if(vec_MotEntrer[i] != '\0')
        {
          vec_temp [i] = vec_MotEntrer [i+1];
        }
      }
  }

/*===========================================================================================================================================================================*/
  void pVerificationMotComplet(int &vgl_nbErreurs, char vec_Mot [],char vec_MotEntrer [], char vec_temp [])
/*===========================================================================================================================================================================*/
/* Utilisé par: main                                                                                                                                                         */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Cette procédure sert à vérifier le mot complet après le #                                                                                                                 */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Utilise: pEnlever                                                                                                                                                         */
/*===========================================================================================================================================================================*/
  {
  bool reponseErronee = false;
  if (vec_MotEntrer [0] == '#')
  {
    pEnlever(vec_MotEntrer, vec_temp);
    for (int posDansMot = 0; vec_Mot[posDansMot] != '\0'; posDansMot++)
    {
      if (vec_Mot[posDansMot] != vec_temp[posDansMot])
      {
        reponseErronee = true;
        break;
      }
    }
      if (reponseErronee == true && (strlen(vec_MotEntrer) != 1))
      {
        vgl_nbErreurs +=1;
      }
      /*
      else
      {
        cout << "Victoire1";
      }
      */
    }
  }

/*===========================================================================================================================================================================*/
  void pVerificationLettre(int &vgl_nbErreurs, char vec_Mot [],char vec_MotEntrer [], char vec_temp [], bool lettresChoisies[26])
/*===========================================================================================================================================================================*/
/* Utilisé par: main                                                                                                                                                         */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Cette procédure sert à la vérification des lettres entrées individuelles                                                                                                  */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Utilise: n\a                                                                                                                                                              */
/*===========================================================================================================================================================================*/
  {
    int bonnelettre = 0;
    
    if(strlen(vec_MotEntrer) == 1)
    {
      for (int posDansMot = 0; vec_Mot[posDansMot] != '\0'; posDansMot++)
      {
        if (vec_Mot[posDansMot] == vec_MotEntrer[0])
        {
          bonnelettre +=1;
        }
      }
      if (bonnelettre == 0)
      {
        vgl_nbErreurs +=1;
      }
      /*
      else
      {
        cout << "Victoire2";
      }
      */
    }
    /*
    else
    {
    cout << "erreur2"; 
    }
    */
  }
  
  /*
  int main ()
  {
    
    char vec_MotEntrer [50] = "\0";  
    char vec_temp [50] ="\0";

  
    cin >> vec_MotEntrer;
    
    pEnlever(vec_MotEntrer, vec_temp);
    pVerificationMotComplet(vgl_nbErreurs, vec_Mot, vec_MotEntrer, vec_temp);
    pVerificationLettre (vgl_nbErreurs, vec_Mot, vec_MotEntrer, vec_temp);

    cout << vgl_nbErreurs;
    cout << vec_temp;

  
    return 0;
  }
  */
  
  int main()
  {
  char vec_MotEntrer[30];
  char vec_temp[30];
  cin >> vec_MotEntrer;
  
  bool reponseErronee = false;
  if (vec_MotEntrer [0] == '#' && strlen(vec_MotEntrer) - 1 == strlen(vec_Mot))
  {
    pEnlever(vec_MotEntrer, vec_temp);
    for (int posDansMot = 0; vec_Mot[posDansMot] != '\0'; posDansMot++)
    {
      if (vec_Mot[posDansMot] != toupper(vec_temp[posDansMot]))
      {
        reponseErronee = true;
        break;
      }
    }
      if (reponseErronee == true && (strlen(vec_MotEntrer) != 1))
      {
        vgl_nbErreurs +=1;
      }
      
      else
      {
        cout << "true";
      }
      
    }
    return 0;
  }

