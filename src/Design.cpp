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
      cout<<"\n\t\t\t\t                          NCNI          NOM          PRENOM                    " <<endl;
    }
    else if(type == 'r'){
            cout << " \n\n              [   :: VEUILLEZ  FAIRE UN CHOIX SVP ::  ] \t" ;
    }
    else if(type =='e'){
        cerr << " \n             [   :: ERREUR DE SAISIR ::  ] \t";
    }
    else if(type == 't'){
         cout <<"              [   ::Voulez-vous continuer à ajouter des entités  ?(o/n)  ::] \t";
    }
        else if(type == 'j'){
         cout <<"              [   ::VEUILLEZ RENSEIGNER UN NUMERO CORRECT  ::] \t";
    }
        else if(type == 'v')
    {
      cout<<"\n\t\t\t\t                                NCNI      MOYENNE      DECISION                 \n " <<endl;
    }else if(type == '5')
    {        cout<<"\t\t\t\t             -------------------------------                          "<<endl;
             cout<<"\t\t\t\t             AFFICHAGE DES ADMIS AU CONCOURS                          "<<endl;
             cout<<"\t\t\t\t             -------------------------------                          \n\n"<<endl;


    }else if(type == '6')
    {        cout<<"\t\t\t\t             ---------------------------------------------------------                          "<<endl;
             cout<<"\t\t\t\t             AFFICHAGE DES CANDIDATS PRESENTS DANS LA LISETE D'ATTENTE                         "<<endl;
             cout<<"\t\t\t\t             ---------------------------------------------------------                          \n\n"<<endl;

    }else if(type == '8')
    {        cout<<"\t\t\t\t             ---------------------------------------------------------------------------------                     "<<endl;
             cout<<"\t\t\t\t            SUPPRESSION DES CANDIDATS DE LA LISTE D'ATTENTE  ET AFFICHAGE DES ADMIS DEFINITIFS                         "<<endl;
             cout<<"\t\t\t\t             ---------------------------------------------------------------------------------                        \n\n"<<endl;

    }else if(type == 'q'){
         cout <<"              [   ::Voulez-vous continuer à évaluer la section Ajouter des entités ?(o/n)  ::] \t";
    }
    else if(type == 'n'){
         cout <<"              [   ::Voulez-vous continuer à évaluer cette section d'affichage ?(o/n)  ::] \t";
         }else if(type == 's'){
         cout <<"              [   ::Aimeriez -vous  continuer à évaluer la section de Modification ?(o/n)  ::] \t";
    }
    else if(type == 'p'){
         cout <<"              [   ::Aimeriez -vous  continuer à ajouter les candidats ?(o/n)  ::] \t";
    }else if(type == 'i'){
         cout <<"              [   ::Continuez la modification de la matiere ?(o/n)  ::] \t";
    }else if(type == 'z'){
         cout <<"              [   ::Continuez la modification du Candidat  ?(o/n)  ::] \t";
    }else if(type == 'y'){
         cout <<"              [   ::Continuez la Suppression du Candidat  ?(o/n)  ::] \t";
    }
    else if(type == 'a'){
         cout <<"              [   ::Continuez la Suppression de la Matiere  ?(o/n)  ::] \t";
    }
    else if(type == 'd'){
         cout <<"              [   ::Continuez la Suppression de l' Evaluation  ?(o/n)  ::] \t";
    }
    else if(type == 'l'){
         cout <<"              [   ::Aimeriez -vous  continuer à évaluer la section de Suppression  ?(o/n)  ::] \t";
    }
        else if(type == 'u'){
         cout <<"              [   ::Aimeriez -vous  continuer à évaluer ce module add/modif/delete  ?(o/n)  ::] \t";
    }
    else if(type == 'k'){
         cout <<"\t\t\t\t                            --------------------------------------------------      "<<endl;
         cout <<"\t\t\t\t                     [   :: Nous avons  là les Differents RESULTAT DU CONCOURS  ::] "<<endl;
         cout <<"\t\t\t\t                            --------------------------------------------------      "<<endl;

    }
    else if(type == '7'){
         cout <<"\t\t\t\t                            --------------------------------------------------      "<<endl;
         cout <<"\t\t\t\t                     [   :: AFFICHAGE DES  STATISTIQUES  RELATIF  AU  CONCOURS  ::] "<<endl;
         cout <<"\t\t\t\t                            --------------------------------------------------      "<<endl;

    }    else if(type == '0'){
         cout <<"\t\t\t\t                            --------------------------------------------------      "<<endl;
         cout <<"\t\t\t\t                     [   :: Voulez-vous revenir au Menu Principale??? (o/n) ::] "<<endl;
         cout <<"\t\t\t\t                            --------------------------------------------------      \t";

    }
   else if(type == '9'){
         cout <<"\t\t\t\t                            ---------      "<<endl;
         cout <<"\t\t\t\t                            CANDIDATS      "<<endl;
         cout <<"\t\t\t\t                            ---------      "<<endl;

    }
       else if(type == 'b'){
         cout <<"\t\t\t\t                            --------      "<<endl;
         cout <<"\t\t\t\t                            MATIERES      "<<endl;
         cout <<"\t\t\t\t                            --------      \n"<<endl;

    }       else if(type == 'h'){
         cout <<"\t\t\t\t                            -----------      "<<endl;
         cout <<"\t\t\t\t                            EVALUATIONS      "<<endl;
         cout <<"\t\t\t\t                            -----------      "<<endl;

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

 void Design::afficherAdmis(string ncni,string nom, string prenom,double moyen)
 {       cout<<"\n\t\t\t\t                          "<<ncni<<"          "<<nom <<   "          " <<prenom<<endl;

 }

  void Design::afficheResultat(string ncni,double moyenne, string decision)
 {           cout<<"\n\t\t\t\t                                "<<ncni<<"      "<<moyenne <<   "      "   <<decision<< "            "<<endl;

 }

 void Design::afficheStatistisque(double ad,double aj,double re)
 {    Utilitaire u;
      string nb ="Fichiers/candidat.txt";
      cout<<"\n\n";
      cout<<"                                                [ Statistique ]    ==>>  Admis =  "<< ad << " % "<< endl;
      cout<<"                                                [ Statistique ]    ==>>  Ajourné =  "<< aj << " % "<< endl;
      cout<<"                                                [ Statistique ]    ==>>  Refusé =  "<< re << " % "<< endl;

      cout<<"\n";
      cout<<"                                Nombres de Candidats ayant concouris  =  "<< u.nombre_elem_Fichier(nb)<< endl;
      cout<<"                            -----------------------------------------"<< endl;
 }

 void Design::debut(){
            cout<<"\n"<<endl;
            cout<<"\t\t\t\t\t\t\t.----------------------------------------------."<<endl;
            cout<<"\t\t\t\t\t\t\t|                                              |"<<endl;
            cout<<"\t\t\t\t\t\t\t|          BIENVENUE DANS NOTRE PROGRAMME      |"<<endl;
            cout<<"\t\t\t\t\t\t\t|           (WELCOME IN OUR PROGRAM)           |"<<endl;
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
            cout<<"\t\t\t\t|         2 AFFICHER LES DIFFERENTS  LES ENTITES PRESENTS LES FICHIERS                               |"<<endl;
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

    } else if(mode == '5')
    {
             cout<<"\t\t\t\t|         1         AFFICHER LES DONNEES  CONTENANT LES INFORMATIONS RELATIFS AUX CANDIDATS         |"<<endl;
            cout<<"\t\t\t\t|         2          AFFICHER LES DONNEES  CONTENANT LES INFORMATIONS RELATIFS AUX MATIERES          |"<<endl;
            cout<<"\t\t\t\t|         3          AFFICHER LES DONNEES  CONTENANT LES INFORMATIONS RELATIFS AUX EVALUATIONS       |"<<endl;
    }
    else if(mode == 'a')
    {        cout<<"\t\t\t\t             -------------------------------------------------                        "<<endl;
             cout<<"\t\t\t\t             PRESENTATION DES RESULTATS DEFINITIFS DU CONCOURS                        "<<endl;
             cout<<"\t\t\t\t             -------------------------------------------------                    \n\n"<<endl;

    }
}

void Design::afficherEntite(char type,string cni_code,string nom_libelle, int age_note_cof=0,string prenom=""   )

{
    if(type == 'c')
    {

           cout<<"\t\t\t\t                          [NCNI] : "<< cni_code<<"       [NOM] :"<<nom_libelle<<"        [PRENOM] : "<<prenom<<"       [AGE] : "<<age_note_cof<<"\n"<<endl;

    }
    else if (type == 'm')
    {
       cout<<"\t\t\t\t                          [CODE] :"<< cni_code<<" [Libelle] :"<<nom_libelle<<"             [Coefficient] :   "<<age_note_cof<<"\n"<<endl;
    }
    else if(type == 'e')
    {
         cout<<"\t\t\t\t                          [NCNI] :"<< cni_code<<"           [CODE] :"<<nom_libelle<<"           [NOTE] :    "<<age_note_cof<<endl;
    }

}

void Design::fintp(){


        cout<<"  \t\t\t\t ---------------------------------------------------------------------------------------"<<endl;
        cout << "\t\t\t\t |        M           M   EEEEEEEEEEEE   RRRRRRRR      CCCCCCCCCCC  ------------        |"<<endl;
        cout << "\t\t\t\t |        M  M      M M   E              R      R     C                   I             |"<<endl;
        cout << "\t\t\t\t |        M   M    M  M   E              R      R    C                    I             |"<<endl;
        cout << "\t\t\t\t |        M     M     M   E              R      R   C                     I             |"<<endl;
        cout << "\t\t\t\t |        M           M   EEEEEEEEE      RRRRRRRR  C                      I             |"<<endl;
        cout << "\t\t\t\t |        M           M   E              R       R  C                     I             |"<<endl;
        cout << "\t\t\t\t |        M           M   E              R        R  C                    I             |"<<endl;
        cout << "\t\t\t\t |        M           M   E              R         R  C                   I             |"<<endl;
        cout << "\t\t\t\t |        M           M   E              R          R  C                  I             |"<<endl;
        cout << "\t\t\t\t |        M           M   EEEEEEEEEEEE   R           R  CCCCCCCCCC   -----I-----        |"<<endl;
        cout<<"  \t\t\t\t ---------------------------------------------------------------------------------------"<<endl;

}
