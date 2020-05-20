#include "Utilitaire.h"

#include <string>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
Utilitaire::Utilitaire()
{

}

Utilitaire::~Utilitaire()
{

}
         /** cette methode verifie si un candidat existe deja **/
bool Utilitaire::Existe_Candidat(string ncni)
{
    ifstream output("Fichiers/candidat.txt",ios::in);
    Candidat cdt;
    Design dg;
    if(output){

        while ( output>> cdt){
           if(cdt.GetNCNI() == ncni){
              return true;
           }
        }
            return false;
    }
    else{
         dg.Message_Erreur_flux();
    }
}

/** cette methode verifit si une matiere existe deja dans le fichier **/

bool Utilitaire::Existe_Matiere( string newcode)
{    Design dg;
     Matiere m;
    ifstream output("Fichiers/matiere.txt",ios::in);

    if(output){

        while (output>> m ){
                if(m.Getcode() == newcode){
                    return 1;
                }
            }
            return 0;
    }else{
        dg.Message_Erreur_flux();
    }
}

/** cette methode permet de recuperer les coefficient d' une matiere à partir du code renseigné **/

int Utilitaire::coef_Matiere(string code)
{  Matiere m;
   ifstream input("Fichiers/matiere.txt",ios::in);

   while(input >> m){
       if(m.Getcode() == code ){
         return m.Getcoefficient(); /** on retourne le coefficient chercher**/
       }
   }
   return 0;
}

int Utilitaire::nombre_elem_Fichier(char * fichier){

 string line;
 int n=0;
 ifstream input(fichier,ios::in);
    while(getline(input,line)){
      n++;
    }
 return n;
}
