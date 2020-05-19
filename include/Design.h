#ifndef DESIGN_H
#define DESIGN_H

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

    protected:

    private:
};

#endif // DESIGN_H
