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
    cout << "                    Entrer " ;
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
    else if(type == 'f')
    {
      cout<<"\t\t\t\t|       NCNI          NOM            PRENOM           AGE              " <<endl;
    }else if(type == 'r'){
            cout << " \n\n              [   :: VEUILLEZ  FAIRE UN CHOIX SVP ::  ] \t" ;
    }
    else if(type =='e'){
        cerr << " \n             [   :: ERREUR DE SAISIR ::  ] \t";
    }
    else if(type == 't'){
         cout <<"              [   ::Voulez-vous continuer à ajouter des entités????(o/n)  ::] \t";
    }
        else if(type == 'j'){
         cout <<"              [   ::VEUILLEZ RENSEIGNER UN NUMERO CORRECT  ::] \t";
    }
        else if(type == 'v')
    {
      cout<<"\n\t\t\t\t       NCNI      MOYENNE      DECISION                 \n " <<endl;
    }else if(type == '5')
    {
            cout<<"\n\t\t\t\t         5 GENERATTION DU FICHIER ADMIS ET AFFICHAGE DES ADMIS DU CONCOURS                          |\n\n"<<endl;

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
                else if(mode == 'x'){
          cout << " ::::::   Svp veuillez renseigner un numero correct  ::::: \n";
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
                cout <<"              ..........................................................."<<endl;
                cout <<"              Vous pouvez modifier :"<<endl;
                cout <<"             ----------------------"<<endl;
                cout <<"       :::::::::: Le code ::::::::::"<<endl;
                cout <<"       :::::::::: Le libelle  ::::::::::"<<endl;
                cout <<"       :::::::::: Le coefficient ::::::::::"<<endl;
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
                cout << "          ***** IMPOSSIBLE D'ENREGISTRER LE CANDIDAT !!!! ***** "<<endl;
                cout << "          ***** SON IDENTIFIANT EXISTE DEJA DANS LA BASE DE DONNEE] ***** "<<endl;
                cout << "           Mais vous pouvez modifier ou supprimer l'enregistrement existant }"<<endl;
            }else if(type=='m'){
                cout << "          ***** IMPOSSIBLE D'ENREGISTRER LA MATIERE !!!! ***** "<<endl;
                cout << "          ***** SON IDENTIFIANT EXISTE DEJA DANS LA BASE DE DONNEE] ***** "<<endl;
                cout << "            Mais vous pouvez modifier ou supprimer l'enregistrement existant }"<<endl;
            }else if(type=='e'){
                cout << "           ***  IMPOSSIBLE D'ENREGISTRER L' EVALUATION !!!!**"<<endl;
                cout << "          Soit le code n'existe pas soit  votre n'existe pas Merci !!! "<<endl;
            }else if(type == 'w'){
                                  cout << " La note doit etre strictement positive !!! ";
            }else if(type == 'd')
            {
                 cout << "           Le NCNI renseign�  n'existe pas Merci !!! "<<endl;
            }
}
void Design::Message_Validation(char rep)
{
  if(rep=='c'){
      cout << "                  \n***** Enregistrement Reussi avec Sucess !!!! ***** "<<endl;
  }else if (rep == 'm'){
     cout << "                   \n***** Modification Reussi avec Sucess !!!! ***** "<<endl;
  }
  else if (rep == 's'){
     cout << "                   \n***** Suppression Reussi avec Sucess !!!! ***** "<<endl;
  }
}

 void Design::afficherAdmis(string ncni,string nom, string prenom,int age)
 {       cout<<"\n\t\t\t\t      "<<ncni<<"          "<<nom <<   "          "   <<prenom << "             "<<age << "        "<<endl;

 }
  void Design::afficherAdmis(string ncni,string nom, string prenom)
 {       cout<<"\n\t\t\t\t      "<<ncni<<"          "<<nom <<   "          "   <<prenom << "                  "<<endl;

 }
  void Design::afficheResultat(string ncni,double moyenne, string decision)
 {           cout<<"\t\t\t\t      "<<ncni<<"      "<<moyenne <<   "      "   <<decision<< "            "<<endl;

 }

 void Design::afficheStatistisque(double ad,double aj,double re)
 {    Utilitaire u;
      cout<<"\n\n";
      cout<<"                            [ Statistique ]    ==>>  Admis =  "<< ad << " % "<< endl;
      cout<<"                            [ Statistique ]    ==>>  Ajourné =  "<< aj << " % "<< endl;
      cout<<"                            [ Statistique ]    ==>>  Refusé =  "<< re << " % "<< endl;
      cout<<"\n";
      cout<<"                            Nombres de Candidats ayant concouris  =  "<< u.nombre_elem_Fichier("Fichiers/candidat.txt")<< endl;
      cout<<"                            -----------------------------------------";
 }

 void Design::debut(){
            cout<<"\n"<<endl;
            cout<<"\t\t\t\t\t\t\t.----------------------------------------------."<<endl;
            cout<<"\t\t\t\t\t\t\t|                                              |"<<endl;
            cout<<"\t\t\t\t\t\t\t|          BIENVENUE DANS NOTRE PROGRAMME         |"<<endl;
            cout<<"\t\t\t\t\t\t\t|           (WELCOME IN OUR PROGRAM)          |"<<endl;
            cout<<"\t\t\t\t\t\t\t|                                              |"<<endl;
            cout<<"\t\t\t\t\t\t\t.----------------------------------------------."<<endl;
        }
void Design::menuPrincipal()
{
            cout<<"\n"<<endl;
            cout<<"\t\t\t\t-----------------------------------------------------------------------------------------------------."<<endl;
            cout<<"\t\t\t\t|                                                                                                    |"<<endl;
            cout<<"\t\t\t\t|                                        EVALUATION DU PROGRAMME                                     |"<<endl;
            cout<<"\t\t\t\t|                                    MERCI DE SUIVRE LES INSTRUCTIONS                                |"<<endl;
            cout<<"\t\t\t\t|                                                                                                    |"<<endl;
            cout<<"\t\t\t\t|.---------------------------------------------------------------------------------------------------."<<endl;
              cout<<"\n"<<endl;
              cout<<"\n"<<endl;

            cout<<"\t\t\t\t|         1 AFFICHER LES STRUCTURES DE  DONNEES UTILISEES POUR LA GESTION DU CONCOURS                |"<<endl;
             cout<<"\n"<<endl;
            cout<<"\t\t\t\t|         2 AFFICHER LES METHODES UTILISEES POUR REMPPLIR LES ENTITES LA GESTION                     |"<<endl;
             cout<<"\n"<<endl;
            cout<<"\t\t\t\t|         3 AJOUTER MODIFIER SUPPRIMER DES ENTITES                                                   |"<<endl;
             cout<<"\n"<<endl;
            cout<<"\t\t\t\t|         4 GENERATTION DU FICHIER RESULTAT ET AFFICHAGE DES RESULTATS DU CONCOURS                   |"<<endl;
             cout<<"\n"<<endl;
            cout<<"\t\t\t\t|         5 GENERATTION DU FICHIER ADMIS ET AFFICHAGE DES ADMIS DU CONCOURS                          |"<<endl;
             cout<<"\n"<<endl;
            cout<<"\t\t\t\t|         6 AFFICHER LES CANDIDATS PRESENT DANS LA LISTE D'ATTENTE                                   |"<<endl;
             cout<<"\n"<<endl;
            cout<<"\t\t\t\t|         7 AFFICHER LES STATISTIQUES RELATIF AU CONCOURS                                            |"<<endl;
             cout<<"\n"<<endl;
            cout<<"\t\t\t\t|         8 SUPPRIMER LES CANDIDATS DE LA LISTE D'ATTENTE  ET AFFICHER LES ADMIS DEFINITIFS          |"<<endl;
             cout<<"\n"<<endl;
            cout<<"\t\t\t\t|         9 AFFICHER LES ADMIS PAR ORDRE DE MERITE                                                   |"<<endl;

}

void Design::actionMenu( char mode)
{
    if(mode=='1'){
             cout<<"\t\t\t\t|         1                  AJOUTER                                                                |"<<endl;
            cout<<"\t\t\t\t|         2                  MODIFIER                                                                |"<<endl;
            cout<<"\t\t\t\t|         3                  SUPPRIMER                                                               |"<<endl;

    }
        else if(mode=='2'){
             cout<<"\t\t\t\t|         1                  AJOUTER  CANDIDAT                                                      |"<<endl;
            cout<<"\t\t\t\t|         2                   AJOUTER  MATIERE                                                       |"<<endl;
            cout<<"\t\t\t\t|         3                   AJOUTER  EVALUATION                                                    |"<<endl;

    }
        else if(mode=='3'){
             cout<<"\t\t\t\t|         1                  MODIFIER  CANDIDAT                                                     |"<<endl;
            cout<<"\t\t\t\t|         2                   MODIFIER  MATIERE                                                      |"<<endl;

    }
        else if(mode=='4'){
             cout<<"\t\t\t\t|         1                  SUPPRIMER  CANDIDAT                                                    |"<<endl;
            cout<<"\t\t\t\t|         2                   SUPPRIMER  MATIERE                                                     |"<<endl;
            cout<<"\t\t\t\t|         3                   SUPPRIMER  EVALUATION                                                  |"<<endl;

    }
}

