#ifndef CONTROLE_H
#define CONTROLE_H

#include <iostream>
#include <string>
using namespace std;

class Controle
{
    public:
        Controle();
        ~Controle(); 

        void saisirControle();
        void afficherControle();

        float getnote();
        float getpoids();
        string gettype();
        
        void setnote(float);
        void setpoids(float);
        void settype(string);

    private:
        string type;
        float note;
        float poids;
};

#endif

