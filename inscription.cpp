#include "inscription.h"
#include <vector>

Inscription::Inscription()
{
	
}
Inscription::Inscription(Module m)
{ 
mod = m;
}
Inscription::~Inscription()
{
	
}
string Inscription::getCodeModule()
{ 
return mod.getcode(); 
}
float Inscription::getCoeffModule()
{ 
return mod.getcoeff(); 
}
void Inscription::ajouterControle(Controle c)
{
    controles.push_back(c);
}

float Inscription::moyenneModule()
{
    vector<Controle> ctrls = getControles();
    if(ctrls.size() == 0)
        return -1;
    float somme = 0;
    float totalPoids = 0;
    for(int i=0;i<ctrls.size();i++)
    {
        somme += ctrls[i].getnote() * ctrls[i].getpoids();
        totalPoids += ctrls[i].getpoids();
    }
    if(totalPoids <= 0)
        return -1;
    return somme / totalPoids;
}
void Inscription::afficherInscription()
{
    mod.afficherModule();

    if(controles.size() == 0)
    {
        cout << "Pas encore ajoute" << endl;
        return;
    }

    for(int i=0;i<(int)controles.size();i++)
        controles[i].afficherControle();

    float m = moyenneModule();

    if(m == -1)
        cout << "Moyenne module : Pas encore ajoute" << endl;
    else
        cout << "Moyenne module : " << m << endl;
        
}

vector<Controle> Inscription::getControles()
{
    return controles;
}
Module& Inscription::getModule()
{
    return mod;
}

