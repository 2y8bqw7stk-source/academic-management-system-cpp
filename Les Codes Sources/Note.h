#ifndef NOTE_H
#define NOTE_H

#include "tableau.h"

class Note : public tableau
{
public:
    Note(int a);

    void saisirNotes();
    void afficherNotes();
};

#endif

