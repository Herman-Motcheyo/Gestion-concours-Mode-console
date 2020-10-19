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
        void afficherAdmis(string,string,string,double moyn=0);
        void afficheStatistisque(double,double,double);
        void afficheResultat(string,double,string);
        void debut();
        void fin();
        void menuPrincipal();
        void actionMenu(char);
        void afficherEntite(char,string ,string,int,string);
        void fintp();

    protected:

    private:
};

#endif // DESIGN_H
