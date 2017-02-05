//  colasPrioridades.h
//  Planificador de procesos
//
//  Created by Juan Ortiz & Andres Buelvas on 29/1/17.
//  Copyright © 2017 Juan Ortiz & Andres Buelvas. All rights reserved.
//

#ifndef colasPrioridades
#define colasPrioridades

#include "cola.h"

typedef struct EstrucSched {
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
