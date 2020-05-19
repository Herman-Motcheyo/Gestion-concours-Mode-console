#include "Evaluation.h"
#include <string>
#include <iostream>

using namespace std;
Evaluation::Evaluation()
{

}

Evaluation::~Evaluation()
{

}

 istream & operator >> (istream & flux, Evaluation &eval)
 {    char caract;
     flux >>  eval.NCNI>> caract>>eval.code>>caract >> eval.note;
     return flux;
 }

 ostream & operator << (ostream &flux, Evaluation &eval)
 {
     flux <<eval.GetNCNI() << " ;"  <<  eval.Getcode() <<" ;" << eval.Getnote() << endl;

     return flux;
 }

void Evaluation::ajouterEvaluation(){
  ofstream input("Fichiers/evaluation.txt",ios::app|ios::out);
    Evaluation eva;
    Utilitaire utile;
    Design dg;

  if(input){
            dg.Menu_Entrer("evaluation",'n');
    cin >>eva.NCNI;

    if(utile.Existe_Candidat(eva.NCNI))
    {
       dg.Menu_Entrer("evaluation",'c');
       cin  >>eva.code;
        if(utile.Existe_Matiere(eva.code))
        {     do{
                      dg.Menu_Entrer("evaluation",'t');
                      dg.Message_Erreur('w');
                    cin >>eva.note;

               }while(eva.note < 0 || eva.note > 20 );

              input  << eva.NCNI  <<" ;" <<eva.code <<" ;"  <<eva.note  <<endl;
              dg.Message_Validation('c');
        }else{
             dg.Message_Erreur('e');
        }

    }else
    {

     dg.Message_Erreur('e');

  }

} else{
     dg.Message_Erreur_flux();
  }

    input.close();
}
