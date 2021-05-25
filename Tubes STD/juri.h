#ifndef JURI_H_INCLUDED
#define JURI_H_INCLUDED
#include "otak.h"
#include "peserta.h"
#include "admin.h"

adrJ loginJuri(ListJ LJ);
void menilai(ListR &LR,adrJ J,ListP &LP);
adrR searchNilai(ListR LR, int nilai);


#endif // JURI_H_INCLUDED
