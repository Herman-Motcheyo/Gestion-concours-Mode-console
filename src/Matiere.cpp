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
