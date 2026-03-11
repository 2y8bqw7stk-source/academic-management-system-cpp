#ifndef PERSONNE_H
#define PERSONNE_H

#include <iostream>
#include <string>
using namespace std;

struct DateNaissance
{
    int j;
    int m;
    int a;
};
class Personne
{
    public:
        Personne();
        ~Personne();

        void saisirPersonne();
        void afficherPersonne();

        string getcin();
        string getnom();
        string getpre();
        DateNaissance getdate();

        void setcin(string);
        void setnom(string);
        void setpre(string);
        void setdate(DateNaissance);

    protected:
        string cinx;
        string nom;
        string pre;
        DateNaissance dn;
};

#endif

