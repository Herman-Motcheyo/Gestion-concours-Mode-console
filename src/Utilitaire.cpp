#include "Utilitaire.h"
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
    ifstream output("candidat.txt",ios::in);
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
    ifstream output("matiere.txt",ios::in);

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
   ifstream input("matiere.txt",ios::in);

   while(input >> m){
       if(m.Getcode() == code ){
         return m.Getcoefficient(); /** on retourne le coefficient chercher**/
       }
   }
   return 0;
}

                  /** cette methode permet de calculer le nombre d'element du fichier **/
int Utilitaire::nombre_elem_Fichier(string fichier)
{

 string line;
 int n=0;
 ifstream input(fichier,ios::in);
    while(getline(input,line)){
      n++;
    }
 return n;
}

                /** cet methode permet d'obtenir les notes d'un candidat à partir de sa cni **/
double* Utilitaire::notes_candidat(string cni,int nb_el)
{  Evaluation e;
   Candidat c;
   Design d;
   Utilitaire util;
   int i=0;
   double notes[nb_el];
   ifstream input("evaluation.txt",ios::in);
    if(input){

      while (input >> e){
      if(e.GetNCNI() == cni){
       if(util.Existe_Matiere(e.Getcode())){
         notes[i] = e.Getnote();
         i++;
       }

      }
    }
      return notes;
    }else{
       d.Message_Erreur_flux();
    }

}

                 /** cete methode permet de calculer la moyenne d'un candidat **/
  double Utilitaire::moyenne(double notes[]  ,int coef[] , int nb_el)
  {
       int somme=0;
       double notecoef=0, result =0;
       for(int i = 0; i< nb_el- 1;i++ ){
             somme +=coef[i];
             notecoef += (notes[i]*coef[i]);

      //   cout<<"not "<< i<< "est " <<notes[i]  << "  co est "<< coef[i] <<endl ;
       }
       result = notecoef/(somme);
       return result;
  }


                      /** cette methode permet d' avoir les resultats des candidat **/
  /**
     principe:

              on parcours le fichier,on verifit si la cni du candidat correspond à  celui de l'evaluation
              et que le code de la matiere concernée existe , alors on recupere les notes et les coeficients
              dans un tableau ensuite on appele le methode qui permet de calculer la moyenne lorsque la taille
              des elements dans le fichier matiere = à un indice initialisé qui s'incrementait lorsque l'on remplissait
              les notes.
  **/
 void Utilitaire::resultat()
  {   Evaluation e;
      Design dg;
      Candidat c;
      Matiere m;

     int n = nombre_elem_Fichier("matiere.txt");
     if(n != 0){

         ifstream input("candidat.txt",ios::in);
         ofstream output("resultat.txt",ios::out|ios::trunc);

         double notes[n],moyen;
         int coef[n];
         if(input && output){

          while(input  >> c ){
           int i=0;
            ifstream input2("evaluation.txt",ios::in);
             while(input2 >> e ){
              if(c.GetNCNI() == e.GetNCNI()){

                 if(Existe_Matiere( e.Getcode())){
                   notes[i] = e.Getnote();
                   coef[i] = coef_Matiere(e.Getcode());
                 //  cout<<"notes "<< i<< "est " <<notes[i]  << "  coesf est "<< coef[i] <<endl ;
                   i++;
                 }
              }
             }

              moyen = moyenne(notes,coef,n);
              //cout<< moyen <<endl;
              output << c.GetNCNI()  <<" ;" << moyen<<" ;"<<decision(notes,moyen,n)  <<endl;

} input.close();
  output.close();
         }else{
           dg.Message_Erreur_flux();
         }

     }
  }
   /**  cette methode permet d'afficher les resultats du concours**/

   void Utilitaire::afficherResultat()
   {   Design dg;
       string decision,cni;
       double moyenne;
      ifstream input("resultat.txt",ios::in);

      if(input){
            dg.Entrer('v');
           while(input  >> cni){
            input.get(); input.get();
            input >> moyenne;
            input.get(); input.get();
            input >> decision;
            dg.afficheResultat(cni,moyenne,decision);
           }
        input.close();
      }
      else{
        dg.Message_Erreur_flux();
      }
   }
      /** cette methode permet de decider de la situation d'un candidat(admi,ajourné,echec)  **/
 string Utilitaire::decision(double notes[],double moyenne ,int nb_el)
 {
    if(moyenne >= 10){

      for(int i=0;i<nb_el-1;i++){
        if(notes[i] >= 10){
            return "admis";
        }
        else{
           return "ajourné";
         }
      }
    }
     return "refuse";

 }

      /** cette methode permet de produire le fichier admis.txt contenat les informations relatives aux candidats admis**/
void Utilitaire::admis()
{
Design d;
   string cni,decisionn;
   double moyen;
   ifstream input("resultat.txt",ios::in);
   ofstream output("admis.txt",ios::out|ios::trunc);

   if(input && output){
         while(input >> cni){
           input.get();
           input.get();
           input >> moyen;
           input.get();
           input.get();
           input >> decisionn;
           if(decisionn == "admis"){
             ifstream input2("candidat.txt");
             Candidat c;
             if(input2){
              bool trouver =true; /** permet de s'arreter lorsqu'on a vu la cni **/

               while((input2 >> c) && trouver){
                  if(c.GetNCNI() == cni){
                    output << c;
                    trouver = false;
                  }
               }
               input2.close();
             }
             else{
                 d.Message_Erreur_flux();
             }
           }
         }
         input.close();
         output.close();
   }else{
       d.Message_Erreur_flux();
   }
}

 /** Permet d'afficher la liste des Candidats admis au concours **/
void  Utilitaire::afficherListeAdmis(){

Design dg;
string nom,prenom,ncni;
int age;

  ifstream input("admis.txt",ios::out);
  if(input){
   dg.Entrer('f');
       while(input >> ncni ){
          input.get();
           input.get();
           input >> nom;
           input.get();
           input.get();
           input >> prenom;
           input.get();
           input.get();
           input.get();
           input >>age;

       dg.afficherAdmis(ncni,nom,prenom);
       }
  input.close();
  }
  else{
   dg.Message_Erreur_flux();
  }
}


   /** Fournir le fichier attente.txt pour les candidats ayant reussiir au concours donc l'age > 20 **/
void Utilitaire::attente()
{ Design dg;
  string nom,prenom,ncni;
  int age;
  ifstream input("admis.txt",ios::in);
  ofstream output("attente.txt",ios::out|ios::trunc);
  if(input &&output){

      while(input >> ncni ){
          input.get();
           input.get();
           input >> nom;
           input.get();
           input.get();
           input >> prenom;
           input.get();
           input.get();
           input.get();
           input >>age;

          if(age >= 20){
            Candidat c;
            bool trouver =true;
            ifstream input2("candidat.txt",ios::in);
            while ((input2  >> c) && trouver){
             if(c.GetAGE() == age){
                output << c.GetNCNI() <<" ;"<<c.GetNOM()<<" ;"<<c.GetPRENOM()<<endl;
             }
            }
          }
       }
  input.close();

  }else{
   dg.Message_Erreur_flux();
  }

}

/** Permet d'afficher les candidats presents dans la liste d'attentes  **/
void Utilitaire::afficherListeAttente()
{

Design dg;
string nom,prenom,ncni;


  ifstream input("attente.txt",ios::out);
  if(input){
   dg.Entrer('f');
       while(input >> ncni ){
          input.get();
           input.get();
           input >> nom;
           input.get();
           input.get();
           input >> prenom;

      dg.afficherAdmis(ncni,nom,prenom);
       }
  input.close();
  }
  else{
   dg.Message_Erreur_flux();
  }
}

  /** permet de retourner le pourcentage des candidats pour le decision(admis,refusé,ajourné) **/
  /**
 principe:
    lors de la lecture du fichier resulat.txt,initialisé une variable compteur qui s'increment
     lorsque la decision == celle passée en parametre ensuite le nombre de candidat = nombre de lgnes
     presents dans candidat.txt.
  **/
double Utilitaire::statistique(string deci)
{
  Design d;
   string cni,decisionn;
   double moyen,stat;
   int compteur =0;
  ifstream input("resultat.txt",ios::in);
  int nb_candidat =nombre_elem_Fichier("candidat.txt");
  if(input){

     while(input >> cni){
           input.get();
           input.get();
           input >> moyen;
           input.get();
           input.get();
           input >> decisionn;

           if(decisionn == deci){
            compteur++;
           }
     }
      stat =((double)compteur/(double)nb_candidat)*100;


  }
  else{
  d.Message_Erreur_flux();
  }
    return stat;
}
      /** permet d'afficher les statistiques relatifs au concours**/
 void  Utilitaire:: afficheStatistique()
 {
   Design d;
   double nbadmis=0,nbrefuse=0,nbajourne=0;

   nbadmis = statistique("admis");
   nbrefuse = statistique("refuse");
   nbajourne = statistique("ajourné");
   d.afficheStatistisque(nbadmis,nbajourne,nbrefuse);
 }

        /** permet de supprimer les candidat admis agés de plus de 20 ans **/
 void Utilitaire::supprimer()
 {  Design d;
    string nom,prenom,nci;
    int age;
    bool trouver =true;
    ifstream input("admis.txt",ios::in);
    ofstream output("tmp1.txt",ios::out|ios::trunc);

    if(input && output){
        while(input >>nci) {
          input.get();
           input.get();
           input >> nom;
           input.get();
           input.get();
           input >> prenom;
           input.get();
           input.get();
           input.get();
           input >>age;

           if(age <20){
             trouver =true;
             output << nci <<" ;"<<nom<<" ;"<<prenom <<" ;"<<age<<endl;
           }
        }

    input.close();
    output.close();
    }  else{
     d.Message_Erreur_flux();
    }

    if(trouver){
        ifstream input2("tmp1.txt",ios::in);
        ofstream output2("admis.txt",ios::out|ios::trunc);
        if(input2 && output2){
           while(input2 >>nci){
            input2.get();  input2.get();
            input2 >> nom;
            input2.get();  input2.get();
            input2>> prenom;
            input2.get();  input2.get();
            input2 >> age;
             output2 << nci <<" ;"<<nom<<" ;"<<prenom <<" ;"<<age<<endl;
       }
        input2.close();
        output2.close();
        }
        else{
           d.Message_Erreur_flux();
        }
    }
 }

 void Utilitaire::afficheAdmisDefinitif(){
  Design dg;
string nom,prenom,ncni;
int age;

  ifstream input("admis.txt",ios::out);
  if(input){
   dg.Entrer('f');
       while(input >> ncni ){
          input.get(); input.get();
           input >> nom;
           input.get();  input.get();
           input >> prenom;
           input.get();input.get();
           input >>age;

       dg.afficherAdmis(ncni,nom,prenom);
       }
  input.close();
  }
  else{
   dg.Message_Erreur_flux();
  }
 }

void Utilitaire::afficheMerite()
{   Design d;
    int i =0,j=0;

    string nci2,decision;
    int Nbre =nombre_elem_Fichier("admis.txt");
    int Nbre2 = nombre_elem_Fichier("resultat.txt");


    ifstream input("admis.txt");
    ifstream input2("resultat.txt");
         struct Participant
        {
           string nci;
           string nom;
           string prenom;
           int age;
           double moyen;
        };
       struct Dataresultat
        {
           string nci2;
           string decision;
          double moyen;
         };

if(input && input2)
    {
      Participant p[Nbre],tmp;
      Dataresultat r[Nbre2];

         while(input >> p[i].nci && i != Nbre)
         {  //cout << i<<endl;
             input.get();input.get();
             input >>p[i].nom;
           //  cout << p[i].nom<<endl;
             input.get();input.get();
             input >>p[i].prenom;
             input.get();input.get();
             input >>p[i].age;
            //   cout << p[i].prenom<<endl;

             ++i;
         }

          while(input2 >> r[j].nci2 && j != Nbre2)
         { // cout << j<<endl;
              //cout << r[j].nci2<<endl;
             input2.get();input2.get();
             input2 >>r[j].moyen;
            // cout << r[j].moyen<<endl;
             input2.get();input2.get();
             input2 >>r[j].decision;
             ++j;
         }

        for(int k =0;k< Nbre2;k++)
         {
           for(int x=0;x<Nbre ;x++)
           {
             if( p[x].nci ==  r[k].nci2)
             {
                p[x].moyen = r[k].moyen;

             }
           }
         }

         for(i=1;i<Nbre;i++)
         {
           j=i-1;
           while(j>=0 && p[j].moyen<=p[j+1].moyen)
           {
             tmp=p[j];
             p[j]=p[j+1];
             p[j+1]=tmp;
             j--;
           }
         }
         cout<<"                                MOYENNES"<<endl;
         for(auto element:p)
            {
           //   cout<<element.nom<<" "<<element.prenom<<" "<<element.moyen<<element.nci<<endl;
              cout<<"                                "<<element.moyen;
                d.afficherAdmis(element.nci,element.nom,element.prenom);
            }
    }else
    {
        d.Message_Erreur_flux();
    }
}
void Utilitaire::dataStructure()
{
         cout <<"\t\t\t\t                            --------------------------------------------------      "<<endl;
         cout <<"\t\t\t\t                     [   :: STRUCTURES DE DONNEES POUR LA GESTION DU CONCOURS   ::] "<<endl;
         cout <<"\t\t\t\t                            --------------------------------------------------      "<<endl;

         cout <<"\t\t\t\t                            --------------------------------------------------      "<<endl;

         cout <<"\t\t\t\t  POUR LA GESTION DU CONCOURS  ,ON A      \n"<<endl;
         cout <<"\t\t\t\t  Une classe Candidat.hpp possedant les attributs d'un candidat  et les prototypes des methodes"<<endl;
         cout <<"\t\t\t\t          pour traiter les Candidats telque ''ajouterCandidat()''  ''supprimer_Candidat()'' ''modifierCandidat()'' "<<endl;
         cout <<"\t\t\t\t          et la surcharge du flux de lecture et d ecriture '' << >> '' ensuite un fichier ''Candidat.cpp''"<<endl;
         cout <<"\t\t\t\t          pour l'implementation des methodes citées plus haut \n"<<endl;

         cout <<"\t\t\t\t                            --------------------------------------------------      "<<endl;
         cout <<"\t\t\t\t  Une classe Matiere.hpp possedant les attributs d'une matiere  et les prototypes des methodes"<<endl;
         cout <<"\t\t\t\t          pour traiter les Matiere telque ''ajouterMatiere()''  ''supprimerMatiere()'' ''modifierCandidat()'' "<<endl;
         cout <<"\t\t\t\t          et la surcharge du flux de lecture et d ecriture '' << >> '' ensuite un fichier ''Matiere.cpp''"<<endl;
         cout <<"\t\t\t\t          pour l'implementation des methodes citées plus haut \n"<<endl;

         cout <<"\t\t\t\t                            --------------------------------------------------      "<<endl;
         cout <<"\t\t\t\t  Une classe Evaluation.hpp possedant les attributs d'une evaluation  et les prototypes des methodes"<<endl;
         cout <<"\t\t\t\t          pour traiter les Evaluations telque ''ajouterEvaluation'' ,supprimer et modifier "<<endl;
         cout <<"\t\t\t\t          et la surcharge du flux de lecture et d ecriture '' << >> '' ensuite un fichier ''Evaluation.cpp''"<<endl;
         cout <<"\t\t\t\t          pour l'implementation des methodes citées plus haut \n"<<endl;

         cout <<"\t\t\t\t                            --------------------------------------------------      "<<endl;
         cout <<"\t\t\t\t  Une classe Utilitaire.hpp  ne possedant pas d'attributs .Elle contient les prototypes des methodes"<<endl;
         cout <<"\t\t\t\t          pour gerer les resultats du concours. Toutes les autres methodes sont à l'interieur "<<endl;
         cout <<"\t\t\t\t          ensuite un fichier ''Utilitaire.cpp'' pour l' implementation des methodes \n"<<endl;

         cout <<"\t\t\t\t                            --------------------------------------------------      "<<endl;
         cout <<"\t\t\t\t  Une classe Design.hpp  ne possedant pas d'attributs .Elle contient les prototypes des methodes"<<endl;
         cout <<"\t\t\t\t          pour gerer l ' affichage des donnees du concours.Ensuite un fichier ''Design.cpp'' pour"<<endl;
         cout <<"\t\t\t\t          l' implementation des methodes cet fichier ne contient que des 'cout' \n"<<endl;


         cout <<"\t\t\t\t                            --------------------------------------------------      "<<endl;
         cout <<"\t\t\t\t  Le dossier 'Fichiers' contient les differents fichiers pour  la gestion du concours  "<<endl;
         cout <<"\t\t\t\t          Entre autres admis.txt , attente.txt ,candidat.txt ,matiere.txt ,resultat.txt , evaluation.txt \n"<<endl;
}
void Utilitaire::vueSurNCI(){
  Design d;
    ifstream fcandidat("candidat.txt",ios::in);
    Candidat c;
    if(fcandidat)
    {   cout << " Les NCNI existants deja dans  le fichiers sont: "<<endl;
        cout << "[";
        while (fcandidat >> c )
        {

         cout << c.GetNCNI()<<" | ";

          }
           cout << "]"<<endl;
        fcandidat.close();
    }
    else
    {
        d.Message_Erreur_flux();
    }

}
void Utilitaire::vueSurCode(){
   Design d;
    ifstream fmatiere("matiere.txt",ios::in);
    Matiere m;
    if(fmatiere)
    {   cout << " Les Codes existants deja dans  le fichiers sont: "<<endl;
        cout << "[";
        while (fmatiere >> m )
        {

         cout <<m.Getcode()<<" | ";
        }
         cout << "]"<<endl;
        fmatiere.close();
    }else
    {
        d.Message_Erreur_flux();
    }
}

int Utilitaire::testBug(string choix)
{
  if(choix.find("-")== string::npos)
  {
      try
      {
         int var = stoi(choix);
         if(var >= 10){
            return 0;
         }else{
             return var;
          }
      }catch(const std::exception& e)
      {
          return 0;
      }
  }else{
       return 0;
  }
}
 double Utilitaire::testBugNote(string choix)
{
  if(choix.find("-")== string::npos)
  {
      try
      {
         double var = stod(choix);
         if(var < 0 || var > 20){
            return var;
         }
      }catch(const std::exception& e)
      {
          return -1;
      }
  }else{
       return -1;
  }
}
