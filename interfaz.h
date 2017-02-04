// interfaz.h
// created by Juan Ortiz on 28/01/2017
// Copyright c 2017 Juan Ortiz. All rights reserved

#ifndef interfaz_h
#define interfaz_h

#include <stdio.h>

#include "colasPrioridades.h"
#include "rutinas.h"

void menu(EstrucSched* s, char* salida);

void menuInterno(EstrucSched* s, char* salida);

void Imprime(EstrucSched *s);

void ImprimeProceso (Proceso* p);

void Salir (EstrucSched *s, char* salida);
void escribeSalida (Proceso *p, FILE* fp);

void msg_estatoInvalido ();
void msg_ErrorInsertar (Proceso* p);
void msg_ErrorElim ();
void msg_Busy ();
void msg_ErrorOpenFile ();

#endif //interfaz_h