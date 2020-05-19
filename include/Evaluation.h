#ifndef EVALUATION_H
#define EVALUATION_H

#include <string>
#include "Utilitaire.h"
#include "Design.h"
#include "Evaluation.h"

#include <fstream>


using namespace std;
class Evaluation
{
    public:
        Evaluation();
        virtual ~Evaluation();

        void ajouterEvaluation();
        void supprimerEvaluation( int);
        void supprimerEvaluation( string);

         friend istream & operator >> (istream & flux, Evaluation &eval);
         friend ostream & operator << (ostream &flux, Evaluation &eval);

        string GetNCNI() { return NCNI; }
        void SetNCNI(string val) { NCNI = val; }
        double Getnote() { return note; }
        void Setnote(double val) { note = val; }
        string Getcode() { return code; }
        void Setcode(string val) { code = val; }

    protected:

    private:
        string NCNI;
        double note;
        string code;
};

#endif // EVALUATION_H
