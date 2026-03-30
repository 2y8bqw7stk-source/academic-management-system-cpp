#ifndef SYSTEME_H
#define SYSTEME_H

#include <iostream>
#include <vector>
#include "enseignant.h"
#include <string>
#include <fstream>
#include "etudiant.h"
#include "Module.h"

using namespace std;

class Systeme
{
    public:
        Systeme();
        ~Systeme();

        void menu();

    private:
        vector<Etudiant> etudiants;
        vector<Module> modules;
        vector<Enseignant> enseignants;
       	int cinExisteGlobal(string);
		int cneExiste(string);
		int NMPExiste(string);
		int positionEtudiantParCNE(string);
		int positionModuleParCode(string);
		int positionEnseignantParNMP(string);
		int identifiantExiste(string id);
        int codeModuleExiste(string);
        void ajouterEtudiant();
        void ajouterModule();
        void inscrireEtudiant();
        void ajouterControle();
        void afficherEtudiant();
        void afficherTousEtudiants();
        void afficherTousModules();
        void rechercherEtudiant();
        void sauvegarder();
        void charger();
        void ajouterEnseignant();
        void affecterResponsableModule();
        void afficherEnseignantParNMP();
        void afficherTousEnseignants();
        void afficherEnseignantsAvecModules();
        void statistiquesModules();
		void filtrerParMoyenne();
		void rechercherParModule();
		int intituleModuleExiste(string intitule);
		void classementEtudiants();
		void filtrerParDecision();
		void tauxReussiteParModule();
};

#endif

