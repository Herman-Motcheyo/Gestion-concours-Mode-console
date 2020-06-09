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




/** cette methode permet de supprrimer une evaluation à partir du numero de cni du candidat **/
void Evaluation::supprimerEvaluationCandidat(string NCNI){
                ifstream input("Fichiers/evaluation.txt",ios::in);
                ofstream output("Fichiers/tmp2.txt",ios::out|ios::trunc);
                Evaluation eval;
                bool trouve=false;
                while( input >> eval ){
                    if(eval.GetNCNI()==NCNI){
                        trouve=true;
                    }else{
                        output << eval;
                    }
                }
                input.close();
                output.close();
                //on effectue la recopie s'il ya existence de l'enregistrement
                if(trouve){
                    ifstream input("Fichiers/tmp2.txt",ios::in);
                    ofstream output("Fichiers/evaluation.txt",ios::out|ios::trunc);
                    while( input >> eval ){
                        output << eval;
                    }
                    input.close();
                    output.close();
                }
        }

      /** cette methode permet de supprrimer une evaluation à partir du code la  matiere **/
        void Evaluation::supprimerEvaluationMatiere(string code){
                ifstream input("Fichiers/evaluation.txt",ios::in);
                ofstream output("Fichiers/tmp2.txt",ios::out|ios::trunc);
                Evaluation eval;
                bool trouve=false;
                while( input >> eval ){
                    if(eval.Getcode()==code){
                        trouve=true;
                    }else{
                        output << eval;
                    }
                }
                input.close();
                output.close();
                //on effectue la recopie s'il ya existence de l'enregistrement
                if(trouve){
                    ifstream input("Fichiers/tmp2.txt",ios::in);
                    ofstream output("Fichiers/evaluation.txt",ios::out|ios::trunc);
                    while( input >> eval ){
                        output << eval;
                    }
                    input.close();
                    output.close();
                }
        }

        /** cette methode permet de modifier la cni d'un candidat ayant passé une evaluation **/

 void Evaluation::modifierEvaluationCandidat( string ancien_nci,string ncni){
            ifstream input("Fichiers/evaluation.txt",ios::in);
            ofstream output("Fichiers/tmp2.txt",ios::out|ios::trunc);
            Evaluation e;
            Design dg;
            bool trouver =false;

            if(input && output){
                while(input  >> e)
                {
                if(e.GetNCNI() == ancien_nci){
                     trouver =true;
                      e.SetNCNI(ncni);
                }
                   output  << e;
                  /* if(e.GetNCNI() != ancien_nci ){
                        output  << e;
                   }
                   else{
                      trouver =true;
                      e.SetNCNI(ncni);
                   }*/
                }
                 output.close();
                 input.close();
            }
            else{
             dg.Message_Erreur_flux();
            }

            if(trouver){

                ifstream input("Fichiers/tmp2.txt",ios::in);
                ofstream output("Fichiers/evaluation.txt",ios::out|ios::trunc);

               if(input && output){
                   while(input >> e ){
                      output << e;
                   }
                   //  dg.Message_Validation('m');
                  input.close();
                  output.close();
               }
               else{
               dg.Message_Erreur_flux();
               }

          }
 }

        /** cette methode permet de modifier lE CODE d'une matiere pour un Candidat ayant passé une evaluation **/

 void Evaluation::modifierEvaluationMatiere( string ancien_code,string ncode){
            ifstream input("Fichiers/evaluation.txt",ios::in);
            ofstream output("Fichiers/tmp2.txt",ios::out|ios::trunc);
            Evaluation e;
            Design dg;
            bool trouver =false;

            if(input && output){
                while(input  >> e)
                {
                if(e.Getcode() == ancien_code){
                     trouver =true;
                      e.Setcode(ncode);
                }
                   output  << e;
                }
                 output.close();
                 input.close();
            }
            else{
             dg.Message_Erreur_flux();
            }

            if(trouver){

                ifstream input("Fichiers/tmp2.txt",ios::in);
                ofstream output("Fichiers/evaluation.txt",ios::out|ios::trunc);

               if(input && output){
                   while(input >> e ){
                      output << e;
                   }
                   //  dg.Message_Validation('m');
                  input.close();
                  output.close();
               }
               else{
               dg.Message_Erreur_flux();
               }

          }
 }

 void Evaluation::afficherEvaluation()
{    Design d;
    ifstream feval("Fichiers/evaluation.txt",ios::in);
    Evaluation e;
    if(feval)
    {
        while (feval >> e )
        {

            d.afficherEntite('e',e.GetNCNI(),e.Getcode() ,e.Getnote(),"x");
        }
        feval.close();
    }
    else
    {
        d.Message_Erreur_flux();
    }
}

