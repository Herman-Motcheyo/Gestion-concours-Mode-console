#ifndef DESIGN_H
#define DESIGN_H
#include "Utilitaire.h"
#include <string>

using namespace std;
class Design
{
    public:
        Design();
        virtual ~Design();

        void Menu_Entrer(string ,char);
        void MenuModifier(string ,char);
        void MenuModifier(char);
        void Entrer();
        void Entrer(char );
        void Message_Erreur_flux();
        void Message_Erreur(char );
        void Message_Validation(char);
        void afficherAdmis(string,string,string,int);
        void afficheStatistisque(double,double,double);
        void debut();
        void fin();

    protected:

    private:
};

#endif // DESIGN_H
