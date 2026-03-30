#include "personne.h"

Personne::Personne()
{
    cinx ="";
    nom = "";
    pre = "";
    dn.j = 0;
    dn.m = 0;
    dn.a = 0;
}
Personne::~Personne()
{
	
}
void Personne::saisirPersonne()
{
   
    cout << "Nom : ";
    cin >> nom;

    cout << "Prenom : ";
    cin >> pre;

    cout << "Date de naissance\n";

    cout << "Jour : ";
    cin >> dn.j;

    while(dn.j < 1 || dn.j > 31)
    {
        cout << "Jour invalide. Ressaisir : ";
        cin >> dn.j;
    }

    cout << "Mois : ";
    cin >> dn.m;

    while(dn.m < 1 || dn.m > 12)
    {
        cout << "Mois invalide. Ressaisir : ";
        cin >> dn.m;
    }

    cout << "Annee : ";
    cin >> dn.a;

    while(dn.a < 1900 || dn.a > 2100)
    {
        cout << "Annee invalide. Ressaisir : ";
        cin >> dn.a;
    }
}

void Personne::afficherPersonne()
{
    cout << "CIN : " << cinx << endl;
    cout << "Nom : " << nom << endl;
    cout << "Prenom : " << pre << endl;
    cout << "Date : "
         << dn.j << "/"
         << dn.m << "/"
         << dn.a << endl;
}

string Personne::getcin()
{
    return cinx;
}

string Personne::getnom()
{
    return nom;
}

string Personne::getpre()
{
    return pre;
}

DateNaissance Personne::getdate()
{
    return dn;
}

void Personne::setcin(string c)
{
    cinx = c;
}

void Personne::setnom(string n)
{
    nom = n;
}

void Personne::setpre(string p)
{
    pre = p;
}

void Personne::setdate(DateNaissance d)
{
    dn = d;
}

