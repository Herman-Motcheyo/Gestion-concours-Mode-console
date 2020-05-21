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
        int nombre_elem_Fichier(char *);
        double* notes_candidat(string ,int );
        double moyenne(double[],int [],int);
        void resultat();
        string decision(double[],double ,int);
        void admis();
        void afficherListeAdmis();
        void attente();
        void afficherListeAttente();
        double statistique(string);
        void afficheStatistique();
        void supprimer();
        void afficheAdmisDefinitif();


    private:
};

#endif // UTILITAIRE_H
