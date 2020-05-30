#pragma once

#include "kidGarden.h"

void input(kidGarden*&, int&, char*);
void add(kidGarden*&, int& amount, char*);
void output(kidGarden*, int);
void sort(kidGarden*, int, char*);
void cipher_del(kidGarden*, int&, char*);
void condition_del(kidGarden*, int&, char*);
void fieldCorrection(kidGarden*&, int, char*);
void fieldReplace(kidGarden*&, int, char*);