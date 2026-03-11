#include "controle.h"

Controle::Controle()
{
    type = "";
    note = 0;
    poids = 0;
}

Controle::~Controle()
{
	
	
}
void Controle::saisirControle()
{
    while(true)
{
    cout << "Type (CC/TP/EXAMEN) : ";
    cin >> type;

    if(type == "CC" || type == "TP" || type == "EXAMEN")
        break;

    cout << "Type invalide. Seulement CC, TP ou EXAMEN\n";
}
    cout << "Note : ";
    cin >> note;

    while(note < 0 || note > 20)
    {
        cout << "Note invalide (0-20). Ressaisir : ";
        cin >> note;
    }
    cout << "Poids : ";
cin >> poids;

while(poids <= 0 || poids > 100)
{
    cout << "Poids invalide (1-100). Ressaisir : ";
    cin >> poids;
}
}

void Controle::afficherControle()
{
    cout << "Type : " << type
         << " | Note : " << note
         << " | Poids : " << poids
         << endl;
}

float Controle::getnote()
{
    return note;
}

float Controle::getpoids()
{
    return poids;
}

string Controle::gettype()
{
    return type;
}

void Controle::setnote(float n)
{
    note = n;
}

void Controle::setpoids(float p)
{
    poids = p;
}

void Controle::settype(string t)
{
    type = t;
}

