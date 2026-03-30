#include "Note.h"
#include <iostream>
using namespace std;

Note::Note(int a) : tableau(a)
{
}

void Note::saisirNotes()
{
    float a;
    for (int i = 0; i < taille; i++)
    {
        do {
            cout << "T[" << i << "]=";
            cin >> a;
        } while ((a < 0) || (a > 20));

        set(a, i);
    }
}

void Note::afficherNotes()
{
    for (int i = 0; i < taille; i++)
    {
        cout << "T[" << i << "]=" << get(i) << endl;
    }
}

