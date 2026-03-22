#include "Module.h"
#include <iostream>
using namespace std;
Module::Module()
{
    code = "";
    intitule = "";
    coeff = 1;
}

Module::Module(string c, string i, float co)
{
    code = c;
    intitule = i;
    coeff = co;
}
Module::~Module()
{
	
}
void Module::saisirModule(vector<Module>& modulesExistants)
{
    while(true)
    {
        cout << "Code module : ";
        cin >> code;

        int i = 0;
        for(i = 0; i < (int)modulesExistants.size(); i++)
        {
            if(modulesExistants[i].getcode() == code)
            {
                cout << "Code deja utilise. Ressaisir.\n";
                break;
            }
        }

        if(i == modulesExistants.size())
            break;
    }
    while(true)
    {
        cout << "Intitule : ";
        cin >> intitule;
        int erreur = 0;

        for(int k = 0; k < (int)intitule.length(); k++)
        {
            if(intitule[k] >= '0' && intitule[k] <= '9')
            {
                erreur = 1;
                break;
            }
        }

        if(erreur == 1)
        {
            cout << "L'intitule ne doit pas contenir de chiffres. Ressaisir.\n";
            continue;
        }
        int i = 0;
        for(i = 0; i < (int)modulesExistants.size(); i++)
        {
            if(modulesExistants[i].getintitule() == intitule)
            {
                cout << "Intitule deja utilise. Ressaisir.\n";
                break;
            }
        }

        if(i == modulesExistants.size())
            break;
    }

    cout << "Coefficient (1 a 14) : ";
    cin >> coeff;

    while(coeff < 1 || coeff > 14)
    {
        cout << "Coefficient invalide. Ressaisir : ";
        cin >> coeff;
    }
}
void Module::afficherModule()
{
    cout << "Code : " << code << endl;
    cout << "Intitule : " << intitule << endl;
    cout << "Coefficient : " << coeff << endl;

    cout << "Responsables : ";
    if(nmpResponsables.size() == 0) cout << "Aucun";
    else
    {
        for(int i=0;i<(int)nmpResponsables.size();i++)
        {
            cout << nmpResponsables[i];
            if(i != (int)nmpResponsables.size()-1) cout << ", ";
        }
    }
    cout << endl;
}

string Module::getcode()
{ 
return code; 
}
string Module::getintitule()
{ 
return intitule;
}
float Module::getcoeff()
{ 
return coeff;
}

void Module::setcode(string c)
{ 
code = c; 
}
void Module::ajouterResponsable(string nmp)
{
    for(int i=0;i<(int)nmpResponsables.size();i++)
        if(nmpResponsables[i] == nmp)
            return; 
    nmpResponsables.push_back(nmp);
}
float Module::calculerMoyenne()
{
    if(controles.size() == 0)
        return 0;

    float somme = 0;
    float sommePoids = 0;

    for(int i=0;i<(int)controles.size();i++)
    {
        somme += controles[i].getnote() * controles[i].getpoids();
        sommePoids += controles[i].getpoids();
    }

    if(sommePoids == 0)
        return 0;

    return somme / sommePoids;
}

vector<string> Module::getResponsables()
{
    return nmpResponsables;
}
void Module::setintitule(string i)
{
    intitule = i;
}

void Module::setcoeff(float c)
{
    coeff = c;
}

