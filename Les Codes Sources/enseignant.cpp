#include "enseignant.h"
#include <iostream>
#include <vector>
using namespace std;

Enseignant::Enseignant()
{
    nmp = "";
}

Enseignant::~Enseignant()
{
	
}
void Enseignant::saisirEnseignant()
{
    saisirPersonne();

    cout << "NMP (Numero Prof) : ";
    cin >> nmp;

    while(nmp == "" || nmp == getcin())
    {
        if(nmp == "")
            cout << "NMP vide interdit. Ressaisir : ";
        else
            cout << "NMP ne peut pas etre identique au CIN. Ressaisir : ";

        cin >> nmp;
    }
}
void Enseignant::afficherEnseignant()
{
    afficherPersonne();
    cout << "NMP : " << nmp << endl;
}

string Enseignant::getNMP()
{
    return nmp;
}

void Enseignant::setNMP(string s)
{
    nmp = s;
}


