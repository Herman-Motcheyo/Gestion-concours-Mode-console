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


    private:
};

#endif // UTILITAIRE_H
