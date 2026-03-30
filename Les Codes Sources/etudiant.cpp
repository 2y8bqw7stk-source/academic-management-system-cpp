#include "etudiant.h"

Etudiant::Etudiant()
{

}
Etudiant::~Etudiant()
{
	
}
string Etudiant::getcne()
{ 
return cne;
}
void Etudiant::setcne(string s)
{ 
cne = s; 
}
void Etudiant::saisirEtudiant()
{
    saisirPersonne();

    cout << "CNE : ";
    cin >> cne;

    while(cne == "" || cne == getcin())
    {
        if(cne == "")
            cout << "CNE vide interdit. Ressaisir : ";
        else
            cout << "CNE ne peut pas etre identique au CIN. Ressaisir : ";

        cin >> cne;
    }
}
void Etudiant::inscrireModule(Module m)
{
    inscriptions.push_back(Inscription(m));
}

int Etudiant::ajouterControleDansModule(string code)
{
    for(int i=0;i<(int)inscriptions.size();i++)
    {
        if(inscriptions[i].getCodeModule() == code)
        {
            int nb;
            cout << "Nombre controles : ";
            cin >> nb;

            for(int j=0;j<nb;j++)
            {
                Controle c;
                c.saisirControle();
                inscriptions[i].ajouterControle(c);
            }

            return 1;
        }
    }
    return 0;
}

float Etudiant::moyenneGenerale()
{
    if(inscriptions.size() == 0)
        return -1;

    float s = 0;
    float sc = 0;

    for(int i=0;i<(int)inscriptions.size();i++)
    {
        float m = inscriptions[i].moyenneModule();
        if(m != -1)
        {
            s += m * inscriptions[i].getCoeffModule();
            sc += inscriptions[i].getCoeffModule();
        }
    }

    if(sc == 0)
        return -1;

    return s / sc;
}

void Etudiant::afficherEtudiantComplet()
{
    afficherPersonne();
    cout << "CNE : " << cne << endl;

    if(inscriptions.size() == 0)
    {
        cout << "Pas encore ajoute" << endl;
        return;
    }

    for(int i=0;i<(int)inscriptions.size();i++)
    {
        cout << "-----------------" << endl;
        inscriptions[i].afficherInscription();
    }

    float mg = moyenneGenerale();

    if(mg == -1)
        cout << "Moyenne generale : Pas encore ajoute" << endl;
    else
    {
        cout << "Moyenne generale : " << mg << endl;
        if(mg >= 10)
            cout << "Decision : Admis" << endl;
        else
            cout << "Decision : Ajourné" << endl;
    }
}
float Etudiant::moyenneModule(string code)
{
    for(int i = 0; i < (int)inscriptions.size(); i++)
    {
        if(inscriptions[i].getCodeModule() == code)
            return inscriptions[i].moyenneModule();
    }

    return -1;
}
vector<Inscription>& Etudiant::getInscriptions()
{
    return inscriptions;
}


