#ifndef ENSEIGNANT_H
#define ENSEIGNANT_H

#include "personne.h"

class Enseignant : public Personne
{
    public:
        Enseignant();
        ~Enseignant();

        void saisirEnseignant();
        void afficherEnseignant();

        string getNMP();
        void setNMP(string);

    private:
        string nmp;
};

#endif

