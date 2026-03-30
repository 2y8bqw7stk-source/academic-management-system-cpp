#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <vector>
#include "personne.h"
#include "inscription.h"

class Etudiant : public Personne
{
    public:
        Etudiant();
        ~Etudiant();

        string getcne();
        void setcne(string);

        void saisirEtudiant();
        void inscrireModule(Module);
        int ajouterControleDansModule(string);

        float moyenneGenerale();
        void afficherEtudiantComplet();
        float moyenneModule(string codeModule);
       vector<Inscription>& getInscriptions();

    private:
        string cne;
        vector<Inscription> inscriptions;

};

#endif

