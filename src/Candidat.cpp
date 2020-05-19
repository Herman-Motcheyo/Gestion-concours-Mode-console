#include "Candidat.h"

#include <string>
#include <iostream>
#include <fstream>



using namespace std;
Candidat::Candidat()
{

}
 /*Candidat::Candidat(int ncni,int age,string nom,string prenom){
            NCNI=ncni;AGE=age;NOM=nom;PRENOM=prenom;
        }*/

Candidat::~Candidat()
{

}   /** surchage du flux de lecture pour recuperer les donn�es du fichier  **/

istream & operator >>(istream &flux,Candidat &cand)
        {
            char point_virgule;
             flux >> cand.NCNI >> point_virgule >> cand.NOM >> point_virgule >> cand.PRENOM >> point_virgule>>cand.AGE;
           return flux;
       }


       /** surcharge du flux d' ecriture pour ecrire un etudiant dans un fichier **/

ostream & operator  <<(ostream &flux ,Candidat cdt)
{
         flux  <<cdt.GetNCNI()  <<";" <<cdt.GetNOM() <<";"  <<cdt.GetPRENOM() <<";"  << cdt.GetAGE() <<"\n" ;
          return flux;
}

void Candidat::ajouterCandidat()
{
  ofstream input("Fichiers/candidat.txt",ios::app|ios::out);//flux permettant d'ecrire dans le fichier
    Candidat cdt;
    Utilitaire utile;
    Design dg;

    if(input){

    dg.Menu_Entrer("candidat",'c');
    cin >>cdt.NCNI;

    if(utile.Existe_Candidat(cdt.NCNI))
    {
             dg.Message_Erreur('c');
    }else
    {
      dg.Menu_Entrer("candidat",'n');
       cin >>cdt.NOM;
       dg.Menu_Entrer("candidat",'p');
       cin >>cdt.PRENOM;


       do{
       dg.Menu_Entrer("candidat",'a');
         cin >>cdt.AGE;
       }while(cdt.AGE <10 );


       input  <<cdt.NCNI  <<" ;" <<cdt.NOM <<" ;"  <<cdt.PRENOM <<" ; "  << cdt.AGE <<endl;
        dg.Message_Validation('c');
        input.close();
    }

    }else{
         dg.Message_Erreur_flux();
    }
}
