#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include <vector>
#include "module.h"
#include "controle.h"
using namespace std;

class Inscription
{
    public:
        Inscription();
        Inscription(Module);
        ~Inscription();

        string getCodeModule();
        float getCoeffModule();

        void ajouterControle(Controle);

        float moyenneModule();
        void afficherInscription();
        vector<Controle> getControles();
        Module& getModule();

    private:
        Module mod;
        vector<Controle> controles;
};

#endif

