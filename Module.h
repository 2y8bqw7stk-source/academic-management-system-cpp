#ifndef Module.h
#define Module.h

#include <iostream>
#include <string>
#include <vector>
#include "controle.h"
using namespace std;

class Module
{
public:
    Module();
    Module(string, string, float);
    ~Module();

    void saisirModule(vector<Module>& modulesExistants);
    void afficherModule();

    string getcode();
    string getintitule();
    float getcoeff();

    void ajouterResponsable(string nmp);
    float calculerMoyenne();
    void setcode(string c);
	void setintitule(string i);
	void setcoeff(float c);
    vector<string> getResponsables();

private:
    string code;
    string intitule;
    float coeff;
    vector<string> nmpResponsables;
    vector<Controle> controles;
};

#endif

