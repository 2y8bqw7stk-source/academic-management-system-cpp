#include "systeme.h"
#include <fstream>
#include <iostream>
using namespace std;

Systeme::Systeme()
{ 
charger();
}
Systeme::~Systeme()
{
	
}
int Systeme::cinExisteGlobal(string c)
{
    for(int i = 0; i < (int)etudiants.size(); i++)
    {
        if(etudiants[i].getcin() == c)
            return 1;
    }
    for(int i = 0; i < (int)enseignants.size(); i++)
    {
        if(enseignants[i].getcin() == c)
            return 1;
    }

    return 0;
}
int Systeme::identifiantExiste(string id)
{
    for(int i=0;i<etudiants.size();i++)
    {
        if(etudiants[i].getcin() == id ||
           etudiants[i].getcne() == id)
            return 1;
    }
    for(int i=0;i<enseignants.size();i++)
    {
        if(enseignants[i].getcin() == id ||
           enseignants[i].getNMP() == id)
            return 1;
    }

    return 0;
}

int Systeme::codeModuleExiste(string code)
{
    for(int i=0;i<(int)modules.size();i++)
        if(modules[i].getcode() == code)
            return 1;
    return 0;
}
int Systeme::intituleModuleExiste(string intitule)
{
    for(int i=0;i<(int)modules.size();i++)
        if(modules[i].getintitule() == intitule)
            return 1;

    return 0;
}
int Systeme::positionEtudiantParCNE(string cne)
{
    for(int i=0;i<(int)etudiants.size();i++)
        if(etudiants[i].getcne() == cne)
            return i;
    return -1;
}

int Systeme::positionModuleParCode(string code)
{
    for(int i=0;i<(int)modules.size();i++)
        if(modules[i].getcode() == code)
            return i;
    return -1;
}

int Systeme::positionEnseignantParNMP(string nmp)
{
    for(int i=0;i<(int)enseignants.size();i++)
        if(enseignants[i].getNMP() == nmp)
            return i;
    return -1;
}

void Systeme::ajouterEnseignant()
{
    system("cls");

    Enseignant e;
    string cinx;
    do{
        cout << "CIN : ";
        cin >> cinx;

        if(identifiantExiste(cinx) == 1 || cinx == "")
            cout << "CIN invalide ou deja utilise !\n";

    }while(identifiantExiste(cinx) == 1 || cinx == "");

    e.setcin(cinx);
    e.saisirPersonne();
    string nmp;
    do{
        cout << "NMP : ";
        cin >> nmp;

        if(identifiantExiste(nmp) == 1 || nmp == "" || nmp == cinx)
            cout << "NMP invalide, deja utilise ou identique au CIN !\n";

    }while(identifiantExiste(nmp) == 1 || nmp == "" || nmp == cinx);

    e.setNMP(nmp);

    enseignants.push_back(e);

    cout << "Enseignant ajoute avec succes." << endl;
}
void Systeme::ajouterEtudiant()
{
    system("cls");

    Etudiant e;
    string cinx;
    do{
        cout << "CIN : ";
        cin >> cinx;

        if(identifiantExiste(cinx) == 1 || cinx == "")
            cout << "CIN invalide ou deja utilise !\n";

    }while(identifiantExiste(cinx) == 1 || cinx == "");

    e.setcin(cinx);
    e.saisirPersonne();
    string cne;
    do{
        cout << "CNE : ";
        cin >> cne;

        if(identifiantExiste(cne) == 1 || cne == "" || cne == cinx)
            cout << "CNE invalide, deja utilise ou identique au CIN !\n";

    }while(identifiantExiste(cne) == 1 || cne == "" || cne == cinx);

    e.setcne(cne);

    etudiants.push_back(e);

    cout << "Etudiant ajoute avec succes." << endl;
}
void Systeme::ajouterModule()
{
    system("cls");

    Module m;

    string code;

    cout << "Code module : ";
    cin >> code;

    while(codeModuleExiste(code) == 1)
    {
        cout << "Code module deja existant. Redonner : ";
        cin >> code;
    }

    m.setcode(code);

    string intitule;

    cout << "Intitule : ";
    cin >> intitule;

    while(intituleModuleExiste(intitule) == 1)
    {
        cout << "Intitule deja existant. Redonner : ";
        cin >> intitule;
    }

    m.setintitule(intitule);

    float coeff;

    cout << "Coefficient (1 a 14) : ";
    cin >> coeff;

    while(coeff < 1 || coeff > 14)
    {
        cout << "Coefficient invalide. Redonner : ";
        cin >> coeff;
    }

    m.setcoeff(coeff);

    modules.push_back(m);

    cout << "Module ajoute avec succes." << endl;
}

void Systeme::inscrireEtudiant()
{
    system("cls");

    string cne;
    cout << "CNE etudiant : ";
    cin >> cne;

    int pe = positionEtudiantParCNE(cne);
    if(pe < 0)
    {
        cout << "Etudiant introuvable." << endl;
        return;
    }

    string code;
    cout << "Code module : ";
    cin >> code;

    int pm = positionModuleParCode(code);
    if(pm < 0)
    {
        cout << "Module introuvable." << endl;
        return;
    }

    etudiants[pe].inscrireModule(modules[pm]);
    cout << "Inscription faite." << endl;
}

void Systeme::ajouterControle()
{
    system("cls");

    string cne, code;

    cout << "CNE etudiant : ";
    cin >> cne;

    int pe = positionEtudiantParCNE(cne);
    if(pe < 0){ cout << "Etudiant introuvable." << endl; return; }

    cout << "Code module : ";
    cin >> code;

    int ok = etudiants[pe].ajouterControleDansModule(code);

    if(ok == 0)
        cout << "Etudiant non inscrit a ce module." << endl;
    else
        cout << "Controle ajoute." << endl;
}

void Systeme::afficherEtudiant()
{
    system("cls");

    string cne;
    cout << "CNE : ";
    cin >> cne;

    int pe = positionEtudiantParCNE(cne);
    if(pe < 0){ cout << "Etudiant introuvable." << endl; return; }

    etudiants[pe].afficherEtudiantComplet();
}

void Systeme::afficherTousEtudiants()
{
    system("cls");

    if(etudiants.size() == 0)
    {
        cout << "Pas encore ajoute." << endl;
        return;
    }

    for(int i=0;i<(int)etudiants.size();i++)
    {
        cout << "--------------------" << endl;
        etudiants[i].afficherEtudiantComplet();
    }
}

void Systeme::afficherTousModules()
{
    system("cls");

    if(modules.size() == 0)
    {
        cout << "Pas encore ajoute." << endl;
        return;
    }

    for(int i=0;i<(int)modules.size();i++)
    {
        cout << "--------------------" << endl;
        modules[i].afficherModule();
    }
}

void Systeme::rechercherEtudiant()
{
    system("cls");

    string x;
    cout << "Recherche (CIN ou CNE) : ";
    cin >> x;

    for(int i=0;i<(int)etudiants.size();i++)
    {
        if(etudiants[i].getcin() == x || etudiants[i].getcne() == x)
        {
            etudiants[i].afficherEtudiantComplet();
            return;
        }
    }

    cout << "Aucun etudiant trouve." << endl;
}
void Systeme::affecterResponsableModule()
{
    system("cls");

    if(modules.size() == 0)
    {
        cout << "Pas encore de module." << endl;
        return;
    }

    if(enseignants.size() == 0)
    {
        cout << "Pas encore d'enseignant." << endl;
        return;
    }

    string code;
    cout << "Entrer code du module : ";
    cin >> code;

    int pm = positionModuleParCode(code);
    if(pm == -1)
    {
        cout << "Module introuvable." << endl;
        return;
    }

    string nmp;
    cout << "Entrer NMP de l'enseignant : ";
    cin >> nmp;

    int pe = positionEnseignantParNMP(nmp);
    if(pe == -1)
    {
        cout << "Enseignant introuvable." << endl;
        return;
    }
    modules[pm].ajouterResponsable(nmp);

    cout << "Responsable ajoute avec succes." << endl;
}

void Systeme::sauvegarder()
{
    ofstream f("systeme.txt");

    if(!f)
    {
        cout << "Erreur ouverture fichier." << endl;
        return;
    }
    f << modules.size() << endl;

    for(int i=0;i<modules.size();i++)
    {
        vector<string> resp = modules[i].getResponsables();

        f << modules[i].getcode() << " "
          << modules[i].getintitule() << " "
          << modules[i].getcoeff() << " "
          << resp.size() << " ";

        for(int j=0;j<resp.size();j++)
            f << resp[j] << " ";

        f << endl;
    }
    f << etudiants.size() << endl;

    for(int i=0;i<etudiants.size();i++)
    {
        DateNaissance d = etudiants[i].getdate();

        f << etudiants[i].getcin() << " "
          << etudiants[i].getnom() << " "
          << etudiants[i].getpre() << " "
          << d.j << " " << d.m << " " << d.a << " "
          << etudiants[i].getcne() << " ";

        vector<Inscription>& ins = etudiants[i].getInscriptions();
        f << ins.size() << endl;

        for(int j=0;j<ins.size();j++)
        {
            f << ins[j].getCodeModule() << " ";

            vector<Controle> ctrls = ins[j].getControles();
            f << ctrls.size() << endl;

            for(int k=0;k<ctrls.size();k++)
            {
                f << ctrls[k].gettype() << " "
                  << ctrls[k].getnote() << " "
                  << ctrls[k].getpoids() << endl;
            }
        }
    }
    f << enseignants.size() << endl;

    for(int i=0;i<enseignants.size();i++)
    {
        DateNaissance d = enseignants[i].getdate();

        f << enseignants[i].getcin() << " "
          << enseignants[i].getnom() << " "
          << enseignants[i].getpre() << " "
          << d.j << " " << d.m << " " << d.a << " "
          << enseignants[i].getNMP() << endl;
    }

    f.close();

    cout << "Sauvegarde complete terminee." << endl;
}

void Systeme::charger()
{
    ifstream f("systeme.txt");

    if(!f)
    {
        cout << "Fichier introuvable." << endl;
        return;
    }

    modules.clear();
    etudiants.clear();
    enseignants.clear();

    int n;
    f >> n;

    for(int i=0;i<n;i++)
    {
        string code, intit;
        float coeff;
        int nbResp;

        f >> code >> intit >> coeff >> nbResp;

        Module m(code,intit,coeff);

        for(int j=0;j<nbResp;j++)
        {
            string r;
            f >> r;
            m.ajouterResponsable(r);
        }

        modules.push_back(m);
    }
    f >> n;

    for(int i=0;i<n;i++)
    {
        Etudiant e;
        string cinx, nom, pre, cne;
        DateNaissance d;
        int nbIns;

        f >> cinx >> nom >> pre >> d.j >> d.m >> d.a >> cne >> nbIns;

        e.setcin(cinx);
        e.setnom(nom);
        e.setpre(pre);
        e.setdate(d);
        e.setcne(cne);

        for(int j=0;j<nbIns;j++)
        {
            string codeModule;
            int nbCtrl;

            f >> codeModule >> nbCtrl;

            int pm = positionModuleParCode(codeModule);

            if(pm != -1)
            {
                e.inscrireModule(modules[pm]);
                for(int k=0;k<nbCtrl;k++)
                {
                    string type;
                    float note, poids;

                    f >> type >> note >> poids;

                    Controle c;
                    c.settype(type);
                    c.setnote(note);
                    c.setpoids(poids);

                    e.getInscriptions().back().ajouterControle(c);
                }
            }
            else
            {
                for(int k=0;k<nbCtrl;k++)
                {
                    string type;
                    float note, poids;
                    f >> type >> note >> poids;
                }
            }
        }

        etudiants.push_back(e);
    }
    f >> n;

    for(int i=0;i<n;i++)
    {
        Enseignant e;
        string cinx, nom, pre, nmp;
        DateNaissance d;

        f >> cinx >> nom >> pre >> d.j >> d.m >> d.a >> nmp;

        e.setcin(cinx);
        e.setnom(nom);
        e.setpre(pre);
        e.setdate(d);
        e.setNMP(nmp);

        enseignants.push_back(e);
    }

    f.close();

    cout << "Chargement complet termine." << endl;
}
void Systeme::afficherEnseignantParNMP()
{
    system("cls");

    if(enseignants.size() == 0)
    {
        cout << "Aucun enseignant enregistre." << endl;
        return;
    }

    string nmp;
    cout << "Entrer NMP : ";
    cin >> nmp;

    int pe = positionEnseignantParNMP(nmp);
    if(pe == -1)
    {
        cout << "Enseignant introuvable." << endl;
        return;
    }

    cout << "==============================" << endl;
    enseignants[pe].afficherEnseignant();

    cout << "Modules responsables :" << endl;

    int trouve = 0;
    for(int j=0;j<(int)modules.size();j++)
    {
        vector<string> resp = modules[j].getResponsables();
        for(int k=0;k<(int)resp.size();k++)
        {
            if(resp[k] == nmp)
            {
                cout << "   -> " << modules[j].getcode()
                     << " | " << modules[j].getintitule()
                     << endl;
                trouve = 1;
                break;
            }
        }
    }

    if(trouve == 0)
        cout << "   Pas encore de module affecte." << endl;
}

void Systeme::afficherTousEnseignants()
{
    system("cls");

    if(enseignants.size() == 0)
    {
        cout << "Aucun enseignant." << endl;
        return;
    }

    for(int i=0;i<(int)enseignants.size();i++)
    {
        cout << "\n===== ENSEIGNANT " << i+1 << " =====" << endl;
        enseignants[i].afficherEnseignant();
    }
}

void Systeme::afficherEnseignantsAvecModules()
{
    system("cls");

    if(enseignants.size() == 0)
    {
        cout << "Aucun enseignant." << endl;
        return;
    }

    for(int i=0;i<(int)enseignants.size();i++)
    {
        cout << "\n=========================" << endl;
        cout << "ENSEIGNANT " << i+1 << endl;
        cout << "-------------------------" << endl;

        enseignants[i].afficherEnseignant();

        cout << "Modules responsables :" << endl;

        int trouve = 0;
        string nmp = enseignants[i].getNMP();

        for(int j=0;j<(int)modules.size();j++)
        {
            vector<string> resp = modules[j].getResponsables();
            for(int k=0;k<(int)resp.size();k++)
            {
                if(resp[k] == nmp)
                {
                    cout << " - Code : " << modules[j].getcode()
                         << " | Intitule : " << modules[j].getintitule()
                         << " | Coeff : " << modules[j].getcoeff()
                         << endl;
                    trouve = 1;
                    break;
                }
            }
        }

        if(trouve == 0)
            cout << "   Aucun module affecte." << endl;
    }
}
void Systeme::statistiquesModules()
{
    for(int m = 0; m < (int)modules.size(); m++)
    {
        int total = 0;
        int reussite = 0;
        float sommeMoyennes = 0;

        for(int e = 0; e < (int)etudiants.size(); e++)
        {
            float moy = etudiants[e].moyenneModule(modules[m].getcode());

            if(moy != -1) 
            {
                total++;
                sommeMoyennes += moy;

                if(moy >= 10)
                    reussite++;
            }
        }

        cout << "----------------------" << endl;
        cout << "Module : " << modules[m].getcode() << endl;

        if(total > 0)
        {
            cout << "Moyenne generale : " << sommeMoyennes/total << endl;
            cout << "Taux de reussite : " << (reussite*100.0)/total << " %" << endl;
        }
        else
        {
            cout << "Aucun etudiant inscrit." << endl;
        }
    }
}
void Systeme::filtrerParMoyenne()
{
    float seuil;
    cout << "Afficher etudiants avec moyenne >= : ";
    cin >> seuil;

    int compteur = 0;

    for(int i = 0; i < (int)etudiants.size(); i++)
    {
        float moy = etudiants[i].moyenneGenerale();

        if(moy >= seuil)
        {
            cout << "-------------------" << endl;
            etudiants[i].afficherEtudiantComplet();
            compteur++;
        }
    }

    if(compteur == 0)
        cout << "Aucun etudiant ne correspond au seuil." << endl;
}
void Systeme::rechercherParModule()
{
    string code;
    cout << "Code module : ";
    cin >> code;

    bool trouve = false;

    for(int i = 0; i < (int)etudiants.size(); i++)
    {
        float moy = etudiants[i].moyenneModule(code);

        if(moy != -1)
        {
            trouve = true;

            cout << "-------------------" << endl;
            etudiants[i].afficherEtudiantComplet();
            cout << "Moyenne module : " << moy << endl;
        }
    }

    if(!trouve)
    {
        cout << "Aucun etudiant inscrit dans ce module." << endl;
    }
}
void Systeme::classementEtudiants()
{
    if(etudiants.size() == 0)
    {
        cout << "Aucun etudiant." << endl;
        return;
    }

    vector<Etudiant> temp = etudiants;
    for(int i = 0; i < (int)temp.size() - 1; i++)
    {
        int maxIndex = i;

        for(int j = i + 1; j < (int)temp.size(); j++)
        {
            if(temp[j].moyenneGenerale() > temp[maxIndex].moyenneGenerale())
                maxIndex = j;
        }

        if(maxIndex != i)
        {
            Etudiant t = temp[i];
            temp[i] = temp[maxIndex];
            temp[maxIndex] = t;
        }
    }

    cout << "===== CLASSEMENT =====" << endl;

    for(int i = 0; i < (int)temp.size(); i++)
    {
        cout << "Classement" << i+1 << " : "
             << temp[i].getnom() << " "
             << temp[i].getpre()
             << " | Moyenne : "
             << temp[i].moyenneGenerale()
             << endl;
    }

}
void Systeme::filtrerParDecision()
{
    string decision;
    cout << "Decision (Admis/Ajourne) : ";
    cin >> decision;

    int compteur = 0;

    for(int i = 0; i < (int)etudiants.size(); i++)
    {
        float moy = etudiants[i].moyenneGenerale();

        string dec;

        if(moy >= 10)
            dec = "Admis";
        else
            dec = "Ajourne";

        if(dec == decision)
        {
            cout << "-------------------" << endl;
            etudiants[i].afficherEtudiantComplet();
            compteur++;
        }
    }

    if(compteur == 0)
        cout << "Aucun etudiant trouve." << endl;

}
void Systeme::tauxReussiteParModule()
{
    for(int m = 0; m < (int)modules.size(); m++)
    {
        int total = 0;
        int reussite = 0;

        for(int e = 0; e < (int)etudiants.size(); e++)
        {
            float moy = etudiants[e].moyenneModule(modules[m].getcode());

            if(moy != -1)
            {
                total++;

                if(moy >= 10)
                    reussite++;
            }
        }

        cout << "--------------------" << endl;
        cout << "Module : " << modules[m].getcode() << endl;

        if(total == 0)
        {
            cout << "Aucun etudiant inscrit." << endl;
        }
        else
        {
            cout << "Taux de reussite : "
                 << (reussite * 100.0) / total
                 << " %" << endl;
        }
    }

}
void Systeme::menu()
{
    int ch;

    do{
        system("cls");

        cout << "MENU DU SYSTEME ACADEMIQUE" << endl;
        cout << "1. Ajouter etudiant" << endl;
        cout << "2. Ajouter module" << endl;
        cout << "3. Inscrire etudiant a un module" << endl;
        cout << "4. Ajouter controles et notes" << endl;
        cout << "5. Afficher un etudiant complet" << endl;
        cout << "6. Afficher tous les etudiants" << endl;
        cout << "7. Afficher tous les modules" << endl;
        cout << "8. Rechercher etudiant (CIN/CNE)" << endl;
        cout << "9. Ajouter Enseignant" << endl;
        cout << "10.Affecter responsable a un module" << endl;
        cout << "11.Afficher un enseignant par NMP" << endl;
        cout << "12.Afficher tous les enseignants" << endl;
        cout << "13.Afficher enseignants avec leurs modules" << endl;
        cout << "14.Sauvegarder" << endl;
        cout << "15.Charger" << endl;
        cout << "16.Statistiques globales" << endl;
		cout << "17.Filtrer par moyenne" << endl;
		cout << "18.Rechercher par module" << endl;
		cout << "19.Classement des etudiants" << endl; 
		cout << "20.Filtrer par decision" << endl;          
		cout << "21.Taux de reussite par module" <<endl;
        cout << "0. Quitter" << endl;
        cout << "Choix : ";

        cin >> ch;

        if(ch == 1) ajouterEtudiant();
        else if(ch == 2) ajouterModule();
        else if(ch == 3) inscrireEtudiant();
        else if(ch == 4) ajouterControle();
        else if(ch == 5) afficherEtudiant();
        else if(ch == 6) afficherTousEtudiants();
        else if(ch == 7) afficherTousModules();
        else if(ch == 8) rechercherEtudiant();
        else if(ch == 9) ajouterEnseignant();
        else if(ch == 10) affecterResponsableModule();
        else if(ch == 11) afficherEnseignantParNMP();
        else if(ch == 12) afficherTousEnseignants();
        else if(ch == 13) afficherEnseignantsAvecModules();
        else if(ch == 14) sauvegarder();
        else if(ch == 15) charger();
        else if(ch == 16) statistiquesModules();
		else if(ch == 17) filtrerParMoyenne();
		else if(ch == 18) rechercherParModule();
		else if(ch == 19) classementEtudiants();       
		else if(ch == 20) filtrerParDecision();       
		else if(ch == 21) tauxReussiteParModule();      
		else if(ch == 0) cout << "Au revoir." << endl;
		else cout << "Choix invalide." << endl;
		
        system("pause");

    }while(ch != 0);

}

