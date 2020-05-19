#include "Matiere.h"


#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Matiere::Matiere()
{

}

Matiere::~Matiere()
{

}

istream & operator >>(istream &flux,Matiere &m)
        {
            char point_virgule;
             flux >> m.code >> point_virgule >> m.libelle>> point_virgule >> m.coefficient;
           return flux;
       }

ostream & operator <<(ostream &flux,Matiere &m)
        {
            char point_virgule = ';' ;
             flux << m.Getcode() << point_virgule << m.Getlibelle()<< point_virgule << m.Getcoefficient();
           return flux;
       }

void Matiere::ajouterMatiere()
{
 ofstream input("Fichiers/matiere.txt",ios::app|ios::out);//flux permettant d'ecrire dans le fichier
   Matiere mat;
    Utilitaire utile;
    Design dg;

    if(input){

    dg.Menu_Entrer("matiere",'c');
    cin >>mat.code;

    if(utile.Existe_Matiere(mat.code))
    {
             dg.Message_Erreur('m');
    }else
    {
      dg.Menu_Entrer("matiere",'l');
       cin >>mat.libelle;
       dg.Menu_Entrer("matiere",'f');
       cin >>mat.coefficient;


       input  <<mat.code  <<" ;" <<mat.libelle <<" ;"  <<mat.coefficient  <<endl;
     dg.Message_Validation('c');
     input.close();
    }

    }else{
         dg.Message_Erreur_flux();
    }
}

void Matiere::supprimerMatiere(string code)
{
 ifstream input("Fichiers/matiere.txt",ios::in);
  ofstream output("Fichiers/tmp2.txt",ios::out|ios::trunc);
  Design dg;
  Matiere m;
  Evaluation e;
  bool presence =false;

  /** ici on recherche si le numero de cni existe dans le fichier **/

  if(input && output){

    while( input >> m )
    {
        if(m.Getcode() != code)
        {
            output << m;
        }else
        {
            presence = true;
            e.supprimerEvaluation(code);
        }
    }
    input.close();
    output.close();
  }
  else{
    dg.Message_Erreur_flux();
  }
   /** ici on echange les deux fichiers **/

   if(presence)
   {
       ifstream input2("Fichiers/tmp2.txt",ios::in);
       ofstream output2("Fichiers/matiere.txt",ios::out|ios::trunc);

       while(input2 >> m )
       {
           output2<< m;
       }
       input2.close();
       output2.close();
   }

}

