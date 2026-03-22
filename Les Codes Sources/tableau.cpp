#include "tableau.h"
#include <iostream>
using namespace std;

tableau::tableau(int a) : taille(a)
{
    for (int i = 0; i < taille; i++)
        data.push_back(0);
}

tableau::~tableau()
{
}

void tableau::set(float v, int pos)
{
    if (pos >= 0 && pos < taille)
        data[pos] = v;
}

float tableau::get(int pos)
{
    if (pos >= 0 && pos < taille)
        return data[pos];

    return 0;
}

float tableau::calculeMoyenne()
{
    if (taille == 0) {
	return 0; }
    float somme = 0;
    for (int i = 0; i < taille; i++)
        somme += data[i];

    return somme / taille;
}

