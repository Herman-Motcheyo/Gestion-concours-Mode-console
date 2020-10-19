#ifndef UTILITAIRE_H
#define UTILITAIRE_H
#include "Candidat.h"
#include "Matiere.h"
#include "Design.h"
#include <string>

class Utilitaire
{
    public:
        Utilitaire();
        virtual ~Utilitaire();

        bool Existe_Candidat(string);
        bool Existe_Matiere( string);
        int coef_Matiere(string);
        int nombre_elem_Fichier(string);
        double* notes_candidat(string ,int );
        double moyenne(double[],int [],int);
        void resultat();             /*  par le prof */
        string decision(double[],double ,int);   /*  par le prof */
        void admis();                 /*  par le prof */
        void afficherListeAdmis();
        void afficherResultat();
        void attente();            /*  par le prof */
        void afficherListeAttente();
        double statistique(string);    /*  par le prof */
        void afficheStatistique();
        void supprimer();           /*  par le prof */
        void afficheAdmisDefinitif();
        void afficheMerite();      /*  par le prof */
        void dataStructure();
        void vueSurNCI();
        void vueSurCode();
        int  testBug(string);
        double testBugNote(string);


    private:
};

#endif // UTILITAIRE_H
