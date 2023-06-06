#ifndef FUNCION_H
#define FUNCION_H
#include "dataType.h"

int izbornik(const char* const);    //4

void kreiranjeDatoteke(const char* const);

void dodavanjeIgraca(const char* const);

void* ucitavanjeIgraca(const char* const);

void ispisPodataka(const IGRAC* const);

void* dresIgraca(IGRAC* const);

void* imeIgraca(IGRAC* const);

void* prezimeIgraca(IGRAC* const);

int izlazIzPrograma(IGRAC*);

#endif
