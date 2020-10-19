#ifndef CANDIDAT_H
#define CANDIDAT_H

#include <string>
#include "Utilitaire.h"
#include "Design.h"
#include "Evaluation.h"

#include <fstream>


using namespace std;
class Candidat
{
    public:
        Candidat();

        Candidat(string ncni,int age,string nom,string prenom);

        virtual ~Candidat();

        friend istream & operator >>(istream &flux,Candidat &cand);
        friend ostream & operator  <<(ostream &flux ,Candidat cdt);

        void ajouterCandidat();
        void supprimer_Candidat(string);
        void modifierCandidat();
        void afficherCandidat();

        string GetNCNI() { return NCNI; }
        void SetNCNI(string val) { NCNI = val; }
        int GetAGE() { return AGE; }
        void SetAGE(int val) { AGE = val; }
        string GetPRENOM() { return PRENOM; }
        void SetPRENOM(string val) { PRENOM = val; }
        string GetNOM() { return NOM; }
        void SetNOM(string val) { NOM = val; }

    protected:

    private:
        string NCNI;
        int AGE;
        string PRENOM;
        string NOM;
};

#endif // CANDIDAT_H
