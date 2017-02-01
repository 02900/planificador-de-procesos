// interfaz.h
// created by Juan Ortiz on 28/01/2017
// Copyright c 2017 Juan Ortiz. All rights reserved

#ifndef interfaz_h
#define interfaz_h

//#include <stdio.h>
//#include <stdlib.h>

#include "colasPrioridades.h"
#include "rutinas.h"

void menu(EstrucSched* s);

void menuInterno(EstrucSched* s);

void Imprime(EstrucSched *s);

void ImprimeProceso (Proceso* p);

#endif //interfaz_h