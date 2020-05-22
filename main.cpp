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
d.debut();
d.menuPrincipal();
d.Entrer('r');
try{
      cin >>choix;
   switch(choix){

       case 1:
           break;
       case 2 :
            break;
       case 3 :
           d.actionMenu('1');
           d.Entrer('r');
           cin >>choix;
           switch(choix){
              case 1:
                    d.actionMenu('2');
                    d.Entrer('r');
                    cin >>choix;
                     switch(choix){

                      case 1:
                         do{
                            c.ajouterCandidat();
                            d.Entrer('t');
                            cin >>rep;
                         }while (rep == 'o');

                       break;
                case 2:
                   do{
                     m.ajouterMatiere();
                     d.Entrer('t');
                      cin >>rep;
                  }while (rep == 'o');

                break;
            case 3:
                   do{
                    e.ajouterEvaluation();
                     d.Entrer('t');
                      cin >>rep;
                  }while (rep == 'o');

                break;

            default :
                    d.Entrer('t');
                break;
                   }
          break;


            case 2:
                d.actionMenu('3');
                     d.Entrer('r');
                    cin >>choix;
                     switch(choix){
                       case 1:
                         do{
                            c.modifierCandidat();
                            d.Entrer('t');
                            cin >>rep;
                         }while (rep == 'o');

                       break;

                        case 2:
                         do{
                            m.modifierMatiere();
                            d.Entrer('t');
                            cin >>rep;
                         }while (rep == 'o');

                       break;
                 default :
                        d.Entrer('t');
                     break;
                     }
                     break;
                        case 3:
                              d.actionMenu('4');
                              d.Entrer('r');
                              cin >>choix;
                     switch(choix){

                         case 1:
                               do{
                                    d.Menu_Entrer("candidat", 'c');
                                cin >>nci;
                            c.supprimer_Candidat(nci);
                            d.Message_Validation('s');
                            d.Entrer('t');
                            cin >>rep;
                         }while (rep == 'o');

                       break;
                         case 2:
                               do{
                                    d.Menu_Entrer("matiere", 'c');
                                cin >>code;
                           m.supprimerMatiere(code);
                            d.Message_Validation('s');
                            d.Entrer('t');
                            cin >>rep;
                         }while (rep == 'o');

                       break;
                         case 3:
                               do{
                                    d.Menu_Entrer("evaluation", 'c');
                                  cin >>code;
                             e.supprimerEvaluationCandidat(code);
                            d.Message_Validation('s');
                            d.Entrer('t');
                            cin >>rep;
                         }while (rep == 'o');

                       break;
                     }
                            break;

                break;
             }
        break;
                         case 4:
                             u.resultat();
                             u.afficherResultat();
                            break;
                         case 5:
                               d.Entrer('5');
                               u.admis();
                               u.afficherListeAdmis();
                            break;
                         case 6:
                             u.attente();
                             u.afficherListeAttente();
                            break;
                         case 7 :
                                u.afficheStatistique();
                            break;
                         case 8:
                                u.supprimer();
                               u.afficheAdmisDefinitif();
                            break;

   }
}catch(int exep){
    d.Entrer('e');
}



    return 0;
}
