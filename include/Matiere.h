#ifndef MATIERE_H
#define MATIERE_H

#include "Utilitaire.h"
#include "Design.h"
#include "Evaluation.h"

#include <fstream>
#include <string>


using namespace std;

class Matiere
{
    public:
        Matiere();
        virtual ~Matiere();

        void ajouterMatiere();
        void supprimerMatiere( string );
        void modifierMatiere();
        void afficherMatiere();

        friend istream & operator >>(istream &flux,Matiere &m);
        friend ostream & operator << (ostream &flux, Matiere &m);

        int Getcoefficient() { return coefficient; }
        void Setcoefficient(int val) { coefficient = val; }
        string Getcode() { return code; }
        void Setcode(string val) { code = val; }
        string Getlibelle() { return libelle; }
        void Setlibelle(string val) { libelle = val; }

    protected:

    private:
        int coefficient;
        string code;
        string libelle;
};

#endif // MATIERE_H
