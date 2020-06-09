#include <iostream>
#include <string>
#include "Candidat.h"
#include "Matiere.h"
#include "Evaluation.h"
#include "Utilitaire.h"


using namespace std;

int main()
{
Design d;
Candidat c;
Matiere m;
Evaluation e;
Utilitaire u;
int choix = 0;
char rep;
string nci,code;

do
{
d.debut();
d.menuPrincipal();
d.Entrer('r');

cin >>choix;

 if(choix == 1)
 {
   u.dataStructure();    /* structure de données utilisées pour la gestion du concours*/

 }else if(choix == 2)
 {  do{
     d.actionMenu('5');
     d.Entrer('r');
     cin >>choix;
     if(choix == 1)
     {   d.Entrer('9');
         d.Entrer('w');
         c.afficherCandidat();   /* Affichage des candidats*/
     }else if(choix == 2)
     {   d.Entrer('b');
         m.afficherMatiere(); /* Affichage des matieres*/
     }else if(choix ==3)
     {   d.Entrer('h');
         e.afficherEvaluation(); /* Affichage des Evaluations*/
     }
        d.Entrer('n');
        cin >>rep;
 }while(rep == 'o');

 } else if(choix == 3)
 {  do{

     d.actionMenu('1');
     d.Entrer('r');
     cin >>choix;
      if(choix == 1)
      {  do
      {
         d.actionMenu('2');
         d.Entrer('r');
         cin >>choix;
         if(choix == 1)
         {
            do{
                u.vueSurNCI();    /*montre les nci deja presents en bd pour eviter que le systeme lance des erreurs*/
               c.ajouterCandidat();               /* Ajout des candidats*/
               d.Entrer('p');
              cin >>rep;
            }while (rep == 'o');
         }else if(choix == 2)
         {
           do{
                u.vueSurCode(); /*montre les code deja presents en bd pour eviter au systeme de lancer des erreurs*/
            m.ajouterMatiere();               /* Ajout des matieres*/
            d.Entrer('t');
            cin >>rep;
            }while (rep == 'o');

          }else if(choix== 3)
         {
            do{
              e.ajouterEvaluation();                   /* Ajout des evaluations*/
              d.Entrer('t');
              cin >>rep;
           }while (rep == 'o');
        }
              d.Entrer('q');
              cin >>rep;
          }while (rep == 'o');
      }else if(choix == 2)
      {   do{
                d.actionMenu('3');
                     d.Entrer('r');
                    cin >>choix;
                     if( choix == 1)
                     {
                         do{
                            c.modifierCandidat();                  /* modifications des candidats*/
                            d.Entrer('z');
                            cin >>rep;
                         }while (rep == 'o');
                     }else if(choix == 2)
                     {
                          do{
                            m.modifierMatiere();                  /* modifications des matieres*/
                            d.Entrer('i');
                            cin >>rep;
                         }while (rep == 'o');
                     }
                d.Entrer('s');
                cin >>rep;
      }while (rep == 'o');

      }else if(choix == 3)
      {  do{
            d.actionMenu('4');
            d.Entrer('r');
            cin >>choix;

            if(choix == 1)
            {
                    do{
                        u.vueSurNCI();
                        d.Menu_Entrer("candidat", 'c');           /* suppression  des candidats*/
                        cin >>nci;
                        c.supprimer_Candidat(nci);
                        d.Message_Validation('s');
                        d.Entrer('y');
                        cin >>rep;
                    }while (rep == 'o');
            }
               else if(choix == 2)
               {     do{
                       u.vueSurCode();
                        d.Menu_Entrer("matiere", 'c');
                        cin >>code;
                        m.supprimerMatiere(code);                     /* suppression  des matieres*/
                        d.Message_Validation('s');
                        d.Entrer('a');
                        cin >>rep;
                    }while (rep == 'o');
               } else if(choix == 3)
               {
                    do{
                        d.Menu_Entrer("evaluation", 'c');
                        cin >>code;
                        e.supprimerEvaluationCandidat(code);              /* suppression  de evaluation*/
                        d.Message_Validation('s');
                        d.Entrer('d');
                            cin >>rep;
                    }while (rep == 'o');
               }
            d.Entrer('l');
            cin >>rep;
      }while (rep == 'o');

      }
        d.Entrer('u');
        cin >>rep;
 }while (rep == 'o');

 }else if(choix == 4)
 {
        d.Entrer('k');
        u.resultat();                    /*fonction resultat pour le resultat, et affichage*/
        u.afficherResultat();
 }else if(choix == 5)
 {
        d.Entrer('5');
        u.admis();                         /*fonction admis   et affichage*/
        u.afficherListeAdmis();
 }else if(choix== 6)
 {      d.Entrer('6');
        u.attente();                        /*fonction attente  et affichage*/
        u.afficherListeAttente();
 }else if(choix == 7)
 {       d.Entrer('7');                     /*affichage des statistiques*/
        u.afficheStatistique();
 }else if(choix == 8)
 {       d.Entrer('8');                    /*affichage en masses */
         u.supprimer();
         u.afficheAdmisDefinitif();
 }
 else if(choix == 9)
 {
     d.actionMenu('a');
    d.Entrer('f');
      u.afficheMerite();                 /*affichage par ordre de merite */
 }

        d.Entrer('0');
        cin >>rep;
        if(rep=='n')                  /* fin du projet */
            d.fintp();
      }while (rep == 'o');


    return 0;
}
