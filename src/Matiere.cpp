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
            string point_virgule = " ;" ;
             flux << m.Getcode() << point_virgule << m.Getlibelle()<< point_virgule << m.Getcoefficient()<<"\n";
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


/** cette methode permet de supprimer une matiere **/
 void Matiere::supprimerMatiere(string CODE){
                Matiere mati;
                Evaluation e;
                ifstream input("Fichiers/matiere.txt",ios::in);
                ofstream output("Fichiers/tmp1.txt",ios::out|ios::trunc);
                bool trouve=false;
                //on recupere le ncni s'il existe
                while( input >> mati ){
                    if(mati.Getcode()==CODE){
                        trouve=true;
                       e.supprimerEvaluationMatiere(mati.Getcode());
                    }else{
                        output << mati;
                    }
                }
                input.close();
                output.close();
                if(trouve){
                    //on effectue la recopie
                    ifstream input("Fichiers/tmp1.txt",ios::in);
                    ofstream output("Fichiers/matiere.txt",ios::out|ios::trunc);
                    while( input >> mati ){
                        output << mati;
                    }
                    input.close();
                    output.close();
                }
        }


        /** cette methode permet de modifier une matiere**/
void Matiere::modifierMatiere()
{
    ifstream input("Fichiers/matiere.txt",ios::in);
    ofstream output("Fichiers/tmp1.txt",ios::out|ios::trunc);
    Matiere m;
    Evaluation e;
    Design dg;
    Utilitaire utile;
    string ancien_code,new_code,libelle;
    int coefficient;
    int  choix=0;

    bool trouver =false;

    dg.Entrer('m');
    cin >>ancien_code;

    if(input && output)
    {
       if(utile.Existe_Matiere(ancien_code))
       {

               dg.MenuModifier('m');
                cin >>choix;

           while(input >> m )
           {
               if(m.Getcode()== ancien_code)
               {

                 trouver =true;
                 if(choix== 1)
                 {
                     dg.MenuModifier("matiere",'c');
                      cin >>new_code;
                      m.Setcode(new_code);
                      e.modifierEvaluationMatiere(ancien_code,new_code);
                 }
                 else if(choix ==2)
                 {
                     dg.MenuModifier("matiere",'l');
                      cin >>  libelle;
                      m.Setlibelle(libelle);
                 }
                else if(choix ==3)
                 {
                      do{
                           dg.MenuModifier("matiere",'f');
                           cin >>  coefficient;
                           m.Setcoefficient(coefficient);
                      }while(coefficient <= 0 );
                 }

                    else{
                    trouver= false;
                   dg.MenuModifier("matiere",'x');
                 }
              }

                output << m;/** on ecrit dans le fichier temporelle **/

               }
           }


       else
       {
           dg.Message_Erreur('d');
       }
                    input.close();
                    output.close();
       }
    else{
      dg.Message_Erreur_flux();
    }

      /**  on permute le contenu des 2 fichiers **/
    if(trouver){
          ifstream input2("Fichiers/tmp1.txt",ios::in);
          ofstream output2("Fichiers/matiere.txt",ios::out|ios::trunc);

          if(input2 && output2)
          {
           while( input2 >> m)
           {
             output2 << m;
            }
                input2.close();
                output2.close();
            dg.Message_Validation('m');
          }
          else{
             dg.Message_Erreur_flux();
          }
    }

}
void Matiere::afficherMatiere()
{    Design d;
    ifstream fmatiere("Fichiers/matiere.txt",ios::in);
    Matiere m;
    if(fmatiere)
    {
        while (fmatiere >> m )
        {

            d.afficherEntite('m',m.Getcode(),m.Getlibelle() ,m.Getcoefficient(),"x");
        }
        fmatiere.close();
    }else
    {
        d.Message_Erreur_flux();
    }
}

