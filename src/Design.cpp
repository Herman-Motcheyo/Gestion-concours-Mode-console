#include "Design.h"
#include <iostream>

using namespace std;
Design::Design()
{

}

Design::~Design()
{

}
void Design::Entrer()
{
    cout << "Entrer " ;
}

void Design::Entrer(char type)
{
    if(type == 'c')
    {
         cout << " Vous pouvez modifier le Candidat  \n" ;
         cout << " Entrer  l'ancien numero de cni \t" ;

    }
    else if(type == 'm')
    {
        cout << " Vous pouvez modifier le MAtiere \n" ;
         cout << " Entrer  l'ancien code de matiere \t" ;
    }
}

void Design::Menu_Entrer(string entite, char mode)
{
    if(entite == "candidat"){
        if(mode == 'c'){
            Entrer();
            cout << " Le NUMERO DE CNI\t" ;
        }
        else if(mode == 'n' ){
             Entrer();
             cout << " Le NOM \t" ;
        }
        else if(mode == 'p' ){
             Entrer();
             cout << " Le PRENOM \t" ;
        }
        else if(mode == 'a' ){
             Entrer();
             cout << " L' AGE \t" ;
        }
    }else if(entite == "matiere"){
          if(mode == 'c'){
            Entrer();
            cout << " Le CODE DE LA MATIERE\t" ;
        }
        else if(mode == 'l' ){
             Entrer();
             cout << " Le Libell� \t" ;
        }
        else if(mode == 'f' ){
             Entrer();
             cout << " Le Coefficient \t" ;
        }

    }
    else if(entite == "evaluation"){
        if(mode == 'n'){
            Entrer();
            cout << " Le NUMERO DE CNI\t" ;
        }
        else if(mode == 'c' ){
             Entrer();
             cout << " Le CODE DE LA MATIERE \t" ;
        }
        else if(mode == 't' ){
             Entrer();
             cout << " LA NOTE OBTENUE \t" ;
        }
    }
}
void Design::MenuModifier(string entite ,char mode)
{
     if(entite == "candidat"){
        if(mode == 'c'){
            Entrer();
            cout << " La NOUVELLE CNI\t" ;
        }
        else if(mode == 'n' ){
             Entrer();
             cout << " Le NOUVEAU NOM \t" ;
        }
        else if(mode == 'p' ){
             Entrer();
             cout << " Le NOUVEAU PRENOM \t" ;
        }
        else if(mode == 'a' ){
             Entrer();
             cout << " L' AGE \t" ;
        }
    }else if(entite == "matiere"){
          if(mode == 'c'){
            Entrer();
            cout << " Le CODE DE LA MATIERE\t" ;
        }
        else if(mode == 'l' ){
             Entrer();
             cout << " Le Libell� \t" ;
        }
        else if(mode == 'f' ){
             Entrer();
             cout << " Le Coefficient \t" ;
        }
        else if(mode == 'x'){
          cout << " ::::::   Svp veuillez renseigner un numero correct  ::::: \n";
        }

    }
    else if(entite == "evaluation"){
        if(mode == 'n'){
            Entrer();
            cout << " Le NUMERO DE CNI\t" ;
        }
        else if(mode == 'c' ){
             Entrer();
             cout << " Le CODE DE LA MATIERE \t" ;
        }
        else if(mode == 't' ){
             Entrer();
             cout << " LA NOTE OBTENUE \t" ;
        }
    }
}
void Design::MenuModifier(char mode){
            if(mode=='c'){ // c pour candidat
                cout <<"....................................................................."<<endl;
                cout <<" Vous pouvez modifier :"<<endl;
                cout <<" ----------------------"<<endl;
                cout <<"  :::::: Le numero de CNI ::::::"<<endl;
                cout <<"  :::::: Le nom  ::::::" <<endl;
                cout <<"   :::::: Le prenom :::::: "<<endl;
                cout <<"  :::::: L'age ::::::"<<endl;
                  Entrer();
                cout <<" 1 pour la  cni ; ";
                cout <<"2 pour le nom ; ";
                cout <<"3 pour le prenom ; ";
                cout <<"4 pour l' age "<<endl;
                cout <<"....................................................................."<<endl;

            }else if(mode=='m'){ // m pour matiere
                cout <<"..........................................................."<<endl;
                cout <<" Vous pouvez modifier :"<<endl;
                cout <<" ----------------------"<<endl;
                cout <<"  -> Le code"<<endl;
                cout <<"  -> Le libelle"<<endl;
                cout <<"  -> Le coefficient"<<endl;
                  Entrer();;
                cout <<" 1 pour le code ; ";
                cout <<"2 pour le libelle ; ";
                cout <<"3 pour le coeficient  "<<endl;
                cout <<"..........................................................."<<endl;
            }else{}

        }


void Design::Message_Erreur_flux()
{
  cout << "Impossible de manipuler le flux de fichier Probl�me d'ouverture \t" ;
}
void Design::Message_Erreur(char type)
{
          if(type=='c'){
                cout << "  ***** IMPOSSIBLE D'ENREGISTRER LE CANDIDAT !!!! ***** "<<endl;
                cout << "  ***** SON IDENTIFIANT EXISTE DEJA DANS LA BASE DE DONNEE] ***** "<<endl;
                cout << " { Mais vous pouvez modifier ou supprimer l'enregistrement existant }"<<endl;
            }else if(type=='m'){
                cout << " ***** IMPOSSIBLE D'ENREGISTRER LA MATIERE !!!! ***** "<<endl;
                cout << " ***** SON IDENTIFIANT EXISTE DEJA DANS LA BASE DE DONNEE] ***** "<<endl;
                cout << " { Mais vous pouvez modifier ou supprimer l'enregistrement existant }"<<endl;
            }else if(type=='e'){
                cout << " ***  IMPOSSIBLE D'ENREGISTRER L' EVALUATION !!!!**"<<endl;
                cout << "Soit le code n'existe pas soit  votre n'existe pas Merci !!! "<<endl;
            }else if(type == 'w'){
                                  cout << " La note doit etre strictement positive !!! ";
            }else if(type == 'd')
            {
                 cout << "Le NCNI renseign�  n'existe pas Merci !!! "<<endl;
            }
}
void Design::Message_Validation(char rep)
{
  if(rep=='c'){
      cout << " ***** Enregistrement Reussi avec Sucess !!!! ***** "<<endl;
  }else if (rep == 'm'){
     cout << " ***** Modification Reussi avec Sucess !!!! ***** "<<endl;
  }
}
