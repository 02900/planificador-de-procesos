// colasPrioridades.h
// Created by Juan Ortiz on 28/01/2017
// Copyright c 2017 Juan Ortiz. All rights reseved.

#ifndef colasPrioridades
#define colasPrioridades

#include "cola.h"

// Estructura de colas de prioridades del planificador
// Es una estructura con apuntadores a las colas. 
typedef struct EstrucSched {
    int init;
	Cola* q0;
	Cola* q1;
	Cola* q2;
	Cola* q3;
	Cola* q4;
	Cola* q5;
    
    Cola*  enEjecucion;
} EstrucSched;

EstrucSched* Construye(char* filename);

#endif //colasPrioridades
