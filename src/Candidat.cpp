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
         flux  <<cdt.GetNCNI()  <<" ;" <<cdt.GetNOM() <<" ;"  <<cdt.GetPRENOM() <<" ; "  << cdt.GetAGE() <<"\n" ;
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


       input  <<cdt.NCNI  <<" ;" <<cdt.NOM <<" ;"  <<cdt.PRENOM <<" ;"  << cdt.AGE <<endl;
        dg.Message_Validation('c');
        input.close();
    }

    }else{
         dg.Message_Erreur_flux();
    }
}


/**
 Principe est que je recupere le ncni du candidat puis je parcours le fichier si
       lae ncni et  different de celui rencontrer dans le fichiers alors je recopie cette ligne et je la met
       dans un fichier temporel .Ala fin il ne doit rester aue les donn�es � supprimer
       puis je vide le fichier candit et je remet le fichier temporel

 **/
 /**
     ios::in ouvert pour les oprations de saisir
     ios::out ouvert pour les operations de sorties
     ios::trunc si le fichier est ouvert pour les oprations de sortties et qu'il existe d�ja ,son
              contenu pr�cedent est supprimer  et remplac�
 **/

/*void Candidat::supprimer_Candidat(string ncni)
{
  ifstream input("Fichiers/candidat.txt",ios::in);
  ofstream output("Fichiers/tmp1.txt",ios::out|ios::trunc);
  Design dg;
  Candidat c;
  Evaluation e;
  bool presence;
 ici on recherche si le numero de cni existe dans le fichier

 if(input && output){

    while( input >> c )
    {
        if(c.GetNCNI() != ncni)
        {
            output << c;
        }else
        {
            presence = true;
            e.supprimerEvaluation(ncni);
        }
    }
    input.close();
    output.close();
  }
  else{
    dg.Message_Erreur_flux();
  }
   /** ici on echange les deux fichiers **/

   /*if(presence)
   {
       ifstream input2("Fichiers/tmp1.txt",ios::in);
       ofstream output2("Fichiers/candidat.txt",ios::out|ios::trunc);
       string line,cni,nom,prenom;
       int age;
       char v;

       while(input2 >> c )
       {
          output2  <<c.NCNI  <<" ;" <<c.NOM <<" ;"  <<c.PRENOM <<" ; "  << c.AGE <<endl;
       }

       do
       {
         input2 >> cni;

          input2 >> v;
           input2 >> v;


         input2 >> nom;
           input2 >> v;
            input2 >> v;


         input2 >> prenom;
         input2 >> v;
          input2 >> v;
           input2 >> v;

        input2 >> prenom;

          output2  <<cni <<" ;" <<nom <<" ;"  <<prenom <<" ; "  << age <<"\n";


       }while(getline(input2,line));
       while(getline(input2,line)){
                input2 >> cni;

          input2 >> v;
           input2 >> v;


         input2 >> nom;
           input2 >> v;
            input2 >> v;


         input2 >> prenom;
         input2 >> v;
          input2 >> v;
           input2 >> v;

        input2 >> prenom;

          output2  <<cni <<" ;" <<nom <<" ;"  <<prenom <<" ; "  << age <<"\n \n";
       }

       input2.close();
       output2.close();
   }

}*/
 void Candidat::supprimer_Candidat(string NCNI){
                Candidat cand;
                Evaluation e;

                       string line,cni,nom,prenom;
       int age;
       char v;
                ifstream input("Fichiers/candidat.txt",ios::in);
                ofstream output("tmp1.txt",ios::out|ios::trunc);
                bool trouve=false;
                //on recupere le ncni s'il existe
                while( input >> cand ){
                    if(cand.GetNCNI()!=NCNI){
                        output << cand;
                    }else{
                        trouve=true;
                        e.supprimerEvaluation(cand.GetNCNI());
                    }
                }
                input.close();
                output.close();
                if(trouve){
                    //on effectue la recopie
                    ifstream input("tmp1.txt",ios::in);
                    ofstream output("Fichiers/candidat.txt",ios::out|ios::trunc);
                        while( input >> cand ){
                        output << cand;
                    }

      /* while(getline(input,line)){
                input >> cni;

          input >> v;
           input >> v;


         input >> nom;
           input >> v;
            input >> v;


         input >> prenom;
         input >> v;
          input >> v;
           input >> v;

        input >> age;

 output  <<cni <<" ;" <<nom <<" ;"  <<prenom <<" ; "  << age <<"\n";
       }*/
                    input.close();
                    output.close();
                }

        }
